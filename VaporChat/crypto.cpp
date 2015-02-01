#include <QApplication>
#include <QMessageBox>

#include <string>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <openssl/bio.h>
#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/rand.h>


RSA *rsa;//key pair
const int def_padding = RSA_PKCS1_OAEP_PADDING;


////////////////    BOILERPLATE CODE    ////////////////

void error() {
    QMessageBox errbox;
    errbox.setText(ERR_error_string(ERR_get_error(), 0));
    errbox.exec();
}

void init_crypto() {
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    OPENSSL_config(NULL);

    //initialize singletons
    rsa = RSA_new();
}



////////////////    RSA CODE    ////////////////

//returns the keys in PEM format in the respective buffers. Caller must free() the buffers after use.
void createKeyPair(char *password, char **pub_out, char **priv_out)
{
    QMessageBox errbox;

    // Generate RSA keypair
    BIGNUM *e = NULL;
    BN_dec2bn(&e, "65537");

    rsa = RSA_new();
    if(!RSA_generate_key_ex(rsa, 2048, e, NULL)) error();

    // Export keypair to BIO
    BIO *bp_pub = BIO_new(BIO_s_mem());
    BIO *bp_priv = BIO_new(BIO_s_mem());

    //convert RSA to EVP_PKEY
    EVP_PKEY *evpkey = EVP_PKEY_new();
    if (!EVP_PKEY_set1_RSA(evpkey, rsa)) error();

    if(!PEM_write_bio_PKCS8PrivateKey(bp_priv, evpkey,
                                      EVP_aes_256_cbc(), password,
                                      strlen(password), 0, 0)) error();
    if(!PEM_write_bio_PUBKEY(bp_pub, evpkey)) error();

    EVP_PKEY_free(evpkey);


    // Write the keys to the output buffers
    char *priv_str, *pub_str;

    int size_priv = BIO_get_mem_data(bp_priv, &priv_str);
    int size_pub = BIO_get_mem_data(bp_pub, &pub_str);

    *priv_out = (char *)malloc(size_priv+1);
    *pub_out = (char *)malloc(size_pub+1);

    memcpy(*priv_out, priv_str, size_priv);
    memcpy(*pub_out, pub_str, size_pub);
    (*priv_out)[size_priv] = 0;
    (*pub_out)[size_pub] = 0;

    BIO_free(bp_priv);
    BIO_free(bp_pub);
}

//imports pem keys into the user's global RSA struct
void importKeyPair(char *privatePassword, char *privatekey, char *publickey) {
    BIO *pubk = BIO_new_mem_buf(publickey, -1);
    BIO *privk = BIO_new_mem_buf(privatekey, -1);

    if(pubk == NULL) error();

    if(!PEM_read_bio_RSA_PUBKEY(pubk, &rsa, NULL, NULL)) error();
    if(!PEM_read_bio_RSAPrivateKey(privk, &rsa, 0, privatePassword)) error();

    if(!RSA_check_key(rsa)) error();
}

void importPubKey(char *pubkey, RSA * rsa_pub_out) {
    BIO *pubk = BIO_new_mem_buf(pubkey, -1);

    if(pubk == NULL) error();

    if(!PEM_read_bio_RSA_PUBKEY(pubk, &rsa_pub_out, NULL, NULL)) error();
}

//out must be free()'d by caller
void RSAEncrypt(RSA *pubkey, char *in, int inlen, char **out, int *len)
{
    *out = (char *)malloc(RSA_size(pubkey));
    *len = RSA_public_encrypt(inlen, (const unsigned char*)in, (unsigned char*)*out, pubkey, def_padding);

    if(*len == -1) error();
}

void RSADecrypt(RSA *privatekey, char *in, int inlen, char **out, int *len) {
    *out = (char *)malloc(RSA_size(privatekey));
    *len = RSA_private_decrypt(inlen, (const unsigned char*)in, (unsigned char*)*out, privatekey, def_padding);

    if(*len == -1) error();
}




////////////////    AES CODE    ////////////////

//Generates a 256bit random key
int generateRandAESKey(char *buf, int buflen)
{
    if(buflen != 32)
        return 0;

    if(!RAND_bytes((unsigned char *)buf, buflen)) error();
    return 1;
}

//AESEncrypt() {


//}


////////////////    OTHER CRYPTO CODE    ////////////////
void bin2hex(char *bin, int binlen, char **hexout)
{
    char *a = "0123456789abcdef";

    *hexout = (char *)malloc(binlen*2+1);

    for(int i = 0; i < binlen; ++i) {
        (*hexout)[i*2] = a[(unsigned char)bin[i] >> 4];
        (*hexout)[i*2+1] = a[(unsigned char)(bin[i] & 0xF)];
    }

    (*hexout)[binlen*2] = 0;
}

void hex2bin(char *hex, unsigned char **binout)
{
    char *a = "0123456789abcdef";
    int hexlen = strlen(hex);
    int binlen = hexlen/2;
    *binout = (unsigned char *)malloc(strlen(hex)*2);

    char character[2] = {0};
    for(int i = 0; i < hexlen; ++i) {
        character[0] = (hex[i*2]);
        (*binout)[i] = (strstr(a, character)-a) << 4;
        character[0] = (hex[i*2+1]);
        (*binout)[i] = (*binout)[i] | (strstr(a, character)-a);
    }

    (*binout)[binlen*2] = 0;
}



