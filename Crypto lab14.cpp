#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    ERR_load_crypto_strings();

    ctx = SSL_CTX_new(SSLv23_server_method());
    SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM);

    bio = BIO_new_accept("443");
    BIO_set_accept_bios(bio, BIO_BIND_REUSEADDR);
    BIO_do_accept(bio);

    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
    SSL_CTX_set_verify_depth(ctx, 1);

    while (1) {
        BIO *client = BIO_pop(bio);
        ssl = SSL_new(ctx);
        SSL_set_bio(ssl, client, client);
        SSL_accept(ssl);

        // SSL communication with the client

        SSL_shutdown(ssl);
        SSL_free(ssl);
        BIO_free(client);
    }

    SSL_CTX_free(ctx);
    ERR_free_strings();
    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();
    ERR_remove_state(0);
    ERR_free_strings();

    return 0;
}
Perform the configuring of S/MIME for e-mail communication.
