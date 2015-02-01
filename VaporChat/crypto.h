#ifndef CRYPTO_H
#define CRYPTO_H

#include "openssl/rsa.h"

void init_crypto();

void createKeyPair(char *password, char **pub_out, char **priv_out);
void importKeyPair(char *privatePassword, char *privatekey, char *publickey);

void RSAEncrypt(RSA *pubkey, char *in, int inlen, char **out, int *len);
void RSADecrypt(RSA *privatekey, char *in, int inlen, char **out, int *len);


void bin2hex(char *bin, int binlen, char **hexout);

#endif // CRYPTO_H

