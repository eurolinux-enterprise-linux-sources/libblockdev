#include <glib.h>
#include <glib-object.h>
#include <blockdev/utils.h>


#ifndef BD_LVM_API
#define BD_LVM_API

#ifdef __LP64__
// 64bit system
#define BD_LVM_MAX_LV_SIZE (8 * 1152921504606846976ULL)
#else
// 32bit system
#define BD_LVM_MAX_LV_SIZE (16 * 1099511627776ULL)
#endif

#define BD_LVM_DEFAULT_PE_START (1 * 1048576ULL)
#define BD_LVM_DEFAULT_PE_SIZE (4 * 1048576ULL)
#define BD_LVM_MIN_PE_SIZE (1 * 1024ULL)
#define BD_LVM_MAX_PE_SIZE (16 * 1073741824ULL)
#define BD_LVM_MIN_THPOOL_MD_SIZE (2 * 1048576ULL)
#define BD_LVM_MAX_THPOOL_MD_SIZE (16 * 1073741824ULL)
#define BD_LVM_MIN_THPOOL_CHUNK_SIZE (64 * 1024ULL)
#define BD_LVM_MAX_THPOOL_CHUNK_SIZE (1 * 1073741824ULL)
#define BD_LVM_DEFAULT_CHUNK_SIZE (64 * 1024ULL)

/* according to lvmcache (7) */
#define BD_LVM_MIN_CACHE_MD_SIZE (8 * 1048576ULL)

GQuark  bd_lvm_error_quark (void);


#define BD_LVM_ERROR bd_lvm_error_quark ()
typedef enum {
    BD_LVM_ERROR_PARSE,
    BD_LVM_ERROR_NOEXIST,
    BD_LVM_ERROR_DM_ERROR,
    BD_LVM_ERROR_NOT_ROOT,
    BD_LVM_ERROR_CACHE_INVAL,
    BD_LVM_ERROR_CACHE_NOCACHE,
    BD_LVM_ERROR_TECH_UNAVAIL,
    BD_LVM_ERROR_FAIL,
} BDLVMError;

typedef enum {
    BD_LVM_CACHE_POOL_STRIPED = 1 << 0,
    BD_LVM_CACHE_POOL_RAID1 =    1 << 1,
    BD_LVM_CACHE_POOL_RAID5 =    1 << 2,
    BD_LVM_CACHE_POOL_RAID6 =    1 << 3,
    BD_LVM_CACHE_POOL_RAID10 =   1 << 4,

    BD_LVM_CACHE_POOL_META_STRIPED = 1 << 10,
    BD_LVM_CACHE_POOL_META_RAID1 =    1 << 11,
    BD_LVM_CACHE_POOL_META_RAID5 =    1 << 12,
    BD_LVM_CACHE_POOL_META_RAID6 =    1 << 13,
    BD_LVM_CACHE_POOL_META_RAID10 =   1 << 14,
} BDLVMCachePoolFlags;

typedef enum {
    BD_LVM_CACHE_MODE_WRITETHROUGH,
    BD_LVM_CACHE_MODE_WRITEBACK,
    BD_LVM_CACHE_MODE_UNKNOWN,
} BDLVMCacheMode;

#define BD_LVM_TYPE_PVDATA (bd_lvm_pvdata_get_type ())
GType  bd_lvm_pvdata_get_type ();


typedef struct BDLVMPVdata {
    gchar *pv_name;
    gchar *pv_uuid;
    guint64 pv_free;
    guint64 pv_size;
    guint64 pe_start;
    gchar *vg_name;
    gchar *vg_uuid;
    guint64 vg_size;
    guint64 vg_free;
    guint64 vg_extent_size;
    guint64 vg_extent_count;
    guint64 vg_free_count;
    guint64 vg_pv_count;
} BDLVMPVdata;

/**
 * BDLVMPVdata:
 * @pv_name: name of the PV
 * @pv_uuid: UUID of the PV
 * @pv_free: size of the free space in the PV
 * @pv_size: size of the PV
 * @pe_start: start of the physical extents area (i.e. offset of the first PE)
 * @vg_name: name of the VG the PV belongs to
 * @vg_uuid: UUID of the VG the PV belongs to
 * @vg_size: size of the VG the PV belongs to
 * @vg_free: size of the free space in the PV's VG
 * @vg_extent_size: extent size used by the PV's VG
 * @vg_extent_count: number of extents in the PV's VG
 * @vg_free_count: number of free extents in the PV's VG
 * @vg_pv_count: number of PVs that belong to this PV's VG
 */
/**
 * bd_lvm_pvdata_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDLVMPVdata* bd_lvm_pvdata_copy (BDLVMPVdata *data);


/**
 * bd_lvm_pvdata_free: (skip)
 *
 * Frees @data.
 */
void  bd_lvm_pvdata_free (BDLVMPVdata *data);



#define BD_LVM_TYPE_VGDATA (bd_lvm_vgdata_get_type ())
GType  bd_lvm_vgdata_get_type ();


typedef struct BDLVMVGdata {
    gchar *name;
    gchar *uuid;
    guint64 size;
    guint64 free;
    guint64 extent_size;
    guint64 extent_count;
    guint64 free_count;
    guint64 pv_count;
} BDLVMVGdata;

/**
 * BDLVMVGdata:
 * @name: name of the VG
 * @uuid: UUID of the VG
 * @size: size of the VG
 * @free: size of the free space in the VG
 * @extent_size: extent size used by the VG
 * @extent_count: number of extents in the VG
 * @free_count: number of free extents in the VG
 * @pv_count: number of PVs that belong to the VG
 */
/**
 * bd_lvm_vgdata_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDLVMVGdata* bd_lvm_vgdata_copy (BDLVMVGdata *data);


/**
 * bd_lvm_vgdata_free: (skip)
 *
 * Frees @data.
 */
void  bd_lvm_vgdata_free (BDLVMVGdata *data);



#define BD_LVM_TYPE_LVDATA (bd_lvm_lvdata_get_type ())
GType  bd_lvm_lvdata_get_type ();


typedef struct BDLVMLVdata {
    gchar *lv_name;
    gchar *vg_name;
    gchar *uuid;
    guint64 size;
    gchar *attr;
    gchar *segtype;
    gchar *origin;
    gchar *pool_lv;
    gchar *data_lv;
    gchar *metadata_lv;
    gchar *roles;
    gchar *move_pv;
    guint64 data_percent;
    guint64 metadata_percent;
    guint64 copy_percent;
} BDLVMLVdata;

/**
 * BDLVMLVdata:
 * @lv_name: name of the LV
 * @vg_name: name of the VG the LV belongs to
 * @uuid: UUID of the LV
 * @size: size of the LV
 * @attr: attributes of the LV
 * @segtype: segment type of the LV
 * @origin: origin of the LV (for snapshots, etc.)
 * @pool_lv: pool LV of the LV (for thin and cached LVs)
 * @data_lv: data LV of the LV (for thin and cache pools)
 * @metadata_lv: metadata LV of the LV (for thin and cache pools)
 */
/**
 * bd_lvm_lvdata_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDLVMLVdata* bd_lvm_lvdata_copy (BDLVMLVdata *data);


/**
 * bd_lvm_lvdata_free: (skip)
 *
 * Frees @data.
 */
void  bd_lvm_lvdata_free (BDLVMLVdata *data);



#define BD_LVM_TYPE_CACHE_STATS (bd_lvm_cache_stats_get_type ())
GType  bd_lvm_cache_stats_get_type ();


typedef struct BDLVMCacheStats {
    guint64 block_size;
    guint64 cache_size;
    guint64 cache_used;
    guint64 md_block_size;
    guint64 md_size;
    guint64 md_used;
    guint64 read_hits;
    guint64 read_misses;
    guint64 write_hits;
    guint64 write_misses;
    BDLVMCacheMode mode;
} BDLVMCacheStats;

/**
 * BDLVMCacheStats:
 * @block_size: block size used by the cache
 * @cache_size: size of the cache
 * @cache_used: size of the used space in the cache
 * @md_block_size: block size used for cache metadata
 * @md_size: size of the metadata space of the cache
 * @md_used: size of the used metadata space in the cache
 * @read_hits: number of read hits
 * @read_misses: number of read misses
 * @write_hits: number of write hits
 * @write_misses: number of write misses
 * @mode: mode the cache is operating in
 */
/**
 * bd_lvm_cache_stats_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDLVMCacheStats* bd_lvm_cache_stats_copy (BDLVMCacheStats *data);


/**
 * bd_lvm_cache_stats_free: (skip)
 *
 * Frees @data.
 */
void  bd_lvm_cache_stats_free (BDLVMLVdata *data);



typedef enum {
    BD_LVM_TECH_BASIC = 0,
    BD_LVM_TECH_BASIC_SNAP,
    BD_LVM_TECH_THIN,
    BD_LVM_TECH_CACHE,
    BD_LVM_TECH_CALCS,
    BD_LVM_TECH_THIN_CALCS,
    BD_LVM_TECH_CACHE_CALCS,
    BD_LVM_TECH_GLOB_CONF,
} BDLVMTech;

typedef enum {
    BD_LVM_TECH_MODE_CREATE = 1 << 0,
    BD_LVM_TECH_MODE_REMOVE = 1 << 2,
    BD_LVM_TECH_MODE_MODIFY = 1 << 3,
    BD_LVM_TECH_MODE_QUERY  = 1 << 4,
} BDLVMTechMode;


/**
 * bd_lvm_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDLVMTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is avaible -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_lvm_is_tech_avail (BDLVMTech tech, guint64 mode, GError **error);


/**
 * bd_lvm_is_supported_pe_size:
 * @size: size (in bytes) to test
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given size is supported physical extent size or not
 *
 * Tech category: %BD_LVM_TECH_CALCS no mode (it is ignored)
 */
gboolean  bd_lvm_is_supported_pe_size (guint64 size, GError **error);


/**
 * bd_lvm_get_supported_pe_sizes:
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full) (array zero-terminated=1): list of supported PE sizes
 *
 * Tech category: %BD_LVM_TECH_CALCS no mode (it is ignored)
 */
guint64 * bd_lvm_get_supported_pe_sizes (GError **error);


/**
 * bd_lvm_get_max_lv_size:
 * @error: (out): place to store error (if any)
 *
 * Returns: maximum LV size in bytes
 *
 * Tech category: %BD_LVM_TECH_CALCS no mode (it is ignored)
 */
guint64  bd_lvm_get_max_lv_size (GError **error);


/**
 * bd_lvm_round_size_to_pe:
 * @size: size to be rounded
 * @pe_size: physical extent (PE) size or 0 to use the default
 * @roundup: whether to round up or down (ceil or floor)
 * @error: (out): place to store error (if any)
 *
 * Returns: @size rounded to @pe_size according to the @roundup
 *
 * Rounds given @size up/down to a multiple of @pe_size according to the value
 * of the @roundup parameter. If the rounded value is too big to fit in the
 * return type, the result is rounded down (floored) regardless of the @roundup
 * parameter.
 *
 * Tech category: %BD_LVM_TECH_CALCS no mode (it is ignored)
 */
guint64  bd_lvm_round_size_to_pe (guint64 size, guint64 pe_size, gboolean roundup, GError **error);


/**
 * bd_lvm_get_lv_physical_size:
 * @lv_size: LV size
 * @pe_size: PE size
 * @error: (out): place to store error (if any)
 *
 * Returns: space taken on disk(s) by the LV with given @size
 *
 * Gives number of bytes needed for an LV with the size @lv_size on an LVM stack
 * using given @pe_size.
 *
 * Tech category: %BD_LVM_TECH_CALCS no mode (it is ignored)
 */
guint64  bd_lvm_get_lv_physical_size (guint64 lv_size, guint64 pe_size, GError **error);


/**
 * bd_lvm_get_thpool_padding:
 * @size: size of the thin pool
 * @pe_size: PE size or 0 if the default value should be used
 * @included: if padding is already included in the size
 * @error: (out): place to store error (if any)
 *
 * Returns: size of the padding needed for a thin pool with the given @size
 *         according to the @pe_size and @included
 *
 * Tech category: %BD_LVM_TECH_THIN_CALCS no mode (it is ignored)
 */
guint64  bd_lvm_get_thpool_padding (guint64 size, guint64 pe_size, gboolean included, GError **error);


/**
 * bd_lvm_get_thpool_meta_size:
 * @size: size of the thin pool
 * @chunk_size: chunk size of the thin pool or 0 to use the default (%BD_LVM_DEFAULT_CHUNK_SIZE)
 * @n_snapshots: number of snapshots that will be created in the pool
 * @error: (out): place to store error (if any)
 *
 * Returns: recommended size of the metadata space for the specified pool or 0
 *          in case of error
 *
 * Tech category: %BD_LVM_TECH_THIN_CALCS no mode (it is ignored)
 */
guint64  bd_lvm_get_thpool_meta_size (guint64 size, guint64 chunk_size, guint64 n_snapshots, GError **error);


/**
 * bd_lvm_is_valid_thpool_md_size:
 * @size: the size to be tested
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given size is a valid thin pool metadata size or not
 *
 * Tech category: %BD_LVM_TECH_THIN_CALCS no mode (it is ignored)
 */
gboolean  bd_lvm_is_valid_thpool_md_size (guint64 size, GError **error);


/**
 * bd_lvm_is_valid_thpool_chunk_size:
 * @size: the size to be tested
 * @discard: whether discard/TRIM is required to be supported or not
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given size is a valid thin pool chunk size or not
 *
 * Tech category: %BD_LVM_TECH_THIN_CALCS no mode (it is ignored)
 */
gboolean  bd_lvm_is_valid_thpool_chunk_size (guint64 size, gboolean discard, GError **error);


/**
 * bd_lvm_pvcreate:
 * @device: the device to make PV from
 * @data_alignment: data (first PE) alignment or 0 to use the default
 * @metadata_size: size of the area reserved for metadata or 0 to use the default
 * @extra: (allow-none) (array zero-terminated=1): extra options for the PV creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the PV was successfully created or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_pvcreate (const gchar *device, guint64 data_alignment, guint64 metadata_size, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_pvresize:
 * @device: the device to resize
 * @size: the new requested size of the PV or 0 if it should be adjusted to device's size
 * @extra: (allow-none) (array zero-terminated=1): extra options for the PV resize
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the PV's size was successfully changed or not
 *
 * If given @size different from 0, sets the PV's size to the given value (see
 * pvresize(8)). If given @size 0, adjusts the PV's size to the underlaying
 * block device's size.
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_pvresize (const gchar *device, guint64 size, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_pvremove:
 * @device: the PV device to be removed/destroyed
 * @extra: (allow-none) (array zero-terminated=1): extra options for the PV removal
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the PV was successfully removed/destroyed or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_REMOVE
 */
gboolean  bd_lvm_pvremove (const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_pvmove:
 * @src: the PV device to move extents off of
 * @dest: (allow-none): the PV device to move extents onto or %NULL
 * @extra: (allow-none) (array zero-terminated=1): extra options for the PV move
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the extents from the @src PV where successfully moved or not
 *
 * If @dest is %NULL, VG allocation rules are used for the extents from the @src
 * PV (see pvmove(8)).
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_pvmove (const gchar *src, const gchar *dest, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_pvscan:
 * @device: (allow-none): the device to scan for PVs or %NULL
 * @update_cache: whether to update the lvmetad cache or not
 * @extra: (allow-none) (array zero-terminated=1): extra options for the PV scan
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the system or @device was successfully scanned for PVs or not
 *
 * The @device argument is used only if @update_cache is %TRUE. Otherwise the
 * whole system is scanned for PVs.
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
gboolean  bd_lvm_pvscan (const gchar *device, gboolean update_cache, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_pvinfo:
 * @device: a PV to get information about or %NULL
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the PV on the given @device or
 * %NULL in case of error (the @error) gets populated in those cases)
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
BDLVMPVdata* bd_lvm_pvinfo (const gchar *device, GError **error);


/**
 * bd_lvm_pvs:
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about PVs found in the system
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
BDLVMPVdata** bd_lvm_pvs (GError **error);


/**
 * bd_lvm_vgcreate:
 * @name: name of the newly created VG
 * @pv_list: (array zero-terminated=1): list of PVs the newly created VG should use
 * @pe_size: PE size or 0 if the default value should be used
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VG creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG @name was successfully created or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_vgcreate (const gchar *name, const gchar **pv_list, guint64 pe_size, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_vgremove:
 * @vg_name: name of the to be removed VG
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VG removal
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG was successfully removed or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_REMOVE
 */
gboolean  bd_lvm_vgremove (const gchar *vg_name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_vgrename:
 * @old_vg_name: old name of the VG to rename
 * @new_vg_name: new name for the @old_vg_name VG
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VG rename
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG was successfully renamed or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_vgrename (const gchar *old_vg_name, const gchar *new_vg_name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_vgactivate:
 * @vg_name: name of the to be activated VG
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VG activation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG was successfully activated or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_vgactivate (const gchar *vg_name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_vgdeactivate:
 * @vg_name: name of the to be deactivated VG
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VG deactivation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG was successfully deactivated or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_vgdeactivate (const gchar *vg_name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_vgextend:
 * @vg_name: name of the to be extended VG
 * @device: PV device to extend the @vg_name VG with
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VG extension
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG @vg_name was successfully extended with the given @device or not.
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_vgextend (const gchar *vg_name, const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_vgreduce:
 * @vg_name: name of the to be reduced VG
 * @device: (allow-none): PV device the @vg_name VG should be reduced of or %NULL
 *                        if the VG should be reduced of the missing PVs
 * @extra: (allow-none) (array zero-terminated=1): extra options for the VG reduction
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG @vg_name was successfully reduced of the given @device or not
 *
 * Note: This function does not move extents off of the PV before removing
 *       it from the VG. You must do that first by calling #bd_lvm_pvmove.
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_vgreduce (const gchar *vg_name, const gchar *device, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_vginfo:
 * @vg_name: a VG to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the @vg_name VG or %NULL in case
 * of error (the @error) gets populated in those cases)
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
BDLVMVGdata* bd_lvm_vginfo (const gchar *vg_name, GError **error);


/**
 * bd_lvm_vgs:
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about VGs found in the system
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
BDLVMVGdata** bd_lvm_vgs (GError **error);


/**
 * bd_lvm_lvorigin:
 * @vg_name: name of the VG containing the queried LV
 * @lv_name: name of the queried LV
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): the origin volume for the @vg_name/@lv_name LV or
 * %NULL if failed to determine (@error) is set in those cases)
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
gchar* bd_lvm_lvorigin (const gchar *vg_name, const gchar *lv_name, GError **error);


/**
 * bd_lvm_lvcreate:
 * @vg_name: name of the VG to create a new LV in
 * @lv_name: name of the to-be-created LV
 * @size: requested size of the new LV
 * @type: (allow-none): type of the new LV ("striped", "raid1",..., see lvcreate (8))
 * @pv_list: (allow-none) (array zero-terminated=1): list of PVs the newly created LV should use or %NULL
 * if not specified
 * @extra: (allow-none) (array zero-terminated=1): extra options for the LV creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @vg_name/@lv_name LV was successfully created or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_lvcreate (const gchar *vg_name, const gchar *lv_name, guint64 size, const gchar *type, const gchar **pv_list, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_lvremove:
 * @vg_name: name of the VG containing the to-be-removed LV
 * @lv_name: name of the to-be-removed LV
 * @force: whether to force removal or not
 * @extra: (allow-none) (array zero-terminated=1): extra options for the LV removal
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully removed or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_REMOVE
 */
gboolean  bd_lvm_lvremove (const gchar *vg_name, const gchar *lv_name, gboolean force, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_lvrename:
 * @vg_name: name of the VG containing the to-be-renamed LV
 * @lv_name: name of the to-be-renamed LV
 * @new_name: new name for the @vg_name/@lv_name LV
 * @extra: (allow-none) (array zero-terminated=1): extra options for the LV rename
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully renamed to
 * @vg_name/@new_name or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_lvrename (const gchar *vg_name, const gchar *lv_name, const gchar *new_name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_lvresize:
 * @vg_name: name of the VG containing the to-be-resized LV
 * @lv_name: name of the to-be-resized LV
 * @size: the requested new size of the LV
 * @extra: (allow-none) (array zero-terminated=1): extra options for the LV resize
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully resized or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_lvresize (const gchar *vg_name, const gchar *lv_name, guint64 size, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_lvactivate:
 * @vg_name: name of the VG containing the to-be-activated LV
 * @lv_name: name of the to-be-activated LV
 * @ignore_skip: whether to ignore the skip flag or not
 * @extra: (allow-none) (array zero-terminated=1): extra options for the LV activation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully activated or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_lvactivate (const gchar *vg_name, const gchar *lv_name, gboolean ignore_skip, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_lvdeactivate:
 * @vg_name: name of the VG containing the to-be-deactivated LV
 * @lv_name: name of the to-be-deactivated LV
 * @extra: (allow-none) (array zero-terminated=1): extra options for the LV deactivation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully deactivated or not
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_lvdeactivate (const gchar *vg_name, const gchar *lv_name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_lvsnapshotcreate:
 * @vg_name: name of the VG containing the LV a new snapshot should be created of
 * @origin_name: name of the LV a new snapshot should be created of
 * @snapshot_name: name fo the to-be-created snapshot
 * @size: requested size for the snapshot
 * @extra: (allow-none) (array zero-terminated=1): extra options for the LV snapshot creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @snapshot_name snapshot of the @vg_name/@origin_name LV
 * was successfully created or not.
 *
 * Tech category: %BD_LVM_TECH_BASIC_SNAP-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_lvsnapshotcreate (const gchar *vg_name, const gchar *origin_name, const gchar *snapshot_name, guint64 size, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_lvsnapshotmerge:
 * @vg_name: name of the VG containing the to-be-merged LV snapshot
 * @snapshot_name: name of the to-be-merged LV snapshot
 * @extra: (allow-none) (array zero-terminated=1): extra options for the LV snapshot merge
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@snapshot_name LV snapshot was successfully merged or not
 *
 * Tech category: %BD_LVM_TECH_BASIC_SNAP-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_lvsnapshotmerge (const gchar *vg_name, const gchar *snapshot_name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_lvinfo:
 * @vg_name: name of the VG that contains the LV to get information about
 * @lv_name: name of the LV to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the @vg_name/@lv_name LV or %NULL in case
 * of error (the @error) gets populated in those cases)
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
BDLVMLVdata* bd_lvm_lvinfo (const gchar *vg_name, const gchar *lv_name, GError **error);


/**
 * bd_lvm_lvs:
 * @vg_name: (allow-none): name of the VG to get information about LVs from
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about LVs found in the given
 * @vg_name VG or in system if @vg_name is %NULL
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
BDLVMLVdata** bd_lvm_lvs (const gchar *vg_name, GError **error);


/**
 * bd_lvm_thpoolcreate:
 * @vg_name: name of the VG to create a thin pool in
 * @lv_name: name of the to-be-created pool LV
 * @size: requested size of the to-be-created pool
 * @md_size: requested metadata size or 0 to use the default
 * @chunk_size: requested chunk size or 0 to use the default
 * @profile: (allow-none): profile to use (see lvm(8) for more information) or %NULL to use
 *                         the default
 * @extra: (allow-none) (array zero-terminated=1): extra options for the thin pool creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name thin pool was successfully created or not
 *
 * Tech category: %BD_LVM_TECH_THIN-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_thpoolcreate (const gchar *vg_name, const gchar *lv_name, guint64 size, guint64 md_size, guint64 chunk_size, const gchar *profile, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_thlvcreate:
 * @vg_name: name of the VG containing the thin pool providing extents for the to-be-created thin LV
 * @pool_name: name of the pool LV providing extents for the to-be-created thin LV
 * @lv_name: name of the to-be-created thin LV
 * @size: requested virtual size of the to-be-created thin LV
 * @extra: (allow-none) (array zero-terminated=1): extra options for the thin LV creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name thin LV was successfully created or not
 *
 * Tech category: %BD_LVM_TECH_THIN-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_thlvcreate (const gchar *vg_name, const gchar *pool_name, const gchar *lv_name, guint64 size, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_thlvpoolname:
 * @vg_name: name of the VG containing the queried thin LV
 * @lv_name: name of the queried thin LV
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): the name of the pool volume for the @vg_name/@lv_name
 * thin LV or %NULL if failed to determine (@error) is set in those cases)
 *
 * Tech category: %BD_LVM_TECH_THIN-%BD_LVM_TECH_MODE_QUERY
 */
gchar* bd_lvm_thlvpoolname (const gchar *vg_name, const gchar *lv_name, GError **error);


/**
 * bd_lvm_thsnapshotcreate:
 * @vg_name: name of the VG containing the thin LV a new snapshot should be created of
 * @origin_name: name of the thin LV a new snapshot should be created of
 * @snapshot_name: name fo the to-be-created snapshot
 * @pool_name: (allow-none): name of the thin pool to create the snapshot in or %NULL if not specified
 * @extra: (allow-none) (array zero-terminated=1): extra options for the thin LV snapshot creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @snapshot_name snapshot of the @vg_name/@origin_name
 * thin LV was successfully created or not.
 *
 * Tech category: %BD_LVM_TECH_THIN-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_thsnapshotcreate (const gchar *vg_name, const gchar *origin_name, const gchar *snapshot_name, const gchar *pool_name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_set_global_config:
 * @new_config: (allow-none): string representation of the new global LVM
 *                            configuration to set or %NULL to reset to default
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the new requested global config @new_config was successfully
 *          set or not
 *
 * Tech category: %BD_LVM_TECH_GLOB_CONF no mode (it is ignored)
 */
gboolean  bd_lvm_set_global_config (const gchar *new_config, GError **error);


/**
 * bd_lvm_get_global_config:
 * @error: (out): place to store error (if any)
 *
 * Returns: a copy of a string representation of the currently set LVM global
 *          configuration
 *
 * Tech category: %BD_LVM_TECH_GLOB_CONF no mode (it is ignored)
 */
gchar* bd_lvm_get_global_config (GError **error);


/**
 * bd_lvm_cache_get_default_md_size:
 * @cache_size: size of the cache to determine MD size for
 * @error: (out): place to store error (if any)
 *
 * Returns: recommended default size of the cache metadata LV or 0 in case of error
 *
 * Tech category: %BD_LVM_TECH_CACHE_CALCS no mode (it is ignored)
 */
guint64  bd_lvm_cache_get_default_md_size (guint64 cache_size, GError **error);


/**
 * bd_lvm_cache_get_mode_str:
 * @mode: mode to get the string representation for
 * @error: (out): place to store error (if any)
 *
 * Returns: string representation of @mode or %NULL in case of error
 *
 * Tech category: always provided/supported
 */
const gchar* bd_lvm_cache_get_mode_str (BDLVMCacheMode mode, GError **error);


/**
 * bd_lvm_cache_get_mode_from_str:
 * @mode_str: string representation of a cache mode
 * @error: (out): place to store error (if any)
 *
 * Returns: cache mode for the @mode_str or %BD_LVM_CACHE_MODE_UNKNOWN if
 *          failed to determine
 *
 * Tech category: always provided/supported
 */
BDLVMCacheMode  bd_lvm_cache_get_mode_from_str (const gchar *mode_str, GError **error);


/**
 * bd_lvm_cache_create_pool:
 * @vg_name: name of the VG to create @pool_name in
 * @pool_name: name of the cache pool LV to create
 * @pool_size: desired size of the cache pool @pool_name
 * @md_size: desired size of the @pool_name cache pool's metadata LV or 0 to
 *           use the default
 * @mode: cache mode of the @pool_name cache pool
 * @flags: a combination of (ORed) #BDLVMCachePoolFlags
 * @fast_pvs: (array zero-terminated=1): list of (fast) PVs to create the @pool_name
 *                                       cache pool (and the metadata LV)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the cache pool @vg_name/@pool_name was successfully created or not
 *
 * Tech category: %BD_LVM_TECH_CACHE-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_cache_create_pool (const gchar *vg_name, const gchar *pool_name, guint64 pool_size, guint64 md_size, BDLVMCacheMode mode, BDLVMCachePoolFlags flags, const gchar **fast_pvs, GError **error);


/**
 * bd_lvm_cache_attach:
 * @vg_name: name of the VG containing the @data_lv and the @cache_pool_lv LVs
 * @data_lv: data LV to attache the @cache_pool_lv to
 * @cache_pool_lv: cache pool LV to attach to the @data_lv
 * @extra: (allow-none) (array zero-terminated=1): extra options for the cache attachment
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @cache_pool_lv was successfully attached to the @data_lv or not
 *
 * Tech category: %BD_LVM_TECH_CACHE-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_cache_attach (const gchar *vg_name, const gchar *data_lv, const gchar *cache_pool_lv, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_cache_detach:
 * @vg_name: name of the VG containing the @cached_lv
 * @cached_lv: name of the cached LV to detach its cache from
 * @destroy: whether to destroy the cache after detach or not
 * @extra: (allow-none) (array zero-terminated=1): extra options for the cache detachment
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the cache was successfully detached from the @cached_lv or not
 *
 * Note: synces the cache first
 *
 * Tech category: %BD_LVM_TECH_CACHE-%BD_LVM_TECH_MODE_MODIFY
 */
gboolean  bd_lvm_cache_detach (const gchar *vg_name, const gchar *cached_lv, gboolean destroy, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_cache_create_cached_lv:
 * @vg_name: name of the VG to create a cached LV in
 * @lv_name: name of the cached LV to create
 * @data_size: size of the data LV
 * @cache_size: size of the cache (or cached LV more precisely)
 * @md_size: size of the cache metadata LV or 0 to use the default
 * @mode: cache mode for the cached LV
 * @flags: a combination of (ORed) #BDLVMCachePoolFlags
 * @slow_pvs: (array zero-terminated=1): list of slow PVs (used for the data LV)
 * @fast_pvs: (array zero-terminated=1): list of fast PVs (used for the cache LV)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the cached LV @lv_name was successfully created or not
 *
 * Tech category: %BD_LVM_TECH_CACHE-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_cache_create_cached_lv (const gchar *vg_name, const gchar *lv_name, guint64 data_size, guint64 cache_size, guint64 md_size, BDLVMCacheMode mode, BDLVMCachePoolFlags flags, const gchar **slow_pvs, const gchar **fast_pvs, GError **error);


/**
 * bd_lvm_cache_pool_name:
 * @vg_name: name of the VG containing the @cached_lv
 * @cached_lv: cached LV to get the name of the its pool LV for
 * @error: (out): place to store error (if any)
 *
 * Returns: name of the cache pool LV used by the @cached_lv or %NULL in case of error
 *
 * Tech category: %BD_LVM_TECH_CACHE-%BD_LVM_TECH_MODE_QUERY
 */
gchar* bd_lvm_cache_pool_name (const gchar *vg_name, const gchar *cached_lv, GError **error);


/**
 * bd_lvm_cache_stats:
 * @vg_name: name of the VG containing the @cached_lv
 * @cached_lv: cached LV to get stats for
 * @error: (out): place to store error (if any)
 *
 * Returns: stats for the @cached_lv or %NULL in case of error
 *
 * Tech category: %BD_LVM_TECH_CACHE-%BD_LVM_TECH_MODE_QUERY
 */
BDLVMCacheStats* bd_lvm_cache_stats (const gchar *vg_name, const gchar *cached_lv, GError **error);


/**
 * bd_lvm_data_lv_name:
 * @vg_name: name of the VG containing the queried LV
 * @lv_name: name of the queried LV
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): the name of the (internal) data LV of the
 * @vg_name/@lv_name LV
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
gchar* bd_lvm_data_lv_name (const gchar *vg_name, const gchar *lv_name, GError **error);


/**
 * bd_lvm_metadata_lv_name:
 * @vg_name: name of the VG containing the queried LV
 * @lv_name: name of the queried LV
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): the name of the (internal) metadata LV of the
 * @vg_name/@lv_name LV
 *
 * Tech category: %BD_LVM_TECH_BASIC-%BD_LVM_TECH_MODE_QUERY
 */
gchar* bd_lvm_metadata_lv_name (const gchar *vg_name, const gchar *lv_name, GError **error);


/**
 * bd_lvm_thpool_convert:
 * @vg_name: name of the VG to create the new thin pool in
 * @data_lv: name of the LV that should become the data part of the new pool
 * @metadata_lv: name of the LV that should become the metadata part of the new pool
 * @name: (allow-none): name for the thin pool (if %NULL, the name @data_lv is inherited)
 * @extra: (allow-none) (array zero-terminated=1): extra options for the thin pool creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Converts the @data_lv and @metadata_lv into a new thin pool in the @vg_name
 * VG.
 *
 * Returns: whether the new thin pool was successfully created from @data_lv and
 *          @metadata_lv or not
 *
 * Tech category: %BD_LVM_TECH_THIN-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_thpool_convert (const gchar *vg_name, const gchar *data_lv, const gchar *metadata_lv, const gchar *name, const BDExtraArg **extra, GError **error);


/**
 * bd_lvm_cache_pool_convert:
 * @vg_name: name of the VG to create the new thin pool in
 * @data_lv: name of the LV that should become the data part of the new pool
 * @metadata_lv: name of the LV that should become the metadata part of the new pool
 * @name: (allow-none): name for the thin pool (if %NULL, the name @data_lv is inherited)
 * @extra: (allow-none) (array zero-terminated=1): extra options for the thin pool creation
 *                                                 (just passed to LVM as is)
 * @error: (out): place to store error (if any)
 *
 * Converts the @data_lv and @metadata_lv into a new cache pool in the @vg_name
 * VG.
 *
 * Returns: whether the new cache pool was successfully created from @data_lv and
 *          @metadata_lv or not
 *
 * Tech category: %BD_LVM_TECH_CACHE-%BD_LVM_TECH_MODE_CREATE
 */
gboolean  bd_lvm_cache_pool_convert (const gchar *vg_name, const gchar *data_lv, const gchar *metadata_lv, const gchar *name, const BDExtraArg **extra, GError **error);


#endif  /* BD_LVM_API */
