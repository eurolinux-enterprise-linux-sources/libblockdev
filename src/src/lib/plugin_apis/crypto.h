#include <glib.h>
#include <blockdev/utils.h>


#define BD_CRYPTO_LUKS_METADATA_SIZE (2 * 1048576ULL)

GQuark  bd_crypto_error_quark (void);


#define BD_CRYPTO_ERROR bd_crypto_error_quark ()
typedef enum {
    BD_CRYPTO_ERROR_DEVICE,
    BD_CRYPTO_ERROR_STATE,
    BD_CRYPTO_ERROR_INVALID_SPEC,
    BD_CRYPTO_ERROR_FORMAT_FAILED,
    BD_CRYPTO_ERROR_RESIZE_FAILED,
    BD_CRYPTO_ERROR_RESIZE_PERM,
    BD_CRYPTO_ERROR_ADD_KEY,
    BD_CRYPTO_ERROR_REMOVE_KEY,
    BD_CRYPTO_ERROR_NO_KEY,
    BD_CRYPTO_ERROR_KEY_SLOT,
    BD_CRYPTO_ERROR_NSS_INIT_FAILED,
    BD_CRYPTO_ERROR_CERT_DECODE,
    BD_CRYPTO_ERROR_ESCROW_FAILED,
    BD_CRYPTO_ERROR_INVALID_PARAMS,
    BD_CRYPTO_ERROR_TECH_UNAVAIL,
} BDCryptoError;

typedef enum {
    BD_CRYPTO_TECH_LUKS = 0,
    BD_CRYPTO_TECH_LUKS2,
    BD_CRYPTO_TECH_TRUECRYPT,
    BD_CRYPTO_TECH_ESCROW,
    BD_CRYPTO_TECH_INTEGRITY,
} BDCryptoTech;

typedef enum {
    BD_CRYPTO_TECH_MODE_CREATE         = 1 << 0,
    BD_CRYPTO_TECH_MODE_OPEN_CLOSE     = 1 << 1,
    BD_CRYPTO_TECH_MODE_QUERY          = 1 << 2,
    BD_CRYPTO_TECH_MODE_ADD_KEY        = 1 << 3,
    BD_CRYPTO_TECH_MODE_REMOVE_KEY     = 1 << 4,
    BD_CRYPTO_TECH_MODE_RESIZE         = 1 << 5,
    BD_CRYPTO_TECH_MODE_SUSPEND_RESUME = 1 << 6,
    BD_CRYPTO_TECH_MODE_BACKUP_RESTORE = 1 << 7,
} BDCryptoTechMode;

typedef enum {
    BD_CRYPTO_LUKS_VERSION_LUKS1 = 0,
    BD_CRYPTO_LUKS_VERSION_LUKS2,
} BDCryptoLUKSVersion;

#define BD_CRYPTO_TYPE_LUKS_EXTRA (bd_crypto_luks_extra_get_type ())
GType  bd_crypto_luks_extra_get_type ();


typedef struct BDCryptoLUKSExtra {
    guint64 data_alignment;
    gchar *data_device;
    gchar *integrity;
    guint64 sector_size;
    gchar *label;
    gchar *subsystem;
} BDCryptoLUKSExtra;

/**
 * BDCryptoLUKSExtra:
 * @data_alignment: data alignment in sectors, 0 for default/auto detection
 * @data_device: detached encrypted data device or NULL
 * @integrity: integrity algorithm (e.g. "hmac-sha256") or NULL for no integrity support
 *             Note: this field is valid only for LUKS 2
 * @sector_size: encryption sector size, 0 for default (512)
 *               Note: this field is valid only for LUKS 2
 * @label: LUKS header label or NULL
 *         Note: this field is valid only for LUKS 2
 * @subsytem: LUKS header subsystem or NULL
 *            Note: this field is valid only for LUKS 2
 */
/**
 * bd_crypto_luks_extra_copy: (skip)
 *
 * Creates a new copy of @extra.
 */
BDCryptoLUKSExtra* bd_crypto_luks_extra_copy (BDCryptoLUKSExtra *extra);


/**
 * bd_crypto_luks_extra_free: (skip)
 *
 * Frees @extra.
 */
void  bd_crypto_luks_extra_free (BDCryptoLUKSExtra *extra);



#define BD_CRYPTO_TYPE_LUKS_INFO (bd_crypto_luks_info_get_type ())
GType  bd_crypto_luks_info_get_type ();


typedef struct BDCryptoLUKSInfo {
    BDCryptoLUKSVersion version;
    gchar *cipher;
    gchar *mode;
    gchar *uuid;
    gchar *backing_device;
    gint64 sector_size;
} BDCryptoLUKSInfo;

/**
 * BDCryptoLUKSInfo:
 * @version: LUKS version
 * @cipher: used cipher (e.g. "aes")
 * @mode: used cipher mode (e.g. "xts-plain")
 * @uuid: UUID of the LUKS device
 * @backing_device: name of the underlying block device
 * @sector_size: size (in bytes) of encryption sector
 *               Note: sector size is valid only for LUKS 2
 */
/**
 * bd_crypto_luks_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_crypto_luks_info_free (BDCryptoLUKSInfo *info);


/**
 * bd_crypto_luks_info_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDCryptoLUKSInfo* bd_crypto_luks_info_copy (BDCryptoLUKSInfo *info);



#define BD_CRYPTO_TYPE_INTEGRITY_INFO (bd_crypto_integrity_info_get_type ())
GType  bd_crypto_integrity_info_get_type ();


typedef struct BDCryptoIntegrityInfo {
    gchar *algorithm;
    guint32 key_size;
    guint32 sector_size;
    guint32 tag_size;
    guint32 interleave_sectors;
    guint64 journal_size;
    gchar *journal_crypt;
    gchar *journal_integrity;
} BDCryptoIntegrityInfo;

/**
 * BDCryptoIntegrityInfo:
 * @algorithm: integrity algorithm
 * @key_size: integrity key size in bytes
 * @sector_size: sector size in bytes
 * @tag_size: tag size per-sector in bytes
 * @interleave_sectors: number of interleave sectors
 * @journal_size: size of journal in bytes
 * @journal_crypt: journal encryption algorithm
 * @journal_integrity: journal integrity algorithm
 */
/**
 * bd_crypto_integrity_info_free: (skip)
 *
 * Frees @info.
 */
void  bd_crypto_integrity_info_free (BDCryptoIntegrityInfo *info);


/**
 * bd_crypto_luks_integrity_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDCryptoIntegrityInfo* bd_crypto_integrity_info_copy (BDCryptoIntegrityInfo *info);



/**
 * bd_crypto_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDCryptoTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_crypto_is_tech_avail (BDCryptoTech tech, guint64 mode, GError **error);


/**
 * bd_crypto_generate_backup_passphrase:
 * @error: (out): place to store error (if any)
 *
 * Returns: A newly generated %BD_CRYPTO_BACKUP_PASSPHRASE_LENGTH-long passphrase.
 *
 * See %BD_CRYPTO_BACKUP_PASSPHRASE_CHARSET for the definition of the charset used for the passphrase.
 *
 * Tech category: always available
 */
gchar* bd_crypto_generate_backup_passphrase (GError **error);


/**
 * bd_crypto_device_is_luks:
 * @device: the queried device
 * @error: (out): place to store error (if any)
 *
 * Returns: %TRUE if the given @device is a LUKS device or %FALSE if not or
 * failed to determine (the @error) is populated with the error in such
 * cases)
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_QUERY
 */
gboolean  bd_crypto_device_is_luks (const gchar *device, GError **error);


/**
 * bd_crypto_luks_uuid:
 * @device: the queried device
 * @error: (out): place to store error (if any)
 *
 * Returns: UUID of the @device or %NULL if failed to determine (@error
 * is populated with the error in such cases)
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_QUERY
 */
gchar* bd_crypto_luks_uuid (const gchar *device, GError **error);


/**
 * bd_crypto_luks_get_metadata_size:
 * @device: the queried device
 * @error: (out): place to store error (if any)
 *
 * Returns: luks device metadata size of the @device
 *          or 0 if failed to determine (@error is populated
 *          with the error in such cases)
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_QUERY
 */
guint64  bd_crypto_luks_get_metadata_size (const gchar *device, GError **error);


/**
 * bd_crypto_luks_status:
 * @luks_device: the queried LUKS device
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer none): one of "invalid", "inactive", "active" or "busy" or
 * %NULL if failed to determine (@error is populated with the error in
 * such cases)
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_QUERY
 */
gchar* bd_crypto_luks_status (const gchar *luks_device, GError **error);


/**
 * bd_crypto_luks_format:
 * @device: a device to format as LUKS
 * @cipher: (allow-none): cipher specification (type-mode, e.g. "aes-xts-plain64") or %NULL to use the default
 * @key_size: size of the volume key in bits or 0 to use the default
 * @passphrase: (allow-none): a passphrase for the new LUKS device or %NULL if not requested
 * @key_file: (allow-none): a key file for the new LUKS device or %NULL if not requested
 * @min_entropy: minimum random data entropy (in bits) required to format @device as LUKS
 * @error: (out): place to store error (if any)
 *
 * Formats the given @device as LUKS according to the other parameters given. If
 * @min_entropy is specified (greater than 0), the function waits for enough
 * entropy to be available in the random data pool (WHICH MAY POTENTIALLY TAKE
 * FOREVER).
 *
 * Returns: whether the given @device was successfully formatted as LUKS or not
 * (the @error) contains the error in such cases)
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_CREATE
 */
gboolean  bd_crypto_luks_format (const gchar *device, const gchar *cipher, guint64 key_size, const gchar *passphrase, const gchar *key_file, guint64 min_entropy, GError **error);


/**
 * bd_crypto_luks_format_blob:
 * @device: a device to format as LUKS
 * @cipher: (allow-none): cipher specification (type-mode, e.g. "aes-xts-plain64") or %NULL to use the default
 * @key_size: size of the volume key in bits or 0 to use the default
 * @pass_data: (array length=data_len): a passphrase for the new LUKS device (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @min_entropy: minimum random data entropy (in bits) required to format @device as LUKS
 * @error: (out): place to store error (if any)
 *
 * Formats the given @device as LUKS according to the other parameters given. If
 * @min_entropy is specified (greater than 0), the function waits for enough
 * entropy to be available in the random data pool (WHICH MAY POTENTIALLY TAKE
 * FOREVER).
 *
 * Returns: whether the given @device was successfully formatted as LUKS or not
 * (the @error) contains the error in such cases)
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_CREATE
 */
gboolean  bd_crypto_luks_format_blob (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, GError **error);


/**
 * bd_crypto_luks_format_luks2:
 * @device: a device to format as LUKS
 * @cipher: (allow-none): cipher specification (type-mode, e.g. "aes-xts-plain64") or %NULL to use the default
 * @key_size: size of the volume key in bits or 0 to use the default
 * @passphrase: (allow-none): a passphrase for the new LUKS device or %NULL if not requested
 * @key_file: (allow-none): a key file for the new LUKS device or %NULL if not requested
 * @min_entropy: minimum random data entropy (in bits) required to format @device as LUKS
 * @luks_version: whether to use LUKS v1 or LUKS v2
 * @extra: (allow-none): extra arguments for LUKS format creation
 * @error: (out): place to store error (if any)
 *
 * Formats the given @device as LUKS according to the other parameters given. If
 * @min_entropy is specified (greater than 0), the function waits for enough
 * entropy to be available in the random data pool (WHICH MAY POTENTIALLY TAKE
 * FOREVER).
 *
 * Either @passhphrase or @key_file has to be != %NULL.
 *
 * Using this function with @luks_version set to %BD_CRYPTO_LUKS_VERSION_1 and
 * @extra to %NULL is the same as calling %bd_crypto_luks_format.
 *
 * Returns: whether the given @device was successfully formatted as LUKS or not
 * (the @error) contains the error in such cases)
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS2-%BD_CRYPTO_TECH_MODE_CREATE
 */
gboolean  bd_crypto_luks_format_luks2 (const gchar *device, const gchar *cipher, guint64 key_size, const gchar *passphrase, const gchar *key_file, guint64 min_entropy, BDCryptoLUKSVersion luks_version, BDCryptoLUKSExtra *extra,GError **error);


/**
 * bd_crypto_luks_format_luks2_blob:
 * @device: a device to format as LUKS
 * @cipher: (allow-none): cipher specification (type-mode, e.g. "aes-xts-plain64") or %NULL to use the default
 * @key_size: size of the volume key in bits or 0 to use the default
 * @pass_data: (array length=data_len): a passphrase for the new LUKS device (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @min_entropy: minimum random data entropy (in bits) required to format @device as LUKS
 * @luks_version: whether to use LUKS v1 or LUKS v2
 * @extra: (allow-none): extra arguments for LUKS format creation
 * @error: (out): place to store error (if any)
 *
 * Formats the given @device as LUKS according to the other parameters given. If
 * @min_entropy is specified (greater than 0), the function waits for enough
 * entropy to be available in the random data pool (WHICH MAY POTENTIALLY TAKE
 * FOREVER).
 *
 * Using this function with @luks_version set to %BD_CRYPTO_LUKS_VERSION_1 and
 * @extra to %NULL is the same as calling %bd_crypto_luks_format_blob.
 *
 * Returns: whether the given @device was successfully formatted as LUKS or not
 * (the @error) contains the error in such cases)
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS2-%BD_CRYPTO_TECH_MODE_CREATE
 */
gboolean  bd_crypto_luks_format_luks2_blob (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, BDCryptoLUKSVersion luks_version, BDCryptoLUKSExtra *extra, GError **error);


/**
 * bd_crypto_luks_open:
 * @device: the device to open
 * @name: name for the LUKS device
 * @passphrase: (allow-none): passphrase to open the @device or %NULL
 * @key_file: (allow-none): key file path to use for opening the @device or %NULL
 * @read_only: whether to open as read-only or not (meaning read-write)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully opened or not
 *
 * One of @passphrase, @key_file has to be != %NULL.
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_OPEN_CLOSE
 */
gboolean  bd_crypto_luks_open (const gchar *device, const gchar *name, const gchar *passphrase, const gchar *key_file, gboolean read_only, GError **error);


/**
 * bd_crypto_luks_open_blob:
 * @device: the device to open
 * @name: name for the LUKS device
 * @pass_data: (array length=data_len): a passphrase for the new LUKS device (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @read_only: whether to open as read-only or not (meaning read-write)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully opened or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_OPEN_CLOSE
 */
gboolean  bd_crypto_luks_open_blob (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error);


/**
 * bd_crypto_luks_close:
 * @luks_device: LUKS device to close
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @luks_device was successfully closed or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_OPEN_CLOSE
 */
gboolean  bd_crypto_luks_close (const gchar *luks_device, GError **error);


/**
 * bd_crypto_luks_add_key:
 * @device: device to add new key to
 * @pass: (allow-none): passphrase for the @device or %NULL
 * @key_file: (allow-none): key file for the @device or %NULL
 * @npass: (allow-none): passphrase to add to @device or %NULL
 * @nkey_file: (allow-none): key file to add to @device or %NULL
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @npass or @nkey_file was successfully added to @device
 * or not
 *
 * One of @pass, @key_file has to be != %NULL and the same applies to @npass,
 * @nkey_file.
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_ADD_KEY
 */
gboolean  bd_crypto_luks_add_key (const gchar *device, const gchar *pass, const gchar *key_file, const gchar *npass, const gchar *nkey_file, GError **error);


/**
 * bd_crypto_luks_add_key_blob:
 * @device: device to add new key to
 * @pass_data: (array length=data_len): a passphrase for the new LUKS device (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @npass_data: (array length=ndata_len): a new passphrase for the new LUKS device (may contain arbitrary binary data)
 * @ndata_len: length of the @npass_data buffer
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @npass_data was successfully added to @device or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_ADD_KEY
 */
gboolean  bd_crypto_luks_add_key_blob (const gchar *device, const guint8 *pass_data, gsize data_len, const guint8 *npass_data, gsize ndata_len, GError **error);


/**
 * bd_crypto_luks_remove_key:
 * @device: device to add new key to
 * @pass: (allow-none): passphrase for the @device or %NULL
 * @key_file: (allow-none): key file for the @device or %NULL
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the key was successfully removed or not
 *
 * Either @pass or @key_file has to be != %NULL.
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_REMOVE_KEY
 */
gboolean  bd_crypto_luks_remove_key (const gchar *device, const gchar *pass, const gchar *key_file, GError **error);


/**
 * bd_crypto_luks_remove_key_blob:
 * @device: device to add new key to
 * @pass_data: (array length=data_len): a passphrase for the new LUKS device (may contain arbitrary binary data) to remove
 * @data_len: length of the @pass_data buffer
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the key was successfully removed or not
 *
 * Either @pass or @key_file has to be != %NULL.
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_REMOVE_KEY
 */
gboolean  bd_crypto_luks_remove_key_blob (const gchar *device, const guint8 *pass_data, gsize data_len, GError **error);



/**
 * bd_crypto_luks_change_key:
 * @device: device to change key of
 * @pass: old passphrase
 * @npass: new passphrase
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the key was successfully changed or not
 *
 * No support for changing key files (yet).
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_ADD_KEY&%BD_CRYPTO_TECH_MODE_REMOVE_KEY
 */
gboolean  bd_crypto_luks_change_key (const gchar *device, const gchar *pass, const gchar *npass, GError **error);


/**
 * bd_crypto_luks_change_key_blob:
 * @device: device to change key of
 * @pass_data: (array length=data_len): a passphrase for the new LUKS device (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @npass_data: (array length=ndata_len): a new passphrase for the new LUKS device (may contain arbitrary binary data)
 * @ndata_len: length of the @npass_data buffer
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the key was successfully changed or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_ADD_KEY&%BD_CRYPTO_TECH_MODE_REMOVE_KEY
 */
gboolean  bd_crypto_luks_change_key_blob (const gchar *device, const guint8 *pass_data, gsize data_len, const guint8 *npass_data, gsize ndata_len, GError **error);


/**
 * bd_crypto_luks_resize:
 * @luks_device: opened LUKS device to resize
 * @size: requested size in sectors or 0 to adapt to the backing device
 * @error: (out): place to store error (if any)
 *
 * You need to specify passphrase when resizing LUKS 2 devices that don't have
 * verified key loaded in kernel. If you don't specify a passphrase, resize
 * will fail with %BD_CRYPTO_ERROR_RESIZE_PERM. Use %bd_crypto_luks_resize_luks2
 * or %bd_crypto_luks_resize_luks2_blob for these devices.
 *
 * Returns: whether the @luks_device was successfully resized or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_RESIZE
 */
gboolean  bd_crypto_luks_resize (const gchar *luks_device, guint64 size, GError **error);


/**
 * bd_crypto_luks_resize_luks2:
 * @luks_device: opened LUKS device to resize
 * @passphrase: (allow-none): passphrase to resize the @luks_device or %NULL
 * @key_file: (allow-none): key file path to use for resizinh the @luks_device or %NULL
 * @size: requested size in sectors or 0 to adapt to the backing device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @luks_device was successfully resized or not
 *
 * You need to specify either @passphrase or @keyfile for LUKS 2 devices that
 * don't have verified key loaded in kernel.
 * For LUKS 1 devices you can set both @passphrase and @keyfile to %NULL to
 * achieve the same as calling %bd_crypto_luks_resize.
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS2-%BD_CRYPTO_TECH_MODE_RESIZE
 */
gboolean  bd_crypto_luks_resize_luks2 (const gchar *luks_device, guint64 size, const gchar *passphrase, const gchar *key_file, GError **error);


/**
 * bd_crypto_luks_resize_luks2_blob:
 * @luks_device: opened LUKS device to resize
 * @pass_data: (array length=data_len): a passphrase for the new LUKS device (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @size: requested size in sectors or 0 to adapt to the backing device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @luks_device was successfully resized or not
 *
 * You need to specify @pass_data for LUKS 2 devices that don't have
 * verified key loaded in kernel.
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS2-%BD_CRYPTO_TECH_MODE_RESIZE
 */
gboolean  bd_crypto_luks_resize_luks2_blob (const gchar *luks_device, guint64 size, const guint8* pass_data, gsize data_len, GError **error);


/**
 * bd_crypto_luks_suspend:
 * @luks_device: LUKS device to suspend
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @luks_device was successfully suspended or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_SUSPEND_RESUME
 */
gboolean  bd_crypto_luks_suspend (const gchar *luks_device, GError **error);


/**
 * bd_crypto_luks_resume_blob:
 * @luks_device: LUKS device to resume
 * @pass_data: (array length=data_len): a passphrase for the LUKS device (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @luks_device was successfully resumed or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_SUSPEND_RESUME
 */
gboolean  bd_crypto_luks_resume_blob (const gchar *luks_device, const guint8 *pass_data, gsize data_len, GError **error);


/**
 * bd_crypto_luks_resume:
 * @luks_device: LUKS device to resume
 * @passphrase: (allow-none): passphrase to resume the @device or %NULL
 * @key_file: (allow-none): key file path to use for resuming the @device or %NULL
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @luks_device was successfully resumed or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_SUSPEND_RESUME
 */
gboolean  bd_crypto_luks_resume (const gchar *luks_device, const gchar *passphrase, const gchar *key_file, GError **error);


/**
 * bd_crypto_luks_kill_slot:
 * @device: device to kill slot on
 * @slot: keyslot to destroy
 * @error: (out): place to store error (if any)
 *
 * Note: This can destroy last remaining keyslot without confirmation making
 *       the LUKS device permanently inaccessible.
 *
 * Returns: whether the given @slot was successfully destroyed or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_REMOVE_KEY
 */
gboolean  bd_crypto_luks_kill_slot (const gchar *device, gint slot, GError **error);


/**
 * bd_crypto_luks_header_backup:
 * @device: device to backup the LUKS header
 * @backup_file: file to save the header backup to
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given backup of @device was successfully written to
 *          @backup_file or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_BACKUP_RESTORE
 */
gboolean  bd_crypto_luks_header_backup (const gchar *device, const gchar *backup_file, GError **error);


/**
 * bd_crypto_luks_header_restore:
 * @device: device to restore the LUKS header to
 * @backup_file: existing file with a LUKS header backup
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @device LUKS header was successfully restored
 *          from @backup_file
 *
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_BACKUP_RESTORE
 */
gboolean  bd_crypto_luks_header_restore (const gchar *device, const gchar *backup_file, GError **error);


/**
 * bd_crypto_luks_info:
 * @luks_device: a device to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: information about the @luks_device or %NULL in case of error
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_QUERY
 */
BDCryptoLUKSInfo* bd_crypto_luks_info (const gchar *luks_device, GError **error);


/**
 * bd_crypto_integrity_info:
 * @device: a device to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: information about the @device or %NULL in case of error
 *
 * Tech category: %BD_CRYPTO_TECH_INTEGRITY-%BD_CRYPTO_TECH_MODE_QUERY
 */
BDCryptoIntegrityInfo* bd_crypto_integrity_info (const gchar *device, GError **error);


/**
 * bd_crypto_device_seems_encrypted:
 * @device: the queried device
 * @error: (out): place to store error (if any)
 *
 * Determines whether a block device seems to be encrypted.
 *
 * TCRYPT volumes are not easily identifiable, because they have no
 * cleartext header, but are completely encrypted. This function is
 * used to determine whether a block device is a candidate for being
 * TCRYPT encrypted.
 *
 * To achieve this, we calculate the chi square value of the first
 * 512 Bytes and treat devices with a chi square value between 136
 * and 426 as candidates for being encrypted.
 * For the reasoning, see: https://tails.boum.org/blueprint/veracrypt/
 *
 * Returns: %TRUE if the given @device seems to be encrypted or %FALSE if not or
 * failed to determine (the @error) is populated with the error in such
 * cases)
 *
 * Tech category: %BD_CRYPTO_TECH_TRUECRYPT-%BD_CRYPTO_TECH_MODE_QUERY
 */
gboolean  bd_crypto_device_seems_encrypted (const gchar *device, GError **error);


/**
 * bd_crypto_tc_open:
 * @device: the device to open
 * @name: name for the TrueCrypt/VeraCrypt device
 * @pass_data: (array length=data_len): a passphrase for the TrueCrypt/VeraCrypt volume (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @read_only: whether to open as read-only or not (meaning read-write)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully opened or not
 *
 * Tech category: %BD_CRYPTO_TECH_TRUECRYPT-%BD_CRYPTO_TECH_MODE_OPEN_CLOSE
 */
gboolean  bd_crypto_tc_open (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error);


/**
 * bd_crypto_tc_open_full:
 * @device: the device to open
 * @name: name for the TrueCrypt/VeraCrypt device
 * @pass_data: (array length=data_len): a passphrase for the TrueCrypt/VeraCrypt volume (may contain arbitrary binary data)
 * @data_len: length of the @pass_data buffer
 * @read_only: whether to open as read-only or not (meaning read-write)
 * @keyfiles: (allow-none) (array zero-terminated=1): paths to the keyfiles for the TrueCrypt/VeraCrypt volume
 * @hidden: whether a hidden volume inside the volume should be opened
 * @system: whether to try opening as an encrypted system (with boot loader)
 * @veracrypt: whether to try VeraCrypt modes (TrueCrypt modes are tried anyway)
 * @veracrypt_pim: VeraCrypt PIM value
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @device was successfully opened or not
 *
 * Tech category: %BD_CRYPTO_TECH_TRUECRYPT-%BD_CRYPTO_TECH_MODE_OPEN_CLOSE
 */
gboolean  bd_crypto_tc_open_full (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, const gchar **keyfiles, gboolean hidden, gboolean system, gboolean veracrypt, guint32 veracrypt_pim, gboolean read_only, GError **error);


/**
 * bd_crypto_tc_close:
 * @tc_device: TrueCrypt/VeraCrypt device to close
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @tc_device was successfully closed or not
 *
 * Tech category: %BD_CRYPTO_TECH_TRUECRYPT-%BD_CRYPTO_TECH_MODE_OPEN_CLOSE
 */
gboolean  bd_crypto_tc_close (const gchar *tc_device, GError **error);


/**
 * bd_crypto_escrow_device:
 * @device: path of the device to create escrow data for
 * @passphrase: passphrase used for the device
 * @cert_data: (array zero-terminated=1) (element-type gchar): certificate data to use for escrow
 * @directory: directory to put escrow data into
 * @backup_passphrase: (allow-none): backup passphrase for the device or %NULL
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the ecrow data was successfully created for @device or not
 *
 * Tech category: %BD_CRYPTO_TECH_ESCROW-%BD_CRYPTO_TECH_MODE_CREATE
 */
gboolean  bd_crypto_escrow_device (const gchar *device, const gchar *passphrase, const gchar *cert_data, const gchar *directory, const gchar *backup_passphrase, GError **error);

