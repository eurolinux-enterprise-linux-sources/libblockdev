GQuark  bd_part_error_quark (void) {
        return g_quark_from_static_string ("g-bd-part-error-quark");
}

/**
 * BDPartSpec:
 * @path: path of the partition (block device)
 * @name: name of the partition (for GPT partitions)
 * @type_guid: GUID of the partition's type (GPT)
 * @type: bit combination of partition's types (#BDPartType)
 * @start: start of the partition
 * @size: size of the partition
 * @flags: bit combination of partition's flags (#BDPartFlag)
 */
BDPartSpec* bd_part_spec_copy (BDPartSpec *data) {
        BDPartSpec *ret = g_new0 (BDPartSpec, 1);

    ret->path = g_strdup (data->path);
    ret->name = g_strdup (data->name);
    ret->type_guid = g_strdup (data->type_guid);
    ret->type = data->type;
    ret->start = data->start;
    ret->size = data->size;

    return ret;
}

void  bd_part_spec_free (BDPartSpec *data) {
        g_free (data->path);
    g_free (data->name);
    g_free (data->type_guid);
    g_free (data);
}

GType  bd_part_spec_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDPartSpec",
                                            (GBoxedCopyFunc) bd_part_spec_copy,
                                            (GBoxedFreeFunc) bd_part_spec_free);
    }

    return type;
}

/**
 * BDPartDiskSpec:
 * @path: path of the disk (block device)
 * @table_type: type of the disk's partition table
 * @size: size of the disk
 * @sector_size: disk's sector size
 * @flags: bit combination of the disk's flags (#BDPartDiskFlag)
 */
BDPartDiskSpec* bd_part_disk_spec_copy (BDPartDiskSpec *data) {
        BDPartDiskSpec *ret = g_new0 (BDPartDiskSpec, 1);

    ret->path = g_strdup (data->path);
    ret->table_type = data->table_type;
    ret->size = data->size;
    ret->sector_size = data->sector_size;
    ret->flags = data->flags;

    return ret;
}

void  bd_part_disk_spec_free (BDPartDiskSpec *data) {
        g_free (data->path);
    g_free (data);
}

GType  bd_part_disk_spec_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDPartDiskSpec",
                                            (GBoxedCopyFunc) bd_part_disk_spec_copy,
                                            (GBoxedFreeFunc) bd_part_disk_spec_free);
    }

    return type;
}

static const gchar* const part_functions[] = {
    "bd_part_is_tech_avail",
    "bd_part_create_table",
    "bd_part_get_part_spec",
    "bd_part_get_part_by_pos",
    "bd_part_get_disk_spec",
    "bd_part_get_disk_parts",
    "bd_part_get_disk_free_regions",
    "bd_part_get_best_free_region",
    "bd_part_create_part",
    "bd_part_delete_part",
    "bd_part_resize_part",
    "bd_part_set_part_flag",
    "bd_part_set_disk_flag",
    "bd_part_set_part_flags",
    "bd_part_set_part_name",
    "bd_part_set_part_type",
    "bd_part_set_part_id",
    "bd_part_get_part_id",
    "bd_part_get_part_table_type_str",
    "bd_part_get_flag_str",
    "bd_part_get_type_str",
    NULL};

const gchar* const* get_part_functions (void) {
    return part_functions;
}

static const guint8 part_num_functions = 21;

guint8 get_part_num_functions (void) {
    return part_num_functions;
}

gboolean  bd_part_is_tech_avail_stub (BDPartTech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_part_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_is_tech_avail) (BDPartTech tech, guint64 mode, GError **error) = bd_part_is_tech_avail_stub;

/**
 * bd_part_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDPartTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_part_is_tech_avail (BDPartTech tech, guint64 mode, GError **error) {
    return _bd_part_is_tech_avail (tech, mode, error);
}


gboolean  bd_part_create_table_stub (const gchar *disk, BDPartTableType type, gboolean ignore_existing, GError **error) {
    g_critical ("The function 'bd_part_create_table' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_create_table' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_create_table) (const gchar *disk, BDPartTableType type, gboolean ignore_existing, GError **error) = bd_part_create_table_stub;

/**
 * bd_part_create_table:
 * @disk: path of the disk block device to create partition table on
 * @type: type of the partition table to create
 * @ignore_existing: whether to ignore/overwrite the existing table or not
 *                   (reports an error if %FALSE and there's some table on @disk)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the partition table was successfully created or not
 *
 * Tech category: %BD_PART_TECH_MODE_CREATE_TABLE + the tech according to @type
 */
gboolean  bd_part_create_table (const gchar *disk, BDPartTableType type, gboolean ignore_existing, GError **error) {
    return _bd_part_create_table (disk, type, ignore_existing, error);
}


BDPartSpec* bd_part_get_part_spec_stub (const gchar *disk, const gchar *part, GError **error) {
    g_critical ("The function 'bd_part_get_part_spec' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_part_spec' called, but not implemented!");
    return NULL;
}

BDPartSpec* (*_bd_part_get_part_spec) (const gchar *disk, const gchar *part, GError **error) = bd_part_get_part_spec_stub;

/**
 * bd_part_get_part_spec:
 * @disk: disk to remove the partition from
 * @part: partition to get spec for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): spec of the @part partition from @disk or %NULL in case of error
 *
 * Tech category: %BD_PART_TECH_MODE_QUERY_PART + the tech according to the partition table type
 */
BDPartSpec* bd_part_get_part_spec (const gchar *disk, const gchar *part, GError **error) {
    return _bd_part_get_part_spec (disk, part, error);
}


BDPartSpec* bd_part_get_part_by_pos_stub (const gchar *disk, guint64 position, GError **error) {
    g_critical ("The function 'bd_part_get_part_by_pos' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_part_by_pos' called, but not implemented!");
    return NULL;
}

BDPartSpec* (*_bd_part_get_part_by_pos) (const gchar *disk, guint64 position, GError **error) = bd_part_get_part_by_pos_stub;

/**
 * bd_part_get_part_by_pos:
 * @disk: disk to remove the partition from
 * @position: position (in bytes) determining the partition
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): spec of the partition from @disk spanning over the @position or %NULL if no such
 *          partition exists or in case of error (@error is set)
 *
 * Tech category: %BD_PART_TECH_MODE_QUERY_PART + the tech according to the partition table type
 */
BDPartSpec* bd_part_get_part_by_pos (const gchar *disk, guint64 position, GError **error) {
    return _bd_part_get_part_by_pos (disk, position, error);
}


BDPartDiskSpec* bd_part_get_disk_spec_stub (const gchar *disk, GError **error) {
    g_critical ("The function 'bd_part_get_disk_spec' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_disk_spec' called, but not implemented!");
    return NULL;
}

BDPartDiskSpec* (*_bd_part_get_disk_spec) (const gchar *disk, GError **error) = bd_part_get_disk_spec_stub;

/**
 * bd_part_get_disk_spec:
 * @disk: disk to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the given @disk or %NULL (in case of error)
 *
 * Tech category: %BD_PART_TECH_MODE_QUERY_TABLE + the tech according to the partition table type
 */
BDPartDiskSpec* bd_part_get_disk_spec (const gchar *disk, GError **error) {
    return _bd_part_get_disk_spec (disk, error);
}


BDPartSpec** bd_part_get_disk_parts_stub (const gchar *disk, GError **error) {
    g_critical ("The function 'bd_part_get_disk_parts' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_disk_parts' called, but not implemented!");
    return NULL;
}

BDPartSpec** (*_bd_part_get_disk_parts) (const gchar *disk, GError **error) = bd_part_get_disk_parts_stub;

/**
 * bd_part_get_disk_parts:
 * @disk: disk to get information about partitions for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full) (array zero-terminated=1): specs of the partitions from @disk or %NULL in case of error
 *
 * Tech category: %BD_PART_TECH_MODE_QUERY_TABLE + the tech according to the partition table type
 */
BDPartSpec** bd_part_get_disk_parts (const gchar *disk, GError **error) {
    return _bd_part_get_disk_parts (disk, error);
}


BDPartSpec** bd_part_get_disk_free_regions_stub (const gchar *disk, GError **error) {
    g_critical ("The function 'bd_part_get_disk_free_regions' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_disk_free_regions' called, but not implemented!");
    return NULL;
}

BDPartSpec** (*_bd_part_get_disk_free_regions) (const gchar *disk, GError **error) = bd_part_get_disk_free_regions_stub;

/**
 * bd_part_get_disk_free_regions:
 * @disk: disk to get free regions for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full) (array zero-terminated=1): specs of the free regions from @disk or %NULL in case of error
 *
 * Tech category: %BD_PART_TECH_MODE_QUERY_TABLE + the tech according to the partition table type
 */
BDPartSpec** bd_part_get_disk_free_regions (const gchar *disk, GError **error) {
    return _bd_part_get_disk_free_regions (disk, error);
}


BDPartSpec* bd_part_get_best_free_region_stub (const gchar *disk, BDPartType type, guint64 size, GError **error) {
    g_critical ("The function 'bd_part_get_best_free_region' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_best_free_region' called, but not implemented!");
    return NULL;
}

BDPartSpec* (*_bd_part_get_best_free_region) (const gchar *disk, BDPartType type, guint64 size, GError **error) = bd_part_get_best_free_region_stub;

/**
 * bd_part_get_best_free_region:
 * @disk: disk to get the best free region for
 * @type: type of the partition that is planned to be added
 * @size: size of the partition to be added
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): spec of the best free region on @disk for a new partition of type @type
 *                           with the size of @size or %NULL if there is none such region or if
 *                           there was an error (@error gets populated)
 *
 * Note: For the @type %BD_PART_TYPE_NORMAL, the smallest possible space that *is not* in an extended partition
 *       is found. For the @type %BD_PART_TYPE_LOGICAL, the smallest possible space that *is* in an extended
 *       partition is found. For %BD_PART_TYPE_EXTENDED, the biggest possible space is found as long as there
 *       is no other extended partition (there can only be one).
 *
 * Tech category: %BD_PART_TECH_MODE_QUERY_TABLE + the tech according to the partition table type
 */
BDPartSpec* bd_part_get_best_free_region (const gchar *disk, BDPartType type, guint64 size, GError **error) {
    return _bd_part_get_best_free_region (disk, type, size, error);
}


BDPartSpec* bd_part_create_part_stub (const gchar *disk, BDPartTypeReq type, guint64 start, guint64 size, BDPartAlign align, GError **error) {
    g_critical ("The function 'bd_part_create_part' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_create_part' called, but not implemented!");
    return NULL;
}

BDPartSpec* (*_bd_part_create_part) (const gchar *disk, BDPartTypeReq type, guint64 start, guint64 size, BDPartAlign align, GError **error) = bd_part_create_part_stub;

/**
 * bd_part_create_part:
 * @disk: disk to create partition on
 * @type: type of the partition to create (if %BD_PART_TYPE_REQ_NEXT, the
 *        partition type will be determined automatically based on the existing
 *        partitions)
 * @start: where the partition should start (i.e. offset from the disk start)
 * @size: desired size of the partition (if 0, a max-sized partition is created)
 * @align: alignment to use for the partition
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): specification of the created partition or %NULL in case of error
 *
 * NOTE: The resulting partition may start at a different position than given by
 *       @start and can have different size than @size due to alignment.
 *
 * Tech category: %BD_PART_TECH_MODE_MODIFY_TABLE + the tech according to the partition table type
 */
BDPartSpec* bd_part_create_part (const gchar *disk, BDPartTypeReq type, guint64 start, guint64 size, BDPartAlign align, GError **error) {
    return _bd_part_create_part (disk, type, start, size, align, error);
}


gboolean  bd_part_delete_part_stub (const gchar *disk, const gchar *part, GError **error) {
    g_critical ("The function 'bd_part_delete_part' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_delete_part' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_delete_part) (const gchar *disk, const gchar *part, GError **error) = bd_part_delete_part_stub;

/**
 * bd_part_delete_part:
 * @disk: disk to remove the partition from
 * @part: partition to remove
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @part partition was successfully deleted from @disk
 *
 * Tech category: %BD_PART_TECH_MODE_MODIFY_TABLE + the tech according to the partition table type
 */
gboolean  bd_part_delete_part (const gchar *disk, const gchar *part, GError **error) {
    return _bd_part_delete_part (disk, part, error);
}


gboolean  bd_part_resize_part_stub (const gchar *disk, const gchar *part, guint64 size, BDPartAlign align, GError **error) {
    g_critical ("The function 'bd_part_resize_part' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_resize_part' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_resize_part) (const gchar *disk, const gchar *part, guint64 size, BDPartAlign align, GError **error) = bd_part_resize_part_stub;

/**
 * bd_part_resize_part:
 * @disk: disk containing the paritition
 * @part: partition to resize
 * @size: new partition size, 0 for maximal size
 * @align: alignment to use for the partition end
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @part partition was successfully resized on @disk to @size
 *
 * NOTE: The resulting partition may be slightly bigger than requested due to alignment.
 *
 * Tech category: %BD_PART_TECH_MODE_MODIFY_TABLE + the tech according to the partition table type
 */
gboolean  bd_part_resize_part (const gchar *disk, const gchar *part, guint64 size, BDPartAlign align, GError **error) {
    return _bd_part_resize_part (disk, part, size, align, error);
}


gboolean  bd_part_set_part_flag_stub (const gchar *disk, const gchar *part, BDPartFlag flag, gboolean state, GError **error) {
    g_critical ("The function 'bd_part_set_part_flag' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_set_part_flag' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_set_part_flag) (const gchar *disk, const gchar *part, BDPartFlag flag, gboolean state, GError **error) = bd_part_set_part_flag_stub;

/**
 * bd_part_set_part_flag:
 * @disk: disk the partition belongs to
 * @part: partition to set the flag on
 * @flag: flag to set
 * @state: state to set for the @flag (%TRUE = enabled)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the flag @flag was successfully set on the @part partition
 * or not.
 *
 * Tech category: %BD_PART_TECH_MODE_MODIFY_PART + the tech according to the partition table type
 */
gboolean  bd_part_set_part_flag (const gchar *disk, const gchar *part, BDPartFlag flag, gboolean state, GError **error) {
    return _bd_part_set_part_flag (disk, part, flag, state, error);
}


gboolean  bd_part_set_disk_flag_stub (const gchar *disk, BDPartDiskFlag flag, gboolean state, GError **error) {
    g_critical ("The function 'bd_part_set_disk_flag' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_set_disk_flag' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_set_disk_flag) (const gchar *disk, BDPartDiskFlag flag, gboolean state, GError **error) = bd_part_set_disk_flag_stub;

/**
 * bd_part_set_disk_flag:
 * @disk: disk the partition belongs to
 * @flag: flag to set
 * @state: state to set for the @flag (%TRUE = enabled)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the flag @flag was successfully set on the @disk or not
 *
 * Tech category: %BD_PART_TECH_MODE_MODIFY_TABLE + the tech according to the partition table type
 */
gboolean  bd_part_set_disk_flag (const gchar *disk, BDPartDiskFlag flag, gboolean state, GError **error) {
    return _bd_part_set_disk_flag (disk, flag, state, error);
}


gboolean  bd_part_set_part_flags_stub (const gchar *disk, const gchar *part, guint64 flags, GError **error) {
    g_critical ("The function 'bd_part_set_part_flags' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_set_part_flags' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_set_part_flags) (const gchar *disk, const gchar *part, guint64 flags, GError **error) = bd_part_set_part_flags_stub;

/**
 * bd_part_set_part_flags:
 * @disk: disk the partition belongs to
 * @part: partition to set the flag on
 * @flags: flags to set (mask combined from #BDPartFlag numbers)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @flags were successfully set on the @part partition or
 *          not
 *
 * Note: Unsets all the other flags on the partition.
 *       Only GPT-specific flags and the legacy boot flag are supported on GPT
 *       partition tables.
 *
 * Tech category: %BD_PART_TECH_MODE_MODIFY_PART + the tech according to the partition table type
 */
gboolean  bd_part_set_part_flags (const gchar *disk, const gchar *part, guint64 flags, GError **error) {
    return _bd_part_set_part_flags (disk, part, flags, error);
}


gboolean  bd_part_set_part_name_stub (const gchar *disk, const gchar *part, const gchar *name, GError **error) {
    g_critical ("The function 'bd_part_set_part_name' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_set_part_name' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_set_part_name) (const gchar *disk, const gchar *part, const gchar *name, GError **error) = bd_part_set_part_name_stub;

/**
 * bd_part_set_part_name:
 * @disk: device the partition belongs to
 * @part: partition the should be set for
 * @name: name to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the name was successfully set or not
 *
 * Tech category: %BD_PART_TECH_GPT-%BD_PART_TECH_MODE_MODIFY_PART
 */
gboolean  bd_part_set_part_name (const gchar *disk, const gchar *part, const gchar *name, GError **error) {
    return _bd_part_set_part_name (disk, part, name, error);
}


gboolean  bd_part_set_part_type_stub (const gchar *disk, const gchar *part, const gchar *type_guid, GError **error) {
    g_critical ("The function 'bd_part_set_part_type' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_set_part_type' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_set_part_type) (const gchar *disk, const gchar *part, const gchar *type_guid, GError **error) = bd_part_set_part_type_stub;

/**
 * bd_part_set_part_type:
 * @disk: device the partition belongs to
 * @part: partition the should be set for
 * @type_guid: GUID of the type
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @type_guid type was successfully set for @part or not
 *
 * Tech category: %BD_PART_TECH_GPT-%BD_PART_TECH_MODE_MODIFY_PART
 */
gboolean  bd_part_set_part_type (const gchar *disk, const gchar *part, const gchar *type_guid, GError **error) {
    return _bd_part_set_part_type (disk, part, type_guid, error);
}


gboolean  bd_part_set_part_id_stub (const gchar *disk, const gchar *part, const gchar *part_id, GError **error) {
    g_critical ("The function 'bd_part_set_part_id' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_set_part_id' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_part_set_part_id) (const gchar *disk, const gchar *part, const gchar *part_id, GError **error) = bd_part_set_part_id_stub;

/**
 * bd_part_set_part_id:
 * @disk: device the partition belongs to
 * @part: partition the should be set for
 * @part_id: partition Id
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @part_id type was successfully set for @part or not
 *
 * Tech category: %BD_PART_TECH_MODE_MODIFY_PART + the tech according to the partition table type
 */
gboolean  bd_part_set_part_id (const gchar *disk, const gchar *part, const gchar *part_id, GError **error) {
    return _bd_part_set_part_id (disk, part, part_id, error);
}


gchar* bd_part_get_part_id_stub (const gchar *disk, const gchar *part, GError **error) {
    g_critical ("The function 'bd_part_get_part_id' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_part_id' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_part_get_part_id) (const gchar *disk, const gchar *part, GError **error) = bd_part_get_part_id_stub;

/**
 * bd_part_get_part_id:
 * @disk: device the partition belongs to
 * @part: partition the should be set for
 * @error: (out): place to store error (if any)
 *
 * Returns (transfer full): partition id type or %NULL in case of error
 *
 * Tech category: %BD_PART_TECH_MODE_QUERY_PART + the tech according to the partition table type
 */
gchar* bd_part_get_part_id (const gchar *disk, const gchar *part, GError **error) {
    return _bd_part_get_part_id (disk, part, error);
}


const gchar* bd_part_get_part_table_type_str_stub (BDPartTableType type, GError **error) {
    g_critical ("The function 'bd_part_get_part_table_type_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_part_table_type_str' called, but not implemented!");
    return NULL;
}

const gchar* (*_bd_part_get_part_table_type_str) (BDPartTableType type, GError **error) = bd_part_get_part_table_type_str_stub;

/**
 * bd_part_get_part_table_type_str:
 * @type: table type to get string representation for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer none): string representation of @table_type
 *
 * Tech category: the tech according to @type
 */
const gchar* bd_part_get_part_table_type_str (BDPartTableType type, GError **error) {
    return _bd_part_get_part_table_type_str (type, error);
}


const gchar* bd_part_get_flag_str_stub (BDPartFlag flag, GError **error) {
    g_critical ("The function 'bd_part_get_flag_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_flag_str' called, but not implemented!");
    return NULL;
}

const gchar* (*_bd_part_get_flag_str) (BDPartFlag flag, GError **error) = bd_part_get_flag_str_stub;

/**
 * bd_part_get_flag_str:
 * @flag: flag to get string representation for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer none): string representation of @flag
 *
 * Tech category: always available
 */
const gchar* bd_part_get_flag_str (BDPartFlag flag, GError **error) {
    return _bd_part_get_flag_str (flag, error);
}


const gchar* bd_part_get_type_str_stub (BDPartType type, GError **error) {
    g_critical ("The function 'bd_part_get_type_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_part_get_type_str' called, but not implemented!");
    return NULL;
}

const gchar* (*_bd_part_get_type_str) (BDPartType type, GError **error) = bd_part_get_type_str_stub;

/**
 * bd_part_get_type_str:
 * @type: type to get string representation for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer none): string representation of @type
 *
 * Tech category: always available
 */
const gchar* bd_part_get_type_str (BDPartType type, GError **error) {
    return _bd_part_get_type_str (type, error);
}


gpointer load_part_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module part: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_part_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for part: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_part_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for part: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_part_is_tech_avail) = dlsym(handle, "bd_part_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_part_create_table) = dlsym(handle, "bd_part_create_table");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_create_table: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_part_spec) = dlsym(handle, "bd_part_get_part_spec");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_part_spec: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_part_by_pos) = dlsym(handle, "bd_part_get_part_by_pos");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_part_by_pos: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_disk_spec) = dlsym(handle, "bd_part_get_disk_spec");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_disk_spec: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_disk_parts) = dlsym(handle, "bd_part_get_disk_parts");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_disk_parts: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_disk_free_regions) = dlsym(handle, "bd_part_get_disk_free_regions");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_disk_free_regions: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_best_free_region) = dlsym(handle, "bd_part_get_best_free_region");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_best_free_region: %s", error);

    dlerror();
    * (void**) (&_bd_part_create_part) = dlsym(handle, "bd_part_create_part");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_create_part: %s", error);

    dlerror();
    * (void**) (&_bd_part_delete_part) = dlsym(handle, "bd_part_delete_part");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_delete_part: %s", error);

    dlerror();
    * (void**) (&_bd_part_resize_part) = dlsym(handle, "bd_part_resize_part");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_resize_part: %s", error);

    dlerror();
    * (void**) (&_bd_part_set_part_flag) = dlsym(handle, "bd_part_set_part_flag");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_set_part_flag: %s", error);

    dlerror();
    * (void**) (&_bd_part_set_disk_flag) = dlsym(handle, "bd_part_set_disk_flag");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_set_disk_flag: %s", error);

    dlerror();
    * (void**) (&_bd_part_set_part_flags) = dlsym(handle, "bd_part_set_part_flags");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_set_part_flags: %s", error);

    dlerror();
    * (void**) (&_bd_part_set_part_name) = dlsym(handle, "bd_part_set_part_name");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_set_part_name: %s", error);

    dlerror();
    * (void**) (&_bd_part_set_part_type) = dlsym(handle, "bd_part_set_part_type");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_set_part_type: %s", error);

    dlerror();
    * (void**) (&_bd_part_set_part_id) = dlsym(handle, "bd_part_set_part_id");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_set_part_id: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_part_id) = dlsym(handle, "bd_part_get_part_id");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_part_id: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_part_table_type_str) = dlsym(handle, "bd_part_get_part_table_type_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_part_table_type_str: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_flag_str) = dlsym(handle, "bd_part_get_flag_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_flag_str: %s", error);

    dlerror();
    * (void**) (&_bd_part_get_type_str) = dlsym(handle, "bd_part_get_type_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_part_get_type_str: %s", error);

    return handle;
}

gboolean unload_part (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_part_is_tech_avail = bd_part_is_tech_avail_stub;
    _bd_part_create_table = bd_part_create_table_stub;
    _bd_part_get_part_spec = bd_part_get_part_spec_stub;
    _bd_part_get_part_by_pos = bd_part_get_part_by_pos_stub;
    _bd_part_get_disk_spec = bd_part_get_disk_spec_stub;
    _bd_part_get_disk_parts = bd_part_get_disk_parts_stub;
    _bd_part_get_disk_free_regions = bd_part_get_disk_free_regions_stub;
    _bd_part_get_best_free_region = bd_part_get_best_free_region_stub;
    _bd_part_create_part = bd_part_create_part_stub;
    _bd_part_delete_part = bd_part_delete_part_stub;
    _bd_part_resize_part = bd_part_resize_part_stub;
    _bd_part_set_part_flag = bd_part_set_part_flag_stub;
    _bd_part_set_disk_flag = bd_part_set_disk_flag_stub;
    _bd_part_set_part_flags = bd_part_set_part_flags_stub;
    _bd_part_set_part_name = bd_part_set_part_name_stub;
    _bd_part_set_part_type = bd_part_set_part_type_stub;
    _bd_part_set_part_id = bd_part_set_part_id_stub;
    _bd_part_get_part_id = bd_part_get_part_id_stub;
    _bd_part_get_part_table_type_str = bd_part_get_part_table_type_str_stub;
    _bd_part_get_flag_str = bd_part_get_flag_str_stub;
    _bd_part_get_type_str = bd_part_get_type_str_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_part_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for part: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

