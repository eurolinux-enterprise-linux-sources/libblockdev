GQuark  bd_kbd_error_quark (void) {
        return g_quark_from_static_string ("g-bd-kbd-error-quark");
}

/**
 * BDKBDZramStats:
 *
 * see zRAM kernel documentation for details
 * (https://www.kernel.org/doc/Documentation/blockdev/zram.txt)
 */
/**
 * bd_kbd_zram_stats_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDKBDZramStats* bd_kbd_zram_stats_copy (BDKBDZramStats *data) {
        BDKBDZramStats *new = g_new0 (BDKBDZramStats, 1);
    new->disksize = data->disksize;
    new->num_reads = data->num_reads;
    new->num_writes = data->num_writes;
    new->invalid_io = data->invalid_io;
    new->zero_pages = data->zero_pages;
    new->max_comp_streams = data->max_comp_streams;
    new->comp_algorithm = g_strdup (data->comp_algorithm);
    new->orig_data_size = data->orig_data_size;
    new->compr_data_size = data->compr_data_size;
    new->mem_used_total = data->mem_used_total;

    return new;
}

/**
 * bd_kbd_zram_stats_free: (skip)
 *
 * Frees @data.
 */
void  bd_kbd_zram_stats_free (BDKBDZramStats *data) {
        g_free (data->comp_algorithm);
    g_free (data);
}

GType  bd_kbd_zram_stats_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDKBDZramStats",
                                            (GBoxedCopyFunc) bd_kbd_zram_stats_copy,
                                            (GBoxedFreeFunc) bd_kbd_zram_stats_free);
    }

    return type;
}

/**
 * BDKBDBcacheStats:
 * @state: state of the cache
 * @block_size: block size used by the cache
 * @cache_size: size of the cache
 * @cache_used: size of the used space in the cache
 * @hits: number of hits
 * @misses: number of misses
 * @bypass_hits: number of bypass hits
 * @bypass_misses: number of bypass misses
 */
/**
 * bd_kbd_bcache_stats_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDKBDBcacheStats* bd_kbd_bcache_stats_copy (BDKBDBcacheStats *data) {
        BDKBDBcacheStats *new = g_new0 (BDKBDBcacheStats, 1);

    new->state = g_strdup (data->state);
    new->block_size = data->block_size;
    new->cache_size = data->cache_size;
    new->cache_used = data->cache_used;
    new->hits = data->hits;
    new->misses = data->misses;
    new->bypass_hits = data->bypass_hits;
    new->bypass_misses = data->bypass_misses;

    return new;
}

/**
 * bd_kbd_bcache_stats_free: (skip)
 *
 * Frees @data.
 */
void  bd_kbd_bcache_stats_free (BDKBDBcacheStats *data) {
        g_free (data->state);
    g_free (data);
}

GType  bd_kbd_bcache_stats_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDKBDBcacheStats",
                                            (GBoxedCopyFunc) bd_kbd_bcache_stats_copy,
                                            (GBoxedFreeFunc) bd_kbd_bcache_stats_free);
    }

    return type;
}

static const gchar* const kbd_functions[] = {
    "bd_kbd_is_tech_avail",
    "bd_kbd_zram_create_devices",
    "bd_kbd_zram_destroy_devices",
    "bd_kbd_zram_add_device",
    "bd_kbd_zram_remove_device",
    "bd_kbd_zram_get_stats",
    "bd_kbd_bcache_create",
    "bd_kbd_bcache_attach",
    "bd_kbd_bcache_detach",
    "bd_kbd_bcache_destroy",
    "bd_kbd_bcache_get_mode",
    "bd_kbd_bcache_get_mode_str",
    "bd_kbd_bcache_get_mode_from_str",
    "bd_kbd_bcache_set_mode",
    "bd_kbd_bcache_status",
    "bd_kbd_bcache_get_backing_device",
    "bd_kbd_bcache_get_cache_device",
    NULL};

const gchar* const* get_kbd_functions (void) {
    return kbd_functions;
}

static const guint8 kbd_num_functions = 17;

guint8 get_kbd_num_functions (void) {
    return kbd_num_functions;
}

gboolean  bd_kbd_is_tech_avail_stub (BDKBDTech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_kbd_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_is_tech_avail) (BDKBDTech tech, guint64 mode, GError **error) = bd_kbd_is_tech_avail_stub;

/**
 * bd_kbd_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDKBDTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_kbd_is_tech_avail (BDKBDTech tech, guint64 mode, GError **error) {
    return _bd_kbd_is_tech_avail (tech, mode, error);
}


gboolean  bd_kbd_zram_create_devices_stub (guint64 num_devices, const guint64 *sizes, const guint64 *nstreams, GError **error) {
    g_critical ("The function 'bd_kbd_zram_create_devices' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_zram_create_devices' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_zram_create_devices) (guint64 num_devices, const guint64 *sizes, const guint64 *nstreams, GError **error) = bd_kbd_zram_create_devices_stub;

/**
 * bd_kbd_zram_create_devices:
 * @num_devices: number of devices to create
 * @sizes: (array zero-terminated=1): requested sizes (in bytes) for created zRAM
 *                                    devices
 * @nstreams: (allow-none) (array zero-terminated=1): numbers of streams for created
 *                                                    zRAM devices
 * @error: (out): place to store error (if any)
 *
 * Returns: whether @num_devices zRAM devices were successfully created or not
 *
 * **Lengths of @size and @nstreams (if given) have to be >= @num_devices!**
 *
 * Tech category: %BD_KBD_TECH_ZRAM-%BD_KBD_TECH_MODE_CREATE
 */
gboolean  bd_kbd_zram_create_devices (guint64 num_devices, const guint64 *sizes, const guint64 *nstreams, GError **error) {
    return _bd_kbd_zram_create_devices (num_devices, sizes, nstreams, error);
}


gboolean  bd_kbd_zram_destroy_devices_stub (GError **error) {
    g_critical ("The function 'bd_kbd_zram_destroy_devices' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_zram_destroy_devices' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_zram_destroy_devices) (GError **error) = bd_kbd_zram_destroy_devices_stub;

/**
 * bd_kbd_zram_destroy_devices:
 * @error: (out): place to store error (if any)
 *
 * Returns: whether zRAM devices were successfully destroyed or not
 *
 * The only way how to destroy zRAM device right now is to unload the 'zram'
 * module and thus destroy all of them. That's why this function doesn't allow
 * specification of which devices should be destroyed.
 *
 * Tech category: %BD_KBD_TECH_ZRAM-%BD_KBD_TECH_MODE_DESTROY
 */
gboolean  bd_kbd_zram_destroy_devices (GError **error) {
    return _bd_kbd_zram_destroy_devices (error);
}


gboolean  bd_kbd_zram_add_device_stub (guint64 size, guint64 nstreams, gchar **device, GError **error) {
    g_critical ("The function 'bd_kbd_zram_add_device' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_zram_add_device' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_zram_add_device) (guint64 size, guint64 nstreams, gchar **device, GError **error) = bd_kbd_zram_add_device_stub;

/**
 * bd_kbd_zram_add_device:
 * @size: size of the zRAM device to add
 * @nstreams: number of streams to use for the new device (or 0 to use the defaults)
 * @device: (allow-none) (out): place to store the name of the newly added device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a new zRAM device was added or not
 *
 * Tech category: %BD_KBD_TECH_ZRAM-%BD_KBD_TECH_MODE_MODIFY
 */
gboolean  bd_kbd_zram_add_device (guint64 size, guint64 nstreams, gchar **device, GError **error) {
    return _bd_kbd_zram_add_device (size, nstreams, device, error);
}


gboolean  bd_kbd_zram_remove_device_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_kbd_zram_remove_device' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_zram_remove_device' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_zram_remove_device) (const gchar *device, GError **error) = bd_kbd_zram_remove_device_stub;

/**
 * bd_kbd_zram_remove_device:
 * @device: zRAM device to remove
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully removed or not
 *
 * Tech category: %BD_KBD_TECH_ZRAM-%BD_KBD_TECH_MODE_MODIFY
 */
gboolean  bd_kbd_zram_remove_device (const gchar *device, GError **error) {
    return _bd_kbd_zram_remove_device (device, error);
}


BDKBDZramStats* bd_kbd_zram_get_stats_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_kbd_zram_get_stats' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_zram_get_stats' called, but not implemented!");
    return NULL;
}

BDKBDZramStats* (*_bd_kbd_zram_get_stats) (const gchar *device, GError **error) = bd_kbd_zram_get_stats_stub;

/**
 * bd_kbd_zram_get_stats:
 * @device: zRAM device to get stats for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): statistics for the zRAM device
 *
 * Tech category: %BD_KBD_TECH_ZRAM-%BD_KBD_TECH_MODE_QUERY
 */
BDKBDZramStats* bd_kbd_zram_get_stats (const gchar *device, GError **error) {
    return _bd_kbd_zram_get_stats (device, error);
}


gboolean  bd_kbd_bcache_create_stub (const gchar *backing_device, const gchar *cache_device, const BDExtraArg **extra, const gchar **bcache_device, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_create' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_create' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_bcache_create) (const gchar *backing_device, const gchar *cache_device, const BDExtraArg **extra, const gchar **bcache_device, GError **error) = bd_kbd_bcache_create_stub;

/**
 * bd_kbd_bcache_create:
 * @backing_device: backing (slow) device of the cache
 * @cache_device: cache (fast) device of the cache
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'make-bcache' utility)
 * @bcache_device: (out) (allow-none) (transfer full): place to store the name of the new bcache device (if any)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the bcache device was successfully created or not
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_CREATE
 */
gboolean  bd_kbd_bcache_create (const gchar *backing_device, const gchar *cache_device, const BDExtraArg **extra, const gchar **bcache_device, GError **error) {
    return _bd_kbd_bcache_create (backing_device, cache_device, extra, bcache_device, error);
}


gboolean  bd_kbd_bcache_attach_stub (const gchar *c_set_uuid, const gchar *bcache_device, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_attach' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_attach' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_bcache_attach) (const gchar *c_set_uuid, const gchar *bcache_device, GError **error) = bd_kbd_bcache_attach_stub;

/**
 * bd_kbd_bcache_attach:
 * @c_set_uuid: cache set UUID of the cache to attach
 * @bcache_device: bcache device to attach @c_set_uuid cache to
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @c_set_uuid cache was successfully attached to @bcache_device or not
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_MODIFY
 */
gboolean  bd_kbd_bcache_attach (const gchar *c_set_uuid, const gchar *bcache_device, GError **error) {
    return _bd_kbd_bcache_attach (c_set_uuid, bcache_device, error);
}


gboolean  bd_kbd_bcache_detach_stub (const gchar *bcache_device, gchar **c_set_uuid, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_detach' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_detach' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_bcache_detach) (const gchar *bcache_device, gchar **c_set_uuid, GError **error) = bd_kbd_bcache_detach_stub;

/**
 * bd_kbd_bcache_detach:
 * @bcache_device: bcache device to detach the cache from
 * @c_set_uuid: (out) (allow-none) (transfer full): cache set UUID of the detached cache
 * @error: (out): place to store error (if any)
 * Returns: whether the bcache device @bcache_device was successfully destroyed or not
 *
 * Note: Flushes the cache first.
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_MODIFY
 */
gboolean  bd_kbd_bcache_detach (const gchar *bcache_device, gchar **c_set_uuid, GError **error) {
    return _bd_kbd_bcache_detach (bcache_device, c_set_uuid, error);
}


gboolean  bd_kbd_bcache_destroy_stub (const gchar *bcache_device, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_destroy' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_destroy' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_bcache_destroy) (const gchar *bcache_device, GError **error) = bd_kbd_bcache_destroy_stub;

/**
 * bd_kbd_bcache_destroy:
 * @bcache_device: bcache device to destroy
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the bcache device @bcache_device was successfully destroyed or not
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_DESTROY
 */
gboolean  bd_kbd_bcache_destroy (const gchar *bcache_device, GError **error) {
    return _bd_kbd_bcache_destroy (bcache_device, error);
}


BDKBDBcacheMode  bd_kbd_bcache_get_mode_stub (const gchar *bcache_device, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_get_mode' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_get_mode' called, but not implemented!");
    return 0;
}

BDKBDBcacheMode  (*_bd_kbd_bcache_get_mode) (const gchar *bcache_device, GError **error) = bd_kbd_bcache_get_mode_stub;

/**
 * bd_kbd_bcache_get_mode:
 * @bcache_device: device to get mode of
 * @error: (out): place to store error (if any)
 *
 * Returns: current mode of the @bcache_device
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_QUERY
 */
BDKBDBcacheMode  bd_kbd_bcache_get_mode (const gchar *bcache_device, GError **error) {
    return _bd_kbd_bcache_get_mode (bcache_device, error);
}


const gchar* bd_kbd_bcache_get_mode_str_stub (BDKBDBcacheMode mode, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_get_mode_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_get_mode_str' called, but not implemented!");
    return NULL;
}

const gchar* (*_bd_kbd_bcache_get_mode_str) (BDKBDBcacheMode mode, GError **error) = bd_kbd_bcache_get_mode_str_stub;

/**
 * bd_kbd_bcache_get_mode_str:
 * @mode: mode to get string representation of
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer none): string representation of @mode or %NULL in case of error
 *
 * Tech category: always available
 */
const gchar* bd_kbd_bcache_get_mode_str (BDKBDBcacheMode mode, GError **error) {
    return _bd_kbd_bcache_get_mode_str (mode, error);
}


BDKBDBcacheMode  bd_kbd_bcache_get_mode_from_str_stub (const gchar *mode_str, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_get_mode_from_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_get_mode_from_str' called, but not implemented!");
    return 0;
}

BDKBDBcacheMode  (*_bd_kbd_bcache_get_mode_from_str) (const gchar *mode_str, GError **error) = bd_kbd_bcache_get_mode_from_str_stub;

/**
 * bd_kbd_bcache_get_mode_from_str:
 * @mode_str: string representation of mode
 * @error: (out): place to store error (if any)
 *
 * Returns: mode matching the @mode_str given or %BD_KBD_MODE_UNKNOWN in case of no match
 */
BDKBDBcacheMode  bd_kbd_bcache_get_mode_from_str (const gchar *mode_str, GError **error) {
    return _bd_kbd_bcache_get_mode_from_str (mode_str, error);
}


gboolean  bd_kbd_bcache_set_mode_stub (const gchar *bcache_device, BDKBDBcacheMode mode, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_set_mode' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_set_mode' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_kbd_bcache_set_mode) (const gchar *bcache_device, BDKBDBcacheMode mode, GError **error) = bd_kbd_bcache_set_mode_stub;

/**
 * bd_kbd_bcache_set_mode:
 * @bcache_device: bcache device to set mode of
 * @mode: mode to set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the mode was successfully set or not
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_MODIFY
 */
gboolean  bd_kbd_bcache_set_mode (const gchar *bcache_device, BDKBDBcacheMode mode, GError **error) {
    return _bd_kbd_bcache_set_mode (bcache_device, mode, error);
}


BDKBDBcacheStats* bd_kbd_bcache_status_stub (const gchar *bcache_device, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_status' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_status' called, but not implemented!");
    return NULL;
}

BDKBDBcacheStats* (*_bd_kbd_bcache_status) (const gchar *bcache_device, GError **error) = bd_kbd_bcache_status_stub;

/**
 * bd_kbd_bcache_status:
 * @bcache_device: bcache device to get status for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): status of the @bcache_device or %NULL in case of
 *                           error (@error is set)
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_QUERY
 */
BDKBDBcacheStats* bd_kbd_bcache_status (const gchar *bcache_device, GError **error) {
    return _bd_kbd_bcache_status (bcache_device, error);
}


gchar* bd_kbd_bcache_get_backing_device_stub (const gchar *bcache_device, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_get_backing_device' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_get_backing_device' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_kbd_bcache_get_backing_device) (const gchar *bcache_device, GError **error) = bd_kbd_bcache_get_backing_device_stub;

/**
 * bd_kbd_bcache_get_backing_device:
 * @bcache_device: Bcache device to get the backing device for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): name of the backing device of the @bcache_device
 *                           or %NULL if failed to determine (@error is populated)
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_QUERY
 */
gchar* bd_kbd_bcache_get_backing_device (const gchar *bcache_device, GError **error) {
    return _bd_kbd_bcache_get_backing_device (bcache_device, error);
}


gchar* bd_kbd_bcache_get_cache_device_stub (const gchar *bcache_device, GError **error) {
    g_critical ("The function 'bd_kbd_bcache_get_cache_device' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_kbd_bcache_get_cache_device' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_kbd_bcache_get_cache_device) (const gchar *bcache_device, GError **error) = bd_kbd_bcache_get_cache_device_stub;

/**
 * bd_kbd_bcache_get_cache_device:
 * @bcache_device: Bcache device to get the cache device for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): name of the cache device of the @bcache_device
 *                           or %NULL if failed to determine (@error is populated)
 *
 * Note: returns the name of the first cache device of @bcache_device (in case
 *       there are more)
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_QUERY
 */
gchar* bd_kbd_bcache_get_cache_device (const gchar *bcache_device, GError **error) {
    return _bd_kbd_bcache_get_cache_device (bcache_device, error);
}


gpointer load_kbd_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module kbd: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_kbd_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for kbd: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_kbd_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for kbd: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_kbd_is_tech_avail) = dlsym(handle, "bd_kbd_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_zram_create_devices) = dlsym(handle, "bd_kbd_zram_create_devices");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_zram_create_devices: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_zram_destroy_devices) = dlsym(handle, "bd_kbd_zram_destroy_devices");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_zram_destroy_devices: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_zram_add_device) = dlsym(handle, "bd_kbd_zram_add_device");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_zram_add_device: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_zram_remove_device) = dlsym(handle, "bd_kbd_zram_remove_device");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_zram_remove_device: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_zram_get_stats) = dlsym(handle, "bd_kbd_zram_get_stats");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_zram_get_stats: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_create) = dlsym(handle, "bd_kbd_bcache_create");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_create: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_attach) = dlsym(handle, "bd_kbd_bcache_attach");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_attach: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_detach) = dlsym(handle, "bd_kbd_bcache_detach");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_detach: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_destroy) = dlsym(handle, "bd_kbd_bcache_destroy");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_destroy: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_get_mode) = dlsym(handle, "bd_kbd_bcache_get_mode");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_get_mode: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_get_mode_str) = dlsym(handle, "bd_kbd_bcache_get_mode_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_get_mode_str: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_get_mode_from_str) = dlsym(handle, "bd_kbd_bcache_get_mode_from_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_get_mode_from_str: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_set_mode) = dlsym(handle, "bd_kbd_bcache_set_mode");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_set_mode: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_status) = dlsym(handle, "bd_kbd_bcache_status");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_status: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_get_backing_device) = dlsym(handle, "bd_kbd_bcache_get_backing_device");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_get_backing_device: %s", error);

    dlerror();
    * (void**) (&_bd_kbd_bcache_get_cache_device) = dlsym(handle, "bd_kbd_bcache_get_cache_device");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_kbd_bcache_get_cache_device: %s", error);

    return handle;
}

gboolean unload_kbd (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_kbd_is_tech_avail = bd_kbd_is_tech_avail_stub;
    _bd_kbd_zram_create_devices = bd_kbd_zram_create_devices_stub;
    _bd_kbd_zram_destroy_devices = bd_kbd_zram_destroy_devices_stub;
    _bd_kbd_zram_add_device = bd_kbd_zram_add_device_stub;
    _bd_kbd_zram_remove_device = bd_kbd_zram_remove_device_stub;
    _bd_kbd_zram_get_stats = bd_kbd_zram_get_stats_stub;
    _bd_kbd_bcache_create = bd_kbd_bcache_create_stub;
    _bd_kbd_bcache_attach = bd_kbd_bcache_attach_stub;
    _bd_kbd_bcache_detach = bd_kbd_bcache_detach_stub;
    _bd_kbd_bcache_destroy = bd_kbd_bcache_destroy_stub;
    _bd_kbd_bcache_get_mode = bd_kbd_bcache_get_mode_stub;
    _bd_kbd_bcache_get_mode_str = bd_kbd_bcache_get_mode_str_stub;
    _bd_kbd_bcache_get_mode_from_str = bd_kbd_bcache_get_mode_from_str_stub;
    _bd_kbd_bcache_set_mode = bd_kbd_bcache_set_mode_stub;
    _bd_kbd_bcache_status = bd_kbd_bcache_status_stub;
    _bd_kbd_bcache_get_backing_device = bd_kbd_bcache_get_backing_device_stub;
    _bd_kbd_bcache_get_cache_device = bd_kbd_bcache_get_cache_device_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_kbd_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for kbd: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

