#include <QApplication>
#include <QMessageBox>

#include <string>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "openssl/bio.h"
#include "openssl/aes.h"
#include "openssl/rsa.h"
#include "openssl/pem.h"
#include <openssl/err.h>
#include <openssl/conf.h>


static RSA *rsa;//key pair


void init_crypto() {
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    OPENSSL_config(NULL);

    //initialize singletons
    rsa = RSA_new();
}


//returns the keys in PEM format in the respective buffers. Caller must free() the buffers after use.
void createKeyPair(char *password, char *pub_out, char *priv_out)
{
    QMessageBox errbox;

    // Generate RSA keypair
    BIGNUM *e = NULL;
    BN_dec2bn(&e, "65537");

    rsa = RSA_new();
    if(!RSA_generate_key_ex(rsa, 2048, e, NULL)) goto err;

    // Export keypair to BIO
    BIO *bp_pub = BIO_new(BIO_s_mem());
    BIO *bp_priv = BIO_new(BIO_s_mem());


    //convert RSA to EVP
    EVP_PKEY *evpkey = EVP_PKEY_new();
    if (!EVP_PKEY_set1_RSA(evpkey, rsa)) goto err;

    if(!PEM_write_bio_PKCS8PrivateKey(bp_priv, evpkey,
                                      EVP_aes_256_cbc(), password,
                                      strlen(password), 0, 0)) goto err;
    if(!PEM_write_bio_PUBKEY(bp_pub, evpkey)) goto err;


    // Output the private key to the buffers
    char *priv_str;
    char *pub_str;

    int size_priv = BIO_get_mem_data(bp_priv, &priv_str);
    int size_pub = BIO_get_mem_data(bp_pub, &pub_str);

    priv_out = (char *)malloc(size_priv+1);
    pub_out = (char *)malloc(size_pub+1);

    memcpy(priv_out, priv_str, size_priv);
    memcpy(pub_out, pub_str, size_pub);
    priv_out[size_priv] = 0;
    pub_out[size_pub] = 0;

    errbox.setText(pub_out);
    errbox.exec();

    errbox.setText(priv_out);
    errbox.exec();

    goto done;
err:
    errbox.setText(ERR_error_string(ERR_get_error(), 0));
    errbox.exec();

done:
    BIO_free(bp_priv);
    BIO_free(bp_pub);
}


