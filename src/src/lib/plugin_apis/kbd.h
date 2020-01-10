#include <glib.h>
#include <glib-object.h>
#include <blockdev/utils.h>


#ifndef BD_KBD_API
#define BD_KBD_API

GQuark  bd_kbd_error_quark (void);


#define BD_KBD_ERROR bd_kbd_error_quark ()
typedef enum {
    BD_KBD_ERROR_INVAL,
    BD_KBD_ERROR_KMOD_INIT_FAIL,
    BD_KBD_ERROR_MODULE_FAIL,
    BD_KBD_ERROR_MODULE_NOEXIST,
    BD_KBD_ERROR_ZRAM_NOEXIST,
    BD_KBD_ERROR_ZRAM_INVAL,
    BD_KBD_ERROR_BCACHE_PARSE,
    BD_KBD_ERROR_BCACHE_SETUP_FAIL,
    BD_KBD_ERROR_BCACHE_DETACH_FAIL,
    BD_KBD_ERROR_BCACHE_NOT_ATTACHED,
    BD_KBD_ERROR_BCACHE_UUID,
    BD_KBD_ERROR_BCACHE_MODE_FAIL,
    BD_KBD_ERROR_BCACHE_MODE_INVAL,
    BD_KBD_ERROR_BCACHE_NOEXIST,
    BD_KBD_ERROR_BCACHE_INVAL,
    BD_KBD_ERROR_TECH_UNAVAIL,
} BDKBDError;

typedef enum {
    BD_KBD_MODE_WRITETHROUGH,
    BD_KBD_MODE_WRITEBACK,
    BD_KBD_MODE_WRITEAROUND,
    BD_KBD_MODE_NONE,
    BD_KBD_MODE_UNKNOWN,
} BDKBDBcacheMode;

#define BD_KBD_TYPE_ZRAM_STATS (bd_kbd_zram_stats_get_type ())
GType  bd_kbd_zram_stats_get_type ();


typedef struct BDKBDZramStats {
    guint64 disksize;
    guint64 num_reads;
    guint64 num_writes;
    guint64 invalid_io;
    guint64 zero_pages;
    guint64 max_comp_streams;
    gchar* comp_algorithm;
    guint64 orig_data_size;
    guint64 compr_data_size;
    guint64 mem_used_total;
} BDKBDZramStats;

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
BDKBDZramStats* bd_kbd_zram_stats_copy (BDKBDZramStats *data);


/**
 * bd_kbd_zram_stats_free: (skip)
 *
 * Frees @data.
 */
void  bd_kbd_zram_stats_free (BDKBDZramStats *data);



#define BD_KBD_TYPE_BCACHE_STATS (bd_kbd_bcache_stats_get_type ())
GType  bd_kbd_bcache_stats_get_type ();


typedef struct BDKBDBcacheStats {
    gchar *state;
    guint64 block_size;
    guint64 cache_size;
    guint64 cache_used;
    guint64 hits;
    guint64 misses;
    guint64 bypass_hits;
    guint64 bypass_misses;
} BDKBDBcacheStats;

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
BDKBDBcacheStats* bd_kbd_bcache_stats_copy (BDKBDBcacheStats *data);


/**
 * bd_kbd_bcache_stats_free: (skip)
 *
 * Frees @data.
 */
void  bd_kbd_bcache_stats_free (BDKBDBcacheStats *data);



typedef enum {
    BD_KBD_TECH_ZRAM = 0,
    BD_KBD_TECH_BCACHE,
} BDKBDTech;

typedef enum {
    BD_KBD_TECH_MODE_CREATE  = 1 << 0,
    BD_KBD_TECH_MODE_DESTROY = 1 << 1,
    BD_KBD_TECH_MODE_MODIFY  = 1 << 2,
    BD_KBD_TECH_MODE_QUERY   = 1 << 3,
} BDKBDTechMode;

/**
 * bd_kbd_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDKBDTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_kbd_is_tech_avail (BDKBDTech tech, guint64 mode, GError **error);


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
gboolean  bd_kbd_zram_create_devices (guint64 num_devices, const guint64 *sizes, const guint64 *nstreams, GError **error);


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
gboolean  bd_kbd_zram_destroy_devices (GError **error);


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
gboolean  bd_kbd_zram_add_device (guint64 size, guint64 nstreams, gchar **device, GError **error);


/**
 * bd_kbd_zram_remove_device:
 * @device: zRAM device to remove
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully removed or not
 *
 * Tech category: %BD_KBD_TECH_ZRAM-%BD_KBD_TECH_MODE_MODIFY
 */
gboolean  bd_kbd_zram_remove_device (const gchar *device, GError **error);


/**
 * bd_kbd_zram_get_stats:
 * @device: zRAM device to get stats for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): statistics for the zRAM device
 *
 * Tech category: %BD_KBD_TECH_ZRAM-%BD_KBD_TECH_MODE_QUERY
 */
BDKBDZramStats* bd_kbd_zram_get_stats (const gchar *device, GError **error);


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
gboolean  bd_kbd_bcache_create (const gchar *backing_device, const gchar *cache_device, const BDExtraArg **extra, const gchar **bcache_device, GError **error);


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
gboolean  bd_kbd_bcache_attach (const gchar *c_set_uuid, const gchar *bcache_device, GError **error);


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
gboolean  bd_kbd_bcache_detach (const gchar *bcache_device, gchar **c_set_uuid, GError **error);


/**
 * bd_kbd_bcache_destroy:
 * @bcache_device: bcache device to destroy
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the bcache device @bcache_device was successfully destroyed or not
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_DESTROY
 */
gboolean  bd_kbd_bcache_destroy (const gchar *bcache_device, GError **error);


/**
 * bd_kbd_bcache_get_mode:
 * @bcache_device: device to get mode of
 * @error: (out): place to store error (if any)
 *
 * Returns: current mode of the @bcache_device
 *
 * Tech category: %BD_KBD_TECH_BCACHE-%BD_KBD_TECH_MODE_QUERY
 */
BDKBDBcacheMode  bd_kbd_bcache_get_mode (const gchar *bcache_device, GError **error);


/**
 * bd_kbd_bcache_get_mode_str:
 * @mode: mode to get string representation of
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer none): string representation of @mode or %NULL in case of error
 *
 * Tech category: always available
 */
const gchar* bd_kbd_bcache_get_mode_str (BDKBDBcacheMode mode, GError **error);


/**
 * bd_kbd_bcache_get_mode_from_str:
 * @mode_str: string representation of mode
 * @error: (out): place to store error (if any)
 *
 * Returns: mode matching the @mode_str given or %BD_KBD_MODE_UNKNOWN in case of no match
 */
BDKBDBcacheMode  bd_kbd_bcache_get_mode_from_str (const gchar *mode_str, GError **error);


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
gboolean  bd_kbd_bcache_set_mode (const gchar *bcache_device, BDKBDBcacheMode mode, GError **error);


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
BDKBDBcacheStats* bd_kbd_bcache_status (const gchar *bcache_device, GError **error);


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
gchar* bd_kbd_bcache_get_backing_device (const gchar *bcache_device, GError **error);


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
gchar* bd_kbd_bcache_get_cache_device (const gchar *bcache_device, GError **error);


#endif  /* BD_KBD_API */
