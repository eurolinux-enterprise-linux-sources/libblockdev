GQuark  bd_mpath_error_quark (void) {
        return g_quark_from_static_string ("g-bd-mpath-error-quark");
}

static const gchar const * const mpath_functions[] = {
    "bd_mpath_flush_mpaths",
    "bd_mpath_is_mpath_member",
    "bd_mpath_get_mpath_members",
    "bd_mpath_set_friendly_names",
    NULL};

gchar const * const * get_mpath_functions (void) {
    return mpath_functions;
}

static const guint8 mpath_num_functions = 4;

guint8 get_mpath_num_functions (void) {
    return mpath_num_functions;
}

gboolean  bd_mpath_flush_mpaths_stub (GError **error) {
    g_critical ("The function 'bd_mpath_flush_mpaths' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_mpath_flush_mpaths' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_mpath_flush_mpaths) (GError **error) = bd_mpath_flush_mpaths_stub;

/**
 * bd_mpath_flush_mpaths:
 * @error: (out): place to store error (if any)
 *
 * Returns: whether multipath device maps were successfully flushed or not
 *
 * Flushes all unused multipath device maps.
 */
gboolean  bd_mpath_flush_mpaths (GError **error) {
    return _bd_mpath_flush_mpaths (error);
}


gboolean  bd_mpath_is_mpath_member_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_mpath_is_mpath_member' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_mpath_is_mpath_member' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_mpath_is_mpath_member) (const gchar *device, GError **error) = bd_mpath_is_mpath_member_stub;

/**
 * bd_mpath_is_mpath_member:
 * @device: device to test
 * @error: (out): place to store error (if any)
 *
 * Returns: %TRUE if the device is a multipath member, %FALSE if not or an error
 * appeared when queried (@error is set in those cases)
 */
gboolean  bd_mpath_is_mpath_member (const gchar *device, GError **error) {
    return _bd_mpath_is_mpath_member (device, error);
}


gchar** bd_mpath_get_mpath_members_stub (GError **error) {
    g_critical ("The function 'bd_mpath_get_mpath_members' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_mpath_get_mpath_members' called, but not implemented!");
    return NULL;
}

gchar** (*_bd_mpath_get_mpath_members) (GError **error) = bd_mpath_get_mpath_members_stub;

/**
 * bd_mpath_get_mpath_members:
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full) (array zero-terminated=1): list of names of all devices that are
 *                                                     members of the mpath mappings (or %NULL
 *                                                     in case of error)
 */
gchar** bd_mpath_get_mpath_members (GError **error) {
    return _bd_mpath_get_mpath_members (error);
}


gboolean  bd_mpath_set_friendly_names_stub (gboolean enabled, GError **error) {
    g_critical ("The function 'bd_mpath_set_friendly_names' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_mpath_set_friendly_names' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_mpath_set_friendly_names) (gboolean enabled, GError **error) = bd_mpath_set_friendly_names_stub;

/**
 * bd_mpath_set_friendly_names:
 * @enabled: whether friendly names should be enabled or not
 * @error: (out): place to store error (if any)
 *
 * Returns: if successfully set or not
 */
gboolean  bd_mpath_set_friendly_names (gboolean enabled, GError **error) {
    return _bd_mpath_set_friendly_names (enabled, error);
}


gpointer load_mpath_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module mpath: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_mpath_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for mpath: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_mpath_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for mpath: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_mpath_flush_mpaths) = dlsym(handle, "bd_mpath_flush_mpaths");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_mpath_flush_mpaths: %s", error);

    dlerror();
    * (void**) (&_bd_mpath_is_mpath_member) = dlsym(handle, "bd_mpath_is_mpath_member");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_mpath_is_mpath_member: %s", error);

    dlerror();
    * (void**) (&_bd_mpath_get_mpath_members) = dlsym(handle, "bd_mpath_get_mpath_members");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_mpath_get_mpath_members: %s", error);

    dlerror();
    * (void**) (&_bd_mpath_set_friendly_names) = dlsym(handle, "bd_mpath_set_friendly_names");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_mpath_set_friendly_names: %s", error);

    return handle;
}

gboolean unload_mpath (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_mpath_flush_mpaths = bd_mpath_flush_mpaths_stub;
    _bd_mpath_is_mpath_member = bd_mpath_is_mpath_member_stub;
    _bd_mpath_get_mpath_members = bd_mpath_get_mpath_members_stub;
    _bd_mpath_set_friendly_names = bd_mpath_set_friendly_names_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_mpath_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for mpath: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

