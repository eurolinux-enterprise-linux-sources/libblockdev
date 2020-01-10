GQuark  bd_fs_error_quark (void) {
        return g_quark_from_static_string ("g-bd-fs-error-quark");
}

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
BDFSExt2Info* bd_fs_ext2_info_copy (BDFSExt2Info *data) {
        BDFSExt2Info *ret = g_new0 (BDFSExt2Info, 1);

    ret->label = g_strdup (data->label);
    ret->uuid = g_strdup (data->uuid);
    ret->state = g_strdup (data->state);
    ret->block_size = data->block_size;
    ret->block_count = data->block_count;
    ret->free_blocks = data->free_blocks;

    return ret;
}

/**
 * bd_fs_ext3_info_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDFSExt3Info* bd_fs_ext3_info_copy (BDFSExt3Info *data) {
        return (BDFSExt3Info*) bd_fs_ext2_info_copy (data);
}

/**
 * bd_fs_ext4_info_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDFSExt4Info* bd_fs_ext4_info_copy (BDFSExt4Info *data) {
        return (BDFSExt4Info*) bd_fs_ext2_info_copy (data);
};

/**
 * bd_fs_ext2_info_free: (skip)
 *
 * Frees @data.
 */
void bd_fs_ext2_info_free (BDFSExt2Info *data) {
    g_free (data->label);
    g_free (data->uuid);
    g_free (data->state);
    g_free (data);
}

/**
 * bd_fs_ext3_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_ext3_info_free (BDFSExt3Info *data) {
        bd_fs_ext2_info_free ((BDFSExt2Info*) data);
}

/**
 * bd_fs_ext4_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_ext4_info_free (BDFSExt4Info *data) {
        bd_fs_ext2_info_free ((BDFSExt2Info*) data);
}

GType  bd_fs_ext2_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDFSExt2Info",
                                            (GBoxedCopyFunc) bd_fs_ext2_info_copy,
                                            (GBoxedFreeFunc) bd_fs_ext2_info_free);
    }

    return type;
}

GType  bd_fs_ext3_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDFSExt3Info",
                                            (GBoxedCopyFunc) bd_fs_ext3_info_copy,
                                            (GBoxedFreeFunc) bd_fs_ext3_info_free);
    }

    return type;
}

GType  bd_fs_ext4_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDFSExt4Info",
                                            (GBoxedCopyFunc) bd_fs_ext4_info_copy,
                                            (GBoxedFreeFunc) bd_fs_ext4_info_free);
    }

    return type;
}

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
BDFSXfsInfo* bd_fs_xfs_info_copy (BDFSXfsInfo *data) {
        BDFSXfsInfo *ret = g_new0 (BDFSXfsInfo, 1);

    ret->label = g_strdup (data->label);
    ret->uuid = g_strdup (data->uuid);
    ret->block_size = data->block_size;
    ret->block_count = data->block_count;

    return ret;
}

/**
 * bd_fs_xfs_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_xfs_info_free (BDFSXfsInfo *data) {
        g_free (data->label);
    g_free (data->uuid);
    g_free (data);
}

GType  bd_fs_xfs_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDFSXfsInfo",
                                            (GBoxedCopyFunc) bd_fs_xfs_info_copy,
                                            (GBoxedFreeFunc) bd_fs_xfs_info_free);
    }

    return type;
}

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
BDFSVfatInfo* bd_fs_vfat_info_copy (BDFSVfatInfo *data) {
        BDFSVfatInfo *ret = g_new0 (BDFSVfatInfo, 1);

    ret->label = g_strdup (data->label);
    ret->uuid = g_strdup (data->uuid);
    ret->cluster_size = data->cluster_size;
    ret->cluster_count = data->cluster_count;

    return ret;
}

/**
 * bd_fs_vfat_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_vfat_info_free (BDFSVfatInfo *data) {
        g_free (data->label);
    g_free (data->uuid);
    g_free (data);
}

GType  bd_fs_vfat_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDFSVfatInfo",
                                            (GBoxedCopyFunc) bd_fs_vfat_info_copy,
                                            (GBoxedFreeFunc) bd_fs_vfat_info_free);
    }

    return type;
}

/**
 * BDFSNtfsInfo:
 * @size: size of the filesystem in bytes
 * @free_space: number of free space in the filesystem in bytes
 */
/**
 * bd_fs_ntfs_info_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDFSNtfsInfo* bd_fs_ntfs_info_copy (BDFSNtfsInfo *data) {
        BDFSNtfsInfo *ret = g_new0 (BDFSNtfsInfo, 1);

    ret->size = data->size;
    ret->free_space = data->free_space;

    return ret;
}

/**
 * bd_fs_ntfs_info_free: (skip)
 *
 * Frees @data.
 */
void  bd_fs_ntfs_info_free (BDFSNtfsInfo *data) {
        g_free (data);
}

GType  bd_fs_ntfs_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDFSNtfsInfo",
                                            (GBoxedCopyFunc) bd_fs_ntfs_info_copy,
                                            (GBoxedFreeFunc) bd_fs_ntfs_info_free);
    }

    return type;
}

static const gchar* const fs_functions[] = {
    "bd_fs_is_tech_avail",
    "bd_fs_wipe",
    "bd_fs_clean",
    "bd_fs_get_fstype",
    "bd_fs_unmount",
    "bd_fs_mount",
    "bd_fs_get_mountpoint",
    "bd_fs_resize",
    "bd_fs_repair",
    "bd_fs_check",
    "bd_fs_set_label",
    "bd_fs_can_resize",
    "bd_fs_can_check",
    "bd_fs_can_repair",
    "bd_fs_can_set_label",
    "bd_fs_ext2_mkfs",
    "bd_fs_ext3_mkfs",
    "bd_fs_ext4_mkfs",
    "bd_fs_ext2_wipe",
    "bd_fs_ext3_wipe",
    "bd_fs_ext4_wipe",
    "bd_fs_ext2_check",
    "bd_fs_ext3_check",
    "bd_fs_ext4_check",
    "bd_fs_ext2_repair",
    "bd_fs_ext3_repair",
    "bd_fs_ext4_repair",
    "bd_fs_ext2_set_label",
    "bd_fs_ext3_set_label",
    "bd_fs_ext4_set_label",
    "bd_fs_ext2_get_info",
    "bd_fs_ext3_get_info",
    "bd_fs_ext4_get_info",
    "bd_fs_ext2_resize",
    "bd_fs_ext3_resize",
    "bd_fs_ext4_resize",
    "bd_fs_xfs_mkfs",
    "bd_fs_xfs_wipe",
    "bd_fs_xfs_check",
    "bd_fs_xfs_repair",
    "bd_fs_xfs_set_label",
    "bd_fs_xfs_get_info",
    "bd_fs_xfs_resize",
    "bd_fs_vfat_mkfs",
    "bd_fs_vfat_wipe",
    "bd_fs_vfat_check",
    "bd_fs_vfat_repair",
    "bd_fs_vfat_set_label",
    "bd_fs_vfat_get_info",
    "bd_fs_vfat_resize",
    "bd_fs_ntfs_mkfs",
    "bd_fs_ntfs_wipe",
    "bd_fs_ntfs_check",
    "bd_fs_ntfs_repair",
    "bd_fs_ntfs_set_label",
    "bd_fs_ntfs_resize",
    "bd_fs_ntfs_get_info",
    NULL};

const gchar* const* get_fs_functions (void) {
    return fs_functions;
}

static const guint8 fs_num_functions = 57;

guint8 get_fs_num_functions (void) {
    return fs_num_functions;
}

gboolean  bd_fs_is_tech_avail_stub (BDFSTech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_fs_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_is_tech_avail) (BDFSTech tech, guint64 mode, GError **error) = bd_fs_is_tech_avail_stub;

/**
 * bd_fs_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDFSTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_fs_is_tech_avail (BDFSTech tech, guint64 mode, GError **error) {
    return _bd_fs_is_tech_avail (tech, mode, error);
}


gboolean  bd_fs_wipe_stub (const gchar *device, gboolean all, GError **error) {
    g_critical ("The function 'bd_fs_wipe' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_wipe' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_wipe) (const gchar *device, gboolean all, GError **error) = bd_fs_wipe_stub;

/**
 * bd_fs_wipe:
 * @device: the device to wipe signatures from
 * @all: whether to wipe all (%TRUE) signatures or just the first (%FALSE) one
 * @error: (out): place to store error (if any)
 *
 * Returns: whether signatures were successfully wiped on @device or not
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_WIPE
 */
gboolean  bd_fs_wipe (const gchar *device, gboolean all, GError **error) {
    return _bd_fs_wipe (device, all, error);
}


gboolean  bd_fs_clean_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_clean' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_clean' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_clean) (const gchar *device, GError **error) = bd_fs_clean_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_WIPE
 */
gboolean  bd_fs_clean (const gchar *device, GError **error) {
    return _bd_fs_clean (device, error);
}


gchar* bd_fs_get_fstype_stub (const gchar *device,  GError **error) {
    g_critical ("The function 'bd_fs_get_fstype' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_get_fstype' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_fs_get_fstype) (const gchar *device,  GError **error) = bd_fs_get_fstype_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_QUERY
 */
gchar* bd_fs_get_fstype (const gchar *device,  GError **error) {
    return _bd_fs_get_fstype (device, error);
}


gboolean  bd_fs_unmount_stub (const gchar *spec, gboolean lazy, gboolean force, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_unmount' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_unmount' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_unmount) (const gchar *spec, gboolean lazy, gboolean force, const BDExtraArg **extra, GError **error) = bd_fs_unmount_stub;

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
 *
 * Tech category: %BD_FS_TECH_MOUNT (no mode, ignored)
 */
gboolean  bd_fs_unmount (const gchar *spec, gboolean lazy, gboolean force, const BDExtraArg **extra, GError **error) {
    return _bd_fs_unmount (spec, lazy, force, extra, error);
}


gboolean  bd_fs_mount_stub (const gchar *device, const gchar *mountpoint, const gchar *fstype, const gchar *options, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_mount' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_mount' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_mount) (const gchar *device, const gchar *mountpoint, const gchar *fstype, const gchar *options, const BDExtraArg **extra, GError **error) = bd_fs_mount_stub;

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
 *
 * Tech category: %BD_FS_TECH_MOUNT (no mode, ignored)
 */
gboolean  bd_fs_mount (const gchar *device, const gchar *mountpoint, const gchar *fstype, const gchar *options, const BDExtraArg **extra, GError **error) {
    return _bd_fs_mount (device, mountpoint, fstype, options, extra, error);
}


gchar* bd_fs_get_mountpoint_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_get_mountpoint' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_get_mountpoint' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_fs_get_mountpoint) (const gchar *device, GError **error) = bd_fs_get_mountpoint_stub;

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
 *
 * Tech category: %BD_FS_TECH_MOUNT (no mode, ignored)
 */
gchar* bd_fs_get_mountpoint (const gchar *device, GError **error) {
    return _bd_fs_get_mountpoint (device, error);
}


gboolean  bd_fs_resize_stub (const gchar *device, guint64 new_size, GError **error) {
    g_critical ("The function 'bd_fs_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_resize) (const gchar *device, guint64 new_size, GError **error) = bd_fs_resize_stub;

/**
 * bd_fs_resize:
 * @device: the device the file system of which to resize
 * @new_size: new requested size for the file system (if 0, the file system is
 *            adapted to the underlying block device)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system on @device was successfully resized or not
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_RESIZE
 */
gboolean  bd_fs_resize (const gchar *device, guint64 new_size, GError **error) {
    return _bd_fs_resize (device, new_size, error);
}


gboolean  bd_fs_repair_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_repair) (const gchar *device, GError **error) = bd_fs_repair_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_REPAIR
 */
gboolean  bd_fs_repair (const gchar *device, GError **error) {
    return _bd_fs_repair (device, error);
}


gboolean  bd_fs_check_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_check) (const gchar *device, GError **error) = bd_fs_check_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_CHECK
 */
gboolean  bd_fs_check (const gchar *device, GError **error) {
    return _bd_fs_check (device, error);
}


gboolean  bd_fs_set_label_stub (const gchar *device, const gchar *label, GError **error) {
    g_critical ("The function 'bd_fs_set_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_set_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_set_label) (const gchar *device, const gchar *label, GError **error) = bd_fs_set_label_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_SET_LABEL
 */
gboolean  bd_fs_set_label (const gchar *device, const gchar *label, GError **error) {
    return _bd_fs_set_label (device, label, error);
}


gboolean  bd_fs_can_resize_stub (const gchar *type, BDFsResizeFlags *mode, gchar **required_utility, GError **error) {
    g_critical ("The function 'bd_fs_can_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_can_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_can_resize) (const gchar *type, BDFsResizeFlags *mode, gchar **required_utility, GError **error) = bd_fs_can_resize_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_QUERY
 */
gboolean  bd_fs_can_resize (const gchar *type, BDFsResizeFlags *mode, gchar **required_utility, GError **error) {
    return _bd_fs_can_resize (type, mode, required_utility, error);
}


gboolean  bd_fs_can_check_stub (const gchar *type, gchar **required_utility, GError **error) {
    g_critical ("The function 'bd_fs_can_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_can_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_can_check) (const gchar *type, gchar **required_utility, GError **error) = bd_fs_can_check_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_QUERY
 */
gboolean  bd_fs_can_check (const gchar *type, gchar **required_utility, GError **error) {
    return _bd_fs_can_check (type, required_utility, error);
}


gboolean  bd_fs_can_repair_stub (const gchar *type, gchar **required_utility, GError **error) {
    g_critical ("The function 'bd_fs_can_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_can_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_can_repair) (const gchar *type, gchar **required_utility, GError **error) = bd_fs_can_repair_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_QUERY
 */
gboolean  bd_fs_can_repair (const gchar *type, gchar **required_utility, GError **error) {
    return _bd_fs_can_repair (type, required_utility, error);
}


gboolean  bd_fs_can_set_label_stub (const gchar *type, gchar **required_utility, GError **error) {
    g_critical ("The function 'bd_fs_can_set_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_can_set_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_can_set_label) (const gchar *type, gchar **required_utility, GError **error) = bd_fs_can_set_label_stub;

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
 *
 * Tech category: %BD_FS_TECH_GENERIC-%BD_FS_TECH_MODE_QUERY
 */
gboolean  bd_fs_can_set_label (const gchar *type, gchar **required_utility, GError **error) {
    return _bd_fs_can_set_label (type, required_utility, error);
}


gboolean  bd_fs_ext2_mkfs_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext2_mkfs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext2_mkfs' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext2_mkfs) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_ext2_mkfs_stub;

/**
 * bd_fs_ext2_mkfs:
 * @device: the device to create a new ext2 fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mke2fs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new ext2 fs was successfully created on @device or not
 *
 * Tech category: %BD_FS_TECH_EXT2-%BD_FS_TECH_MODE_MKFS
 */
gboolean  bd_fs_ext2_mkfs (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext2_mkfs (device, extra, error);
}


gboolean  bd_fs_ext3_mkfs_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext3_mkfs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext3_mkfs' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext3_mkfs) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_ext3_mkfs_stub;

/**
 * bd_fs_ext3_mkfs:
 * @device: the device to create a new ext3 fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mke2fs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new ext3 fs was successfully created on @device or not
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_MKFS
 */
gboolean  bd_fs_ext3_mkfs (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext3_mkfs (device, extra, error);
}


gboolean  bd_fs_ext4_mkfs_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext4_mkfs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext4_mkfs' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext4_mkfs) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_ext4_mkfs_stub;

/**
 * bd_fs_ext4_mkfs:
 * @device: the device to create a new ext4 fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkfs.ext4' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new ext4 fs was successfully created on @device or not
 *
 * Tech category: %BD_FS_TECH_EXT4-%BD_FS_TECH_MODE_MKFS
 */
gboolean  bd_fs_ext4_mkfs (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext4_mkfs (device, extra, error);
}


gboolean  bd_fs_ext2_wipe_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ext2_wipe' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext2_wipe' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext2_wipe) (const gchar *device, GError **error) = bd_fs_ext2_wipe_stub;

/**
 * bd_fs_ext2_wipe:
 * @device: the device to wipe an ext2 signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext2 signature was successfully wiped from the @device or
 *          not
 *
 * Tech category: %BD_FS_TECH_EXT2-%BD_FS_TECH_MODE_WIPE
 */
gboolean  bd_fs_ext2_wipe (const gchar *device, GError **error) {
    return _bd_fs_ext2_wipe (device, error);
}


gboolean  bd_fs_ext3_wipe_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ext3_wipe' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext3_wipe' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext3_wipe) (const gchar *device, GError **error) = bd_fs_ext3_wipe_stub;

/**
 * bd_fs_ext3_wipe:
 * @device: the device to wipe an ext3 signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext3 signature was successfully wiped from the @device or
 *          not
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_WIPE
 */
gboolean  bd_fs_ext3_wipe (const gchar *device, GError **error) {
    return _bd_fs_ext3_wipe (device, error);
}


gboolean  bd_fs_ext4_wipe_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ext4_wipe' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext4_wipe' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext4_wipe) (const gchar *device, GError **error) = bd_fs_ext4_wipe_stub;

/**
 * bd_fs_ext4_wipe:
 * @device: the device to wipe an ext4 signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext4 signature was successfully wiped from the @device or
 *          not
 *
 * Tech category: %BD_FS_TECH_EXT4-%BD_FS_TECH_MODE_WIPE
 */
gboolean  bd_fs_ext4_wipe (const gchar *device, GError **error) {
    return _bd_fs_ext4_wipe (device, error);
}


gboolean  bd_fs_ext2_check_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext2_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext2_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext2_check) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_ext2_check_stub;

/**
 * bd_fs_ext2_check:
 * @device: the device the file system on which to check
 * @extra: (allow-none) (array zero-terminated=1): extra options for the check (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext2 file system on the @device is clean or not
 *
 * Tech category: %BD_FS_TECH_EXT2-%BD_FS_TECH_MODE_CHECK
 */
gboolean  bd_fs_ext2_check (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext2_check (device, extra, error);
}


gboolean  bd_fs_ext3_check_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext3_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext3_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext3_check) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_ext3_check_stub;

/**
 * bd_fs_ext3_check:
 * @device: the device the file system on which to check
 * @extra: (allow-none) (array zero-terminated=1): extra options for the check (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext3 file system on the @device is clean or not
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_CHECK
 */
gboolean  bd_fs_ext3_check (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext3_check (device, extra, error);
}


gboolean  bd_fs_ext4_check_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext4_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext4_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext4_check) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_ext4_check_stub;

/**
 * bd_fs_ext4_check:
 * @device: the device the file system on which to check
 * @extra: (allow-none) (array zero-terminated=1): extra options for the check (right now
 *                                                 passed to the 'e2fsck' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ext4 file system on the @device is clean or not
 *
 * Tech category: %BD_FS_TECH_EXT4-%BD_FS_TECH_MODE_CHECK
 */
gboolean  bd_fs_ext4_check (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext4_check (device, extra, error);
}


gboolean  bd_fs_ext2_repair_stub (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext2_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext2_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext2_repair) (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) = bd_fs_ext2_repair_stub;

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
 *
 * Tech category: %BD_FS_TECH_EXT2-%BD_FS_TECH_MODE_REPAIR
 */
gboolean  bd_fs_ext2_repair (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext2_repair (device, unsafe, extra, error);
}


gboolean  bd_fs_ext3_repair_stub (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext3_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext3_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext3_repair) (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) = bd_fs_ext3_repair_stub;

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
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_REPAIR
 */
gboolean  bd_fs_ext3_repair (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext3_repair (device, unsafe, extra, error);
}


gboolean  bd_fs_ext4_repair_stub (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext4_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext4_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext4_repair) (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) = bd_fs_ext4_repair_stub;

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
 *
 * Tech category: %BD_FS_TECH_EXT4-%BD_FS_TECH_MODE_REPAIR
 */
gboolean  bd_fs_ext4_repair (const gchar *device, gboolean unsafe, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext4_repair (device, unsafe, extra, error);
}


gboolean  bd_fs_ext2_set_label_stub (const gchar *device, const gchar *label, GError **error) {
    g_critical ("The function 'bd_fs_ext2_set_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext2_set_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext2_set_label) (const gchar *device, const gchar *label, GError **error) = bd_fs_ext2_set_label_stub;

/**
 * bd_fs_ext2_set_label:
 * @device: the device the file system on which to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of ext2 file system on the @device was
 *          successfully set or not
 *
 * Tech category: %BD_FS_TECH_EXT2-%BD_FS_TECH_MODE_SET_LABEL
 */
gboolean  bd_fs_ext2_set_label (const gchar *device, const gchar *label, GError **error) {
    return _bd_fs_ext2_set_label (device, label, error);
}


gboolean  bd_fs_ext3_set_label_stub (const gchar *device, const gchar *label, GError **error) {
    g_critical ("The function 'bd_fs_ext3_set_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext3_set_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext3_set_label) (const gchar *device, const gchar *label, GError **error) = bd_fs_ext3_set_label_stub;

/**
 * bd_fs_ext3_set_label:
 * @device: the device the file system on which to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of ext3 file system on the @device was
 *          successfully set or not
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_SET_LABEL
 */
gboolean  bd_fs_ext3_set_label (const gchar *device, const gchar *label, GError **error) {
    return _bd_fs_ext3_set_label (device, label, error);
}


gboolean  bd_fs_ext4_set_label_stub (const gchar *device, const gchar *label, GError **error) {
    g_critical ("The function 'bd_fs_ext4_set_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext4_set_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext4_set_label) (const gchar *device, const gchar *label, GError **error) = bd_fs_ext4_set_label_stub;

/**
 * bd_fs_ext4_set_label:
 * @device: the device the file system on which to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of ext4 file system on the @device was
 *          successfully set or not
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_SET_LABEL
 */
gboolean  bd_fs_ext4_set_label (const gchar *device, const gchar *label, GError **error) {
    return _bd_fs_ext4_set_label (device, label, error);
}


BDFSExt2Info* bd_fs_ext2_get_info_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ext2_get_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext2_get_info' called, but not implemented!");
    return NULL;
}

BDFSExt2Info* (*_bd_fs_ext2_get_info) (const gchar *device, GError **error) = bd_fs_ext2_get_info_stub;

/**
 * bd_fs_ext2_get_info:
 * @device: the device the file system of which to get info for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 *
 * Tech category: %BD_FS_TECH_EXT2-%BD_FS_TECH_MODE_QUERY
 */
BDFSExt2Info* bd_fs_ext2_get_info (const gchar *device, GError **error) {
    return _bd_fs_ext2_get_info (device, error);
}


BDFSExt3Info* bd_fs_ext3_get_info_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ext3_get_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext3_get_info' called, but not implemented!");
    return NULL;
}

BDFSExt3Info* (*_bd_fs_ext3_get_info) (const gchar *device, GError **error) = bd_fs_ext3_get_info_stub;

/**
 * bd_fs_ext3_get_info:
 * @device: the device the file system of which to get info for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_QUERY
 */
BDFSExt3Info* bd_fs_ext3_get_info (const gchar *device, GError **error) {
    return _bd_fs_ext3_get_info (device, error);
}


BDFSExt4Info* bd_fs_ext4_get_info_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ext4_get_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext4_get_info' called, but not implemented!");
    return NULL;
}

BDFSExt4Info* (*_bd_fs_ext4_get_info) (const gchar *device, GError **error) = bd_fs_ext4_get_info_stub;

/**
 * bd_fs_ext4_get_info:
 * @device: the device the file system of which to get info for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_QUERY
 */
BDFSExt4Info* bd_fs_ext4_get_info (const gchar *device, GError **error) {
    return _bd_fs_ext4_get_info (device, error);
}


gboolean  bd_fs_ext2_resize_stub (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext2_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext2_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext2_resize) (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) = bd_fs_ext2_resize_stub;

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
 *
 * Tech category: %BD_FS_TECH_EXT2-%BD_FS_TECH_MODE_RESIZE
 */
gboolean  bd_fs_ext2_resize (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext2_resize (device, new_size, extra, error);
}


gboolean  bd_fs_ext3_resize_stub (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext3_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext3_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext3_resize) (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) = bd_fs_ext3_resize_stub;

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
 *
 * Tech category: %BD_FS_TECH_EXT3-%BD_FS_TECH_MODE_RESIZE
 */
gboolean  bd_fs_ext3_resize (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext3_resize (device, new_size, extra, error);
}


gboolean  bd_fs_ext4_resize_stub (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ext4_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ext4_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ext4_resize) (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) = bd_fs_ext4_resize_stub;

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
 *
 * Tech category: %BD_FS_TECH_EXT4-%BD_FS_TECH_MODE_RESIZE
 */
gboolean  bd_fs_ext4_resize (const gchar *device, guint64 new_size, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ext4_resize (device, new_size, extra, error);
}


gboolean  bd_fs_xfs_mkfs_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_xfs_mkfs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_xfs_mkfs' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_xfs_mkfs) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_xfs_mkfs_stub;

/**
 * bd_fs_xfs_mkfs:
 * @device: the device to create a new xfs fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkfs.xfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new xfs fs was successfully created on @device or not
 *
 * Tech category: %BD_FS_TECH_XFS-%BD_FS_TECH_MODE_MKFS
 */
gboolean  bd_fs_xfs_mkfs (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_xfs_mkfs (device, extra, error);
}


gboolean  bd_fs_xfs_wipe_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_xfs_wipe' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_xfs_wipe' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_xfs_wipe) (const gchar *device, GError **error) = bd_fs_xfs_wipe_stub;

/**
 * bd_fs_xfs_wipe:
 * @device: the device to wipe an xfs signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an xfs signature was successfully wiped from the @device or
 *          not
 *
 * Tech category: %BD_FS_TECH_XFS-%BD_FS_TECH_MODE_WIPE
 */
gboolean  bd_fs_xfs_wipe (const gchar *device, GError **error) {
    return _bd_fs_xfs_wipe (device, error);
}


gboolean  bd_fs_xfs_check_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_xfs_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_xfs_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_xfs_check) (const gchar *device, GError **error) = bd_fs_xfs_check_stub;

/**
 * bd_fs_xfs_check:
 * @device: the device containing the file system to check
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an xfs file system on the @device is clean or not
 *
 * Note: If the file system is mounted RW, it will always be reported as not
 *       clean!
 *
 * Tech category: %BD_FS_TECH_XFS-%BD_FS_TECH_MODE_CHECK
 */
gboolean  bd_fs_xfs_check (const gchar *device, GError **error) {
    return _bd_fs_xfs_check (device, error);
}


gboolean  bd_fs_xfs_repair_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_xfs_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_xfs_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_xfs_repair) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_xfs_repair_stub;

/**
 * bd_fs_xfs_repair:
 * @device: the device containing the file system to repair
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'xfs_repair' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an xfs file system on the @device was successfully repaired
 *          (if needed) or not (error is set in that case)
 *
 * Tech category: %BD_FS_TECH_XFS-%BD_FS_TECH_MODE_REPAIR
 */
gboolean  bd_fs_xfs_repair (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_xfs_repair (device, extra, error);
}


gboolean  bd_fs_xfs_set_label_stub (const gchar *device, const gchar *label, GError **error) {
    g_critical ("The function 'bd_fs_xfs_set_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_xfs_set_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_xfs_set_label) (const gchar *device, const gchar *label, GError **error) = bd_fs_xfs_set_label_stub;

/**
 * bd_fs_xfs_set_label:
 * @device: the device containing the file system to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of xfs file system on the @device was
 *          successfully set or not
 *
 * Tech category: %BD_FS_TECH_XFS-%BD_FS_TECH_MODE_SET_LABEL
 */
gboolean  bd_fs_xfs_set_label (const gchar *device, const gchar *label, GError **error) {
    return _bd_fs_xfs_set_label (device, label, error);
}


BDFSXfsInfo* bd_fs_xfs_get_info_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_xfs_get_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_xfs_get_info' called, but not implemented!");
    return NULL;
}

BDFSXfsInfo* (*_bd_fs_xfs_get_info) (const gchar *device, GError **error) = bd_fs_xfs_get_info_stub;

/**
 * bd_fs_xfs_get_info:
 * @device: the device containing the file system to get info for (device must
            be mounted, trying to get info for an unmounted device will result
            in an error)
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 *
 * Tech category: %BD_FS_TECH_XFS-%BD_FS_TECH_MODE_QUERY
 */
BDFSXfsInfo* bd_fs_xfs_get_info (const gchar *device, GError **error) {
    return _bd_fs_xfs_get_info (device, error);
}


gboolean  bd_fs_xfs_resize_stub (const gchar *mpoint, guint64 new_size, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_xfs_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_xfs_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_xfs_resize) (const gchar *mpoint, guint64 new_size, const BDExtraArg **extra, GError **error) = bd_fs_xfs_resize_stub;

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
 *
 * Tech category: %BD_FS_TECH_XFS-%BD_FS_TECH_MODE_RESIZE
 */
gboolean  bd_fs_xfs_resize (const gchar *mpoint, guint64 new_size, const BDExtraArg **extra, GError **error) {
    return _bd_fs_xfs_resize (mpoint, new_size, extra, error);
}


gboolean  bd_fs_vfat_mkfs_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_vfat_mkfs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_vfat_mkfs' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_vfat_mkfs) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_vfat_mkfs_stub;

/**
 * bd_fs_vfat_mkfs:
 * @device: the device to create a new vfat fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkfs.vfat' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new vfat fs was successfully created on @device or not
 *
 * Tech category: %BD_FS_TECH_VFAT-%BD_FS_TECH_MODE_MKFS
 */
gboolean  bd_fs_vfat_mkfs (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_vfat_mkfs (device, extra, error);
}


gboolean  bd_fs_vfat_wipe_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_vfat_wipe' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_vfat_wipe' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_vfat_wipe) (const gchar *device, GError **error) = bd_fs_vfat_wipe_stub;

/**
 * bd_fs_vfat_wipe:
 * @device: the device to wipe an vfat signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an vfat signature was successfully wiped from the @device or
 *          not
 *
 * Tech category: %BD_FS_TECH_VFAT-%BD_FS_TECH_MODE_WIPE
 */
gboolean  bd_fs_vfat_wipe (const gchar *device, GError **error) {
    return _bd_fs_vfat_wipe (device, error);
}


gboolean  bd_fs_vfat_check_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_vfat_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_vfat_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_vfat_check) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_vfat_check_stub;

/**
 * bd_fs_vfat_check:
 * @device: the device containing the file system to check
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'fsck.vfat' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an vfat file system on the @device is clean or not
 *
 * Tech category: %BD_FS_TECH_VFAT-%BD_FS_TECH_MODE_CHECK
 */
gboolean  bd_fs_vfat_check (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_vfat_check (device, extra, error);
}


gboolean  bd_fs_vfat_repair_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_vfat_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_vfat_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_vfat_repair) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_vfat_repair_stub;

/**
 * bd_fs_vfat_repair:
 * @device: the device containing the file system to repair
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'fsck.vfat' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an vfat file system on the @device was successfully repaired
 *          (if needed) or not (error is set in that case)
 *
 * Tech category: %BD_FS_TECH_VFAT-%BD_FS_TECH_MODE_REPAIR
 */
gboolean  bd_fs_vfat_repair (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_vfat_repair (device, extra, error);
}


gboolean  bd_fs_vfat_set_label_stub (const gchar *device, const gchar *label, GError **error) {
    g_critical ("The function 'bd_fs_vfat_set_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_vfat_set_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_vfat_set_label) (const gchar *device, const gchar *label, GError **error) = bd_fs_vfat_set_label_stub;

/**
 * bd_fs_vfat_set_label:
 * @device: the device containing the file system to set label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of vfat file system on the @device was
 *          successfully set or not
 *
 * Tech category: %BD_FS_TECH_VFAT-%BD_FS_TECH_MODE_SET_LABEL
 */
gboolean  bd_fs_vfat_set_label (const gchar *device, const gchar *label, GError **error) {
    return _bd_fs_vfat_set_label (device, label, error);
}


BDFSVfatInfo* bd_fs_vfat_get_info_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_vfat_get_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_vfat_get_info' called, but not implemented!");
    return NULL;
}

BDFSVfatInfo* (*_bd_fs_vfat_get_info) (const gchar *device, GError **error) = bd_fs_vfat_get_info_stub;

/**
 * bd_fs_vfat_get_info:
 * @device: the device containing the file system to get info for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 *
 * Tech category: %BD_FS_TECH_VFAT-%BD_FS_TECH_MODE_QUERY
 */
BDFSVfatInfo* bd_fs_vfat_get_info (const gchar *device, GError **error) {
    return _bd_fs_vfat_get_info (device, error);
}


gboolean  bd_fs_vfat_resize_stub (const gchar *device, guint64 new_size, GError **error) {
    g_critical ("The function 'bd_fs_vfat_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_vfat_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_vfat_resize) (const gchar *device, guint64 new_size, GError **error) = bd_fs_vfat_resize_stub;

/**
 * bd_fs_vfat_resize:
 * @device: the device the file system of which to resize
 * @new_size: new requested size for the file system (if 0, the file system is
 *            adapted to the underlying block device)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system on @device was successfully resized or not
 *
 * Tech category: %BD_FS_TECH_VFAT-%BD_FS_TECH_MODE_RESIZE
 */
gboolean  bd_fs_vfat_resize (const gchar *device, guint64 new_size, GError **error) {
    return _bd_fs_vfat_resize (device, new_size, error);
}


gboolean  bd_fs_ntfs_mkfs_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_fs_ntfs_mkfs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ntfs_mkfs' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ntfs_mkfs) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_fs_ntfs_mkfs_stub;

/**
 * bd_fs_ntfs_mkfs:
 * @device: the device to create a new ntfs fs on
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkntfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new NTFS fs was successfully created on @device or not
 *
 * Tech category: %BD_FS_TECH_NTFS-%BD_FS_TECH_MODE_MKFS
 */
gboolean  bd_fs_ntfs_mkfs (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_fs_ntfs_mkfs (device, extra, error);
}


gboolean  bd_fs_ntfs_wipe_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ntfs_wipe' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ntfs_wipe' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ntfs_wipe) (const gchar *device, GError **error) = bd_fs_ntfs_wipe_stub;

/**
 * bd_fs_ntfs_wipe:
 * @device: the device to wipe an ntfs signature from
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ntfs signature was successfully wiped from the @device or not
 *
 * Tech category: %BD_FS_TECH_NTFS-%BD_FS_TECH_MODE_WIPE
 */
gboolean  bd_fs_ntfs_wipe (const gchar *device, GError **error) {
    return _bd_fs_ntfs_wipe (device, error);
}


gboolean  bd_fs_ntfs_check_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ntfs_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ntfs_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ntfs_check) (const gchar *device, GError **error) = bd_fs_ntfs_check_stub;

/**
 * bd_fs_ntfs_check:
 * @device: the device containing the file system to check
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an ntfs file system on the @device is clean or not
 *
 * Tech category: %BD_FS_TECH_NTFS-%BD_FS_TECH_MODE_CHECK
 */
gboolean  bd_fs_ntfs_check (const gchar *device, GError **error) {
    return _bd_fs_ntfs_check (device, error);
}


gboolean  bd_fs_ntfs_repair_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ntfs_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ntfs_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ntfs_repair) (const gchar *device, GError **error) = bd_fs_ntfs_repair_stub;

/**
 * bd_fs_ntfs_repair:
 * @device: the device containing the file system to repair
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an NTFS file system on the @device was successfully repaired
 *          (if needed) or not (error is set in that case)
 *
 * Tech category: %BD_FS_TECH_NTFS-%BD_FS_TECH_MODE_REPAIR
 */
gboolean  bd_fs_ntfs_repair (const gchar *device, GError **error) {
    return _bd_fs_ntfs_repair (device, error);
}


gboolean  bd_fs_ntfs_set_label_stub (const gchar *device, const gchar *label, GError **error) {
    g_critical ("The function 'bd_fs_ntfs_set_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ntfs_set_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ntfs_set_label) (const gchar *device, const gchar *label, GError **error) = bd_fs_ntfs_set_label_stub;

/**
 * bd_fs_ntfs_set_label:
 * @device: the device containing the file system to set the label for
 * @label: label to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label of the NTFS file system on the @device was
 *          successfully set or not
 *
 * Tech category: %BD_FS_TECH_NTFS-%BD_FS_TECH_MODE_SET_LABEL
 */
gboolean  bd_fs_ntfs_set_label (const gchar *device, const gchar *label, GError **error) {
    return _bd_fs_ntfs_set_label (device, label, error);
}


gboolean  bd_fs_ntfs_resize_stub (const gchar *device, guint64 new_size, GError **error) {
    g_critical ("The function 'bd_fs_ntfs_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ntfs_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_fs_ntfs_resize) (const gchar *device, guint64 new_size, GError **error) = bd_fs_ntfs_resize_stub;

/**
 * bd_fs_ntfs_resize:
 * @device: the device the file system of which to resize
 * @new_size: new requested size for the file system in bytes (if 0, the file system
 *            is adapted to the underlying block device)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the file system on @device was successfully resized or not
 *
 * Tech category: %BD_FS_TECH_NTFS-%BD_FS_TECH_MODE_RESIZE
 */
gboolean  bd_fs_ntfs_resize (const gchar *device, guint64 new_size, GError **error) {
    return _bd_fs_ntfs_resize (device, new_size, error);
}


BDFSNtfsInfo* bd_fs_ntfs_get_info_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_fs_ntfs_get_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_fs_ntfs_get_info' called, but not implemented!");
    return NULL;
}

BDFSNtfsInfo* (*_bd_fs_ntfs_get_info) (const gchar *device, GError **error) = bd_fs_ntfs_get_info_stub;

/**
 * bd_fs_ntfs_get_info:
 * @device: the device containing the file system to get info for (device must
            not be mounted, trying to get info for a mounted device will result
            in an error)
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the file system on @device or
 *                           %NULL in case of error
 *
 * Tech category: %BD_FS_TECH_NTFS-%BD_FS_TECH_MODE_QUERY
 */
BDFSNtfsInfo* bd_fs_ntfs_get_info (const gchar *device, GError **error) {
    return _bd_fs_ntfs_get_info (device, error);
}


gpointer load_fs_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module fs: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_fs_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for fs: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_fs_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for fs: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_fs_is_tech_avail) = dlsym(handle, "bd_fs_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_fs_wipe) = dlsym(handle, "bd_fs_wipe");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_wipe: %s", error);

    dlerror();
    * (void**) (&_bd_fs_clean) = dlsym(handle, "bd_fs_clean");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_clean: %s", error);

    dlerror();
    * (void**) (&_bd_fs_get_fstype) = dlsym(handle, "bd_fs_get_fstype");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_get_fstype: %s", error);

    dlerror();
    * (void**) (&_bd_fs_unmount) = dlsym(handle, "bd_fs_unmount");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_unmount: %s", error);

    dlerror();
    * (void**) (&_bd_fs_mount) = dlsym(handle, "bd_fs_mount");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_mount: %s", error);

    dlerror();
    * (void**) (&_bd_fs_get_mountpoint) = dlsym(handle, "bd_fs_get_mountpoint");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_get_mountpoint: %s", error);

    dlerror();
    * (void**) (&_bd_fs_resize) = dlsym(handle, "bd_fs_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_resize: %s", error);

    dlerror();
    * (void**) (&_bd_fs_repair) = dlsym(handle, "bd_fs_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_repair: %s", error);

    dlerror();
    * (void**) (&_bd_fs_check) = dlsym(handle, "bd_fs_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_check: %s", error);

    dlerror();
    * (void**) (&_bd_fs_set_label) = dlsym(handle, "bd_fs_set_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_set_label: %s", error);

    dlerror();
    * (void**) (&_bd_fs_can_resize) = dlsym(handle, "bd_fs_can_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_can_resize: %s", error);

    dlerror();
    * (void**) (&_bd_fs_can_check) = dlsym(handle, "bd_fs_can_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_can_check: %s", error);

    dlerror();
    * (void**) (&_bd_fs_can_repair) = dlsym(handle, "bd_fs_can_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_can_repair: %s", error);

    dlerror();
    * (void**) (&_bd_fs_can_set_label) = dlsym(handle, "bd_fs_can_set_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_can_set_label: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext2_mkfs) = dlsym(handle, "bd_fs_ext2_mkfs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext2_mkfs: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext3_mkfs) = dlsym(handle, "bd_fs_ext3_mkfs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext3_mkfs: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext4_mkfs) = dlsym(handle, "bd_fs_ext4_mkfs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext4_mkfs: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext2_wipe) = dlsym(handle, "bd_fs_ext2_wipe");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext2_wipe: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext3_wipe) = dlsym(handle, "bd_fs_ext3_wipe");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext3_wipe: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext4_wipe) = dlsym(handle, "bd_fs_ext4_wipe");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext4_wipe: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext2_check) = dlsym(handle, "bd_fs_ext2_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext2_check: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext3_check) = dlsym(handle, "bd_fs_ext3_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext3_check: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext4_check) = dlsym(handle, "bd_fs_ext4_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext4_check: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext2_repair) = dlsym(handle, "bd_fs_ext2_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext2_repair: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext3_repair) = dlsym(handle, "bd_fs_ext3_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext3_repair: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext4_repair) = dlsym(handle, "bd_fs_ext4_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext4_repair: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext2_set_label) = dlsym(handle, "bd_fs_ext2_set_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext2_set_label: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext3_set_label) = dlsym(handle, "bd_fs_ext3_set_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext3_set_label: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext4_set_label) = dlsym(handle, "bd_fs_ext4_set_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext4_set_label: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext2_get_info) = dlsym(handle, "bd_fs_ext2_get_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext2_get_info: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext3_get_info) = dlsym(handle, "bd_fs_ext3_get_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext3_get_info: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext4_get_info) = dlsym(handle, "bd_fs_ext4_get_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext4_get_info: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext2_resize) = dlsym(handle, "bd_fs_ext2_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext2_resize: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext3_resize) = dlsym(handle, "bd_fs_ext3_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext3_resize: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ext4_resize) = dlsym(handle, "bd_fs_ext4_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ext4_resize: %s", error);

    dlerror();
    * (void**) (&_bd_fs_xfs_mkfs) = dlsym(handle, "bd_fs_xfs_mkfs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_xfs_mkfs: %s", error);

    dlerror();
    * (void**) (&_bd_fs_xfs_wipe) = dlsym(handle, "bd_fs_xfs_wipe");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_xfs_wipe: %s", error);

    dlerror();
    * (void**) (&_bd_fs_xfs_check) = dlsym(handle, "bd_fs_xfs_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_xfs_check: %s", error);

    dlerror();
    * (void**) (&_bd_fs_xfs_repair) = dlsym(handle, "bd_fs_xfs_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_xfs_repair: %s", error);

    dlerror();
    * (void**) (&_bd_fs_xfs_set_label) = dlsym(handle, "bd_fs_xfs_set_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_xfs_set_label: %s", error);

    dlerror();
    * (void**) (&_bd_fs_xfs_get_info) = dlsym(handle, "bd_fs_xfs_get_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_xfs_get_info: %s", error);

    dlerror();
    * (void**) (&_bd_fs_xfs_resize) = dlsym(handle, "bd_fs_xfs_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_xfs_resize: %s", error);

    dlerror();
    * (void**) (&_bd_fs_vfat_mkfs) = dlsym(handle, "bd_fs_vfat_mkfs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_vfat_mkfs: %s", error);

    dlerror();
    * (void**) (&_bd_fs_vfat_wipe) = dlsym(handle, "bd_fs_vfat_wipe");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_vfat_wipe: %s", error);

    dlerror();
    * (void**) (&_bd_fs_vfat_check) = dlsym(handle, "bd_fs_vfat_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_vfat_check: %s", error);

    dlerror();
    * (void**) (&_bd_fs_vfat_repair) = dlsym(handle, "bd_fs_vfat_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_vfat_repair: %s", error);

    dlerror();
    * (void**) (&_bd_fs_vfat_set_label) = dlsym(handle, "bd_fs_vfat_set_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_vfat_set_label: %s", error);

    dlerror();
    * (void**) (&_bd_fs_vfat_get_info) = dlsym(handle, "bd_fs_vfat_get_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_vfat_get_info: %s", error);

    dlerror();
    * (void**) (&_bd_fs_vfat_resize) = dlsym(handle, "bd_fs_vfat_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_vfat_resize: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ntfs_mkfs) = dlsym(handle, "bd_fs_ntfs_mkfs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ntfs_mkfs: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ntfs_wipe) = dlsym(handle, "bd_fs_ntfs_wipe");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ntfs_wipe: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ntfs_check) = dlsym(handle, "bd_fs_ntfs_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ntfs_check: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ntfs_repair) = dlsym(handle, "bd_fs_ntfs_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ntfs_repair: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ntfs_set_label) = dlsym(handle, "bd_fs_ntfs_set_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ntfs_set_label: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ntfs_resize) = dlsym(handle, "bd_fs_ntfs_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ntfs_resize: %s", error);

    dlerror();
    * (void**) (&_bd_fs_ntfs_get_info) = dlsym(handle, "bd_fs_ntfs_get_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_fs_ntfs_get_info: %s", error);

    return handle;
}

gboolean unload_fs (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_fs_is_tech_avail = bd_fs_is_tech_avail_stub;
    _bd_fs_wipe = bd_fs_wipe_stub;
    _bd_fs_clean = bd_fs_clean_stub;
    _bd_fs_get_fstype = bd_fs_get_fstype_stub;
    _bd_fs_unmount = bd_fs_unmount_stub;
    _bd_fs_mount = bd_fs_mount_stub;
    _bd_fs_get_mountpoint = bd_fs_get_mountpoint_stub;
    _bd_fs_resize = bd_fs_resize_stub;
    _bd_fs_repair = bd_fs_repair_stub;
    _bd_fs_check = bd_fs_check_stub;
    _bd_fs_set_label = bd_fs_set_label_stub;
    _bd_fs_can_resize = bd_fs_can_resize_stub;
    _bd_fs_can_check = bd_fs_can_check_stub;
    _bd_fs_can_repair = bd_fs_can_repair_stub;
    _bd_fs_can_set_label = bd_fs_can_set_label_stub;
    _bd_fs_ext2_mkfs = bd_fs_ext2_mkfs_stub;
    _bd_fs_ext3_mkfs = bd_fs_ext3_mkfs_stub;
    _bd_fs_ext4_mkfs = bd_fs_ext4_mkfs_stub;
    _bd_fs_ext2_wipe = bd_fs_ext2_wipe_stub;
    _bd_fs_ext3_wipe = bd_fs_ext3_wipe_stub;
    _bd_fs_ext4_wipe = bd_fs_ext4_wipe_stub;
    _bd_fs_ext2_check = bd_fs_ext2_check_stub;
    _bd_fs_ext3_check = bd_fs_ext3_check_stub;
    _bd_fs_ext4_check = bd_fs_ext4_check_stub;
    _bd_fs_ext2_repair = bd_fs_ext2_repair_stub;
    _bd_fs_ext3_repair = bd_fs_ext3_repair_stub;
    _bd_fs_ext4_repair = bd_fs_ext4_repair_stub;
    _bd_fs_ext2_set_label = bd_fs_ext2_set_label_stub;
    _bd_fs_ext3_set_label = bd_fs_ext3_set_label_stub;
    _bd_fs_ext4_set_label = bd_fs_ext4_set_label_stub;
    _bd_fs_ext2_get_info = bd_fs_ext2_get_info_stub;
    _bd_fs_ext3_get_info = bd_fs_ext3_get_info_stub;
    _bd_fs_ext4_get_info = bd_fs_ext4_get_info_stub;
    _bd_fs_ext2_resize = bd_fs_ext2_resize_stub;
    _bd_fs_ext3_resize = bd_fs_ext3_resize_stub;
    _bd_fs_ext4_resize = bd_fs_ext4_resize_stub;
    _bd_fs_xfs_mkfs = bd_fs_xfs_mkfs_stub;
    _bd_fs_xfs_wipe = bd_fs_xfs_wipe_stub;
    _bd_fs_xfs_check = bd_fs_xfs_check_stub;
    _bd_fs_xfs_repair = bd_fs_xfs_repair_stub;
    _bd_fs_xfs_set_label = bd_fs_xfs_set_label_stub;
    _bd_fs_xfs_get_info = bd_fs_xfs_get_info_stub;
    _bd_fs_xfs_resize = bd_fs_xfs_resize_stub;
    _bd_fs_vfat_mkfs = bd_fs_vfat_mkfs_stub;
    _bd_fs_vfat_wipe = bd_fs_vfat_wipe_stub;
    _bd_fs_vfat_check = bd_fs_vfat_check_stub;
    _bd_fs_vfat_repair = bd_fs_vfat_repair_stub;
    _bd_fs_vfat_set_label = bd_fs_vfat_set_label_stub;
    _bd_fs_vfat_get_info = bd_fs_vfat_get_info_stub;
    _bd_fs_vfat_resize = bd_fs_vfat_resize_stub;
    _bd_fs_ntfs_mkfs = bd_fs_ntfs_mkfs_stub;
    _bd_fs_ntfs_wipe = bd_fs_ntfs_wipe_stub;
    _bd_fs_ntfs_check = bd_fs_ntfs_check_stub;
    _bd_fs_ntfs_repair = bd_fs_ntfs_repair_stub;
    _bd_fs_ntfs_set_label = bd_fs_ntfs_set_label_stub;
    _bd_fs_ntfs_resize = bd_fs_ntfs_resize_stub;
    _bd_fs_ntfs_get_info = bd_fs_ntfs_get_info_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_fs_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for fs: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

