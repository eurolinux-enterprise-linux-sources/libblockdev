GQuark  bd_swap_error_quark (void) {
        return g_quark_from_static_string ("g-bd-swap-error-quark");
}

static const gchar const * const swap_functions[] = {
    "bd_swap_mkswap",
    "bd_swap_swapon",
    "bd_swap_swapoff",
    "bd_swap_swapstatus",
    NULL};

gchar const * const * get_swap_functions (void) {
    return swap_functions;
}

static const guint8 swap_num_functions = 4;

guint8 get_swap_num_functions (void) {
    return swap_num_functions;
}

gboolean  bd_swap_mkswap_stub (const gchar *device, const gchar *label, const BDExtraArg **extra, GError **error) {
    g_critical ("The function 'bd_swap_mkswap' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_swap_mkswap' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_swap_mkswap) (const gchar *device, const gchar *label, const BDExtraArg **extra, GError **error) = bd_swap_mkswap_stub;

/**
 * bd_swap_mkswap:
 * @device: a device to create swap space on
 * @label: (allow-none): a label for the swap space device
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkswap' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the swap space was successfully created or not
 */
gboolean  bd_swap_mkswap (const gchar *device, const gchar *label, const BDExtraArg **extra, GError **error) {
    return _bd_swap_mkswap (device, label, extra, error);
}


gboolean  bd_swap_swapon_stub (const gchar *device, gint priority, GError **error) {
    g_critical ("The function 'bd_swap_swapon' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_swap_swapon' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_swap_swapon) (const gchar *device, gint priority, GError **error) = bd_swap_swapon_stub;

/**
 * bd_swap_swapon:
 * @device: swap device to activate
 * @priority: priority of the activated device or -1 to use the default
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the swap device was successfully activated or not
 */
gboolean  bd_swap_swapon (const gchar *device, gint priority, GError **error) {
    return _bd_swap_swapon (device, priority, error);
}


gboolean  bd_swap_swapoff_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_swap_swapoff' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_swap_swapoff' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_swap_swapoff) (const gchar *device, GError **error) = bd_swap_swapoff_stub;

/**
 * bd_swap_swapoff:
 * @device: swap device to deactivate
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the swap device was successfully deactivated or not
 */
gboolean  bd_swap_swapoff (const gchar *device, GError **error) {
    return _bd_swap_swapoff (device, error);
}


gboolean  bd_swap_swapstatus_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_swap_swapstatus' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_swap_swapstatus' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_swap_swapstatus) (const gchar *device, GError **error) = bd_swap_swapstatus_stub;

/**
 * bd_swap_swapstatus:
 * @device: swap device to get status of
 * @error: (out): place to store error (if any)
 *
 * Returns: %TRUE if the swap device is active, %FALSE if not active or failed
 * to determine (@error) is set not a non-NULL value in such case)
 */
gboolean  bd_swap_swapstatus (const gchar *device, GError **error) {
    return _bd_swap_swapstatus (device, error);
}


gpointer load_swap_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module swap: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_swap_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for swap: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_swap_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for swap: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_swap_mkswap) = dlsym(handle, "bd_swap_mkswap");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_swap_mkswap: %s", error);

    dlerror();
    * (void**) (&_bd_swap_swapon) = dlsym(handle, "bd_swap_swapon");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_swap_swapon: %s", error);

    dlerror();
    * (void**) (&_bd_swap_swapoff) = dlsym(handle, "bd_swap_swapoff");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_swap_swapoff: %s", error);

    dlerror();
    * (void**) (&_bd_swap_swapstatus) = dlsym(handle, "bd_swap_swapstatus");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_swap_swapstatus: %s", error);

    return handle;
}

gboolean unload_swap (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_swap_mkswap = bd_swap_mkswap_stub;
    _bd_swap_swapon = bd_swap_swapon_stub;
    _bd_swap_swapoff = bd_swap_swapoff_stub;
    _bd_swap_swapstatus = bd_swap_swapstatus_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_swap_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for swap: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

