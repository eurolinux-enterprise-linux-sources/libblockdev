GQuark  bd_dm_error_quark (void) {
        return g_quark_from_static_string ("g-bd-dm-error-quark");
}

static const gchar const * const dm_functions[] = {
    "bd_dm_create_linear",
    "bd_dm_remove",
    "bd_dm_name_from_node",
    "bd_dm_node_from_name",
    "bd_dm_map_exists",
    "bd_dm_get_member_raid_sets",
    "bd_dm_activate_raid_set",
    "bd_dm_deactivate_raid_set",
    "bd_dm_get_raid_set_type",
    NULL};

gchar const * const * get_dm_functions (void) {
    return dm_functions;
}

static const guint8 dm_num_functions = 9;

guint8 get_dm_num_functions (void) {
    return dm_num_functions;
}

gboolean  bd_dm_create_linear_stub (const gchar *map_name, const gchar *device, guint64 length, const gchar *uuid, GError **error) {
    g_critical ("The function 'bd_dm_create_linear' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_create_linear' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_dm_create_linear) (const gchar *map_name, const gchar *device, guint64 length, const gchar *uuid, GError **error) = bd_dm_create_linear_stub;

/**
 * bd_dm_create_linear:
 * @map_name: name of the map
 * @device: device to create map for
 * @length: length of the mapping in sectors
 * @uuid: (allow-none): UUID for the new dev mapper device or %NULL if not specified
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the new linear mapping @map_name was successfully created
 * for the @device or not
 */
gboolean  bd_dm_create_linear (const gchar *map_name, const gchar *device, guint64 length, const gchar *uuid, GError **error) {
    return _bd_dm_create_linear (map_name, device, length, uuid, error);
}


gboolean  bd_dm_remove_stub (const gchar *map_name, GError **error) {
    g_critical ("The function 'bd_dm_remove' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_remove' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_dm_remove) (const gchar *map_name, GError **error) = bd_dm_remove_stub;

/**
 * bd_dm_remove:
 * @map_name: name of the map to remove
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @map_name map was successfully removed or not
 */
gboolean  bd_dm_remove (const gchar *map_name, GError **error) {
    return _bd_dm_remove (map_name, error);
}


gchar* bd_dm_name_from_node_stub (const gchar *dm_node, GError **error) {
    g_critical ("The function 'bd_dm_name_from_node' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_name_from_node' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_dm_name_from_node) (const gchar *dm_node, GError **error) = bd_dm_name_from_node_stub;

/**
 * bd_dm_name_from_node:
 * @dm_node: name of the DM node (e.g. "dm-0")
 * @error: (out): place to store error (if any)
 *
 * Returns: map name of the map providing the @dm_node device or %NULL
 * (@error) contains the error in such cases)
 */
gchar* bd_dm_name_from_node (const gchar *dm_node, GError **error) {
    return _bd_dm_name_from_node (dm_node, error);
}


gchar* bd_dm_node_from_name_stub (const gchar *map_name, GError **error) {
    g_critical ("The function 'bd_dm_node_from_name' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_node_from_name' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_dm_node_from_name) (const gchar *map_name, GError **error) = bd_dm_node_from_name_stub;

/**
 * bd_dm_node_from_name:
 * @map_name: name of the queried DM map
 * @error: (out): place to store error (if any)
 *
 * Returns: DM node name for the @map_name map or %NULL (@error) contains
 * the error in such cases)
 */
gchar* bd_dm_node_from_name (const gchar *map_name, GError **error) {
    return _bd_dm_node_from_name (map_name, error);
}


gboolean  bd_dm_map_exists_stub (const gchar *map_name, gboolean live_only, gboolean active_only, GError **error) {
    g_critical ("The function 'bd_dm_map_exists' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_map_exists' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_dm_map_exists) (const gchar *map_name, gboolean live_only, gboolean active_only, GError **error) = bd_dm_map_exists_stub;

/**
 * bd_dm_map_exists:
 * @map_name: name of the queried map
 * @live_only: whether to go through the live maps only or not
 * @active_only: whether to ignore suspended maps or not
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @map_name exists (and is live if @live_only is
 * %TRUE (and is active if @active_only is %TRUE)).
 */
gboolean  bd_dm_map_exists (const gchar *map_name, gboolean live_only, gboolean active_only, GError **error) {
    return _bd_dm_map_exists (map_name, live_only, active_only, error);
}


gchar** bd_dm_get_member_raid_sets_stub (const gchar *name, const gchar *uuid, gint major, gint minor, GError **error) {
    g_critical ("The function 'bd_dm_get_member_raid_sets' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_get_member_raid_sets' called, but not implemented!");
    return NULL;
}

gchar** (*_bd_dm_get_member_raid_sets) (const gchar *name, const gchar *uuid, gint major, gint minor, GError **error) = bd_dm_get_member_raid_sets_stub;

/**
 * bd_dm_get_member_raid_sets:
 * @name: (allow-none): name of the member
 * @uuid: (allow-none): uuid of the member
 * @major: major number of the device or -1 if not specified
 * @minor: minor number of the device or -1 if not specified
 * @error: (out): variable to store error (if any)
 *
 * Returns: (transfer full) (array zero-terminated=1): list of names of the RAID sets related to
 * the member or %NULL in case of error
 *
 * One of @name, @uuid or @major:@minor has to be given.
 */
gchar** bd_dm_get_member_raid_sets (const gchar *name, const gchar *uuid, gint major, gint minor, GError **error) {
    return _bd_dm_get_member_raid_sets (name, uuid, major, minor, error);
}


gboolean  bd_dm_activate_raid_set_stub (const gchar *name, GError **error) {
    g_critical ("The function 'bd_dm_activate_raid_set' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_activate_raid_set' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_dm_activate_raid_set) (const gchar *name, GError **error) = bd_dm_activate_raid_set_stub;

/**
 * bd_dm_activate_raid_set:
 * @name: name of the DM RAID set to activate
 * @error: (out): variable to store error (if any)
 *
 * Returns: whether the RAID set @name was successfully activate or not
 */
gboolean  bd_dm_activate_raid_set (const gchar *name, GError **error) {
    return _bd_dm_activate_raid_set (name, error);
}


gboolean  bd_dm_deactivate_raid_set_stub (const gchar *name, GError **error) {
    g_critical ("The function 'bd_dm_deactivate_raid_set' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_deactivate_raid_set' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_dm_deactivate_raid_set) (const gchar *name, GError **error) = bd_dm_deactivate_raid_set_stub;

/**
 * bd_dm_deactivate_raid_set:
 * @name: name of the DM RAID set to deactivate
 * @error: (out): variable to store error (if any)
 *
 * Returns: whether the RAID set @name was successfully deactivate or not
 */
gboolean  bd_dm_deactivate_raid_set (const gchar *name, GError **error) {
    return _bd_dm_deactivate_raid_set (name, error);
}


gchar* bd_dm_get_raid_set_type_stub (const gchar *name, GError **error) {
    g_critical ("The function 'bd_dm_get_raid_set_type' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_dm_get_raid_set_type' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_dm_get_raid_set_type) (const gchar *name, GError **error) = bd_dm_get_raid_set_type_stub;

/**
 * bd_dm_get_raid_set_type:
 * @name: name of the DM RAID set to get the type of
 * @error: (out): variable to store error (if any)
 *
 * Returns: string representation of the @name RAID set's type
 */
gchar* bd_dm_get_raid_set_type (const gchar *name, GError **error) {
    return _bd_dm_get_raid_set_type (name, error);
}


gpointer load_dm_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module dm: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_dm_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for dm: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_dm_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for dm: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_dm_create_linear) = dlsym(handle, "bd_dm_create_linear");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_create_linear: %s", error);

    dlerror();
    * (void**) (&_bd_dm_remove) = dlsym(handle, "bd_dm_remove");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_remove: %s", error);

    dlerror();
    * (void**) (&_bd_dm_name_from_node) = dlsym(handle, "bd_dm_name_from_node");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_name_from_node: %s", error);

    dlerror();
    * (void**) (&_bd_dm_node_from_name) = dlsym(handle, "bd_dm_node_from_name");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_node_from_name: %s", error);

    dlerror();
    * (void**) (&_bd_dm_map_exists) = dlsym(handle, "bd_dm_map_exists");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_map_exists: %s", error);

    dlerror();
    * (void**) (&_bd_dm_get_member_raid_sets) = dlsym(handle, "bd_dm_get_member_raid_sets");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_get_member_raid_sets: %s", error);

    dlerror();
    * (void**) (&_bd_dm_activate_raid_set) = dlsym(handle, "bd_dm_activate_raid_set");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_activate_raid_set: %s", error);

    dlerror();
    * (void**) (&_bd_dm_deactivate_raid_set) = dlsym(handle, "bd_dm_deactivate_raid_set");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_deactivate_raid_set: %s", error);

    dlerror();
    * (void**) (&_bd_dm_get_raid_set_type) = dlsym(handle, "bd_dm_get_raid_set_type");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_dm_get_raid_set_type: %s", error);

    return handle;
}

gboolean unload_dm (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_dm_create_linear = bd_dm_create_linear_stub;
    _bd_dm_remove = bd_dm_remove_stub;
    _bd_dm_name_from_node = bd_dm_name_from_node_stub;
    _bd_dm_node_from_name = bd_dm_node_from_name_stub;
    _bd_dm_map_exists = bd_dm_map_exists_stub;
    _bd_dm_get_member_raid_sets = bd_dm_get_member_raid_sets_stub;
    _bd_dm_activate_raid_set = bd_dm_activate_raid_set_stub;
    _bd_dm_deactivate_raid_set = bd_dm_deactivate_raid_set_stub;
    _bd_dm_get_raid_set_type = bd_dm_get_raid_set_type_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_dm_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for dm: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

