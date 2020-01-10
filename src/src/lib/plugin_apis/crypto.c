GQuark  bd_crypto_error_quark (void) {
        return g_quark_from_static_string ("g-bd-crypto-error-quark");
}

static const gchar const * const crypto_functions[] = {
    "bd_crypto_generate_backup_passphrase",
    "bd_crypto_device_is_luks",
    "bd_crypto_luks_uuid",
    "bd_crypto_luks_status",
    "bd_crypto_luks_format",
    "bd_crypto_luks_format_blob",
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
    "bd_crypto_tc_open",
    "bd_crypto_tc_close",
    "bd_crypto_escrow_device",
    NULL};

gchar const * const * get_crypto_functions (void) {
    return crypto_functions;
}

static const guint8 crypto_num_functions = 19;

guint8 get_crypto_num_functions (void) {
    return crypto_num_functions;
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
 * Returns: UUID of the @device or %NULL if failed to determine (@error)
 * is populated with the error in such cases)
 */
gchar* bd_crypto_luks_uuid (const gchar *device, GError **error) {
    return _bd_crypto_luks_uuid (device, error);
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
 */
gboolean  bd_crypto_luks_format_blob (const gchar *device, const gchar *cipher, guint64 key_size, const guint8 *pass_data, gsize data_len, guint64 min_entropy, GError **error) {
    return _bd_crypto_luks_format_blob (device, cipher, key_size, pass_data, data_len, min_entropy, error);
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
 * Returns: whether the @luks_device was successfully resized or not
 */
gboolean  bd_crypto_luks_resize (const gchar *luks_device, guint64 size, GError **error) {
    return _bd_crypto_luks_resize (luks_device, size, error);
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
 */
gboolean  bd_crypto_tc_open (const gchar *device, const gchar *name, const guint8* pass_data, gsize data_len, gboolean read_only, GError **error) {
    return _bd_crypto_tc_open (device, name, pass_data, data_len, read_only, error);
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
    * (void**) (&_bd_crypto_tc_open) = dlsym(handle, "bd_crypto_tc_open");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_crypto_tc_open: %s", error);

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

    _bd_crypto_generate_backup_passphrase = bd_crypto_generate_backup_passphrase_stub;
    _bd_crypto_device_is_luks = bd_crypto_device_is_luks_stub;
    _bd_crypto_luks_uuid = bd_crypto_luks_uuid_stub;
    _bd_crypto_luks_status = bd_crypto_luks_status_stub;
    _bd_crypto_luks_format = bd_crypto_luks_format_stub;
    _bd_crypto_luks_format_blob = bd_crypto_luks_format_blob_stub;
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
    _bd_crypto_tc_open = bd_crypto_tc_open_stub;
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

