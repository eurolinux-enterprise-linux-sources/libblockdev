/*
 * Copyright (C) 2017  Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Vratislav Podzimek <vpodzime@redhat.com>
 */

#include <glib.h>
#include <blkid.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <blockdev/utils.h>

#include "fs.h"
#include "common.h"

gint __attribute__ ((visibility ("hidden")))
synced_close (gint fd) {
    gint ret = 0;
    ret = fsync (fd);
    if (close (fd) != 0)
        ret = 1;
    return ret;
}

gboolean __attribute__ ((visibility ("hidden")))
has_fs (blkid_probe probe, const gchar *device, const gchar *fs_type, GError **error) {
    gint status = 0;
    const gchar *value = NULL;
    size_t len = 0;

    status = blkid_do_safeprobe (probe);
    if (status != 0) {
        if (status < 0)
            g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                         "Failed to probe the device '%s'", device);
        return FALSE;
    }

    if (fs_type) {
        status = blkid_probe_lookup_value (probe, "TYPE", &value, &len);
        if (status != 0) {
            g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                         "Failed to get filesystem type for the device '%s'", device);
            return FALSE;
        }

        if (strncmp (value, fs_type, len-1) != 0) {
            return FALSE;
        }
    }

    blkid_reset_probe (probe);
    return TRUE;
}

gboolean __attribute__ ((visibility ("hidden")))
wipe_fs (const gchar *device, const gchar *fs_type, gboolean wipe_all, GError **error) {
    blkid_probe probe = NULL;
    gint fd = 0;
    gint status = 0;
    const gchar *value = NULL;
    size_t len = 0;
    guint64 progress_id = 0;
    gchar *msg = NULL;
    gboolean has_fs_type = TRUE;
    guint n_try = 0;

    msg = g_strdup_printf ("Started wiping '%s' signatures from the device '%s'", fs_type, device);
    progress_id = bd_utils_report_started (msg);
    g_free (msg);

    probe = blkid_new_probe ();
    if (!probe) {
        g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                     "Failed to create a probe for the device '%s'", device);
        bd_utils_report_finished (progress_id, (*error)->message);
        return FALSE;
    }

    fd = open (device, O_RDWR|O_CLOEXEC);
    if (fd == -1) {
        g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                     "Failed to create a probe for the device '%s'", device);
        blkid_free_probe (probe);
        bd_utils_report_finished (progress_id, (*error)->message);
        return FALSE;
    }

    for (n_try=5, status=-1; (status != 0) && (n_try > 0); n_try--) {
        status = blkid_probe_set_device (probe, fd, 0, 0);
        if (status != 0)
            g_usleep (100 * 1000); /* microseconds */
    }
    status = blkid_probe_set_device (probe, fd, 0, 0);
    if (status != 0) {
        g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                     "Failed to create a probe for the device '%s'", device);
        blkid_free_probe (probe);
        synced_close (fd);
        bd_utils_report_finished (progress_id, (*error)->message);
        return FALSE;
    }

    blkid_probe_enable_partitions(probe, 1);
    blkid_probe_set_partitions_flags(probe, BLKID_PARTS_MAGIC);
    blkid_probe_enable_superblocks(probe, 1);
    blkid_probe_set_superblocks_flags(probe, BLKID_SUBLKS_USAGE | BLKID_SUBLKS_TYPE |
                                             BLKID_SUBLKS_MAGIC | BLKID_SUBLKS_BADCSUM);

    for (n_try=5, status=-1; (status != 0) && (n_try > 0); n_try--) {
        status = blkid_do_probe (probe);
        if (status != 0)
            g_usleep (100 * 1000); /* microseconds */
    }
    if (status != 0) {
        g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                     "Failed to probe the device '%s'", device);
        blkid_free_probe (probe);
        synced_close (fd);
        bd_utils_report_finished (progress_id, (*error)->message);
        return FALSE;
    }

    status = blkid_probe_lookup_value (probe, "USAGE", &value, NULL);
    if (status != 0) {
        g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                     "Failed to get signature type for the device '%s'", device);
        blkid_free_probe (probe);
        synced_close (fd);
        bd_utils_report_finished (progress_id, (*error)->message);
        return FALSE;
    }

    if (strncmp (value, "filesystem", 10) != 0) {
        g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_INVAL,
                     "The signature on the device '%s' is of type '%s', not 'filesystem'", device, value);
        blkid_free_probe (probe);
        synced_close (fd);
        bd_utils_report_finished (progress_id, (*error)->message);
        return FALSE;
    }

    if (fs_type) {
        status = blkid_probe_lookup_value (probe, "TYPE", &value, &len);
        if (status != 0) {
            g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                         "Failed to get filesystem type for the device '%s'", device);
            blkid_free_probe (probe);
            synced_close (fd);
            bd_utils_report_finished (progress_id, (*error)->message);
            return FALSE;
        }

        if (strncmp (value, fs_type, len-1) != 0) {
            g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_INVAL,
                         "The file system type on the device '%s' is '%s', not '%s'", device, value, fs_type);
            blkid_free_probe (probe);
            synced_close (fd);
            bd_utils_report_finished (progress_id, (*error)->message);
            return FALSE;
        }
    }

    status = blkid_do_wipe (probe, FALSE);
    if (status != 0) {
        g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                     "Failed to wipe the filesystem signature on the device '%s'", device);
        blkid_free_probe (probe);
        synced_close (fd);
        bd_utils_report_finished (progress_id, (*error)->message);
        return FALSE;
    }

    blkid_reset_probe (probe);

    if (wipe_all) {
        has_fs_type = has_fs (probe, device, fs_type, error);

        while (has_fs_type) {
            status = blkid_do_probe (probe);
            if (status != 0) {
                g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                             "Failed to probe the device '%s'", device);
                blkid_free_probe (probe);
                synced_close (fd);
                bd_utils_report_finished (progress_id, (*error)->message);
                return FALSE;
            }

            status = blkid_do_wipe (probe, FALSE);
            if (status != 0) {
                g_set_error (error, BD_FS_ERROR, BD_FS_ERROR_FAIL,
                             "Failed to wipe the filesystem signature on the device '%s'", device);
                blkid_free_probe (probe);
                synced_close (fd);
                bd_utils_report_finished (progress_id, (*error)->message);
                return FALSE;
            }

            blkid_reset_probe (probe);
            has_fs_type = has_fs (probe, device, fs_type, error);

        }
    }

    blkid_free_probe (probe);
    synced_close (fd);

    bd_utils_report_finished (progress_id, "Completed");

    return TRUE;
}
