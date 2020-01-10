#include <glib.h>
#include <glib-object.h>
#include <blockdev/utils.h>


#ifndef BD_VDO
#define BD_VDO

GQuark  bd_vdo_error_quark (void);


#define BD_VDO_ERROR bd_vdo_error_quark ()
typedef enum {
    BD_VDO_ERROR_FAIL,
} BDVDOError;

typedef enum {
    BD_VDO_TECH_VDO = 0,
} BDVDOTech;

typedef enum {
    BD_VDO_TECH_MODE_CREATE              = 1 << 0,
    BD_VDO_TECH_MODE_REMOVE              = 1 << 1,
    BD_VDO_TECH_MODE_MODIFY              = 1 << 2,
    BD_VDO_TECH_MODE_ACTIVATE_DEACTIVATE = 1 << 3,
    BD_VDO_TECH_MODE_START_STOP          = 1 << 4,
    BD_VDO_TECH_MODE_QUERY               = 1 << 5,
    BD_VDO_TECH_MODE_GROW                = 1 << 6,
} BDVDOTechMode;

typedef enum {
    BD_VDO_WRITE_POLICY_SYNC,
    BD_VDO_WRITE_POLICY_ASYNC,
    BD_VDO_WRITE_POLICY_AUTO,
    BD_VDO_WRITE_POLICY_UNKNOWN,
} BDVDOWritePolicy;

#define BD_VDO_TYPE_INFO (bd_vdo_info_get_type ())
GType  bd_vdo_info_get_type ();


typedef struct BDVDOInfo {
    gchar *name;
    gchar *device;
    gboolean active;
    gboolean deduplication;
    gboolean compression;
    guint64 logical_size;
    guint64 physical_size;
    guint64 index_memory;
    BDVDOWritePolicy write_policy;
} BDVDOInfo;

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
void  bd_vdo_info_free (BDVDOInfo *info);


/**
 * bd_vdo_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDVDOTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_vdo_is_tech_avail (BDVDOTech tech, guint64 mode, GError **error);


/**
 * bd_vdo_get_write_policy_str:
 * @policy: policy to get the string representation for
 * @error: (out): place to store error (if any)
 *
 * Returns: string representation of @policy or %NULL in case of error
 *
 * Tech category: always provided/supported
 */
const gchar* bd_vdo_get_write_policy_str (BDVDOWritePolicy policy, GError **error);


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
BDVDOWritePolicy  bd_vdo_get_write_policy_from_str (const gchar *policy_str, GError **error);


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
BDVDOInfo* bd_vdo_info (const gchar *name, GError **error);


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
gboolean  bd_vdo_create (const gchar *name, const gchar *backing_device, guint64 logical_size, guint64 index_memory, gboolean compression, gboolean deduplication, BDVDOWritePolicy write_policy, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_remove (const gchar *name, gboolean force, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_change_write_policy (const gchar *name, BDVDOWritePolicy write_policy, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_enable_compression (const gchar *name, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_disable_compression (const gchar *name, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_enable_deduplication (const gchar *name, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_disable_deduplication (const gchar *name, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_activate (const gchar *name, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_deactivate (const gchar *name, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_start (const gchar *name, gboolean rebuild, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_stop (const gchar *name, gboolean force, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_grow_logical (const gchar *name, guint64 size, const BDExtraArg **extra, GError **error);


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
gboolean  bd_vdo_grow_physical (const gchar *name, const BDExtraArg **extra, GError **error);


#endif  /* BD_VDO_API */
