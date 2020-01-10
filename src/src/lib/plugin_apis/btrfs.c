GQuark  bd_btrfs_error_quark (void) {
        return g_quark_from_static_string ("g-bd-btrfs-error-quark");
}

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
BDBtrfsDeviceInfo* bd_btrfs_device_info_copy (BDBtrfsDeviceInfo *info) {
        BDBtrfsDeviceInfo *new_info = g_new0 (BDBtrfsDeviceInfo, 1);

    new_info->id = info->id;
    new_info->path = g_strdup (info->path);
    new_info->size = info->size;
    new_info->used = info->used;

    return new_info;
}

/**
 * bd_btrfs_device_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_btrfs_device_info_free (BDBtrfsDeviceInfo *info) {
        g_free (info->path);
    g_free (info);
}

GType  bd_btrfs_device_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDBtrfsDeviceInfo",
                                            (GBoxedCopyFunc) bd_btrfs_device_info_copy,
                                            (GBoxedFreeFunc) bd_btrfs_device_info_free);
    }

    return type;
}

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
BDBtrfsSubvolumeInfo* bd_btrfs_subvolume_info_copy (BDBtrfsSubvolumeInfo *info) {
        BDBtrfsSubvolumeInfo *new_info = g_new0 (BDBtrfsSubvolumeInfo, 1);

    new_info->id = info->id;
    new_info->parent_id = info->parent_id;
    new_info->path = g_strdup (info->path);

    return new_info;
}

/**
 * bd_btrfs_subvolume_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_btrfs_subvolume_info_free (BDBtrfsSubvolumeInfo *info) {
        g_free (info->path);
    g_free (info);
}

GType  bd_btrfs_subvolume_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDBtrfsSubvolumeInfo",
                                            (GBoxedCopyFunc) bd_btrfs_subvolume_info_copy,
                                            (GBoxedFreeFunc) bd_btrfs_subvolume_info_free);
    }

    return type;
}

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
BDBtrfsFilesystemInfo* bd_btrfs_filesystem_info_copy (BDBtrfsFilesystemInfo *info) {
        BDBtrfsFilesystemInfo *new_info = g_new0 (BDBtrfsFilesystemInfo, 1);

    new_info->label = g_strdup (info->label);
    new_info->uuid = g_strdup (info->uuid);
    new_info->num_devices = info->num_devices;
    new_info->used = info->used;

    return new_info;
}

/**
 * bd_btrfs_filesystem_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_btrfs_filesystem_info_free (BDBtrfsFilesystemInfo *info) {
        g_free (info->label);
    g_free (info->uuid);
    g_free (info);
}

GType  bd_btrfs_filesystem_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDBtrfsFilesystemInfo",
                                            (GBoxedCopyFunc) bd_btrfs_filesystem_info_copy,
                                            (GBoxedFreeFunc) bd_btrfs_filesystem_info_free);
    }

    return type;
}

static const gchar const * const btrfs_functions[] = {
    "bd_btrfs_create_volume",
    "bd_btrfs_add_device",
    "bd_btrfs_remove_device",
    "bd_btrfs_create_subvolume",
    "bd_btrfs_delete_subvolume",
    "bd_btrfs_get_default_subvolume_id",
    "bd_btrfs_set_default_subvolume",
    "bd_btrfs_create_snapshot",
    "bd_btrfs_list_devices",
    "bd_btrfs_list_subvolumes",
    "bd_btrfs_filesystem_info",
    "bd_btrfs_mkfs",
    "bd_btrfs_resize",
    "bd_btrfs_check",
    "bd_btrfs_repair",
    "bd_btrfs_change_label",
    NULL};

gchar const * const * get_btrfs_functions (void) {
    return btrfs_functions;
}

static const guint8 btrfs_num_functions = 16;

guint8 get_btrfs_num_functions (void) {
    return btrfs_num_functions;
}

gboolean  bd_btrfs_create_volume_stub (const gchar **devices, const gchar *label, const gchar *data_level, const gchar *md_level, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_create_volume' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_create_volume' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_create_volume) (const gchar **devices, const gchar *label, const gchar *data_level, const gchar *md_level, const BDExtraArg **extra, GError **error) = bd_btrfs_create_volume_stub;

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
 */
gboolean  bd_btrfs_create_volume (const gchar **devices, const gchar *label, const gchar *data_level, const gchar *md_level, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_create_volume (devices, label, data_level, md_level, extra, error);
}


gboolean  bd_btrfs_add_device_stub (const gchar *mountpoint, const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_add_device' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_add_device' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_add_device) (const gchar *mountpoint, const gchar *device, const BDExtraArg **extra, GError **error) = bd_btrfs_add_device_stub;

/**
 * bd_btrfs_add_device:
 * @mountpoint: mountpoint of the btrfs volume to add new device to
 * @device: a device to add to the btrfs volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the addition (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully added to the @mountpoint btrfs volume or not
 */
gboolean  bd_btrfs_add_device (const gchar *mountpoint, const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_add_device (mountpoint, device, extra, error);
}


gboolean  bd_btrfs_remove_device_stub (const gchar *mountpoint, const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_remove_device' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_remove_device' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_remove_device) (const gchar *mountpoint, const gchar *device, const BDExtraArg **extra, GError **error) = bd_btrfs_remove_device_stub;

/**
 * bd_btrfs_remove_device:
 * @mountpoint: mountpoint of the btrfs volume to remove device from
 * @device: a device to remove from the btrfs volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the removal (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully removed from the @mountpoint btrfs volume or not
 */
gboolean  bd_btrfs_remove_device (const gchar *mountpoint, const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_remove_device (mountpoint, device, extra, error);
}


gboolean  bd_btrfs_create_subvolume_stub (const gchar *mountpoint, const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_create_subvolume' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_create_subvolume' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_create_subvolume) (const gchar *mountpoint, const gchar *name, const BDExtraArg **extra, GError **error) = bd_btrfs_create_subvolume_stub;

/**
 * bd_btrfs_create_subvolume:
 * @mountpoint: mountpoint of the btrfs volume to create subvolume under
 * @name: name of the subvolume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the subvolume creation (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @mountpoint/@name subvolume was successfully created or not
 */
gboolean  bd_btrfs_create_subvolume (const gchar *mountpoint, const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_create_subvolume (mountpoint, name, extra, error);
}


gboolean  bd_btrfs_delete_subvolume_stub (const gchar *mountpoint, const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_delete_subvolume' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_delete_subvolume' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_delete_subvolume) (const gchar *mountpoint, const gchar *name, const BDExtraArg **extra, GError **error) = bd_btrfs_delete_subvolume_stub;

/**
 * bd_btrfs_delete_subvolume:
 * @mountpoint: mountpoint of the btrfs volume to delete subvolume from
 * @name: name of the subvolume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the subvolume deletion (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @mountpoint/@name subvolume was successfully deleted or not
 */
gboolean  bd_btrfs_delete_subvolume (const gchar *mountpoint, const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_delete_subvolume (mountpoint, name, extra, error);
}


guint64  bd_btrfs_get_default_subvolume_id_stub (const gchar *mountpoint, GError **error) {
    g_critical ("The function 'bd_btrfs_get_default_subvolume_id' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_get_default_subvolume_id' called, but not implemented!");
    return 0;
}

guint64  (*_bd_btrfs_get_default_subvolume_id) (const gchar *mountpoint, GError **error) = bd_btrfs_get_default_subvolume_id_stub;

/**
 * bd_btrfs_get_default_subvolume_id:
 * @mountpoint: mountpoint of the volume to get the default subvolume ID of
 * @error: (out): place to store error (if any)
 *
 * Returns: ID of the @mountpoint volume's default subvolume. If 0,
 * @error) may be set to indicate error
 */
guint64  bd_btrfs_get_default_subvolume_id (const gchar *mountpoint, GError **error) {
    return _bd_btrfs_get_default_subvolume_id (mountpoint, error);
}


gboolean  bd_btrfs_set_default_subvolume_stub (const gchar *mountpoint, guint64 subvol_id, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_set_default_subvolume' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_set_default_subvolume' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_set_default_subvolume) (const gchar *mountpoint, guint64 subvol_id, const BDExtraArg **extra, GError **error) = bd_btrfs_set_default_subvolume_stub;

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
 */
gboolean  bd_btrfs_set_default_subvolume (const gchar *mountpoint, guint64 subvol_id, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_set_default_subvolume (mountpoint, subvol_id, extra, error);
}


gboolean  bd_btrfs_create_snapshot_stub (const gchar *source, const gchar *dest, gboolean ro, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_create_snapshot' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_create_snapshot' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_create_snapshot) (const gchar *source, const gchar *dest, gboolean ro, const BDExtraArg **extra, GError **error) = bd_btrfs_create_snapshot_stub;

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
 */
gboolean  bd_btrfs_create_snapshot (const gchar *source, const gchar *dest, gboolean ro, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_create_snapshot (source, dest, ro, extra, error);
}


BDBtrfsDeviceInfo** bd_btrfs_list_devices_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_btrfs_list_devices' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_list_devices' called, but not implemented!");
    return NULL;
}

BDBtrfsDeviceInfo** (*_bd_btrfs_list_devices) (const gchar *device, GError **error) = bd_btrfs_list_devices_stub;

/**
 * bd_btrfs_list_devices:
 * @device: a device that is part of the queried btrfs volume
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about the devices that are part of the btrfs volume
 * containing @device or %NULL in case of error
 */
BDBtrfsDeviceInfo** bd_btrfs_list_devices (const gchar *device, GError **error) {
    return _bd_btrfs_list_devices (device, error);
}


BDBtrfsSubvolumeInfo** bd_btrfs_list_subvolumes_stub (const gchar *mountpoint, gboolean snapshots_only, GError **error) {
    g_critical ("The function 'bd_btrfs_list_subvolumes' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_list_subvolumes' called, but not implemented!");
    return NULL;
}

BDBtrfsSubvolumeInfo** (*_bd_btrfs_list_subvolumes) (const gchar *mountpoint, gboolean snapshots_only, GError **error) = bd_btrfs_list_subvolumes_stub;

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
 */
BDBtrfsSubvolumeInfo** bd_btrfs_list_subvolumes (const gchar *mountpoint, gboolean snapshots_only, GError **error) {
    return _bd_btrfs_list_subvolumes (mountpoint, snapshots_only, error);
}


BDBtrfsFilesystemInfo* bd_btrfs_filesystem_info_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_btrfs_filesystem_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_filesystem_info' called, but not implemented!");
    return NULL;
}

BDBtrfsFilesystemInfo* (*_bd_btrfs_filesystem_info) (const gchar *device, GError **error) = bd_btrfs_filesystem_info_stub;

/**
 * bd_btrfs_filesystem_info:
 * @device: a device that is part of the queried btrfs volume
 * @error: (out): place to store error (if any)
 *
 * Returns: information about the @device's volume's filesystem or %NULL in case of error
 */
BDBtrfsFilesystemInfo* bd_btrfs_filesystem_info (const gchar *device, GError **error) {
    return _bd_btrfs_filesystem_info (device, error);
}


gboolean  bd_btrfs_mkfs_stub (const gchar **devices, const gchar *label, const gchar *data_level, const gchar *md_level, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_mkfs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_mkfs' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_mkfs) (const gchar **devices, const gchar *label, const gchar *data_level, const gchar *md_level, const BDExtraArg **extra, GError **error) = bd_btrfs_mkfs_stub;

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
 */
gboolean  bd_btrfs_mkfs (const gchar **devices, const gchar *label, const gchar *data_level, const gchar *md_level, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_mkfs (devices, label, data_level, md_level, extra, error);
}


gboolean  bd_btrfs_resize_stub (const gchar *mountpoint, guint64 size, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_resize) (const gchar *mountpoint, guint64 size, const BDExtraArg **extra, GError **error) = bd_btrfs_resize_stub;

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
 */
gboolean  bd_btrfs_resize (const gchar *mountpoint, guint64 size, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_resize (mountpoint, size, extra, error);
}


gboolean  bd_btrfs_check_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_check' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_check' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_check) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_btrfs_check_stub;

/**
 * bd_btrfs_check:
 * @device: a device that is part of the checked btrfs volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the check (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the filesystem was successfully checked or not
 */
gboolean  bd_btrfs_check (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_check (device, extra, error);
}


gboolean  bd_btrfs_repair_stub (const gchar *device, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_repair' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_repair' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_repair) (const gchar *device, const BDExtraArg **extra, GError **error) = bd_btrfs_repair_stub;

/**
 * bd_btrfs_repair:
 * @device: a device that is part of the to be repaired btrfs volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the repair (right now
 *                                                 passed to the 'btrfs' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the filesystem was successfully checked and repaired or not
 */
gboolean  bd_btrfs_repair (const gchar *device, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_repair (device, extra, error);
}


gboolean  bd_btrfs_change_label_stub (const gchar *mountpoint, const gchar *label, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_btrfs_change_label' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_btrfs_change_label' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_btrfs_change_label) (const gchar *mountpoint, const gchar *label, const BDExtraArg **extra, GError **error) = bd_btrfs_change_label_stub;

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
 */
gboolean  bd_btrfs_change_label (const gchar *mountpoint, const gchar *label, const BDExtraArg **extra, GError **error) {
    return _bd_btrfs_change_label (mountpoint, label, extra, error);
}


gpointer load_btrfs_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module btrfs: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_btrfs_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for btrfs: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_btrfs_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for btrfs: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_btrfs_create_volume) = dlsym(handle, "bd_btrfs_create_volume");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_create_volume: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_add_device) = dlsym(handle, "bd_btrfs_add_device");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_add_device: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_remove_device) = dlsym(handle, "bd_btrfs_remove_device");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_remove_device: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_create_subvolume) = dlsym(handle, "bd_btrfs_create_subvolume");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_create_subvolume: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_delete_subvolume) = dlsym(handle, "bd_btrfs_delete_subvolume");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_delete_subvolume: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_get_default_subvolume_id) = dlsym(handle, "bd_btrfs_get_default_subvolume_id");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_get_default_subvolume_id: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_set_default_subvolume) = dlsym(handle, "bd_btrfs_set_default_subvolume");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_set_default_subvolume: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_create_snapshot) = dlsym(handle, "bd_btrfs_create_snapshot");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_create_snapshot: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_list_devices) = dlsym(handle, "bd_btrfs_list_devices");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_list_devices: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_list_subvolumes) = dlsym(handle, "bd_btrfs_list_subvolumes");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_list_subvolumes: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_filesystem_info) = dlsym(handle, "bd_btrfs_filesystem_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_filesystem_info: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_mkfs) = dlsym(handle, "bd_btrfs_mkfs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_mkfs: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_resize) = dlsym(handle, "bd_btrfs_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_resize: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_check) = dlsym(handle, "bd_btrfs_check");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_check: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_repair) = dlsym(handle, "bd_btrfs_repair");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_repair: %s", error);

    dlerror();
    * (void**) (&_bd_btrfs_change_label) = dlsym(handle, "bd_btrfs_change_label");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_btrfs_change_label: %s", error);

    return handle;
}

gboolean unload_btrfs (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_btrfs_create_volume = bd_btrfs_create_volume_stub;
    _bd_btrfs_add_device = bd_btrfs_add_device_stub;
    _bd_btrfs_remove_device = bd_btrfs_remove_device_stub;
    _bd_btrfs_create_subvolume = bd_btrfs_create_subvolume_stub;
    _bd_btrfs_delete_subvolume = bd_btrfs_delete_subvolume_stub;
    _bd_btrfs_get_default_subvolume_id = bd_btrfs_get_default_subvolume_id_stub;
    _bd_btrfs_set_default_subvolume = bd_btrfs_set_default_subvolume_stub;
    _bd_btrfs_create_snapshot = bd_btrfs_create_snapshot_stub;
    _bd_btrfs_list_devices = bd_btrfs_list_devices_stub;
    _bd_btrfs_list_subvolumes = bd_btrfs_list_subvolumes_stub;
    _bd_btrfs_filesystem_info = bd_btrfs_filesystem_info_stub;
    _bd_btrfs_mkfs = bd_btrfs_mkfs_stub;
    _bd_btrfs_resize = bd_btrfs_resize_stub;
    _bd_btrfs_check = bd_btrfs_check_stub;
    _bd_btrfs_repair = bd_btrfs_repair_stub;
    _bd_btrfs_change_label = bd_btrfs_change_label_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_btrfs_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for btrfs: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

