#include <glib.h>
#include <glib-object.h>
#include <blockdev/utils.h>


#ifndef BD_NVDIMM_API
#define BD_NVDIMM_API

GQuark  bd_nvdimm_error_quark (void);


#define BD_NVDIMM_ERROR bd_nvdimm_error_quark ()
typedef enum {
    BD_NVDIMM_ERROR_NAMESPACE_PARSE,
    BD_NVDIMM_ERROR_NAMESPACE_FAIL,
    BD_NVDIMM_ERROR_NAMESPACE_NOEXIST,
    BD_NVDIMM_ERROR_NAMESPACE_MODE_INVAL
} BDNVDIMMError;

typedef enum {
    BD_NVDIMM_NAMESPACE_MODE_RAW,
    BD_NVDIMM_NAMESPACE_MODE_SECTOR,
    BD_NVDIMM_NAMESPACE_MODE_MEMORY,
    BD_NVDIMM_NAMESPACE_MODE_DAX,
    BD_NVDIMM_NAMESPACE_MODE_FSDAX,
    BD_NVDIMM_NAMESPACE_MODE_DEVDAX,
    BD_NVDIMM_NAMESPACE_MODE_UNKNOWN
} BDNVDIMMNamespaceMode;

#define BD_NVDIMM_TYPE_NAMESPACE_INFO (bd_nvdimm_namespace_info_get_type ())
GType  bd_nvdimm_namespace_info_get_type ();


typedef struct BDNVDIMMNamespaceInfo {
    gchar *dev;
    guint64 mode;
    guint64 size;
    gchar *uuid;
    guint64 sector_size;
    gchar *blockdev;
    gboolean enabled;
} BDNVDIMMNamespaceInfo;

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
void  bd_nvdimm_namespace_info_free (BDNVDIMMNamespaceInfo *info);


/**
 * bd_nvdimm_namespace_info_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDNVDIMMNamespaceInfo* bd_nvdimm_namespace_info_copy (BDNVDIMMNamespaceInfo *info);



typedef enum {
    BD_NVDIMM_TECH_NAMESPACE = 0,
} BDNVDIMMTech;

typedef enum {
    BD_NVDIMM_TECH_MODE_CREATE              = 1 << 0,
    BD_NVDIMM_TECH_MODE_REMOVE              = 1 << 1,
    BD_NVDIMM_TECH_MODE_ACTIVATE_DEACTIVATE = 1 << 2,
    BD_NVDIMM_TECH_MODE_QUERY               = 1 << 3,
    BD_NVDIMM_TECH_MODE_RECONFIGURE         = 1 << 4,
} BDNVDIMMTechMode;

/**
 * bd_nvdimm_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDNVDIMMTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_nvdimm_is_tech_avail (BDNVDIMMTech tech, guint64 mode, GError **error);


/**
 * bd_nvdimm_namespace_get_mode_from_str:
 * @mode_str: string representation of mode
 * @error: (out): place to store error (if any)
 *
 * Returns: mode matching the @mode_str given or %BD_NVDIMM_NAMESPACE_MODE_UNKNOWN in case of no match
 *
 * Tech category: always available
 */
BDNVDIMMNamespaceMode  bd_nvdimm_namespace_get_mode_from_str (const gchar *mode_str, GError **error);


/**
 * bd_nvdimm_namespace_get_mode_str:
 * @mode: mode to get string representation of
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer none): string representation of @mode or %NULL in case of error
 *
 * Tech category: always available
 */
const gchar* bd_nvdimm_namespace_get_mode_str (BDNVDIMMNamespaceMode mode, GError **error);


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
gchar* bd_nvdimm_namespace_get_devname (const gchar *device, GError **error);


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
gboolean  bd_nvdimm_namespace_enable (const gchar *namespace, const BDExtraArg **extra, GError **error);


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
gboolean  bd_nvdimm_namespace_disable (const gchar *namespace, const BDExtraArg **extra, GError **error);


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
BDNVDIMMNamespaceInfo* bd_nvdimm_namespace_info (const gchar *namespace, const BDExtraArg **extra, GError **error);


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
BDNVDIMMNamespaceInfo** bd_nvdimm_list_namespaces (const gchar *bus, const gchar *region, gboolean idle, const BDExtraArg **extra, GError **error);


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
gboolean  bd_nvdimm_namespace_reconfigure (const gchar* namespace, BDNVDIMMNamespaceMode mode, gboolean force, const BDExtraArg **extra, GError** error);


#endif  /* BD_NVDIMM_API */
