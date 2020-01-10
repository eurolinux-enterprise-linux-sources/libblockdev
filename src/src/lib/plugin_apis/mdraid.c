GQuark  bd_md_error_quark (void) {
        return g_quark_from_static_string ("g-bd-md-error-quark");
}

/**
 * BDMDExamineData:
 * @device: path of the MD device
 * @level: RAID level of the device
 * @num_devices: number of devices used by the MD device
 * @name: name of the MD device
 * @size: size of the MD device
 * @uuid: array UUID
 * @update_time: update time of the MD device
 * @dev_uuid: UUID of the member device
 * @events: number of events on the MD device
 * @metadata: version of the metadata used by the MD device
 * @chunk_size: chunk size used by the MD device
 */
/**
 * bd_md_examine_data_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDMDExamineData* bd_md_examine_data_copy (BDMDExamineData *data) {
        BDMDExamineData *new_data = g_new0 (BDMDExamineData, 1);

    new_data->device = g_strdup (data->device);
    new_data->level = g_strdup (data->level);
    new_data->num_devices = data->num_devices;
    new_data->name = g_strdup (data->name);
    new_data->size = data->size;
    new_data->uuid = g_strdup (data->uuid);
    new_data->update_time = data->update_time;
    new_data->dev_uuid = g_strdup (data->dev_uuid);
    new_data->events = data->events;
    new_data->metadata = g_strdup (data->metadata);
    new_data->chunk_size = data->chunk_size;
    return new_data;
}

/**
 * bd_md_examine_data_free: (skip)
 *
 * Frees @data.
 */
void  bd_md_examine_data_free (BDMDExamineData *data) {
        g_free (data->device);
    g_free (data->level);
    g_free (data->name);
    g_free (data->uuid);
    g_free (data->dev_uuid);
    g_free (data->metadata);
    g_free (data);
}

GType  bd_md_examine_data_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDMDExamineData",
                                            (GBoxedCopyFunc) bd_md_examine_data_copy,
                                            (GBoxedFreeFunc) bd_md_examine_data_free);
    }

    return type;
}

/**
 * BDMDDetailData:
 * @device: path of the device
 * @metadata: version of the metadata used by the device
 * @creation_time: creation time
 * @level: level of the MD RAID
 * @name: name of the MD device
 * @array_size: size of the MD array
 * @use_dev_size: size of the used space
 * @raid_devices: number of devices in the MD array
 * @total_devices: total number of devices in the MD array
 * @active_devices: number of active devices in the MD array
 * @working_devices: number of working devices in the MD array
 * @failed_devices: number of failed devices in the MD array
 * @spare_devices: number of spare devices in the MD array
 * @clean: whether the MD array is clean or not
 * @uuid: uuid of the MD array
 */
/**
 * bd_md_detail_data_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDMDDetailData* bd_md_detail_data_copy (BDMDDetailData *data) {
        BDMDDetailData *new_data = g_new0 (BDMDDetailData, 1);

    new_data->device = g_strdup (data->device);
    new_data->name = g_strdup (data->name);
    new_data->metadata = g_strdup (data->metadata);
    new_data->creation_time = g_strdup (data->creation_time);
    new_data->level = g_strdup (data->level);
    new_data->array_size = data->array_size;
    new_data->use_dev_size = data->use_dev_size;
    new_data->raid_devices = data->raid_devices;
    new_data->active_devices = data->active_devices;
    new_data->working_devices = data->working_devices;
    new_data->failed_devices = data->failed_devices;
    new_data->spare_devices = data->spare_devices;
    new_data->clean = data->clean;
    new_data->uuid = g_strdup (data->uuid);

    return new_data;
}

/**
 * bd_md_detail_data_free: (skip)
 *
 * Frees @data.
 */
void  bd_md_detail_data_free (BDMDDetailData *data) {
        g_free (data->device);
    g_free (data->name);
    g_free (data->metadata);
    g_free (data->creation_time);
    g_free (data->level);
    g_free (data->uuid);

    g_free (data);
}

GType  bd_md_detail_data_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDMDDetailData",
                                            (GBoxedCopyFunc) bd_md_detail_data_copy,
                                            (GBoxedFreeFunc) bd_md_detail_data_free);
    }

    return type;
}

static const gchar* const mdraid_functions[] = {
    "bd_md_is_tech_avail",
    "bd_md_get_superblock_size",
    "bd_md_create",
    "bd_md_destroy",
    "bd_md_deactivate",
    "bd_md_activate",
    "bd_md_run",
    "bd_md_nominate",
    "bd_md_denominate",
    "bd_md_add",
    "bd_md_remove",
    "bd_md_examine",
    "bd_md_detail",
    "bd_md_canonicalize_uuid",
    "bd_md_get_md_uuid",
    "bd_md_node_from_name",
    "bd_md_name_from_node",
    "bd_md_get_status",
    "bd_md_set_bitmap_location",
    "bd_md_get_bitmap_location",
    "bd_md_request_sync_action",
    NULL};

const gchar* const* get_mdraid_functions (void) {
    return mdraid_functions;
}

static const guint8 mdraid_num_functions = 21;

guint8 get_mdraid_num_functions (void) {
    return mdraid_num_functions;
}

gboolean  bd_md_is_tech_avail_stub (BDMDTech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_md_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_is_tech_avail) (BDMDTech tech, guint64 mode, GError **error) = bd_md_is_tech_avail_stub;

/**
 * bd_md_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_md_is_tech_avail (BDMDTech tech, guint64 mode, GError **error) {
    return _bd_md_is_tech_avail (tech, mode, error);
}


guint64  bd_md_get_superblock_size_stub (guint64 member_size, const gchar *version, GError **error) {
    g_critical ("The function 'bd_md_get_superblock_size' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_get_superblock_size' called, but not implemented!");
    return 0;
}

guint64  (*_bd_md_get_superblock_size) (guint64 member_size, const gchar *version, GError **error) = bd_md_get_superblock_size_stub;

/**
 * bd_md_get_superblock_size:
 * @member_size: size of an array member
 * @version: (allow-none): metadata version or %NULL to use the current default version
 * @error: (out): place to store error (if any)
 *
 * Returns: Calculated superblock size for an array with a given @member_size
 * and metadata @version or default if unsupported @version is used.
 *
 * Tech category: always available
 */
guint64  bd_md_get_superblock_size (guint64 member_size, const gchar *version, GError **error) {
    return _bd_md_get_superblock_size (member_size, version, error);
}


gboolean  bd_md_create_stub (const gchar *device_name, const gchar *level, const gchar **disks, guint64 spares, const gchar *version, gboolean bitmap, guint64 chunk_size, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_md_create' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_create' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_create) (const gchar *device_name, const gchar *level, const gchar **disks, guint64 spares, const gchar *version, gboolean bitmap, guint64 chunk_size, const BDExtraArg **extra, GError **error) = bd_md_create_stub;

/**
 * bd_md_create:
 * @device_name: name of the device to create
 * @level: RAID level (as understood by mdadm, see mdadm(8))
 * @disks: (array zero-terminated=1): disks to use for the new RAID (including spares)
 * @spares: number of spare devices
 * @version: (allow-none): metadata version
 * @bitmap: whether to create an internal bitmap on the device or not
 * @chunk_size: chunk size of the device to create
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mdadm' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the new MD RAID device @device_name was successfully created or not
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_CREATE
 */
gboolean  bd_md_create (const gchar *device_name, const gchar *level, const gchar **disks, guint64 spares, const gchar *version, gboolean bitmap, guint64 chunk_size, const BDExtraArg **extra, GError **error) {
    return _bd_md_create (device_name, level, disks, spares, version, bitmap, chunk_size, extra, error);
}


gboolean  bd_md_destroy_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_md_destroy' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_destroy' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_destroy) (const gchar *device, GError **error) = bd_md_destroy_stub;

/**
 * bd_md_destroy:
 * @device: device to destroy MD RAID metadata on
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the MD RAID metadata was successfully destroyed on @device or not
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_DELETE
 */
gboolean  bd_md_destroy (const gchar *device, GError **error) {
    return _bd_md_destroy (device, error);
}


gboolean  bd_md_deactivate_stub (const gchar *raid_spec, GError **error) {
    g_critical ("The function 'bd_md_deactivate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_deactivate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_deactivate) (const gchar *raid_spec, GError **error) = bd_md_deactivate_stub;

/**
 * bd_md_deactivate:
 * @raid_spec: specification of the RAID device (name, node or path)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the RAID device @raid_spec was successfully deactivated or not
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_deactivate (const gchar *raid_spec, GError **error) {
    return _bd_md_deactivate (raid_spec, error);
}


gboolean  bd_md_activate_stub (const gchar *raid_spec, const gchar **members, const gchar *uuid, gboolean start_degraded, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_md_activate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_activate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_activate) (const gchar *raid_spec, const gchar **members, const gchar *uuid, gboolean start_degraded, const BDExtraArg **extra, GError **error) = bd_md_activate_stub;

/**
 * bd_md_activate:
 * @raid_spec: (allow-none): specification of the RAID device (name, node or path) to activate (if not given "--scan" is implied and @members is ignored)
 * @members: (allow-none) (array zero-terminated=1): member devices to be considered for @device activation
 * @uuid: (allow-none): UUID (in the MD RAID format!) of the MD RAID to activate
 * @start_degraded: whether to start the array even if it's degraded
 * @extra: (allow-none) (array zero-terminated=1): extra options for the activation (right now
 *                                                 passed to the 'mdadm' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the MD RAID @device was successfully activated or not
 *
 * Note: either @members or @uuid (or both) have to be specified.
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_activate (const gchar *raid_spec, const gchar **members, const gchar *uuid, gboolean start_degraded, const BDExtraArg **extra, GError **error) {
    return _bd_md_activate (raid_spec, members, uuid, start_degraded, extra, error);
}


gboolean  bd_md_run_stub (const gchar *raid_spec, GError **error) {
    g_critical ("The function 'bd_md_run' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_run' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_run) (const gchar *raid_spec, GError **error) = bd_md_run_stub;

/**
 * bd_md_run:
 * @raid_spec: specification of the (possibly degraded) RAID device (name, node or path) to be started
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @raid_spec was successfully started or not
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_run (const gchar *raid_spec, GError **error) {
    return _bd_md_run (raid_spec, error);
}


gboolean  bd_md_nominate_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_md_nominate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_nominate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_nominate) (const gchar *device, GError **error) = bd_md_nominate_stub;

/**
 * bd_md_nominate:
 * @device: device to nominate (add to its appropriate RAID) as a MD RAID device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully nominated (added to its
 * appropriate RAID) or not
 *
 * Note: may start the MD RAID if it becomes ready by adding @device.
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_nominate (const gchar *device, GError **error) {
    return _bd_md_nominate (device, error);
}


gboolean  bd_md_denominate_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_md_denominate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_denominate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_denominate) (const gchar *device, GError **error) = bd_md_denominate_stub;

/**
 * bd_md_denominate:
 * @device: device to denominate (remove from its appropriate RAID) as a MD RAID device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully denominated (added to its
 * appropriate RAID) or not
 *
 * Note: may start the MD RAID if it becomes ready by adding @device.
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_denominate (const gchar *device, GError **error) {
    return _bd_md_denominate (device, error);
}


gboolean  bd_md_add_stub (const gchar *raid_spec, const gchar *device, guint64 raid_devs, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_md_add' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_add' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_add) (const gchar *raid_spec, const gchar *device, guint64 raid_devs, const BDExtraArg **extra, GError **error) = bd_md_add_stub;

/**
 * bd_md_add:
 * @raid_spec: specification of the RAID device (name, node or path) to add @device into
 * @device: name of the device to add to the @raid_spec RAID device
 * @raid_devs: number of devices the @raid_spec RAID should actively use or 0
 *             to leave unspecified (see below)
 * @extra: (allow-none) (array zero-terminated=1): extra options for the addition (right now
 *                                                 passed to the 'mdadm' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully added to the @raid_spec RAID or
 * not
 *
 * The @raid_devs parameter is used when adding devices to a raid array that has
 * no actual redundancy. In this case it is necessary to explicitly grow the
 * array all at once rather than manage it in the sense of adding spares.
 *
 * Whether the new device will be added as a spare or an active member is
 * decided by mdadm.
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_add (const gchar *raid_spec, const gchar *device, guint64 raid_devs, const BDExtraArg **extra, GError **error) {
    return _bd_md_add (raid_spec, device, raid_devs, extra, error);
}


gboolean  bd_md_remove_stub (const gchar *raid_spec, const gchar *device, gboolean fail, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_md_remove' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_remove' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_remove) (const gchar *raid_spec, const gchar *device, gboolean fail, const BDExtraArg **extra, GError **error) = bd_md_remove_stub;

/**
 * bd_md_remove:
 * @raid_spec: specification of the RAID device (name, node or path) to remove @device from
 * @device: device to remove from the @raid_spec RAID
 * @fail: whether to mark the @device as failed before removing
 * @extra: (allow-none) (array zero-terminated=1): extra options for the removal (right now
 *                                                 passed to the 'mdadm' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully removed from the @raid_spec
 * RAID or not.
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_remove (const gchar *raid_spec, const gchar *device, gboolean fail, const BDExtraArg **extra, GError **error) {
    return _bd_md_remove (raid_spec, device, fail, extra, error);
}


BDMDExamineData* bd_md_examine_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_md_examine' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_examine' called, but not implemented!");
    return NULL;
}

BDMDExamineData* (*_bd_md_examine) (const gchar *device, GError **error) = bd_md_examine_stub;

/**
 * bd_md_examine:
 * @device: name of the device (a member of an MD RAID) to examine
 * @error: (out): place to store error (if any)
 *
 * Returns: information about the MD RAID extracted from the @device
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_QUERY
 */
BDMDExamineData* bd_md_examine (const gchar *device, GError **error) {
    return _bd_md_examine (device, error);
}


BDMDDetailData* bd_md_detail_stub (const gchar *raid_spec, GError **error) {
    g_critical ("The function 'bd_md_detail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_detail' called, but not implemented!");
    return NULL;
}

BDMDDetailData* (*_bd_md_detail) (const gchar *raid_spec, GError **error) = bd_md_detail_stub;

/**
 * bd_md_detail:
 * @raid_spec: specification of the RAID device (name, node or path) to examine
 * @error: (out): place to store error (if any)
 *
 * Returns: information about the MD RAID @raid_spec
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_QUERY
 */
BDMDDetailData* bd_md_detail (const gchar *raid_spec, GError **error) {
    return _bd_md_detail (raid_spec, error);
}


gchar* bd_md_canonicalize_uuid_stub (const gchar *uuid, GError **error) {
    g_critical ("The function 'bd_md_canonicalize_uuid' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_canonicalize_uuid' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_md_canonicalize_uuid) (const gchar *uuid, GError **error) = bd_md_canonicalize_uuid_stub;

/**
 * bd_md_canonicalize_uuid:
 * @uuid: UUID to canonicalize
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): cannonicalized form of @uuid
 *
 * This function expects a UUID in the form that mdadm returns. The change is as
 * follows: 3386ff85:f5012621:4a435f06:1eb47236 -> 3386ff85-f501-2621-4a43-5f061eb47236
 *
 * Tech category: always available
 */
gchar* bd_md_canonicalize_uuid (const gchar *uuid, GError **error) {
    return _bd_md_canonicalize_uuid (uuid, error);
}


gchar* bd_md_get_md_uuid_stub (const gchar *uuid, GError **error) {
    g_critical ("The function 'bd_md_get_md_uuid' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_get_md_uuid' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_md_get_md_uuid) (const gchar *uuid, GError **error) = bd_md_get_md_uuid_stub;

/**
 * bd_md_get_md_uuid:
 * @uuid: UUID to transform into format used by MD RAID
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): transformed form of @uuid
 *
 * This function expects a UUID in the canonical (traditional format) and
 * returns a UUID in the format used by MD RAID and is thus reverse to
 * bd_md_canonicalize_uuid(). The change is as follows:
 * 3386ff85-f501-2621-4a43-5f061eb47236 -> 3386ff85:f5012621:4a435f06:1eb47236
 *
 * Tech category: always available
 */
gchar* bd_md_get_md_uuid (const gchar *uuid, GError **error) {
    return _bd_md_get_md_uuid (uuid, error);
}


gchar* bd_md_node_from_name_stub (const gchar *name, GError **error) {
    g_critical ("The function 'bd_md_node_from_name' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_node_from_name' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_md_node_from_name) (const gchar *name, GError **error) = bd_md_node_from_name_stub;

/**
 * bd_md_node_from_name:
 * @name: name of the MD RAID
 * @error: (out): place to store error (if any)
 *
 * Returns: device node of the @name MD RAID or %NULL in case of error
 *
 * Tech category: always available
 */
gchar* bd_md_node_from_name (const gchar *name, GError **error) {
    return _bd_md_node_from_name (name, error);
}


gchar* bd_md_name_from_node_stub (const gchar *node, GError **error) {
    g_critical ("The function 'bd_md_name_from_node' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_name_from_node' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_md_name_from_node) (const gchar *node, GError **error) = bd_md_name_from_node_stub;

/**
 * bd_md_name_from_node:
 * @node: path of the MD RAID's device node
 * @error: (out): place to store error (if any)
 *
 * Returns: @name of the MD RAID the device node belongs to or %NULL in case of error
 *
 * Tech category: always available
 */
gchar* bd_md_name_from_node (const gchar *node, GError **error) {
    return _bd_md_name_from_node (node, error);
}


gchar* bd_md_get_status_stub (const gchar *raid_spec, GError **error) {
    g_critical ("The function 'bd_md_get_status' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_get_status' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_md_get_status) (const gchar *raid_spec, GError **error) = bd_md_get_status_stub;

/**
 * bd_md_get_status
 * @raid_spec: specification of the RAID device (name, node or path) to get status
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): status of the @raid_spec RAID.
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_QUERY
 */
gchar* bd_md_get_status (const gchar *raid_spec, GError **error) {
    return _bd_md_get_status (raid_spec, error);
}


gboolean  bd_md_set_bitmap_location_stub (const gchar *raid_spec, const gchar *location, GError **error) {
    g_critical ("The function 'bd_md_set_bitmap_location' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_set_bitmap_location' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_set_bitmap_location) (const gchar *raid_spec, const gchar *location, GError **error) = bd_md_set_bitmap_location_stub;

/**
 * bd_md_set_bitmap_location:
 * @raid_spec: specification of the RAID device (name, node or path) to set the bitmap location
 * @location: bitmap location (none, internal or path)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether @location was successfully set for @raid_spec
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_set_bitmap_location (const gchar *raid_spec, const gchar *location, GError **error) {
    return _bd_md_set_bitmap_location (raid_spec, location, error);
}


gchar* bd_md_get_bitmap_location_stub (const gchar *raid_spec, GError **error) {
    g_critical ("The function 'bd_md_get_bitmap_location' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_get_bitmap_location' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_md_get_bitmap_location) (const gchar *raid_spec, GError **error) = bd_md_get_bitmap_location_stub;

/**
 * bd_md_get_bitmap_location:
 * @raid_spec: specification of the RAID device (name, node or path) to get the bitmap location
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): bitmap location for @raid_spec
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_QUERY
 */
gchar* bd_md_get_bitmap_location (const gchar *raid_spec, GError **error) {
    return _bd_md_get_bitmap_location (raid_spec, error);
}


gboolean  bd_md_request_sync_action_stub (const gchar *raid_spec, const gchar *action, GError **error) {
    g_critical ("The function 'bd_md_request_sync_action' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_md_request_sync_action' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_md_request_sync_action) (const gchar *raid_spec, const gchar *action, GError **error) = bd_md_request_sync_action_stub;

/**
 * bd_md_request_sync_action:
 * @raid_spec: specification of the RAID device (name, node or path) to request sync action on
 * @action: requested sync action (resync, recovery, check, repair or idle)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @action was successfully requested for the @raid_spec
 * RAID or not.
 *
 * Tech category: %BD_MD_TECH_MDRAID-%BD_MD_TECH_MODE_MODIFY
 */
gboolean  bd_md_request_sync_action (const gchar *raid_spec, const gchar *action, GError **error) {
    return _bd_md_request_sync_action (raid_spec, action, error);
}


gpointer load_mdraid_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module mdraid: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_md_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for mdraid: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_md_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for mdraid: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_md_is_tech_avail) = dlsym(handle, "bd_md_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_md_get_superblock_size) = dlsym(handle, "bd_md_get_superblock_size");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_get_superblock_size: %s", error);

    dlerror();
    * (void**) (&_bd_md_create) = dlsym(handle, "bd_md_create");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_create: %s", error);

    dlerror();
    * (void**) (&_bd_md_destroy) = dlsym(handle, "bd_md_destroy");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_destroy: %s", error);

    dlerror();
    * (void**) (&_bd_md_deactivate) = dlsym(handle, "bd_md_deactivate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_deactivate: %s", error);

    dlerror();
    * (void**) (&_bd_md_activate) = dlsym(handle, "bd_md_activate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_activate: %s", error);

    dlerror();
    * (void**) (&_bd_md_run) = dlsym(handle, "bd_md_run");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_run: %s", error);

    dlerror();
    * (void**) (&_bd_md_nominate) = dlsym(handle, "bd_md_nominate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_nominate: %s", error);

    dlerror();
    * (void**) (&_bd_md_denominate) = dlsym(handle, "bd_md_denominate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_denominate: %s", error);

    dlerror();
    * (void**) (&_bd_md_add) = dlsym(handle, "bd_md_add");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_add: %s", error);

    dlerror();
    * (void**) (&_bd_md_remove) = dlsym(handle, "bd_md_remove");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_remove: %s", error);

    dlerror();
    * (void**) (&_bd_md_examine) = dlsym(handle, "bd_md_examine");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_examine: %s", error);

    dlerror();
    * (void**) (&_bd_md_detail) = dlsym(handle, "bd_md_detail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_detail: %s", error);

    dlerror();
    * (void**) (&_bd_md_canonicalize_uuid) = dlsym(handle, "bd_md_canonicalize_uuid");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_canonicalize_uuid: %s", error);

    dlerror();
    * (void**) (&_bd_md_get_md_uuid) = dlsym(handle, "bd_md_get_md_uuid");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_get_md_uuid: %s", error);

    dlerror();
    * (void**) (&_bd_md_node_from_name) = dlsym(handle, "bd_md_node_from_name");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_node_from_name: %s", error);

    dlerror();
    * (void**) (&_bd_md_name_from_node) = dlsym(handle, "bd_md_name_from_node");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_name_from_node: %s", error);

    dlerror();
    * (void**) (&_bd_md_get_status) = dlsym(handle, "bd_md_get_status");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_get_status: %s", error);

    dlerror();
    * (void**) (&_bd_md_set_bitmap_location) = dlsym(handle, "bd_md_set_bitmap_location");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_set_bitmap_location: %s", error);

    dlerror();
    * (void**) (&_bd_md_get_bitmap_location) = dlsym(handle, "bd_md_get_bitmap_location");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_get_bitmap_location: %s", error);

    dlerror();
    * (void**) (&_bd_md_request_sync_action) = dlsym(handle, "bd_md_request_sync_action");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_md_request_sync_action: %s", error);

    return handle;
}

gboolean unload_mdraid (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_md_is_tech_avail = bd_md_is_tech_avail_stub;
    _bd_md_get_superblock_size = bd_md_get_superblock_size_stub;
    _bd_md_create = bd_md_create_stub;
    _bd_md_destroy = bd_md_destroy_stub;
    _bd_md_deactivate = bd_md_deactivate_stub;
    _bd_md_activate = bd_md_activate_stub;
    _bd_md_run = bd_md_run_stub;
    _bd_md_nominate = bd_md_nominate_stub;
    _bd_md_denominate = bd_md_denominate_stub;
    _bd_md_add = bd_md_add_stub;
    _bd_md_remove = bd_md_remove_stub;
    _bd_md_examine = bd_md_examine_stub;
    _bd_md_detail = bd_md_detail_stub;
    _bd_md_canonicalize_uuid = bd_md_canonicalize_uuid_stub;
    _bd_md_get_md_uuid = bd_md_get_md_uuid_stub;
    _bd_md_node_from_name = bd_md_node_from_name_stub;
    _bd_md_name_from_node = bd_md_name_from_node_stub;
    _bd_md_get_status = bd_md_get_status_stub;
    _bd_md_set_bitmap_location = bd_md_set_bitmap_location_stub;
    _bd_md_get_bitmap_location = bd_md_get_bitmap_location_stub;
    _bd_md_request_sync_action = bd_md_request_sync_action_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_md_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for mdraid: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

