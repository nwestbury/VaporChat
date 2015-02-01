#ifndef CRYPTO_H
#define CRYPTO_H

#include "openssl/rsa.h"
#include "openssl/evp.h"


void init_crypto();

void createKeyPair(char *password, char **pub_out, char **priv_out);
void importKeyPair(char *privatePassword, char *privatekey, char *publickey);

void RSAEncrypt(RSA *pubkey, char *in, int inlen, char **out, int *len);
void RSADecrypt(RSA *privatekey, char *in, int inlen, char **out, int *len);


int generateKeyRandBytes(char *buf, int buflen);
int AES_InitKeys(unsigned char *key_data, int key_data_len, EVP_CIPHER_CTX *e_ctx, EVP_CIPHER_CTX *d_ctx);
void AESEncrypt(EVP_CIPHER_CTX *ekey, unsigned char *plaintext, unsigned char **cypher, int *len);
void AESDecrypt(EVP_CIPHER_CTX *dkey, unsigned char *ciphertext, unsigned char **plaintext, int *len);


void bin2hex(char *bin, int binlen, char **hexout);
void hex2bin(char *hex, char **binout);

#endif // CRYPTO_H

