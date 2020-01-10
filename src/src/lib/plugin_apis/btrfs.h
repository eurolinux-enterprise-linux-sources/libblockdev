#include <glib.h>
#include <glib-object.h>
#include <blockdev/utils.h>


#define BD_BTRFS_MAIN_VOLUME_ID 5
#define BD_BTRFS_MIN_MEMBER_SIZE (128 * 1048576ULL)

GQuark  bd_btrfs_error_quark (void);


#define BD_BTRFS_ERROR bd_btrfs_error_quark ()
typedef enum {
    BD_BTRFS_ERROR_DEVICE,
    BD_BTRFS_ERROR_PARSE,
    BD_BTRFS_ERROR_TECH_UNAVAIL,
} BDBtrfsError;

#define BD_BTRFS_TYPE_DEVICE_INFO (bd_btrfs_device_info_get_type ())
GType  bd_btrfs_device_info_get_type ();


typedef struct BDBtrfsDeviceInfo {
    guint64 id;
    gchar *path;
    guint64 size;
    guint64 used;
} BDBtrfsDeviceInfo;

/**
 * BDBtrfsDeviceInfo:
 * @id: ID of the device
 * @path: path of the device
 * @size: size of the device
 * @used: size of the used space
 */
/**
 * bd_btrfs_device_info_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDBtrfsDeviceInfo* bd_btrfs_device_info_copy (BDBtrfsDeviceInfo *info);


/**
 * bd_btrfs_device_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_btrfs_device_info_free (BDBtrfsDeviceInfo *info);




#define BD_BTRFS_TYPE_SUBVOLUME_INFO (bd_btrfs_subvolume_info_get_type ())
GType  bd_btrfs_subvolume_info_get_type ();


typedef struct BDBtrfsSubvolumeInfo {
    guint64 id;
    guint64 parent_id;
    gchar *path;
} BDBtrfsSubvolumeInfo;

/**
 * BDBtrfsSubvolumeInfo:
 * @id: ID of the subvolume
 * @parent_id: ID of the parent (sub)volume
 * @path: path of the subvolume
 */
/**
 * bd_btrfs_subvolume_info_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDBtrfsSubvolumeInfo* bd_btrfs_subvolume_info_copy (BDBtrfsSubvolumeInfo *info);


/**
 * bd_btrfs_subvolume_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_btrfs_subvolume_info_free (BDBtrfsSubvolumeInfo *info);




#define BD_BTRFS_TYPE_FILESYSTEM_INFO (bd_btrfs_filesystem_info_get_type ())
GType  bd_btrfs_filesystem_info_get_type ();


typedef struct BDBtrfsFilesystemInfo {
    gchar *label;
    gchar *uuid;
    guint64 num_devices;
    guint64 used;
} BDBtrfsFilesystemInfo;

/**
 * BDBtrfsFilesystemInfo:
 * @label: label of the filesystem
 * @uuid: uuid of the filesystem
 * @num_devices: number of device in the filesystem
 * @used: size of the used space
 */
/**
 * bd_btrfs_filesystem_info_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDBtrfsFilesystemInfo* bd_btrfs_filesystem_info_copy (BDBtrfsFilesystemInfo *info);


/**
 * bd_btrfs_filesystem_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_btrfs_filesystem_info_free (BDBtrfsFilesystemInfo *info);



typedef enum {
    BD_BTRFS_TECH_FS = 0,
    BD_BTRFS_TECH_MULTI_DEV,
    BD_BTRFS_TECH_SUBVOL,
    BD_BTRFS_TECH_SNAPSHOT,
} BDBtrfsTech;

typedef enum {
    BD_BTRFS_TECH_MODE_CREATE = 1 << 0,
    BD_BTRFS_TECH_MODE_DELETE = 1 << 1,
    BD_BTRFS_TECH_MODE_MODIFY = 1 << 2,
    BD_BTRFS_TECH_MODE_QUERY  = 1 << 3,
} BDBtrfsTechMode;

/**
 * bd_btrfs_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDBtrfsTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is avaible -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_btrfs_is_tech_avail (BDBtrfsTech tech, guint64 mode, GError **error);



/**
 * bd_btrfs_create_volume:
 * @devices: (array zero-terminated=1): list of devices to create btrfs volume from
 * @label: (allow-none): label for the volume
 * @data_level: (allow-none): RAID level for the data or %NULL to use the default
 * @md_level: (allow-none): RAID level for the metadata or %NULL to use the default
 * @extra: (allow-none) (array zero-terminated=1): extra options for the volume creation (right now
 *                                                 passed to the 'mkfs.btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the new btrfs volume was created from @devices or not
 *
 * See mkfs.btrfs(8) for details about @data_level, @md_level and btrfs in general.
 *
 * Tech category: %BD_BTRFS_TECH_MULTI_DEV-%BD_BTRFS_TECH_MODE_CREATE
 */
gboolean  bd_btrfs_create_volume (const gchar **devices, const gchar *label, const gchar *data_level, const gchar *md_level, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_add_device:
 * @mountpoint: mountpoint of the btrfs volume to add new device to
 * @device: a device to add to the btrfs volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the addition (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully added to the @mountpoint btrfs volume or not
 *
 * Tech category: %BD_BTRFS_TECH_MULTI_DEV-%BD_BTRFS_TECH_MODE_MODIFY
 */
gboolean  bd_btrfs_add_device (const gchar *mountpoint, const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_remove_device:
 * @mountpoint: mountpoint of the btrfs volume to remove device from
 * @device: a device to remove from the btrfs volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the removal (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully removed from the @mountpoint btrfs volume or not
 *
 * Tech category: %BD_BTRFS_TECH_MULTI_DEV-%BD_BTRFS_TECH_MODE_MODIFY
 */
gboolean  bd_btrfs_remove_device (const gchar *mountpoint, const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_create_subvolume:
 * @mountpoint: mountpoint of the btrfs volume to create subvolume under
 * @name: name of the subvolume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the subvolume creation (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @mountpoint/@name subvolume was successfully created or not
 *
 * Tech category: %BD_BTRFS_TECH_SUBVOL-%BD_BTRFS_TECH_MODE_CREATE
 */
gboolean  bd_btrfs_create_subvolume (const gchar *mountpoint, const gchar *name, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_delete_subvolume:
 * @mountpoint: mountpoint of the btrfs volume to delete subvolume from
 * @name: name of the subvolume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the subvolume deletion (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @mountpoint/@name subvolume was successfully deleted or not
 *
 * Tech category: %BD_BTRFS_TECH_SUBVOL-%BD_BTRFS_TECH_MODE_DELETE
 */
gboolean  bd_btrfs_delete_subvolume (const gchar *mountpoint, const gchar *name, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_get_default_subvolume_id:
 * @mountpoint: mountpoint of the volume to get the default subvolume ID of
 * @error: (out): place to store error (if any)
 *
 * Returns: ID of the @mountpoint volume's default subvolume. If 0,
 * @error) may be set to indicate error
 *
 * Tech category: %BD_BTRFS_TECH_SUBVOL-%BD_BTRFS_TECH_MODE_QUERY
 */
guint64  bd_btrfs_get_default_subvolume_id (const gchar *mountpoint, GError **error);


/**
 * bd_btrfs_set_default_subvolume:
 * @mountpoint: mountpoint of the volume to set the default subvolume ID of
 * @subvol_id: ID of the subvolume to be set as the default subvolume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the setting (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @mountpoint volume's default subvolume was correctly set
 * to @subvol_id or not
 *
 * Tech category: %BD_BTRFS_TECH_SUBVOL-%BD_BTRFS_TECH_MODE_MODIFY
 */
gboolean  bd_btrfs_set_default_subvolume (const gchar *mountpoint, guint64 subvol_id, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_create_snapshot:
 * @source: path to source subvolume
 * @dest: path to new snapshot volume
 * @ro: whether the snapshot should be read-only
 * @extra: (allow-none) (array zero-terminated=1): extra options for the snapshot creation (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @dest snapshot of @source was successfully created or not
 *
 * Tech category: %BD_BTRFS_TECH_SNAPSHOT-%BD_BTRFS_TECH_MODE_CREATE
 */
gboolean  bd_btrfs_create_snapshot (const gchar *source, const gchar *dest, gboolean ro, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_list_devices:
 * @device: a device that is part of the queried btrfs volume
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about the devices that are part of the btrfs volume
 * containing @device or %NULL in case of error
 *
 * Tech category: %BD_BTRFS_TECH_MULTI_DEV-%BD_BTRFS_TECH_MODE_QUERY
 */
BDBtrfsDeviceInfo** bd_btrfs_list_devices (const gchar *device, GError **error);


/**
 * bd_btrfs_list_subvolumes:
 * @mountpoint: a mountpoint of the queried btrfs volume
 * @snapshots_only: whether to list only snapshot subvolumes or not
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about the subvolumes that are part of the btrfs volume
 * mounted at @mountpoint or %NULL in case of error
 *
 * The subvolumes are sorted in a way that no child subvolume appears in the
 * list before its parent (sub)volume.
 *
 * Tech category: %BD_BTRFS_TECH_SUBVOL-%BD_BTRFS_TECH_MODE_QUERY
 */
BDBtrfsSubvolumeInfo** bd_btrfs_list_subvolumes (const gchar *mountpoint, gboolean snapshots_only, GError **error);


/**
 * bd_btrfs_filesystem_info:
 * @device: a device that is part of the queried btrfs volume
 * @error: (out): place to store error (if any)
 *
 * Returns: information about the @device's volume's filesystem or %NULL in case of error
 *
 * Tech category: %BD_BTRFS_TECH_FS-%BD_BTRFS_TECH_MODE_QUERY
 */
BDBtrfsFilesystemInfo* bd_btrfs_filesystem_info (const gchar *device, GError **error);


/**
 * bd_btrfs_mkfs:
 * @devices: (array zero-terminated=1): list of devices to create btrfs volume from
 * @label: (allow-none): label for the volume
 * @data_level: (allow-none): RAID level for the data or %NULL to use the default
 * @md_level: (allow-none): RAID level for the metadata or %NULL to use the default
 * @extra: (allow-none) (array zero-terminated=1): extra options for the volume creation (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the new btrfs volume was created from @devices or not
 *
 * See mkfs.btrfs(8) for details about @data_level, @md_level and btrfs in general.
 *
 * Tech category: %BD_BTRFS_TECH_FS-%BD_BTRFS_TECH_MODE_CREATE
 */
gboolean  bd_btrfs_mkfs (const gchar **devices, const gchar *label, const gchar *data_level, const gchar *md_level, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_resize:
 * @mountpoint: a mountpoint of the to be resized btrfs filesystem
 * @size: requested new size
 * @extra: (allow-none) (array zero-terminated=1): extra options for the volume resize (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @mountpoint filesystem was successfully resized to @size
 * or not
 *
 * Tech category: %BD_BTRFS_TECH_FS-%BD_BTRFS_TECH_MODE_MODIFY
 */
gboolean  bd_btrfs_resize (const gchar *mountpoint, guint64 size, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_check:
 * @device: a device that is part of the checked btrfs volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the check (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the filesystem was successfully checked or not
 *
 * Tech category: %BD_BTRFS_TECH_FS-%BD_BTRFS_TECH_MODE_QUERY
 */
gboolean  bd_btrfs_check (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_repair:
 * @device: a device that is part of the to be repaired btrfs volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the filesystem was successfully checked and repaired or not
 *
 * Tech category: %BD_BTRFS_TECH_FS-%BD_BTRFS_TECH_MODE_MODIFY
 */
gboolean  bd_btrfs_repair (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_btrfs_change_label:
 * @mountpoint: a mountpoint of the btrfs filesystem to change label of
 * @label: new label for the filesystem
 * @extra: (allow-none) (array zero-terminated=1): extra options for the volume creation (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of the @mountpoint filesystem was successfully set
 * to @label or not
 *
 * Tech category: %BD_BTRFS_TECH_FS-%BD_BTRFS_TECH_MODE_MODIFY
 */
gboolean  bd_btrfs_change_label (const gchar *mountpoint, const gchar *label, const BDExtraArg **extra, GError **error);

