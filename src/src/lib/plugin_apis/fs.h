#include <glib.h>
#include <glib-object.h>
#include <blockdev/utils.h>


#ifndef BD_FS_API
#define BD_FS_API

GQuark  bd_fs_error_quark (void);


#define BD_FS_ERROR bd_fs_error_quark ()
typedef enum {
    BD_FS_ERROR_INVAL,
    BD_FS_ERROR_PARSE,
    BD_FS_ERROR_FAIL,
    BD_FS_ERROR_NOFS,
    BD_FS_ERROR_PIPE,
    BD_FS_ERROR_UNMOUNT_FAIL,
    BD_FS_ERROR_NOT_SUPPORTED,
    BD_FS_ERROR_NOT_MOUNTED,
    BD_FS_ERROR_AUTH,
} BDFsError;

#define BD_FS_TYPE_EXT2_INFO (bd_fs_ext2_info_get_type ())
GType  bd_fs_ext2_info_get_type ();

#define BD_FS_TYPE_EXT3_INFO (bd_fs_ext3_info_get_type ())
GType  bd_fs_ext3_info_get_type ();

#define BD_FS_TYPE_EXT4_INFO (bd_fs_ext4_info_get_type ())
GType  bd_fs_ext4_info_get_type ();


typedef struct BDFSExtInfo {
    gchar *label;
    gchar *uuid;
    gchar *state;
    guint64 block_size;
    guint64 block_count;
    guint64 free_blocks;
} BDFSExtInfo;

typedef struct BDFSExtInfo BDFSExt4Info;
typedef struct BDFSExtInfo BDFSExt3Info;
typedef struct BDFSExtInfo BDFSExt2Info;

/**
 * BDFSExtInfo:
 * @label: label of the filesystem
 * @uuid: uuid of the filesystem
 * @state: state of the filesystem (e.g. "clean")
 * @block_size: block size used by the filesystem
 * @block_count: number of blocks in the filesystem
 * @free_blocks: number of free blocks in the filesystem
 */
/**
 * bd_fs_ext2_info_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDFSExt2Info* bd_fs_ext2_info_copy (BDFSExt2Info *data);


/**
 * bd_fs_ext3_info_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDFSExt3Info* bd_fs_ext3_info_copy (BDFSExt3Info *data);


/**
 * bd_fs_ext4_info_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDFSExt4Info* bd_fs_ext4_info_copy (BDFSExt4Info *data);


/**
 * bd_fs_ext3_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_ext3_info_free (BDFSExt3Info *data);


/**
 * bd_fs_ext4_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_ext4_info_free (BDFSExt4Info *data);





#define BD_FS_TYPE_XFS_INFO (bd_fs_xfs_info_get_type ())
GType  bd_fs_xfs_info_get_type ();


typedef struct BDFSXfsInfo {
    gchar *label;
    gchar *uuid;
    guint64 block_size;
    guint64 block_count;
} BDFSXfsInfo;

/**
 * BDFSXfsInfo:
 * @label: label of the filesystem
 * @uuid: uuid of the filesystem
 * @block_size: block size used by the filesystem
 * @block_count: number of blocks in the filesystem
 */
/**
 * bd_fs_xfs_info_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDFSXfsInfo* bd_fs_xfs_info_copy (BDFSXfsInfo *data);


/**
 * bd_fs_xfs_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_xfs_info_free (BDFSXfsInfo *data);



#define BD_FS_TYPE_VFAT_INFO (bd_fs_vfat_info_get_type ())
GType  bd_fs_vfat_info_get_type ();


typedef struct BDFSVfatInfo {
    gchar *label;
    gchar *uuid;
    guint64 cluster_size;
    guint64 cluster_count;
    guint64 free_cluster_count;
} BDFSVfatInfo;

/**
 * BDFSVfatInfo:
 * @label: label of the filesystem
 * @uuid: uuid of the filesystem
 * @cluster_size: cluster size used by the filesystem
 * @cluster_count: number of clusters in the filesystem
 * @free_cluster_count: number of free clusters in the filesystem
 */
/**
 * bd_fs_vfat_info_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDFSVfatInfo* bd_fs_vfat_info_copy (BDFSVfatInfo *data);


/**
 * bd_fs_vfat_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_vfat_info_free (BDFSVfatInfo *data);



/**
 * bd_fs_wipe:
 * @device: the device to wipe signatures from
 * @all: whether to wipe all (%TRUE) signatures or just the first (%FALSE) one
 * @error: (out): place to store error (if any)
 *
 * Returns: whether signatures were successfully wiped on @device or not
 */
gboolean  bd_fs_wipe (const gchar *device, gboolean all, GError **error);


/**
 * bd_fs_clean:
 * @device: the device to clean
 * @error: (out): place to store error (if any)
 *
 * Clean all signatures from @device.
 * Difference between this and bd_fs_wipe() is that this function doesn't
 * return error if @device is already empty. This will also always remove
 * all signatures from @device, not only the first one.
 *
 * Returns: whether @device was successfully cleaned or not
 */
gboolean  bd_fs_clean (const gchar *device, GError **error);


/**
 * bd_fs_get_fstype:
 * @device: the device to probe
 * @error: (out): place to store error (if any)
 *
 * Get first signature on @device as a string.
 *
 * Returns: (transfer full): type of filesystem found on @device, %NULL in case
 *                           no signature has been detected or in case of error
 *                           (@error is set in this case)
 */
gchar* bd_fs_get_fstype (const gchar *device,  GError **error);


/**
 * bd_fs_unmount:
 * @spec: mount point or device to unmount
 * @lazy: enable/disable lazy unmount
 * @force: enable/disable force unmount
 * @extra: (allow-none) (array zero-terminated=1): extra options for the unmount
 *                                                 currently only 'run_as_uid'
 *                                                 and 'run_as_gid' are supported
 *                                                 value must be a valid non zero
 *                                                 uid (gid)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether @spec was successfully unmounted or not
 */
gboolean  bd_fs_unmount (const gchar *spec, gboolean lazy, gboolean force, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_mount:
 * @device: (allow-none): device to mount, if not specified @mountpoint entry
 *                        from fstab will be used
 * @mountpoint: (allow-none): mountpoint for @device, if not specified @device
 *                            entry from fstab will be used
 * @fstype: (allow-none): filesystem type
 * @options: (allow-none): comma delimited options for mount
 * @extra: (allow-none) (array zero-terminated=1): extra options for the unmount
 *                                                 currently only 'run_as_uid'
 *                                                 and 'run_as_gid' are supported
 *                                                 value must be a valid non zero
 *                                                 uid (gid)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether @device (or @mountpoint) was successfully mounted or not
 */
gboolean  bd_fs_mount (const gchar *device, const gchar *mountpoint, const gchar *fstype, const gchar *options, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_get_mountpoint:
 * @device: device to find mountpoint for
 * @error: (out): place to store error (if any)
 *
 * Get mountpoint for @device. If @device is mounted multiple times only
 * one mountpoint will be returned.
 *
 * Returns: (transfer full): mountpoint for @device, %NULL in case device is
 *                           not mounted or in case of an error (@error is set
 *                           in this case)
 */
gchar* bd_fs_get_mountpoint (const gchar *device, GError **error);


/**
 * bd_fs_resize:
 * @device: the device the file system of which to resize
 * @new_size: new requested size for the file system (if 0, the file system is
 *            adapted to the underlying block device)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system on @device was successfully resized or not
 */
gboolean  bd_fs_resize (const gchar *device, guint64 new_size, GError **error);


 /**
 * bd_fs_repair:
 * @device: the device the file system of which to repair
 * @error: (out): place to store error (if any)
 *
 * Repair filesystem on @device. This calls other fs repair functions from this
 * plugin based on detected filesystem (e.g. bd_fs_xfs_repair for XFS). This
 * function will return an error for unknown/unsupported filesystems.
 *
 * Returns: whether the file system on @device was successfully repaired or not
 */
gboolean  bd_fs_repair (const gchar *device, GError **error);


/**
 * bd_fs_check:
 * @device: the device the file system of which to check
 * @error: (out): place to store error (if any)
 *
 * Check filesystem on @device. This calls other fs check functions from this
 * plugin based on detected filesystem (e.g. bd_fs_xfs_check for XFS). This
 * function will return an error for unknown/unsupported filesystems.
 *
 * Returns: whether the file system on @device passed the consistency check or not
 */
gboolean  bd_fs_check (const gchar *device, GError **error);


/**
 * bd_fs_set_label:
 * @device: the device with file system to set the label for
 * @error: (out): place to store error (if any)
 *
 * Set label for filesystem on @device. This calls other fs label functions from this
 * plugin based on detected filesystem (e.g. bd_fs_xfs_set_label for XFS). This
 * function will return an error for unknown/unsupported filesystems.
 *
 * Returns: whether the file system on @device was successfully relabled or not
 */
gboolean  bd_fs_set_label (const gchar *device, const gchar *label, GError **error);


typedef enum {
    BD_FS_OFFLINE_SHRINK = 1 << 1,
    BD_FS_OFFLINE_GROW = 1 << 2,
    BD_FS_ONLINE_SHRINK = 1 << 3,
    BD_FS_ONLINE_GROW = 1 << 4
} BDFsResizeFlags;

/**
 * BDFsResizeFlags:
 * Flags indicating whether a filesystem resize action supports growing and/or
 * shrinking if mounted or unmounted.
 */
/**
 * bd_fs_can_resize:
 * @type: the filesystem type to be tested for installed resize support
 * @mode: (out): flags for allowed resizing (i.e. growing/shrinking support for online/offline)
 * @required_utility: (out) (transfer full): the utility binary which is required for resizing (if missing i.e. returns FALSE but no error)
 * @error: (out): place to store error (if any)
 *
 * Searches for the required utility to resize the given filesystem and returns whether
 * it is installed. The mode flags indicate if growing and/or shrinking resize is available if
 * mounted/unmounted.
 * Unknown filesystems or filesystems which do not support resizing result in errors.
 *
 * Returns: whether filesystem resize is available
 */
gboolean  bd_fs_can_resize (const gchar *type, BDFsResizeFlags *mode, gchar **required_utility, GError **error);


/**
 * bd_fs_can_check:
 * @type: the filesystem type to be tested for installed consistency check support
 * @required_utility: (out) (transfer full): the utility binary which is required for checking (if missing i.e. returns FALSE but no error)
 * @error: (out): place to store error (if any)
 *
 * Searches for the required utility to check the given filesystem and returns whether
 * it is installed.
 * Unknown filesystems or filesystems which do not support checking result in errors.
 *
 * Returns: whether filesystem check is available
 */
gboolean  bd_fs_can_check (const gchar *type, gchar **required_utility, GError **error);


/**
 * bd_fs_can_repair:
 * @type: the filesystem type to be tested for installed repair support
 * @required_utility: (out) (transfer full): the utility binary which is required for repairing (if missing i.e. return FALSE but no error)
 * @error: (out): place to store error (if any)
 *
 * Searches for the required utility to repair the given filesystem and returns whether
 * it is installed.
 * Unknown filesystems or filesystems which do not support reparing result in errors.
 *
 * Returns: whether filesystem repair is available
 */
gboolean  bd_fs_can_repair (const gchar *type, gchar **required_utility, GError **error);


/**
 * bd_fs_can_set_label:
 * @type: the filesystem type to be tested for installed label support
 * @required_utility: (out) (transfer full): the utility binary which is required for relabeling (if missing i.e. return FALSE but no error)
 * @error: (out): place to store error (if any)
 *
 * Searches for the required utility to set the label of the given filesystem and returns whether
 * it is installed.
 * Unknown filesystems or filesystems which do not support setting the label result in errors.
 *
 * Returns: whether setting filesystem label is available
 */
gboolean  bd_fs_can_set_label (const gchar *type, gchar **required_utility, GError **error);


/**
 * bd_fs_ext2_mkfs:
 * @device: the device to create a new ext2 fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mke2fs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new ext2 fs was successfully created on @device or not
 */
gboolean  bd_fs_ext2_mkfs (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext3_mkfs:
 * @device: the device to create a new ext3 fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mke2fs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new ext3 fs was successfully created on @device or not
 */
gboolean  bd_fs_ext3_mkfs (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext4_mkfs:
 * @device: the device to create a new ext4 fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkfs.ext4' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new ext4 fs was successfully created on @device or not
 */
gboolean  bd_fs_ext4_mkfs (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext2_wipe:
 * @device: the device to wipe an ext2 signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext2 signature was successfully wiped from the @device or
 *          not
 */
gboolean  bd_fs_ext2_wipe (const gchar *device, GError **error);


/**
 * bd_fs_ext3_wipe:
 * @device: the device to wipe an ext3 signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext3 signature was successfully wiped from the @device or
 *          not
 */
gboolean  bd_fs_ext3_wipe (const gchar *device, GError **error);


/**
 * bd_fs_ext4_wipe:
 * @device: the device to wipe an ext4 signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext4 signature was successfully wiped from the @device or
 *          not
 */
gboolean  bd_fs_ext4_wipe (const gchar *device, GError **error);


/**
 * bd_fs_ext2_check:
 * @device: the device the file system on which to check
 * @extra: (allow-none) (array zero-terminated=1): extra options for the check (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext2 file system on the @device is clean or not
 */
gboolean  bd_fs_ext2_check (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext3_check:
 * @device: the device the file system on which to check
 * @extra: (allow-none) (array zero-terminated=1): extra options for the check (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext3 file system on the @device is clean or not
 */
gboolean  bd_fs_ext3_check (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext4_check:
 * @device: the device the file system on which to check
 * @extra: (allow-none) (array zero-terminated=1): extra options for the check (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext4 file system on the @device is clean or not
 */
gboolean  bd_fs_ext4_check (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext2_repair:
 * @device: the device the file system on which to repair
 * @unsafe: whether to do unsafe operations too
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext2 file system on the @device was successfully repaired
 *          (if needed) or not (error is set in that case)
 */
gboolean  bd_fs_ext2_repair (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext3_repair:
 * @device: the device the file system on which to repair
 * @unsafe: whether to do unsafe operations too
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext3 file system on the @device was successfully repaired
 *          (if needed) or not (error is set in that case)
 */
gboolean  bd_fs_ext3_repair (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext4_repair:
 * @device: the device the file system on which to repair
 * @unsafe: whether to do unsafe operations too
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext4 file system on the @device was successfully repaired
 *          (if needed) or not (error is set in that case)
 */
gboolean  bd_fs_ext4_repair (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext2_set_label:
 * @device: the device the file system on which to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of ext2 file system on the @device was
 *          successfully set or not
 */
gboolean  bd_fs_ext2_set_label (const gchar *device, const gchar *label, GError **error);


/**
 * bd_fs_ext3_set_label:
 * @device: the device the file system on which to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of ext3 file system on the @device was
 *          successfully set or not
 */
gboolean  bd_fs_ext3_set_label (const gchar *device, const gchar *label, GError **error);


/**
 * bd_fs_ext4_set_label:
 * @device: the device the file system on which to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of ext4 file system on the @device was
 *          successfully set or not
 */
gboolean  bd_fs_ext4_set_label (const gchar *device, const gchar *label, GError **error);


/**
 * bd_fs_ext2_get_info:
 * @device: the device the file system of which to get info for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 */
BDFSExt2Info* bd_fs_ext2_get_info (const gchar *device, GError **error);


/**
 * bd_fs_ext3_get_info:
 * @device: the device the file system of which to get info for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 */
BDFSExt3Info* bd_fs_ext3_get_info (const gchar *device, GError **error);


/**
 * bd_fs_ext4_get_info:
 * @device: the device the file system of which to get info for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 */
BDFSExt4Info* bd_fs_ext4_get_info (const gchar *device, GError **error);


/**
 * bd_fs_ext2_resize:
 * @device: the device the file system of which to resize
 * @new_size: new requested size for the file system (if 0, the file system is
 *            adapted to the underlying block device)
 * @extra: (allow-none) (array zero-terminated=1): extra options for the resize (right now
 *                                                 passed to the 'resize2fs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system on @device was successfully resized or not
 */
gboolean  bd_fs_ext2_resize (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext3_resize:
 * @device: the device the file system of which to resize
 * @new_size: new requested size for the file system (if 0, the file system is
 *            adapted to the underlying block device)
 * @extra: (allow-none) (array zero-terminated=1): extra options for the resize (right now
 *                                                 passed to the 'resize2fs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system on @device was successfully resized or not
 */
gboolean  bd_fs_ext3_resize (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_ext4_resize:
 * @device: the device the file system of which to resize
 * @new_size: new requested size for the file system (if 0, the file system is
 *            adapted to the underlying block device)
 * @extra: (allow-none) (array zero-terminated=1): extra options for the resize (right now
 *                                                 passed to the 'resize2fs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system on @device was successfully resized or not
 */
gboolean  bd_fs_ext4_resize (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_xfs_mkfs:
 * @device: the device to create a new xfs fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkfs.xfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new xfs fs was successfully created on @device or not
 */
gboolean  bd_fs_xfs_mkfs (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_xfs_wipe:
 * @device: the device to wipe an xfs signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an xfs signature was successfully wiped from the @device or
 *          not
 */
gboolean  bd_fs_xfs_wipe (const gchar *device, GError **error);


/**
 * bd_fs_xfs_check:
 * @device: the device containing the file system to check
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an xfs file system on the @device is clean or not
 *
 * Note: if the file system is mounted it may be reported as unclean even if
 *       everything is okay and there are just some pending/in-progress writes
 */
gboolean  bd_fs_xfs_check (const gchar *device, GError **error);


/**
 * bd_fs_xfs_repair:
 * @device: the device containing the file system to repair
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'xfs_repair' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an xfs file system on the @device was successfully repaired
 *          (if needed) or not (error is set in that case)
 */
gboolean  bd_fs_xfs_repair (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_xfs_set_label:
 * @device: the device containing the file system to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of xfs file system on the @device was
 *          successfully set or not
 */
gboolean  bd_fs_xfs_set_label (const gchar *device, const gchar *label, GError **error);


/**
 * bd_fs_xfs_get_info:
 * @device: the device containing the file system to get info for (device must
            be mounted, trying to get info for an unmounted device will result
            in an error)
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 */
BDFSXfsInfo* bd_fs_xfs_get_info (const gchar *device, GError **error);


/**
 * bd_fs_xfs_resize:
 * @mpoint: the mount point of the file system to resize
 * @new_size: new requested size for the file system *in file system blocks* (see bd_fs_xfs_get_info())
 *            (if 0, the file system is adapted to the underlying block device)
 * @extra: (allow-none) (array zero-terminated=1): extra options for the resize (right now
 *                                                 passed to the 'xfs_growfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system mounted on @mpoint was successfully resized or not
 */
gboolean  bd_fs_xfs_resize (const gchar *mpoint, guint64 new_size, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_vfat_mkfs:
 * @device: the device to create a new vfat fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkfs.vfat' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new vfat fs was successfully created on @device or not
 */
gboolean  bd_fs_vfat_mkfs (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_vfat_wipe:
 * @device: the device to wipe an vfat signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an vfat signature was successfully wiped from the @device or
 *          not
 */
gboolean  bd_fs_vfat_wipe (const gchar *device, GError **error);


/**
 * bd_fs_vfat_check:
 * @device: the device containing the file system to check
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'fsck.vfat' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an vfat file system on the @device is clean or not
 */
gboolean  bd_fs_vfat_check (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_vfat_repair:
 * @device: the device containing the file system to repair
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'fsck.vfat' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an vfat file system on the @device was successfully repaired
 *          (if needed) or not (error is set in that case)
 */
gboolean  bd_fs_vfat_repair (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_fs_vfat_set_label:
 * @device: the device containing the file system to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of vfat file system on the @device was
 *          successfully set or not
 */
gboolean  bd_fs_vfat_set_label (const gchar *device, const gchar *label, GError **error);


/**
 * bd_fs_vfat_get_info:
 * @device: the device containing the file system to get info for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 */
BDFSVfatInfo* bd_fs_vfat_get_info (const gchar *device, GError **error);


/**
 * bd_fs_vfat_resize:
 * @device: the device the file system of which to resize
 * @new_size: new requested size for the file system (if 0, the file system is
 *            adapted to the underlying block device)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system on @device was successfully resized or not
 */
gboolean  bd_fs_vfat_resize (const gchar *device, guint64 new_size, GError **error);


#endif  /* BD_FS_API */
