#ifndef NETWORKING_H
#define NETWORKING_H

#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class myNetwork : public QObject
{
    Q_OBJECT
    public:
        void network();
    private slots:
        void replyFinished(QNetworkReply *reply);
};

#endif // NETWORKING_H

