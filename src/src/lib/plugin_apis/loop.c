GQuark  bd_loop_error_quark (void) {
        return g_quark_from_static_string ("g-bd-loop-error-quark");
}

static const gchar* const loop_functions[] = {
    "bd_loop_is_tech_avail",
    "bd_loop_get_backing_file",
    "bd_loop_get_loop_name",
    "bd_loop_setup",
    "bd_loop_setup_from_fd",
    "bd_loop_teardown",
    "bd_loop_get_autoclear",
    "bd_loop_set_autoclear",
    NULL};

const gchar* const* get_loop_functions (void) {
    return loop_functions;
}

static const guint8 loop_num_functions = 8;

guint8 get_loop_num_functions (void) {
    return loop_num_functions;
}

gboolean  bd_loop_is_tech_avail_stub (BDLoopTech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_loop_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_loop_is_tech_avail) (BDLoopTech tech, guint64 mode, GError **error) = bd_loop_is_tech_avail_stub;

/**
 * bd_loop_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDLoopTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_loop_is_tech_avail (BDLoopTech tech, guint64 mode, GError **error) {
    return _bd_loop_is_tech_avail (tech, mode, error);
}


gchar* bd_loop_get_backing_file_stub (const gchar *dev_name, GError **error) {
    g_critical ("The function 'bd_loop_get_backing_file' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_get_backing_file' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_loop_get_backing_file) (const gchar *dev_name, GError **error) = bd_loop_get_backing_file_stub;

/**
 * bd_loop_get_backing_file:
 * @dev_name: name of the loop device to get backing file for (e.g. "loop0")
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): path of the device's backing file or %NULL if none
 *                           is found
 *
 * Tech category: %BD_LOOP_TECH_LOOP-%BD_LOOP_TECH_MODE_QUERY
 */
gchar* bd_loop_get_backing_file (const gchar *dev_name, GError **error) {
    return _bd_loop_get_backing_file (dev_name, error);
}


gchar* bd_loop_get_loop_name_stub (const gchar *file, GError **error) {
    g_critical ("The function 'bd_loop_get_loop_name' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_get_loop_name' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_loop_get_loop_name) (const gchar *file, GError **error) = bd_loop_get_loop_name_stub;

/**
 * bd_loop_get_loop_name:
 * @file: path of the backing file to get loop name for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): name of the loop device associated with the given @file
 *
 * Tech category: %BD_LOOP_TECH_LOOP-%BD_LOOP_TECH_MODE_QUERY
 */
gchar* bd_loop_get_loop_name (const gchar *file, GError **error) {
    return _bd_loop_get_loop_name (file, error);
}


gboolean  bd_loop_setup_stub (const gchar *file, guint64 offset, guint64 size, gboolean read_only, gboolean part_scan, const gchar **loop_name, GError **error) {
    g_critical ("The function 'bd_loop_setup' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_setup' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_loop_setup) (const gchar *file, guint64 offset, guint64 size, gboolean read_only, gboolean part_scan, const gchar **loop_name, GError **error) = bd_loop_setup_stub;

/**
 * bd_loop_setup:
 * @file: file to setup as a loop device
 * @offset: offset of the start of the device (in @file)
 * @size: maximum size of the device (or 0 to leave unspecified)
 * @read_only: whether to setup as read-only (%TRUE) or read-write (%FALSE)
 * @part_scan: whether to enforce partition scan on the newly created device or not
 * @loop_name: (allow-none) (out): if not %NULL, it is used to store the name of the loop device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @file was successfully setup as a loop device or not
 *
 * Tech category: %BD_LOOP_TECH_LOOP-%BD_LOOP_TECH_MODE_CREATE
 */
gboolean  bd_loop_setup (const gchar *file, guint64 offset, guint64 size, gboolean read_only, gboolean part_scan, const gchar **loop_name, GError **error) {
    return _bd_loop_setup (file, offset, size, read_only, part_scan, loop_name, error);
}


gboolean  bd_loop_setup_from_fd_stub (gint fd, guint64 offset, guint64 size, gboolean read_only, gboolean part_scan, const gchar **loop_name, GError **error) {
    g_critical ("The function 'bd_loop_setup_from_fd' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_setup_from_fd' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_loop_setup_from_fd) (gint fd, guint64 offset, guint64 size, gboolean read_only, gboolean part_scan, const gchar **loop_name, GError **error) = bd_loop_setup_from_fd_stub;

/**
 * bd_loop_setup_from_fd:
 * @fd: file descriptor for a file to setup as a new loop device
 * @offset: offset of the start of the device (in file given by @fd)
 * @size: maximum size of the device (or 0 to leave unspecified)
 * @read_only: whether to setup as read-only (%TRUE) or read-write (%FALSE)
 * @part_scan: whether to enforce partition scan on the newly created device or not
 * @loop_name: (allow-none) (out): if not %NULL, it is used to store the name of the loop device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether an new loop device was successfully setup for @fd or not
 *
 * Tech category: %BD_LOOP_TECH_LOOP-%BD_LOOP_TECH_MODE_CREATE
 */
gboolean  bd_loop_setup_from_fd (gint fd, guint64 offset, guint64 size, gboolean read_only, gboolean part_scan, const gchar **loop_name, GError **error) {
    return _bd_loop_setup_from_fd (fd, offset, size, read_only, part_scan, loop_name, error);
}


gboolean  bd_loop_teardown_stub (const gchar *loop, GError **error) {
    g_critical ("The function 'bd_loop_teardown' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_teardown' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_loop_teardown) (const gchar *loop, GError **error) = bd_loop_teardown_stub;

/**
 * bd_loop_teardown:
 * @loop: path or name of the loop device to tear down
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @loop device was successfully torn down or not
 *
 * Tech category: %BD_LOOP_TECH_LOOP-%BD_LOOP_TECH_MODE_DESTROY
 */
gboolean  bd_loop_teardown (const gchar *loop, GError **error) {
    return _bd_loop_teardown (loop, error);
}


gboolean  bd_loop_get_autoclear_stub (const gchar *loop, GError **error) {
    g_critical ("The function 'bd_loop_get_autoclear' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_get_autoclear' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_loop_get_autoclear) (const gchar *loop, GError **error) = bd_loop_get_autoclear_stub;

/**
 * bd_loop_get_autoclear:
 * @loop: path or name of the loop device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the autoclear flag is set on the @loop device or not (if %FALSE, @error may be set)
 *
 * Tech category: %BD_LOOP_TECH_LOOP-%BD_LOOP_TECH_MODE_QUERY
 */
gboolean  bd_loop_get_autoclear (const gchar *loop, GError **error) {
    return _bd_loop_get_autoclear (loop, error);
}


gboolean  bd_loop_set_autoclear_stub (const gchar *loop, gboolean autoclear, GError **error) {
    g_critical ("The function 'bd_loop_set_autoclear' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_set_autoclear' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_loop_set_autoclear) (const gchar *loop, gboolean autoclear, GError **error) = bd_loop_set_autoclear_stub;

/**
 * bd_loop_set_autoclear:
 * @loop: path or name of the loop device
 * @autoclear: whether to set or unset the autoclear flag
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the autoclear flag was successfully set on the @loop device or not
 *
 * Tech category: %BD_LOOP_TECH_LOOP-%BD_LOOP_TECH_MODE_MODIFY
 */
gboolean  bd_loop_set_autoclear (const gchar *loop, gboolean autoclear, GError **error) {
    return _bd_loop_set_autoclear (loop, autoclear, error);
}


gpointer load_loop_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module loop: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_loop_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for loop: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_loop_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for loop: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_loop_is_tech_avail) = dlsym(handle, "bd_loop_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_loop_get_backing_file) = dlsym(handle, "bd_loop_get_backing_file");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_get_backing_file: %s", error);

    dlerror();
    * (void**) (&_bd_loop_get_loop_name) = dlsym(handle, "bd_loop_get_loop_name");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_get_loop_name: %s", error);

    dlerror();
    * (void**) (&_bd_loop_setup) = dlsym(handle, "bd_loop_setup");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_setup: %s", error);

    dlerror();
    * (void**) (&_bd_loop_setup_from_fd) = dlsym(handle, "bd_loop_setup_from_fd");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_setup_from_fd: %s", error);

    dlerror();
    * (void**) (&_bd_loop_teardown) = dlsym(handle, "bd_loop_teardown");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_teardown: %s", error);

    dlerror();
    * (void**) (&_bd_loop_get_autoclear) = dlsym(handle, "bd_loop_get_autoclear");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_get_autoclear: %s", error);

    dlerror();
    * (void**) (&_bd_loop_set_autoclear) = dlsym(handle, "bd_loop_set_autoclear");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_set_autoclear: %s", error);

    return handle;
}

gboolean unload_loop (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_loop_is_tech_avail = bd_loop_is_tech_avail_stub;
    _bd_loop_get_backing_file = bd_loop_get_backing_file_stub;
    _bd_loop_get_loop_name = bd_loop_get_loop_name_stub;
    _bd_loop_setup = bd_loop_setup_stub;
    _bd_loop_setup_from_fd = bd_loop_setup_from_fd_stub;
    _bd_loop_teardown = bd_loop_teardown_stub;
    _bd_loop_get_autoclear = bd_loop_get_autoclear_stub;
    _bd_loop_set_autoclear = bd_loop_set_autoclear_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_loop_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for loop: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

