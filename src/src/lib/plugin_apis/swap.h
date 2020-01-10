#include <glib.h>
#include <blockdev/utils.h>


GQuark  bd_swap_error_quark (void);


#define BD_SWAP_ERROR bd_swap_error_quark ()
typedef enum {
    BD_SWAP_ERROR_UNKNOWN_STATE,
    BD_SWAP_ERROR_ACTIVATE,
    BD_SWAP_ERROR_TECH_UNAVAIL,
} BDSwapError;

typedef enum {
    BD_SWAP_TECH_SWAP = 0,
} BDSwapTech;

typedef enum {
    BD_SWAP_TECH_MODE_CREATE              = 1 << 0,
    BD_SWAP_TECH_MODE_ACTIVATE_DEACTIVATE = 1 << 1,
    BD_SWAP_TECH_MODE_QUERY               = 1 << 2,
    BD_SWAP_TECH_MODE_SET_LABEL           = 1 << 3,
} BDSwapTechMode;

/**
 * bd_swap_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDSwapTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_swap_is_tech_avail (BDSwapTech tech, guint64 mode, GError **error);


/**
 * bd_swap_mkswap:
 * @device: a device to create swap space on
 * @label: (allow-none): a label for the swap space device
 * @extra: (allow-none) (array zero-terminated=1): extra options for the creation (right now
 *                                                 passed to the 'mkswap' utility)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the swap space was successfully created or not
 *
 * Tech category: %BD_SWAP_TECH_SWAP-%BD_SWAP_TECH_MODE_CREATE
 */
gboolean  bd_swap_mkswap (const gchar *device, const gchar *label, const BDExtraArg **extra, GError **error);


/**
 * bd_swap_swapon:
 * @device: swap device to activate
 * @priority: priority of the activated device or -1 to use the default
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the swap device was successfully activated or not
 *
 * Tech category: %BD_SWAP_TECH_SWAP-%BD_SWAP_TECH_MODE_ACTIVATE_DEACTIVATE
 */
gboolean  bd_swap_swapon (const gchar *device, gint priority, GError **error);


/**
 * bd_swap_swapoff:
 * @device: swap device to deactivate
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the swap device was successfully deactivated or not
 *
 * Tech category: %BD_SWAP_TECH_SWAP-%BD_SWAP_TECH_MODE_ACTIVATE_DEACTIVATE
 */
gboolean  bd_swap_swapoff (const gchar *device, GError **error);


/**
 * bd_swap_swapstatus:
 * @device: swap device to get status of
 * @error: (out): place to store error (if any)
 *
 * Returns: %TRUE if the swap device is active, %FALSE if not active or failed
 * to determine (@error) is set not a non-NULL value in such case)
 *
 * Tech category: %BD_SWAP_TECH_SWAP-%BD_SWAP_TECH_MODE_QUERY
 */
gboolean  bd_swap_swapstatus (const gchar *device, GError **error);


/**
 * bd_swap_set_label:
 * @device: a device to set label on
 * @label: label that will be set
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the label was successfully set or not
 *
 * Tech category: %BD_SWAP_TECH_SWAP-%BD_SWAP_TECH_MODE_SET_LABEL
 */
gboolean  bd_swap_set_label (const gchar *device, const gchar *label, GError **error);

