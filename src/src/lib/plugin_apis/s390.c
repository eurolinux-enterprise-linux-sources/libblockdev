GQuark  bd_s390_error_quark (void) {
        return g_quark_from_static_string ("g-bd-s390-error-quark");
}

static const gchar* const s390_functions[] = {
    "bd_s390_is_tech_avail",
    "bd_s390_dasd_format",
    "bd_s390_dasd_needs_format",
    "bd_s390_dasd_online",
    "bd_s390_dasd_is_ldl",
    "bd_s390_dasd_is_fba",
    "bd_s390_sanitize_dev_input",
    "bd_s390_zfcp_sanitize_wwpn_input",
    "bd_s390_zfcp_sanitize_lun_input",
    "bd_s390_zfcp_online",
    "bd_s390_zfcp_scsi_offline",
    "bd_s390_zfcp_offline",
    NULL};

const gchar* const* get_s390_functions (void) {
    return s390_functions;
}

static const guint8 s390_num_functions = 12;

guint8 get_s390_num_functions (void) {
    return s390_num_functions;
}

gboolean  bd_s390_is_tech_avail_stub (BDS390Tech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_s390_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_is_tech_avail) (BDS390Tech tech, guint64 mode, GError **error) = bd_s390_is_tech_avail_stub;

/**
 * bd_s390_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDS390TechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_s390_is_tech_avail (BDS390Tech tech, guint64 mode, GError **error) {
    return _bd_s390_is_tech_avail (tech, mode, error);
}


gboolean  bd_s390_dasd_format_stub (const gchar *dasd, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_s390_dasd_format' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_format' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_format) (const gchar *dasd, const BDExtraArg **extra, GError **error) = bd_s390_dasd_format_stub;

/**
 * bd_s390_dasd_format:
 * @dasd: dasd to format
 * @extra: (allow-none) (array zero-terminated=1): extra options for the formatting (right now
 *                                                 passed to the 'dasdfmt' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether dasdfmt was successful or not
 *
 * Tech category: %BD_S390_TECH_DASD-%BD_S390_TECH_MODE_MODIFY
 */
gboolean  bd_s390_dasd_format (const gchar *dasd, const BDExtraArg **extra, GError **error) {
    return _bd_s390_dasd_format (dasd, extra, error);
}


gboolean  bd_s390_dasd_needs_format_stub (const gchar *dasd, GError **error) {
    g_critical ("The function 'bd_s390_dasd_needs_format' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_needs_format' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_needs_format) (const gchar *dasd, GError **error) = bd_s390_dasd_needs_format_stub;

/**
 * bd_s390_dasd_needs_format:
 * @dasd: dasd to check, whether it needs dasdfmt run on it
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a dasd needs dasdfmt run against it
 *
 * Tech category: %BD_S390_TECH_DASD-%BD_S390_TECH_MODE_QUERY
 */
gboolean  bd_s390_dasd_needs_format (const gchar *dasd, GError **error) {
    return _bd_s390_dasd_needs_format (dasd, error);
}


gboolean  bd_s390_dasd_online_stub (const gchar *dasd, GError **error) {
    g_critical ("The function 'bd_s390_dasd_online' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_online' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_online) (const gchar *dasd, GError **error) = bd_s390_dasd_online_stub;

/**
 * bd_s390_dasd_online:
 * @dasd: dasd to switch online
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a dasd was successfully switched online
 *
 * Tech category: %BD_S390_TECH_DASD-%BD_S390_TECH_MODE_MODIFY
 */
gboolean  bd_s390_dasd_online (const gchar *dasd, GError **error) {
    return _bd_s390_dasd_online (dasd, error);
}


gboolean  bd_s390_dasd_is_ldl_stub (const gchar *dasd, GError **error) {
    g_critical ("The function 'bd_s390_dasd_is_ldl' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_is_ldl' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_is_ldl) (const gchar *dasd, GError **error) = bd_s390_dasd_is_ldl_stub;

/**
 * bd_s390_dasd_is_Ldl:
 * @dasd: dasd to check, whether it is LDL formatted
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a dasd is LDL formatted
 *
 * Tech category: %BD_S390_TECH_DASD-%BD_S390_TECH_MODE_QUERY
 */
gboolean  bd_s390_dasd_is_ldl (const gchar *dasd, GError **error) {
    return _bd_s390_dasd_is_ldl (dasd, error);
}


gboolean  bd_s390_dasd_is_fba_stub (const gchar *dasd, GError **error) {
    g_critical ("The function 'bd_s390_dasd_is_fba' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_is_fba' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_is_fba) (const gchar *dasd, GError **error) = bd_s390_dasd_is_fba_stub;

/**
 * bd_s390_dasd_is_fba:
 * @dasd: dasd to check, whether it is FBA
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a dasd is FBA
 *
 * Tech category: %BD_S390_TECH_DASD-%BD_S390_TECH_MODE_QUERY
 */
gboolean  bd_s390_dasd_is_fba (const gchar *dasd, GError **error) {
    return _bd_s390_dasd_is_fba (dasd, error);
}


gchar* bd_s390_sanitize_dev_input_stub (const gchar *dev, GError **error) {
    g_critical ("The function 'bd_s390_sanitize_dev_input' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_sanitize_dev_input' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_s390_sanitize_dev_input) (const gchar *dev, GError **error) = bd_s390_sanitize_dev_input_stub;

/**
 * bd_s390_sanitize_dev_input:
 * @dev a DASD or zFCP device number
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): a synthesized dasd or zfcp device number
 *
 * Tech category: always available
 */
gchar* bd_s390_sanitize_dev_input (const gchar *dev, GError **error) {
    return _bd_s390_sanitize_dev_input (dev, error);
}


gchar* bd_s390_zfcp_sanitize_wwpn_input_stub (const gchar *wwpn, GError **error) {
    g_critical ("The function 'bd_s390_zfcp_sanitize_wwpn_input' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_zfcp_sanitize_wwpn_input' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_s390_zfcp_sanitize_wwpn_input) (const gchar *wwpn, GError **error) = bd_s390_zfcp_sanitize_wwpn_input_stub;

/**
 * bd_s390_zfcp_sanitize_wwpn_input:
 * @wwpn a zFCP WWPN identifier
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): a synthesized zFCP WWPN
 *
 * Tech category: always available
 */
gchar* bd_s390_zfcp_sanitize_wwpn_input (const gchar *wwpn, GError **error) {
    return _bd_s390_zfcp_sanitize_wwpn_input (wwpn, error);
}


gchar* bd_s390_zfcp_sanitize_lun_input_stub (const gchar *lun, GError **error) {
    g_critical ("The function 'bd_s390_zfcp_sanitize_lun_input' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_zfcp_sanitize_lun_input' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_s390_zfcp_sanitize_lun_input) (const gchar *lun, GError **error) = bd_s390_zfcp_sanitize_lun_input_stub;

/**
 * bd_s390_zfcp_sanitize_lun_input:
 * @lun a zFCP LUN identifier
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): a synthesized zFCP LUN
 *
 * Tech category: always available
 */
gchar* bd_s390_zfcp_sanitize_lun_input (const gchar *lun, GError **error) {
    return _bd_s390_zfcp_sanitize_lun_input (lun, error);
}


gboolean  bd_s390_zfcp_online_stub (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) {
    g_critical ("The function 'bd_s390_zfcp_online' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_zfcp_online' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_zfcp_online) (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) = bd_s390_zfcp_online_stub;

/**
 * bd_s390_zfcp_online:
 * @devno a zFCP device number
 * @wwpn a zFCP WWPN identifier
 * @lun a zFCP LUN identifier
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a zFCP device was successfully switched online
 *
 * Tech category: %BD_S390_TECH_ZFCP-%BD_S390_TECH_MODE_MODIFY
 */
gboolean  bd_s390_zfcp_online (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) {
    return _bd_s390_zfcp_online (devno, wwpn, lun, error);
}


gboolean  bd_s390_zfcp_scsi_offline_stub (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) {
    g_critical ("The function 'bd_s390_zfcp_scsi_offline' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_zfcp_scsi_offline' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_zfcp_scsi_offline) (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) = bd_s390_zfcp_scsi_offline_stub;

/**
 * bd_s390_zfcp_scsi_offline:
 * @devno a zFCP device number
 * @wwpn a zFCP WWPN identifier
 * @lun a zFCP LUN identifier
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a LUN was successfully removed from associated WWPN
 *
 * This function looks through /proc/scsi/scsi and manually removes LUNs from
 * associated WWPNs. zFCP devices are SCSI devices accessible over FCP protocol.
 * In z/OS the IODF (I/O definition file) contains basic information about the
 * I/O config, but WWPN and LUN configuration is done at the OS level, hence
 * this function becomes necessary when switching the device offline. This
 * particular sequence of actions is for some reason unnecessary when switching
 * the device online. Chalk it up to s390x being s390x.
 *
 * Tech category: %BD_S390_TECH_ZFCP-%BD_S390_TECH_MODE_MODIFY
 */
gboolean  bd_s390_zfcp_scsi_offline (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) {
    return _bd_s390_zfcp_scsi_offline (devno, wwpn, lun, error);
}


gboolean  bd_s390_zfcp_offline_stub (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) {
    g_critical ("The function 'bd_s390_zfcp_offline' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_zfcp_offline' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_zfcp_offline) (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) = bd_s390_zfcp_offline_stub;

/**
 * bd_s390_zfcp_offline:
 * @devno: zfcp device number
 * @wwpn: zfcp WWPN (World Wide Port Number)
 * @lun: zfcp LUN (Logical Unit Number)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a zfcp device was successfully switched offline
 *
 * Tech category: %BD_S390_TECH_ZFCP-%BD_S390_TECH_MODE_MODIFY
 */
gboolean  bd_s390_zfcp_offline (const gchar *devno, const gchar *wwpn, const gchar *lun, GError **error) {
    return _bd_s390_zfcp_offline (devno, wwpn, lun, error);
}


gpointer load_s390_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module s390: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_s390_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for s390: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_s390_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for s390: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_s390_is_tech_avail) = dlsym(handle, "bd_s390_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_s390_dasd_format) = dlsym(handle, "bd_s390_dasd_format");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_format: %s", error);

    dlerror();
    * (void**) (&_bd_s390_dasd_needs_format) = dlsym(handle, "bd_s390_dasd_needs_format");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_needs_format: %s", error);

    dlerror();
    * (void**) (&_bd_s390_dasd_online) = dlsym(handle, "bd_s390_dasd_online");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_online: %s", error);

    dlerror();
    * (void**) (&_bd_s390_dasd_is_ldl) = dlsym(handle, "bd_s390_dasd_is_ldl");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_is_ldl: %s", error);

    dlerror();
    * (void**) (&_bd_s390_dasd_is_fba) = dlsym(handle, "bd_s390_dasd_is_fba");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_is_fba: %s", error);

    dlerror();
    * (void**) (&_bd_s390_sanitize_dev_input) = dlsym(handle, "bd_s390_sanitize_dev_input");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_sanitize_dev_input: %s", error);

    dlerror();
    * (void**) (&_bd_s390_zfcp_sanitize_wwpn_input) = dlsym(handle, "bd_s390_zfcp_sanitize_wwpn_input");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_zfcp_sanitize_wwpn_input: %s", error);

    dlerror();
    * (void**) (&_bd_s390_zfcp_sanitize_lun_input) = dlsym(handle, "bd_s390_zfcp_sanitize_lun_input");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_zfcp_sanitize_lun_input: %s", error);

    dlerror();
    * (void**) (&_bd_s390_zfcp_online) = dlsym(handle, "bd_s390_zfcp_online");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_zfcp_online: %s", error);

    dlerror();
    * (void**) (&_bd_s390_zfcp_scsi_offline) = dlsym(handle, "bd_s390_zfcp_scsi_offline");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_zfcp_scsi_offline: %s", error);

    dlerror();
    * (void**) (&_bd_s390_zfcp_offline) = dlsym(handle, "bd_s390_zfcp_offline");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_zfcp_offline: %s", error);

    return handle;
}

gboolean unload_s390 (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_s390_is_tech_avail = bd_s390_is_tech_avail_stub;
    _bd_s390_dasd_format = bd_s390_dasd_format_stub;
    _bd_s390_dasd_needs_format = bd_s390_dasd_needs_format_stub;
    _bd_s390_dasd_online = bd_s390_dasd_online_stub;
    _bd_s390_dasd_is_ldl = bd_s390_dasd_is_ldl_stub;
    _bd_s390_dasd_is_fba = bd_s390_dasd_is_fba_stub;
    _bd_s390_sanitize_dev_input = bd_s390_sanitize_dev_input_stub;
    _bd_s390_zfcp_sanitize_wwpn_input = bd_s390_zfcp_sanitize_wwpn_input_stub;
    _bd_s390_zfcp_sanitize_lun_input = bd_s390_zfcp_sanitize_lun_input_stub;
    _bd_s390_zfcp_online = bd_s390_zfcp_online_stub;
    _bd_s390_zfcp_scsi_offline = bd_s390_zfcp_scsi_offline_stub;
    _bd_s390_zfcp_offline = bd_s390_zfcp_offline_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_s390_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for s390: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

