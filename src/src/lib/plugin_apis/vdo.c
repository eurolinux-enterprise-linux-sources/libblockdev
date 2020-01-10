GQuark  bd_vdo_error_quark (void) {
        return g_quark_from_static_string ("g-bd-vdo-error-quark");
}

/**
 * BDVDOInfo:
 * @name: name of the VDO volume
 * @device: underlying block device
 * @active: whether the volume is active or not
 * @deduplication: whether deduplication is enabled
 * @compression: whether compression is enabled
 * @logical_size: logical size of the volume
 * @physical_size: sphysical size of the volume
 * @index_memory: index memory size
 * @write_policy: write policy of the volume
 */
/**
 * bd_vdo_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_vdo_info_free (BDVDOInfo *info) {
         g_free (info->name);
     g_free (info->device);
     g_free (info);
 }

/**
 * bd_vdo_info_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDVDOInfo* bd_vdo_info_copy (BDVDOInfo *info) {
    BDVDOInfo *new_info = g_new0 (BDVDOInfo, 1);

    new_info->name = g_strdup (info->name);
    new_info->device = g_strdup (info->device);
    new_info->active = info->active;
    new_info->deduplication = info->deduplication;
    new_info->compression = info->compression;
    new_info->logical_size = info->logical_size;
    new_info->physical_size = info->physical_size;
    new_info->index_memory = info->index_memory;
    new_info->write_policy = info->write_policy;

    return new_info;
 }

GType bd_vdo_info_get_type () {
    static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDVDOInfo",
                                            (GBoxedCopyFunc) bd_vdo_info_copy,
                                            (GBoxedFreeFunc) bd_vdo_info_free);
    }

    return type;
}

static const gchar* const vdo_functions[] = {
    "bd_vdo_is_tech_avail",
    "bd_vdo_get_write_policy_str",
    "bd_vdo_get_write_policy_from_str",
    "bd_vdo_info",
    "bd_vdo_create",
    "bd_vdo_remove",
    "bd_vdo_change_write_policy",
    "bd_vdo_enable_compression",
    "bd_vdo_disable_compression",
    "bd_vdo_enable_deduplication",
    "bd_vdo_disable_deduplication",
    "bd_vdo_activate",
    "bd_vdo_deactivate",
    "bd_vdo_start",
    "bd_vdo_stop",
    "bd_vdo_grow_logical",
    "bd_vdo_grow_physical",
    NULL};

const gchar* const* get_vdo_functions (void) {
    return vdo_functions;
}

static const guint8 vdo_num_functions = 17;

guint8 get_vdo_num_functions (void) {
    return vdo_num_functions;
}

gboolean  bd_vdo_is_tech_avail_stub (BDVDOTech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_vdo_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_is_tech_avail) (BDVDOTech tech, guint64 mode, GError **error) = bd_vdo_is_tech_avail_stub;

/**
 * bd_vdo_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDVDOTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_vdo_is_tech_avail (BDVDOTech tech, guint64 mode, GError **error) {
    return _bd_vdo_is_tech_avail (tech, mode, error);
}


const gchar* bd_vdo_get_write_policy_str_stub (BDVDOWritePolicy policy, GError **error) {
    g_critical ("The function 'bd_vdo_get_write_policy_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_get_write_policy_str' called, but not implemented!");
    return NULL;
}

const gchar* (*_bd_vdo_get_write_policy_str) (BDVDOWritePolicy policy, GError **error) = bd_vdo_get_write_policy_str_stub;

/**
 * bd_vdo_get_write_policy_str:
 * @policy: policy to get the string representation for
 * @error: (out): place to store error (if any)
 *
 * Returns: string representation of @policy or %NULL in case of error
 *
 * Tech category: always provided/supported
 */
const gchar* bd_vdo_get_write_policy_str (BDVDOWritePolicy policy, GError **error) {
    return _bd_vdo_get_write_policy_str (policy, error);
}


BDVDOWritePolicy  bd_vdo_get_write_policy_from_str_stub (const gchar *policy_str, GError **error) {
    g_critical ("The function 'bd_vdo_get_write_policy_from_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_get_write_policy_from_str' called, but not implemented!");
    return 0;
}

BDVDOWritePolicy  (*_bd_vdo_get_write_policy_from_str) (const gchar *policy_str, GError **error) = bd_vdo_get_write_policy_from_str_stub;

/**
 * bd_vdo_get_write_policy_from_str:
 * @policy_str: string representation of a write policy mode
 * @error: (out): place to store error (if any)
 *
 * Returns: write policy for the @mode_str or %BD_VDO_WRITE_POLICY_UNKNOWN if
 *          failed to determine
 *
 * Tech category: always provided/supported
 */
BDVDOWritePolicy  bd_vdo_get_write_policy_from_str (const gchar *policy_str, GError **error) {
    return _bd_vdo_get_write_policy_from_str (policy_str, error);
}


BDVDOInfo* bd_vdo_info_stub (const gchar *name, GError **error) {
    g_critical ("The function 'bd_vdo_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_info' called, but not implemented!");
    return NULL;
}

BDVDOInfo* (*_bd_vdo_info) (const gchar *name, GError **error) = bd_vdo_info_stub;

/**
 * bd_vdo_info:
 * @name: a VDO volume to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the VDO volume or %NULL
 * in case of error (@error gets populated in those cases)
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_QUERY
 */
BDVDOInfo* bd_vdo_info (const gchar *name, GError **error) {
    return _bd_vdo_info (name, error);
}


gboolean  bd_vdo_create_stub (const gchar *name, const gchar *backing_device, guint64 logical_size, guint64 index_memory, gboolean compression, gboolean deduplication, BDVDOWritePolicy write_policy, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_create' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_create' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_create) (const gchar *name, const gchar *backing_device, guint64 logical_size, guint64 index_memory, gboolean compression, gboolean deduplication, BDVDOWritePolicy write_policy, const BDExtraArg **extra, GError **error) = bd_vdo_create_stub;

/**
 * bd_vdo_create:
 * @name: name for the VDO volume
 * @backing_device: device to use for VDO storage
 * @logical_size: logical VDO volume size or 0 for default (size of @backing_device)
 * @index_memory: amount of index memory or 0 for default; note that only some
 *                sizes are valid here (0.25, 0.5 and 0.75 GB and integer multiples of 1 GB)
 *                invalid sizes will be rounded DOWN to nearest GB (or one of the allowed
 *                decimal values)
 * @compression: whether to enable compression or not
 * @deduplication: whether to enable deduplication or not
 * @write_policy: write policy for the volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VDO volume was successfully created or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_MODE_CREATE
 */
gboolean  bd_vdo_create (const gchar *name, const gchar *backing_device, guint64 logical_size, guint64 index_memory, gboolean compression, gboolean deduplication, BDVDOWritePolicy write_policy, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_create (name, backing_device, logical_size, index_memory, compression, deduplication, write_policy, extra, error);
}


gboolean  bd_vdo_remove_stub (const gchar *name, gboolean force, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_remove' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_remove' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_remove) (const gchar *name, gboolean force, const BDExtraArg **extra, GError **error) = bd_vdo_remove_stub;

/**
 * bd_vdo_remove:
 * @name: name of an existing VDO volume
 * @force: force remove the volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VDO volume was successfully removed or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_MODIFY
 */
gboolean  bd_vdo_remove (const gchar *name, gboolean force, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_remove (name, force, extra, error);
}


gboolean  bd_vdo_change_write_policy_stub (const gchar *name, BDVDOWritePolicy write_policy, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_change_write_policy' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_change_write_policy' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_change_write_policy) (const gchar *name, BDVDOWritePolicy write_policy, const BDExtraArg **extra, GError **error) = bd_vdo_change_write_policy_stub;

/**
 * bd_vdo_change_write_policy:
 * @name: name of an existing VDO volume
 * @write_policy: new write policy for the volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the policy was successfully changed or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_MODIFY
 */
gboolean  bd_vdo_change_write_policy (const gchar *name, BDVDOWritePolicy write_policy, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_change_write_policy (name, write_policy, extra, error);
}


gboolean  bd_vdo_enable_compression_stub (const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_enable_compression' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_enable_compression' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_enable_compression) (const gchar *name, const BDExtraArg **extra, GError **error) = bd_vdo_enable_compression_stub;

/**
 * bd_vdo_enable_compression:
 * @name: name of an existing VDO volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the compression was successfully enabled or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_MODIFY
 */
gboolean  bd_vdo_enable_compression (const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_enable_compression (name, extra, error);
}


gboolean  bd_vdo_disable_compression_stub (const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_disable_compression' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_disable_compression' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_disable_compression) (const gchar *name, const BDExtraArg **extra, GError **error) = bd_vdo_disable_compression_stub;

/**
 * bd_vdo_disable_compression:
 * @name: name of an existing VDO volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the compression was successfully disabled or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_MODIFY
 */
gboolean  bd_vdo_disable_compression (const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_disable_compression (name, extra, error);
}


gboolean  bd_vdo_enable_deduplication_stub (const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_enable_deduplication' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_enable_deduplication' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_enable_deduplication) (const gchar *name, const BDExtraArg **extra, GError **error) = bd_vdo_enable_deduplication_stub;

/**
 * bd_vdo_enable_deduplication:
 * @name: name of an existing VDO volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the deduplication was successfully enabled or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_MODIFY
 */
gboolean  bd_vdo_enable_deduplication (const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_enable_deduplication (name, extra, error);
}


gboolean  bd_vdo_disable_deduplication_stub (const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_disable_deduplication' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_disable_deduplication' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_disable_deduplication) (const gchar *name, const BDExtraArg **extra, GError **error) = bd_vdo_disable_deduplication_stub;

/**
 * bd_vdo_disable_deduplication:
 * @name: name of an existing VDO volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the deduplication was successfully disabled or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_MODIFY
 */
gboolean  bd_vdo_disable_deduplication (const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_disable_deduplication (name, extra, error);
}


gboolean  bd_vdo_activate_stub (const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_activate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_activate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_activate) (const gchar *name, const BDExtraArg **extra, GError **error) = bd_vdo_activate_stub;

/**
 * bd_vdo_activate:
 * @name: name of an existing VDO volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VDO volume was successfully activated or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_ACTIVATE_DEACTIVATE
 */
gboolean  bd_vdo_activate (const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_activate (name, extra, error);
}


gboolean  bd_vdo_deactivate_stub (const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_deactivate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_deactivate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_deactivate) (const gchar *name, const BDExtraArg **extra, GError **error) = bd_vdo_deactivate_stub;

/**
 * bd_vdo_deactivate:
 * @name: name of an existing VDO volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VDO volume was successfully deactivated or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_ACTIVATE_DEACTIVATE
 */
gboolean  bd_vdo_deactivate (const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_deactivate (name, extra, error);
}


gboolean  bd_vdo_start_stub (const gchar *name, gboolean rebuild, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_start' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_start' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_start) (const gchar *name, gboolean rebuild, const BDExtraArg **extra, GError **error) = bd_vdo_start_stub;

/**
 * bd_vdo_start:
 * @name: name of an existing VDO volume
 * @rebuild: force rebuild the volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VDO volume was successfully started or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_START_STOP
 */
gboolean  bd_vdo_start (const gchar *name, gboolean rebuild, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_start (name, rebuild, extra, error);
}


gboolean  bd_vdo_stop_stub (const gchar *name, gboolean force, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_stop' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_stop' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_stop) (const gchar *name, gboolean force, const BDExtraArg **extra, GError **error) = bd_vdo_stop_stub;

/**
 * bd_vdo_stop:
 * @name: name of an existing VDO volume
 * @force: force stop the volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VDO volume was successfully stopped or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_START_STOP
 */
gboolean  bd_vdo_stop (const gchar *name, gboolean force, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_stop (name, force, extra, error);
}


gboolean  bd_vdo_grow_logical_stub (const gchar *name, guint64 size, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_grow_logical' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_grow_logical' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_grow_logical) (const gchar *name, guint64 size, const BDExtraArg **extra, GError **error) = bd_vdo_grow_logical_stub;

/**
 * bd_vdo_grow_logical:
 * @name: name of an existing VDO volume
 * @size: new logical size for the volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO creation
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VDO volume was successfully resized or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_GROW
 */
gboolean  bd_vdo_grow_logical (const gchar *name, guint64 size, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_grow_logical (name, size, extra, error);
}


gboolean  bd_vdo_grow_physical_stub (const gchar *name, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_vdo_grow_physical' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_vdo_grow_physical' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_vdo_grow_physical) (const gchar *name, const BDExtraArg **extra, GError **error) = bd_vdo_grow_physical_stub;

/**
 * bd_vdo_grow_physical:
 * @name: name of an existing VDO volume
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VDO tool
 *                                                 (just passed to VDO as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VDO volume was successfully grown or not
 *
 * Tech category: %BD_VDO_TECH_VDO-%BD_VDO_TECH_MODE_GROW
 */
gboolean  bd_vdo_grow_physical (const gchar *name, const BDExtraArg **extra, GError **error) {
    return _bd_vdo_grow_physical (name, extra, error);
}


gpointer load_vdo_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module vdo: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_vdo_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for vdo: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_vdo_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for vdo: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_vdo_is_tech_avail) = dlsym(handle, "bd_vdo_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_get_write_policy_str) = dlsym(handle, "bd_vdo_get_write_policy_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_get_write_policy_str: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_get_write_policy_from_str) = dlsym(handle, "bd_vdo_get_write_policy_from_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_get_write_policy_from_str: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_info) = dlsym(handle, "bd_vdo_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_info: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_create) = dlsym(handle, "bd_vdo_create");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_create: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_remove) = dlsym(handle, "bd_vdo_remove");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_remove: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_change_write_policy) = dlsym(handle, "bd_vdo_change_write_policy");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_change_write_policy: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_enable_compression) = dlsym(handle, "bd_vdo_enable_compression");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_enable_compression: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_disable_compression) = dlsym(handle, "bd_vdo_disable_compression");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_disable_compression: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_enable_deduplication) = dlsym(handle, "bd_vdo_enable_deduplication");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_enable_deduplication: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_disable_deduplication) = dlsym(handle, "bd_vdo_disable_deduplication");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_disable_deduplication: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_activate) = dlsym(handle, "bd_vdo_activate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_activate: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_deactivate) = dlsym(handle, "bd_vdo_deactivate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_deactivate: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_start) = dlsym(handle, "bd_vdo_start");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_start: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_stop) = dlsym(handle, "bd_vdo_stop");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_stop: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_grow_logical) = dlsym(handle, "bd_vdo_grow_logical");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_grow_logical: %s", error);

    dlerror();
    * (void**) (&_bd_vdo_grow_physical) = dlsym(handle, "bd_vdo_grow_physical");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_vdo_grow_physical: %s", error);

    return handle;
}

gboolean unload_vdo (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_vdo_is_tech_avail = bd_vdo_is_tech_avail_stub;
    _bd_vdo_get_write_policy_str = bd_vdo_get_write_policy_str_stub;
    _bd_vdo_get_write_policy_from_str = bd_vdo_get_write_policy_from_str_stub;
    _bd_vdo_info = bd_vdo_info_stub;
    _bd_vdo_create = bd_vdo_create_stub;
    _bd_vdo_remove = bd_vdo_remove_stub;
    _bd_vdo_change_write_policy = bd_vdo_change_write_policy_stub;
    _bd_vdo_enable_compression = bd_vdo_enable_compression_stub;
    _bd_vdo_disable_compression = bd_vdo_disable_compression_stub;
    _bd_vdo_enable_deduplication = bd_vdo_enable_deduplication_stub;
    _bd_vdo_disable_deduplication = bd_vdo_disable_deduplication_stub;
    _bd_vdo_activate = bd_vdo_activate_stub;
    _bd_vdo_deactivate = bd_vdo_deactivate_stub;
    _bd_vdo_start = bd_vdo_start_stub;
    _bd_vdo_stop = bd_vdo_stop_stub;
    _bd_vdo_grow_logical = bd_vdo_grow_logical_stub;
    _bd_vdo_grow_physical = bd_vdo_grow_physical_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_vdo_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for vdo: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

