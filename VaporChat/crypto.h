#ifndef CRYPTO_H
#define CRYPTO_H

void init_crypto();

void createKeyPair(char *password, char **pub_out, char **priv_out);
void importKeyPair(char *privatePassword, char *privatekey, char *publickey);

#endif // CRYPTO_H

