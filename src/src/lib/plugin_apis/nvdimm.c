GQuark  bd_nvdimm_error_quark (void) {
        return g_quark_from_static_string ("g-bd-nvdimm-error-quark");
}

/**
 * BDNVDIMMNamespaceInfo:
 * @dev: namespace device name ("namespaceX.Y")
 * @mode: mode of the namespace (BDNVDIMMNamespaceMode)
 * @size: size of the namespace
 * @uuid: UUID of the namespace
 * @sector_size: sector size of the namespace (0 for non-sector namespaces)
 * @blockdev: name of the block device for the namespace
 * @enabled: whether the namespace is enabled or not
 */
/**
 * bd_nvdimm_namespace_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_nvdimm_namespace_info_free (BDNVDIMMNamespaceInfo *info) {
        g_free (info->dev);
    g_free (info->uuid);
    g_free (info->blockdev);
    g_free (info);
}

/**
 * bd_nvdimm_namespace_info_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDNVDIMMNamespaceInfo* bd_nvdimm_namespace_info_copy (BDNVDIMMNamespaceInfo *info) {
        BDNVDIMMNamespaceInfo *new_info = g_new0 (BDNVDIMMNamespaceInfo, 1);

    new_info->dev = info->dev;
    new_info->mode = info->mode;
    new_info->size = info->size;
    new_info->uuid = g_strdup (info->uuid);
    new_info->sector_size = info->sector_size;
    new_info->blockdev = g_strdup (info->blockdev);
    new_info->enabled = info->enabled;

    return new_info;
}

GType  bd_nvdimm_namespace_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDNVDIMMNamespaceInfo",
                                            (GBoxedCopyFunc) bd_nvdimm_namespace_info_copy,
                                            (GBoxedFreeFunc) bd_nvdimm_namespace_info_free);
    }

    return type;
}

static const gchar* const nvdimm_functions[] = {
    "bd_nvdimm_is_tech_avail",
    "bd_nvdimm_namespace_get_mode_from_str",
    "bd_nvdimm_namespace_get_mode_str",
    "bd_nvdimm_namespace_get_devname",
    "bd_nvdimm_namespace_enable",
    "bd_nvdimm_namespace_disable",
    "bd_nvdimm_namespace_info",
    "bd_nvdimm_list_namespaces",
    "bd_nvdimm_namespace_reconfigure",
    NULL};

const gchar* const* get_nvdimm_functions (void) {
    return nvdimm_functions;
}

static const guint8 nvdimm_num_functions = 9;

guint8 get_nvdimm_num_functions (void) {
    return nvdimm_num_functions;
}

gboolean  bd_nvdimm_is_tech_avail_stub (BDNVDIMMTech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_nvdimm_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_nvdimm_is_tech_avail) (BDNVDIMMTech tech, guint64 mode, GError **error) = bd_nvdimm_is_tech_avail_stub;

/**
 * bd_nvdimm_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDNVDIMMTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_nvdimm_is_tech_avail (BDNVDIMMTech tech, guint64 mode, GError **error) {
    return _bd_nvdimm_is_tech_avail (tech, mode, error);
}


BDNVDIMMNamespaceMode  bd_nvdimm_namespace_get_mode_from_str_stub (const gchar *mode_str, GError **error) {
    g_critical ("The function 'bd_nvdimm_namespace_get_mode_from_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_namespace_get_mode_from_str' called, but not implemented!");
    return 0;
}

BDNVDIMMNamespaceMode  (*_bd_nvdimm_namespace_get_mode_from_str) (const gchar *mode_str, GError **error) = bd_nvdimm_namespace_get_mode_from_str_stub;

/**
 * bd_nvdimm_namespace_get_mode_from_str:
 * @mode_str: string representation of mode
 * @error: (out): place to store error (if any)
 *
 * Returns: mode matching the @mode_str given or %BD_NVDIMM_NAMESPACE_MODE_UNKNOWN in case of no match
 *
 * Tech category: always available
 */
BDNVDIMMNamespaceMode  bd_nvdimm_namespace_get_mode_from_str (const gchar *mode_str, GError **error) {
    return _bd_nvdimm_namespace_get_mode_from_str (mode_str, error);
}


const gchar* bd_nvdimm_namespace_get_mode_str_stub (BDNVDIMMNamespaceMode mode, GError **error) {
    g_critical ("The function 'bd_nvdimm_namespace_get_mode_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_namespace_get_mode_str' called, but not implemented!");
    return NULL;
}

const gchar* (*_bd_nvdimm_namespace_get_mode_str) (BDNVDIMMNamespaceMode mode, GError **error) = bd_nvdimm_namespace_get_mode_str_stub;

/**
 * bd_nvdimm_namespace_get_mode_str:
 * @mode: mode to get string representation of
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer none): string representation of @mode or %NULL in case of error
 *
 * Tech category: always available
 */
const gchar* bd_nvdimm_namespace_get_mode_str (BDNVDIMMNamespaceMode mode, GError **error) {
    return _bd_nvdimm_namespace_get_mode_str (mode, error);
}


gchar* bd_nvdimm_namespace_get_devname_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_nvdimm_namespace_get_devname' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_namespace_get_devname' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_nvdimm_namespace_get_devname) (const gchar *device, GError **error) = bd_nvdimm_namespace_get_devname_stub;

/**
 * bd_nvdimm_namespace_get_devname:
 * @device: name or path of a block device (e.g. "/dev/pmem0")
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): namespace device name (e.g. "namespaceX.Y") for @device
 *                           or %NULL if @device is not a NVDIMM namespace
 *                           (@error may be set to indicate error)
 *
 * Tech category: %BD_NVDIMM_TECH_NAMESPACE-%BD_NVDIMM_TECH_MODE_QUERY
 */
gchar* bd_nvdimm_namespace_get_devname (const gchar *device, GError **error) {
    return _bd_nvdimm_namespace_get_devname (device, error);
}


gboolean  bd_nvdimm_namespace_enable_stub (const gchar *namespace, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_nvdimm_namespace_enable' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_namespace_enable' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_nvdimm_namespace_enable) (const gchar *namespace, const BDExtraArg **extra, GError **error) = bd_nvdimm_namespace_enable_stub;

/**
 * bd_nvdimm_namespace_enable:
 * @namespace: name of the namespace to enable
 * @extra: (allow-none) (array zero-terminated=1): extra options (currently unused)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @namespace was successfully enabled or not
 *
 * Tech category: %BD_NVDIMM_TECH_NAMESPACE-%BD_NVDIMM_TECH_MODE_ACTIVATE_DEACTIVATE
 */
gboolean  bd_nvdimm_namespace_enable (const gchar *namespace, const BDExtraArg **extra, GError **error) {
    return _bd_nvdimm_namespace_enable (namespace, extra, error);
}


gboolean  bd_nvdimm_namespace_disable_stub (const gchar *namespace, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_nvdimm_namespace_disable' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_namespace_disable' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_nvdimm_namespace_disable) (const gchar *namespace, const BDExtraArg **extra, GError **error) = bd_nvdimm_namespace_disable_stub;

/**
 * bd_nvdimm_namespace_disable:
 * @namespace: name of the namespace to disable
 * @extra: (allow-none) (array zero-terminated=1): extra options (currently unused)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @namespace was successfully disabled or not
 *
 * Tech category: %BD_NVDIMM_TECH_NAMESPACE-%BD_NVDIMM_TECH_MODE_ACTIVATE_DEACTIVATE
 */
gboolean  bd_nvdimm_namespace_disable (const gchar *namespace, const BDExtraArg **extra, GError **error) {
    return _bd_nvdimm_namespace_disable (namespace, extra, error);
}


BDNVDIMMNamespaceInfo* bd_nvdimm_namespace_info_stub (const gchar *namespace, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_nvdimm_namespace_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_namespace_info' called, but not implemented!");
    return NULL;
}

BDNVDIMMNamespaceInfo* (*_bd_nvdimm_namespace_info) (const gchar *namespace, const BDExtraArg **extra, GError **error) = bd_nvdimm_namespace_info_stub;

/**
 * bd_nvdimm_namespace_info:
 * @namespace: namespace to get information about
 * @extra: (allow-none) (array zero-terminated=1): extra options (currently unused)
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about given namespace or %NULL if no such
 *                           namespace was found (@error may be set to indicate error)
 *
 * Tech category: %BD_NVDIMM_TECH_NAMESPACE-%BD_NVDIMM_TECH_MODE_QUERY
 */
BDNVDIMMNamespaceInfo* bd_nvdimm_namespace_info (const gchar *namespace, const BDExtraArg **extra, GError **error) {
    return _bd_nvdimm_namespace_info (namespace, extra, error);
}


BDNVDIMMNamespaceInfo** bd_nvdimm_list_namespaces_stub (const gchar *bus, const gchar *region, gboolean idle, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_nvdimm_list_namespaces' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_list_namespaces' called, but not implemented!");
    return NULL;
}

BDNVDIMMNamespaceInfo** (*_bd_nvdimm_list_namespaces) (const gchar *bus, const gchar *region, gboolean idle, const BDExtraArg **extra, GError **error) = bd_nvdimm_list_namespaces_stub;

/**
 * bd_nvdimm_list_namespaces:
 * @bus: (allow-none): return only namespaces on given bus (specified by name),
 *                     %NULL may be specified to return namespaces from all buses
 * @region: (allow-none): return only namespaces on given region (specified by regionX name or region id),
 *                        %NULL may be specified to return namespaces from all regions
 * @idle: whether to list idle (not enabled) namespaces too
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'ndctl' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about the namespaces on @bus and @region or
 *                                     %NULL if no namespaces were found (@error may be set to indicate error)
 *
 * Tech category: %BD_NVDIMM_TECH_NAMESPACE-%BD_NVDIMM_TECH_MODE_QUERY
 */
BDNVDIMMNamespaceInfo** bd_nvdimm_list_namespaces (const gchar *bus, const gchar *region, gboolean idle, const BDExtraArg **extra, GError **error) {
    return _bd_nvdimm_list_namespaces (bus, region, idle, extra, error);
}


gboolean  bd_nvdimm_namespace_reconfigure_stub (const gchar* namespace, BDNVDIMMNamespaceMode mode, gboolean force, const BDExtraArg **extra, GError** error) {
    g_critical ("The function 'bd_nvdimm_namespace_reconfigure' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_nvdimm_namespace_reconfigure' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_nvdimm_namespace_reconfigure) (const gchar* namespace, BDNVDIMMNamespaceMode mode, gboolean force, const BDExtraArg **extra, GError** error) = bd_nvdimm_namespace_reconfigure_stub;

/**
 * bd_nvdimm_namespace_reconfigure:
 * @namespace: name of the namespace to recofigure
 * @mode: mode type to set (memory/sector/raw/dax)
 * @error: (out): place to store error if any
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'ndctl' utility)
 *
 * Returns: whether @namespace was successfully reconfigured or not
 */
gboolean  bd_nvdimm_namespace_reconfigure (const gchar* namespace, BDNVDIMMNamespaceMode mode, gboolean force, const BDExtraArg **extra, GError** error) {
    return _bd_nvdimm_namespace_reconfigure (namespace, mode, force, extra, error);
}


gpointer load_nvdimm_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module nvdimm: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_nvdimm_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for nvdimm: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_nvdimm_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for nvdimm: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_nvdimm_is_tech_avail) = dlsym(handle, "bd_nvdimm_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_nvdimm_namespace_get_mode_from_str) = dlsym(handle, "bd_nvdimm_namespace_get_mode_from_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_namespace_get_mode_from_str: %s", error);

    dlerror();
    * (void**) (&_bd_nvdimm_namespace_get_mode_str) = dlsym(handle, "bd_nvdimm_namespace_get_mode_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_namespace_get_mode_str: %s", error);

    dlerror();
    * (void**) (&_bd_nvdimm_namespace_get_devname) = dlsym(handle, "bd_nvdimm_namespace_get_devname");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_namespace_get_devname: %s", error);

    dlerror();
    * (void**) (&_bd_nvdimm_namespace_enable) = dlsym(handle, "bd_nvdimm_namespace_enable");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_namespace_enable: %s", error);

    dlerror();
    * (void**) (&_bd_nvdimm_namespace_disable) = dlsym(handle, "bd_nvdimm_namespace_disable");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_namespace_disable: %s", error);

    dlerror();
    * (void**) (&_bd_nvdimm_namespace_info) = dlsym(handle, "bd_nvdimm_namespace_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_namespace_info: %s", error);

    dlerror();
    * (void**) (&_bd_nvdimm_list_namespaces) = dlsym(handle, "bd_nvdimm_list_namespaces");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_list_namespaces: %s", error);

    dlerror();
    * (void**) (&_bd_nvdimm_namespace_reconfigure) = dlsym(handle, "bd_nvdimm_namespace_reconfigure");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_nvdimm_namespace_reconfigure: %s", error);

    return handle;
}

gboolean unload_nvdimm (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_nvdimm_is_tech_avail = bd_nvdimm_is_tech_avail_stub;
    _bd_nvdimm_namespace_get_mode_from_str = bd_nvdimm_namespace_get_mode_from_str_stub;
    _bd_nvdimm_namespace_get_mode_str = bd_nvdimm_namespace_get_mode_str_stub;
    _bd_nvdimm_namespace_get_devname = bd_nvdimm_namespace_get_devname_stub;
    _bd_nvdimm_namespace_enable = bd_nvdimm_namespace_enable_stub;
    _bd_nvdimm_namespace_disable = bd_nvdimm_namespace_disable_stub;
    _bd_nvdimm_namespace_info = bd_nvdimm_namespace_info_stub;
    _bd_nvdimm_list_namespaces = bd_nvdimm_list_namespaces_stub;
    _bd_nvdimm_namespace_reconfigure = bd_nvdimm_namespace_reconfigure_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_nvdimm_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for nvdimm: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

