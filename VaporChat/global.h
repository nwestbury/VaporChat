#ifndef GLOBAL_H
#define GLOBAL_H

#include <QHash>
#include <openssl/rsa.h>

QT_BEGIN_NAMESPACE

extern QHash<QString, QString> friendHash;
extern QString privateKey;
extern QString publicKey;
extern QString username;

QT_END_NAMESPACE

#endif // GLOBAL_H

