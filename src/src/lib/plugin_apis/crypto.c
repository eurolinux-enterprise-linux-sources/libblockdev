GQuark  bd_crypto_error_quark (void) {
        return g_quark_from_static_string ("g-bd-crypto-error-quark");
}

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
BDCryptoLUKSExtra* bd_crypto_luks_extra_copy (BDCryptoLUKSExtra *extra) {
       BDCryptoLUKSExtra *new_extra = g_new0 (BDCryptoLUKSExtra, 1);

   new_extra->integrity = g_strdup (extra->integrity);
   new_extra->data_alignment = extra->data_alignment;
   new_extra->data_device = g_strdup (extra->data_device);
   new_extra->sector_size = extra->sector_size;
   new_extra->label = g_strdup (extra->label);
   new_extra->subsystem = g_strdup (extra->subsystem);

   return new_extra;
}

/**
 * bd_crypto_luks_extra_free: (skip)
 *
 * Frees @extra.
 */
void  bd_crypto_luks_extra_free (BDCryptoLUKSExtra *extra) {
       g_free (extra->integrity);
   g_free (extra->data_device);
   g_free (extra->label);
   g_free (extra->subsystem);
   g_free (extra);
}

GType  bd_crypto_luks_extra_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDCryptoLUKSExtra",
                                            (GBoxedCopyFunc) bd_crypto_luks_extra_copy,
                                            (GBoxedFreeFunc) bd_crypto_luks_extra_free);
    }

    return type;
}

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
void  bd_crypto_luks_info_free (BDCryptoLUKSInfo *info) {
        g_free (info->cipher);
    g_free (info->mode);
    g_free (info->uuid);
    g_free (info->backing_device);
    g_free (info);
}

/**
 * bd_crypto_luks_info_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDCryptoLUKSInfo* bd_crypto_luks_info_copy (BDCryptoLUKSInfo *info) {
        BDCryptoLUKSInfo *new_info = g_new0 (BDCryptoLUKSInfo, 1);

    new_info->version = info->version;
    new_info->cipher = g_strdup (info->cipher);
    new_info->mode = g_strdup (info->mode);
    new_info->uuid = g_strdup (info->uuid);
    new_info->backing_device = g_strdup (info->backing_device);
    new_info->sector_size = info->sector_size;

    return new_info;
}

GType  bd_crypto_luks_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDCryptoLUKSInfo",
                                            (GBoxedCopyFunc) bd_crypto_luks_info_copy,
                                            (GBoxedFreeFunc) bd_crypto_luks_info_free);
    }

    return type;
}

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
void  bd_crypto_integrity_info_free (BDCryptoIntegrityInfo *info) {
        g_free (info->algorithm);
    g_free (info->journal_crypt);
    g_free (info->journal_integrity);
    g_free (info);
}

/**
 * bd_crypto_luks_integrity_copy: (skip)
 *
 * Creates a new copy of @info.
 */
BDCryptoIntegrityInfo* bd_crypto_integrity_info_copy (BDCryptoIntegrityInfo *info) {
        BDCryptoIntegrityInfo *new_info = g_new0 (BDCryptoIntegrityInfo, 1);

    new_info->algorithm = g_strdup (info->algorithm);
    new_info->key_size = info->key_size;
    new_info->sector_size = info->sector_size;
    new_info->tag_size = info->tag_size;
    new_info->interleave_sectors = info->interleave_sectors;
    new_info->journal_size = info->journal_size;
    new_info->journal_crypt = g_strdup (info->journal_crypt);
    new_info->journal_integrity = g_strdup (info->journal_integrity);

    return new_info;
}

GType  bd_crypto_integrity_info_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDCryptoIntegrityInfo",
                                            (GBoxedCopyFunc) bd_crypto_integrity_info_copy,
                                            (GBoxedFreeFunc) bd_crypto_integrity_info_free);
    }

    return type;
}

static const gchar* const crypto_functions[] = {
    "bd_crypto_is_tech_avail",
    "bd_crypto_generate_backup_passphrase",
    "bd_crypto_device_is_luks",
    "bd_crypto_luks_uuid",
    "bd_crypto_luks_get_metadata_size",
    "bd_crypto_luks_status",
    "bd_crypto_luks_format",
    "bd_crypto_luks_format_blob",
    "bd_crypto_luks_format_luks2",
    "bd_crypto_luks_format_luks2_blob",
    "bd_crypto_luks_open",
    "bd_crypto_luks_open_blob",
    "bd_crypto_luks_close",
    "bd_crypto_luks_add_key",
    "bd_crypto_luks_add_key_blob",
    "bd_crypto_luks_remove_key",
    "bd_crypto_luks_remove_key_blob",
    "bd_crypto_luks_change_key",
    "bd_crypto_luks_change_key_blob",
    "bd_crypto_luks_resize",
    "bd_crypto_luks_resize_luks2",
    "bd_crypto_luks_resize_luks2_blob",
    "bd_crypto_luks_suspend",
    "bd_crypto_luks_resume_blob",
    "bd_crypto_luks_resume",
    "bd_crypto_luks_kill_slot",
    "bd_crypto_luks_header_backup",
    "bd_crypto_luks_header_restore",
    "bd_crypto_luks_info",
    "bd_crypto_integrity_info",
    "bd_crypto_device_seems_encrypted",
    "bd_crypto_tc_open",
    "bd_crypto_tc_open_full",
    "bd_crypto_tc_close",
    "bd_crypto_escrow_device",
    NULL};

const gchar* const* get_crypto_functions (void) {
    return crypto_functions;
}

static const guint8 crypto_num_functions = 35;

guint8 get_crypto_num_functions (void) {
    return crypto_num_functions;
}

gboolean  bd_crypto_is_tech_avail_stub (BDCryptoTech tech, guint64 mode, GError **error) {
    g_critical ("The function 'bd_crypto_is_tech_avail' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_is_tech_avail' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_is_tech_avail) (BDCryptoTech tech, guint64 mode, GError **error) = bd_crypto_is_tech_avail_stub;

/**
 * bd_crypto_is_tech_avail:
 * @tech: the queried tech
 * @mode: a bit mask of queried modes of operation (#BDCryptoTechMode) for @tech
 * @error: (out): place to store error (details about why the @tech-@mode combination is not available)
 *
 * Returns: whether the @tech-@mode combination is available -- supported by the
 *          plugin implementation and having all the runtime dependencies available
 */
gboolean  bd_crypto_is_tech_avail (BDCryptoTech tech, guint64 mode, GError **error) {
    return _bd_crypto_is_tech_avail (tech, mode, error);
}


gchar* bd_crypto_generate_backup_passphrase_stub (GError **error) {
    g_critical ("The function 'bd_crypto_generate_backup_passphrase' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_generate_backup_passphrase' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_crypto_generate_backup_passphrase) (GError **error) = bd_crypto_generate_backup_passphrase_stub;

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
gchar* bd_crypto_generate_backup_passphrase (GError **error) {
    return _bd_crypto_generate_backup_passphrase (error);
}


gboolean  bd_crypto_device_is_luks_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_crypto_device_is_luks' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_device_is_luks' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_device_is_luks) (const gchar *device, GError **error) = bd_crypto_device_is_luks_stub;

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
gboolean  bd_crypto_device_is_luks (const gchar *device, GError **error) {
    return _bd_crypto_device_is_luks (device, error);
}


gchar* bd_crypto_luks_uuid_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_crypto_luks_uuid' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_uuid' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_crypto_luks_uuid) (const gchar *device, GError **error) = bd_crypto_luks_uuid_stub;

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
gchar* bd_crypto_luks_uuid (const gchar *device, GError **error) {
    return _bd_crypto_luks_uuid (device, error);
}


guint64  bd_crypto_luks_get_metadata_size_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_crypto_luks_get_metadata_size' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_get_metadata_size' called, but not implemented!");
    return 0;
}

guint64  (*_bd_crypto_luks_get_metadata_size) (const gchar *device, GError **error) = bd_crypto_luks_get_metadata_size_stub;

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
guint64  bd_crypto_luks_get_metadata_size (const gchar *device, GError **error) {
    return _bd_crypto_luks_get_metadata_size (device, error);
}


gchar* bd_crypto_luks_status_stub (const gchar *luks_device, GError **error) {
    g_critical ("The function 'bd_crypto_luks_status' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_status' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_crypto_luks_status) (const gchar *luks_device, GError **error) = bd_crypto_luks_status_stub;

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
gchar* bd_crypto_luks_status (const gchar *luks_device, GError **error) {
    return _bd_crypto_luks_status (luks_device, error);
}


gboolean  bd_crypto_luks_format_stub (const gchar *device, const gchar *cipher, guint64 key_size, const gchar *passphrase, const gchar *key_file, guint64 min_entropy, GError **error) {
    g_critical ("The function 'bd_crypto_luks_format' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_format' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_format) (const gchar *device, const gchar *cipher, guint64 key_size, const gchar *passphrase, const gchar *key_file, guint64 min_entropy, GError **error) = bd_crypto_luks_format_stub;

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
gboolean  bd_crypto_luks_format (const gchar *device, const gchar *cipher, guint64 key_size, const gchar *passphrase, const gchar *key_file, guint64 min_entropy, GError **error) {
    return _bd_crypto_luks_format (device, cipher, key_size, passphrase, key_file, min_entropy, error);
}


gboolean  bd_crypto_luks_format_blob_stub (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, GError **error) {
    g_critical ("The function 'bd_crypto_luks_format_blob' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_format_blob' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_format_blob) (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, GError **error) = bd_crypto_luks_format_blob_stub;

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
gboolean  bd_crypto_luks_format_blob (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, GError **error) {
    return _bd_crypto_luks_format_blob (device, cipher, key_size, pass_data, data_len, min_entropy, error);
}


gboolean  bd_crypto_luks_format_luks2_stub (const gchar *device, const gchar *cipher, guint64 key_size, const gchar *passphrase, const gchar *key_file, guint64 min_entropy, BDCryptoLUKSVersion luks_version, BDCryptoLUKSExtra *extra,GError **error) {
    g_critical ("The function 'bd_crypto_luks_format_luks2' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_format_luks2' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_format_luks2) (const gchar *device, const gchar *cipher, guint64 key_size, const gchar *passphrase, const gchar *key_file, guint64 min_entropy, BDCryptoLUKSVersion luks_version, BDCryptoLUKSExtra *extra,GError **error) = bd_crypto_luks_format_luks2_stub;

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
gboolean  bd_crypto_luks_format_luks2 (const gchar *device, const gchar *cipher, guint64 key_size, const gchar *passphrase, const gchar *key_file, guint64 min_entropy, BDCryptoLUKSVersion luks_version, BDCryptoLUKSExtra *extra,GError **error) {
    return _bd_crypto_luks_format_luks2 (device, cipher, key_size, passphrase, key_file, min_entropy, luks_version, extra, error);
}


gboolean  bd_crypto_luks_format_luks2_blob_stub (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, BDCryptoLUKSVersion luks_version, BDCryptoLUKSExtra *extra, GError **error) {
    g_critical ("The function 'bd_crypto_luks_format_luks2_blob' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_format_luks2_blob' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_format_luks2_blob) (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, BDCryptoLUKSVersion luks_version, BDCryptoLUKSExtra *extra, GError **error) = bd_crypto_luks_format_luks2_blob_stub;

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
gboolean  bd_crypto_luks_format_luks2_blob (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, BDCryptoLUKSVersion luks_version, BDCryptoLUKSExtra *extra, GError **error) {
    return _bd_crypto_luks_format_luks2_blob (device, cipher, key_size, pass_data, data_len, min_entropy, luks_version, extra, error);
}


gboolean  bd_crypto_luks_open_stub (const gchar *device, const gchar *name, const gchar *passphrase, const gchar *key_file, gboolean read_only, GError **error) {
    g_critical ("The function 'bd_crypto_luks_open' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_open' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_open) (const gchar *device, const gchar *name, const gchar *passphrase, const gchar *key_file, gboolean read_only, GError **error) = bd_crypto_luks_open_stub;

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
gboolean  bd_crypto_luks_open (const gchar *device, const gchar *name, const gchar *passphrase, const gchar *key_file, gboolean read_only, GError **error) {
    return _bd_crypto_luks_open (device, name, passphrase, key_file, read_only, error);
}


gboolean  bd_crypto_luks_open_blob_stub (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error) {
    g_critical ("The function 'bd_crypto_luks_open_blob' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_open_blob' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_open_blob) (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error) = bd_crypto_luks_open_blob_stub;

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
gboolean  bd_crypto_luks_open_blob (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error) {
    return _bd_crypto_luks_open_blob (device, name, pass_data, data_len, read_only, error);
}


gboolean  bd_crypto_luks_close_stub (const gchar *luks_device, GError **error) {
    g_critical ("The function 'bd_crypto_luks_close' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_close' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_close) (const gchar *luks_device, GError **error) = bd_crypto_luks_close_stub;

/**
 * bd_crypto_luks_close:
 * @luks_device: LUKS device to close
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @luks_device was successfully closed or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_OPEN_CLOSE
 */
gboolean  bd_crypto_luks_close (const gchar *luks_device, GError **error) {
    return _bd_crypto_luks_close (luks_device, error);
}


gboolean  bd_crypto_luks_add_key_stub (const gchar *device, const gchar *pass, const gchar *key_file, const gchar *npass, const gchar *nkey_file, GError **error) {
    g_critical ("The function 'bd_crypto_luks_add_key' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_add_key' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_add_key) (const gchar *device, const gchar *pass, const gchar *key_file, const gchar *npass, const gchar *nkey_file, GError **error) = bd_crypto_luks_add_key_stub;

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
gboolean  bd_crypto_luks_add_key (const gchar *device, const gchar *pass, const gchar *key_file, const gchar *npass, const gchar *nkey_file, GError **error) {
    return _bd_crypto_luks_add_key (device, pass, key_file, npass, nkey_file, error);
}


gboolean  bd_crypto_luks_add_key_blob_stub (const gchar *device, const guint8 *pass_data, gsize data_len, const guint8 *npass_data, gsize ndata_len, GError **error) {
    g_critical ("The function 'bd_crypto_luks_add_key_blob' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_add_key_blob' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_add_key_blob) (const gchar *device, const guint8 *pass_data, gsize data_len, const guint8 *npass_data, gsize ndata_len, GError **error) = bd_crypto_luks_add_key_blob_stub;

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
gboolean  bd_crypto_luks_add_key_blob (const gchar *device, const guint8 *pass_data, gsize data_len, const guint8 *npass_data, gsize ndata_len, GError **error) {
    return _bd_crypto_luks_add_key_blob (device, pass_data, data_len, npass_data, ndata_len, error);
}


gboolean  bd_crypto_luks_remove_key_stub (const gchar *device, const gchar *pass, const gchar *key_file, GError **error) {
    g_critical ("The function 'bd_crypto_luks_remove_key' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_remove_key' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_remove_key) (const gchar *device, const gchar *pass, const gchar *key_file, GError **error) = bd_crypto_luks_remove_key_stub;

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
gboolean  bd_crypto_luks_remove_key (const gchar *device, const gchar *pass, const gchar *key_file, GError **error) {
    return _bd_crypto_luks_remove_key (device, pass, key_file, error);
}


gboolean  bd_crypto_luks_remove_key_blob_stub (const gchar *device, const guint8 *pass_data, gsize data_len, GError **error) {
    g_critical ("The function 'bd_crypto_luks_remove_key_blob' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_remove_key_blob' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_remove_key_blob) (const gchar *device, const guint8 *pass_data, gsize data_len, GError **error) = bd_crypto_luks_remove_key_blob_stub;

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
gboolean  bd_crypto_luks_remove_key_blob (const gchar *device, const guint8 *pass_data, gsize data_len, GError **error) {
    return _bd_crypto_luks_remove_key_blob (device, pass_data, data_len, error);
}


gboolean  bd_crypto_luks_change_key_stub (const gchar *device, const gchar *pass, const gchar *npass, GError **error) {
    g_critical ("The function 'bd_crypto_luks_change_key' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_change_key' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_change_key) (const gchar *device, const gchar *pass, const gchar *npass, GError **error) = bd_crypto_luks_change_key_stub;

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
gboolean  bd_crypto_luks_change_key (const gchar *device, const gchar *pass, const gchar *npass, GError **error) {
    return _bd_crypto_luks_change_key (device, pass, npass, error);
}


gboolean  bd_crypto_luks_change_key_blob_stub (const gchar *device, const guint8 *pass_data, gsize data_len, const guint8 *npass_data, gsize ndata_len, GError **error) {
    g_critical ("The function 'bd_crypto_luks_change_key_blob' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_change_key_blob' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_change_key_blob) (const gchar *device, const guint8 *pass_data, gsize data_len, const guint8 *npass_data, gsize ndata_len, GError **error) = bd_crypto_luks_change_key_blob_stub;

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
gboolean  bd_crypto_luks_change_key_blob (const gchar *device, const guint8 *pass_data, gsize data_len, const guint8 *npass_data, gsize ndata_len, GError **error) {
    return _bd_crypto_luks_change_key_blob (device, pass_data, data_len, npass_data, ndata_len, error);
}


gboolean  bd_crypto_luks_resize_stub (const gchar *luks_device, guint64 size, GError **error) {
    g_critical ("The function 'bd_crypto_luks_resize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_resize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_resize) (const gchar *luks_device, guint64 size, GError **error) = bd_crypto_luks_resize_stub;

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
gboolean  bd_crypto_luks_resize (const gchar *luks_device, guint64 size, GError **error) {
    return _bd_crypto_luks_resize (luks_device, size, error);
}


gboolean  bd_crypto_luks_resize_luks2_stub (const gchar *luks_device, guint64 size, const gchar *passphrase, const gchar *key_file, GError **error) {
    g_critical ("The function 'bd_crypto_luks_resize_luks2' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_resize_luks2' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_resize_luks2) (const gchar *luks_device, guint64 size, const gchar *passphrase, const gchar *key_file, GError **error) = bd_crypto_luks_resize_luks2_stub;

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
gboolean  bd_crypto_luks_resize_luks2 (const gchar *luks_device, guint64 size, const gchar *passphrase, const gchar *key_file, GError **error) {
    return _bd_crypto_luks_resize_luks2 (luks_device, size, passphrase, key_file, error);
}


gboolean  bd_crypto_luks_resize_luks2_blob_stub (const gchar *luks_device, guint64 size, const guint8* pass_data, gsize data_len, GError **error) {
    g_critical ("The function 'bd_crypto_luks_resize_luks2_blob' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_resize_luks2_blob' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_resize_luks2_blob) (const gchar *luks_device, guint64 size, const guint8* pass_data, gsize data_len, GError **error) = bd_crypto_luks_resize_luks2_blob_stub;

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
gboolean  bd_crypto_luks_resize_luks2_blob (const gchar *luks_device, guint64 size, const guint8* pass_data, gsize data_len, GError **error) {
    return _bd_crypto_luks_resize_luks2_blob (luks_device, size, pass_data, data_len, error);
}


gboolean  bd_crypto_luks_suspend_stub (const gchar *luks_device, GError **error) {
    g_critical ("The function 'bd_crypto_luks_suspend' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_suspend' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_suspend) (const gchar *luks_device, GError **error) = bd_crypto_luks_suspend_stub;

/**
 * bd_crypto_luks_suspend:
 * @luks_device: LUKS device to suspend
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @luks_device was successfully suspended or not
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_SUSPEND_RESUME
 */
gboolean  bd_crypto_luks_suspend (const gchar *luks_device, GError **error) {
    return _bd_crypto_luks_suspend (luks_device, error);
}


gboolean  bd_crypto_luks_resume_blob_stub (const gchar *luks_device, const guint8 *pass_data, gsize data_len, GError **error) {
    g_critical ("The function 'bd_crypto_luks_resume_blob' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_resume_blob' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_resume_blob) (const gchar *luks_device, const guint8 *pass_data, gsize data_len, GError **error) = bd_crypto_luks_resume_blob_stub;

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
gboolean  bd_crypto_luks_resume_blob (const gchar *luks_device, const guint8 *pass_data, gsize data_len, GError **error) {
    return _bd_crypto_luks_resume_blob (luks_device, pass_data, data_len, error);
}


gboolean  bd_crypto_luks_resume_stub (const gchar *luks_device, const gchar *passphrase, const gchar *key_file, GError **error) {
    g_critical ("The function 'bd_crypto_luks_resume' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_resume' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_resume) (const gchar *luks_device, const gchar *passphrase, const gchar *key_file, GError **error) = bd_crypto_luks_resume_stub;

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
gboolean  bd_crypto_luks_resume (const gchar *luks_device, const gchar *passphrase, const gchar *key_file, GError **error) {
    return _bd_crypto_luks_resume (luks_device, passphrase, key_file, error);
}


gboolean  bd_crypto_luks_kill_slot_stub (const gchar *device, gint slot, GError **error) {
    g_critical ("The function 'bd_crypto_luks_kill_slot' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_kill_slot' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_kill_slot) (const gchar *device, gint slot, GError **error) = bd_crypto_luks_kill_slot_stub;

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
gboolean  bd_crypto_luks_kill_slot (const gchar *device, gint slot, GError **error) {
    return _bd_crypto_luks_kill_slot (device, slot, error);
}


gboolean  bd_crypto_luks_header_backup_stub (const gchar *device, const gchar *backup_file, GError **error) {
    g_critical ("The function 'bd_crypto_luks_header_backup' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_header_backup' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_header_backup) (const gchar *device, const gchar *backup_file, GError **error) = bd_crypto_luks_header_backup_stub;

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
gboolean  bd_crypto_luks_header_backup (const gchar *device, const gchar *backup_file, GError **error) {
    return _bd_crypto_luks_header_backup (device, backup_file, error);
}


gboolean  bd_crypto_luks_header_restore_stub (const gchar *device, const gchar *backup_file, GError **error) {
    g_critical ("The function 'bd_crypto_luks_header_restore' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_header_restore' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_luks_header_restore) (const gchar *device, const gchar *backup_file, GError **error) = bd_crypto_luks_header_restore_stub;

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
gboolean  bd_crypto_luks_header_restore (const gchar *device, const gchar *backup_file, GError **error) {
    return _bd_crypto_luks_header_restore (device, backup_file, error);
}


BDCryptoLUKSInfo* bd_crypto_luks_info_stub (const gchar *luks_device, GError **error) {
    g_critical ("The function 'bd_crypto_luks_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_luks_info' called, but not implemented!");
    return NULL;
}

BDCryptoLUKSInfo* (*_bd_crypto_luks_info) (const gchar *luks_device, GError **error) = bd_crypto_luks_info_stub;

/**
 * bd_crypto_luks_info:
 * @luks_device: a device to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: information about the @luks_device or %NULL in case of error
 *
 * Tech category: %BD_CRYPTO_TECH_LUKS-%BD_CRYPTO_TECH_MODE_QUERY
 */
BDCryptoLUKSInfo* bd_crypto_luks_info (const gchar *luks_device, GError **error) {
    return _bd_crypto_luks_info (luks_device, error);
}


BDCryptoIntegrityInfo* bd_crypto_integrity_info_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_crypto_integrity_info' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_integrity_info' called, but not implemented!");
    return NULL;
}

BDCryptoIntegrityInfo* (*_bd_crypto_integrity_info) (const gchar *device, GError **error) = bd_crypto_integrity_info_stub;

/**
 * bd_crypto_integrity_info:
 * @device: a device to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: information about the @device or %NULL in case of error
 *
 * Tech category: %BD_CRYPTO_TECH_INTEGRITY-%BD_CRYPTO_TECH_MODE_QUERY
 */
BDCryptoIntegrityInfo* bd_crypto_integrity_info (const gchar *device, GError **error) {
    return _bd_crypto_integrity_info (device, error);
}


gboolean  bd_crypto_device_seems_encrypted_stub (const gchar *device, GError **error) {
    g_critical ("The function 'bd_crypto_device_seems_encrypted' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_device_seems_encrypted' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_device_seems_encrypted) (const gchar *device, GError **error) = bd_crypto_device_seems_encrypted_stub;

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
gboolean  bd_crypto_device_seems_encrypted (const gchar *device, GError **error) {
    return _bd_crypto_device_seems_encrypted (device, error);
}


gboolean  bd_crypto_tc_open_stub (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error) {
    g_critical ("The function 'bd_crypto_tc_open' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_tc_open' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_tc_open) (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error) = bd_crypto_tc_open_stub;

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
gboolean  bd_crypto_tc_open (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error) {
    return _bd_crypto_tc_open (device, name, pass_data, data_len, read_only, error);
}


gboolean  bd_crypto_tc_open_full_stub (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, const gchar **keyfiles, gboolean hidden, gboolean system, gboolean veracrypt, guint32 veracrypt_pim, gboolean read_only, GError **error) {
    g_critical ("The function 'bd_crypto_tc_open_full' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_tc_open_full' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_tc_open_full) (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, const gchar **keyfiles, gboolean hidden, gboolean system, gboolean veracrypt, guint32 veracrypt_pim, gboolean read_only, GError **error) = bd_crypto_tc_open_full_stub;

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
gboolean  bd_crypto_tc_open_full (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, const gchar **keyfiles, gboolean hidden, gboolean system, gboolean veracrypt, guint32 veracrypt_pim, gboolean read_only, GError **error) {
    return _bd_crypto_tc_open_full (device, name, pass_data, data_len, keyfiles, hidden, system, veracrypt, veracrypt_pim, read_only, error);
}


gboolean  bd_crypto_tc_close_stub (const gchar *tc_device, GError **error) {
    g_critical ("The function 'bd_crypto_tc_close' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_tc_close' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_tc_close) (const gchar *tc_device, GError **error) = bd_crypto_tc_close_stub;

/**
 * bd_crypto_tc_close:
 * @tc_device: TrueCrypt/VeraCrypt device to close
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @tc_device was successfully closed or not
 *
 * Tech category: %BD_CRYPTO_TECH_TRUECRYPT-%BD_CRYPTO_TECH_MODE_OPEN_CLOSE
 */
gboolean  bd_crypto_tc_close (const gchar *tc_device, GError **error) {
    return _bd_crypto_tc_close (tc_device, error);
}


gboolean  bd_crypto_escrow_device_stub (const gchar *device, const gchar *passphrase, const gchar *cert_data, const gchar *directory, const gchar *backup_passphrase, GError **error) {
    g_critical ("The function 'bd_crypto_escrow_device' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_crypto_escrow_device' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_crypto_escrow_device) (const gchar *device, const gchar *passphrase, const gchar *cert_data, const gchar *directory, const gchar *backup_passphrase, GError **error) = bd_crypto_escrow_device_stub;

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
gboolean  bd_crypto_escrow_device (const gchar *device, const gchar *passphrase, const gchar *cert_data, const gchar *directory, const gchar *backup_passphrase, GError **error) {
    return _bd_crypto_escrow_device (device, passphrase, cert_data, directory, backup_passphrase, error);
}


gpointer load_crypto_from_plugin(const gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module crypto: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "bd_crypto_check_deps");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for crypto: %s", error);
    if (!g_getenv ("LIBBLOCKDEV_SKIP_DEP_CHECKS") && check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "bd_crypto_init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for crypto: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_crypto_is_tech_avail) = dlsym(handle, "bd_crypto_is_tech_avail");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_is_tech_avail: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_generate_backup_passphrase) = dlsym(handle, "bd_crypto_generate_backup_passphrase");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_generate_backup_passphrase: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_device_is_luks) = dlsym(handle, "bd_crypto_device_is_luks");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_device_is_luks: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_uuid) = dlsym(handle, "bd_crypto_luks_uuid");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_uuid: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_get_metadata_size) = dlsym(handle, "bd_crypto_luks_get_metadata_size");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_get_metadata_size: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_status) = dlsym(handle, "bd_crypto_luks_status");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_status: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_format) = dlsym(handle, "bd_crypto_luks_format");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_format: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_format_blob) = dlsym(handle, "bd_crypto_luks_format_blob");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_format_blob: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_format_luks2) = dlsym(handle, "bd_crypto_luks_format_luks2");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_format_luks2: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_format_luks2_blob) = dlsym(handle, "bd_crypto_luks_format_luks2_blob");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_format_luks2_blob: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_open) = dlsym(handle, "bd_crypto_luks_open");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_open: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_open_blob) = dlsym(handle, "bd_crypto_luks_open_blob");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_open_blob: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_close) = dlsym(handle, "bd_crypto_luks_close");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_close: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_add_key) = dlsym(handle, "bd_crypto_luks_add_key");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_add_key: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_add_key_blob) = dlsym(handle, "bd_crypto_luks_add_key_blob");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_add_key_blob: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_remove_key) = dlsym(handle, "bd_crypto_luks_remove_key");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_remove_key: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_remove_key_blob) = dlsym(handle, "bd_crypto_luks_remove_key_blob");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_remove_key_blob: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_change_key) = dlsym(handle, "bd_crypto_luks_change_key");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_change_key: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_change_key_blob) = dlsym(handle, "bd_crypto_luks_change_key_blob");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_change_key_blob: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_resize) = dlsym(handle, "bd_crypto_luks_resize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_resize: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_resize_luks2) = dlsym(handle, "bd_crypto_luks_resize_luks2");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_resize_luks2: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_resize_luks2_blob) = dlsym(handle, "bd_crypto_luks_resize_luks2_blob");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_resize_luks2_blob: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_suspend) = dlsym(handle, "bd_crypto_luks_suspend");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_suspend: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_resume_blob) = dlsym(handle, "bd_crypto_luks_resume_blob");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_resume_blob: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_resume) = dlsym(handle, "bd_crypto_luks_resume");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_resume: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_kill_slot) = dlsym(handle, "bd_crypto_luks_kill_slot");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_kill_slot: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_header_backup) = dlsym(handle, "bd_crypto_luks_header_backup");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_header_backup: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_header_restore) = dlsym(handle, "bd_crypto_luks_header_restore");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_header_restore: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_luks_info) = dlsym(handle, "bd_crypto_luks_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_luks_info: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_integrity_info) = dlsym(handle, "bd_crypto_integrity_info");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_integrity_info: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_device_seems_encrypted) = dlsym(handle, "bd_crypto_device_seems_encrypted");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_device_seems_encrypted: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_tc_open) = dlsym(handle, "bd_crypto_tc_open");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_tc_open: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_tc_open_full) = dlsym(handle, "bd_crypto_tc_open_full");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_tc_open_full: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_tc_close) = dlsym(handle, "bd_crypto_tc_close");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_tc_close: %s", error);

    dlerror();
    * (void**) (&_bd_crypto_escrow_device) = dlsym(handle, "bd_crypto_escrow_device");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_escrow_device: %s", error);

    return handle;
}

gboolean unload_crypto (gpointer handle) {
    char *error = NULL;
    gboolean (*close_fn) (void) = NULL;

    _bd_crypto_is_tech_avail = bd_crypto_is_tech_avail_stub;
    _bd_crypto_generate_backup_passphrase = bd_crypto_generate_backup_passphrase_stub;
    _bd_crypto_device_is_luks = bd_crypto_device_is_luks_stub;
    _bd_crypto_luks_uuid = bd_crypto_luks_uuid_stub;
    _bd_crypto_luks_get_metadata_size = bd_crypto_luks_get_metadata_size_stub;
    _bd_crypto_luks_status = bd_crypto_luks_status_stub;
    _bd_crypto_luks_format = bd_crypto_luks_format_stub;
    _bd_crypto_luks_format_blob = bd_crypto_luks_format_blob_stub;
    _bd_crypto_luks_format_luks2 = bd_crypto_luks_format_luks2_stub;
    _bd_crypto_luks_format_luks2_blob = bd_crypto_luks_format_luks2_blob_stub;
    _bd_crypto_luks_open = bd_crypto_luks_open_stub;
    _bd_crypto_luks_open_blob = bd_crypto_luks_open_blob_stub;
    _bd_crypto_luks_close = bd_crypto_luks_close_stub;
    _bd_crypto_luks_add_key = bd_crypto_luks_add_key_stub;
    _bd_crypto_luks_add_key_blob = bd_crypto_luks_add_key_blob_stub;
    _bd_crypto_luks_remove_key = bd_crypto_luks_remove_key_stub;
    _bd_crypto_luks_remove_key_blob = bd_crypto_luks_remove_key_blob_stub;
    _bd_crypto_luks_change_key = bd_crypto_luks_change_key_stub;
    _bd_crypto_luks_change_key_blob = bd_crypto_luks_change_key_blob_stub;
    _bd_crypto_luks_resize = bd_crypto_luks_resize_stub;
    _bd_crypto_luks_resize_luks2 = bd_crypto_luks_resize_luks2_stub;
    _bd_crypto_luks_resize_luks2_blob = bd_crypto_luks_resize_luks2_blob_stub;
    _bd_crypto_luks_suspend = bd_crypto_luks_suspend_stub;
    _bd_crypto_luks_resume_blob = bd_crypto_luks_resume_blob_stub;
    _bd_crypto_luks_resume = bd_crypto_luks_resume_stub;
    _bd_crypto_luks_kill_slot = bd_crypto_luks_kill_slot_stub;
    _bd_crypto_luks_header_backup = bd_crypto_luks_header_backup_stub;
    _bd_crypto_luks_header_restore = bd_crypto_luks_header_restore_stub;
    _bd_crypto_luks_info = bd_crypto_luks_info_stub;
    _bd_crypto_integrity_info = bd_crypto_integrity_info_stub;
    _bd_crypto_device_seems_encrypted = bd_crypto_device_seems_encrypted_stub;
    _bd_crypto_tc_open = bd_crypto_tc_open_stub;
    _bd_crypto_tc_open_full = bd_crypto_tc_open_full_stub;
    _bd_crypto_tc_close = bd_crypto_tc_close_stub;
    _bd_crypto_escrow_device = bd_crypto_escrow_device_stub;

    dlerror();
    * (void**) (&close_fn) = dlsym(handle, "bd_crypto_close");
    if (((error = dlerror()) != NULL) || !close_fn)
        g_debug("failed to load the close_plugin() function for crypto: %s", error);
    if (close_fn) {
        close_fn();
    }

    return dlclose(handle) == 0;
}

