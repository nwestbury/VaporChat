#ifndef NETWORKING_H
#define NETWORKING_H

#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QMainWindow>


class myNetwork : public QObject
{
    Q_OBJECT
    public:
        void network(QString &file, QStringList &parameters, const char * funcName, QMainWindow * obj);

        myNetwork(QObject *parent) {
            this->setParent(parent);
        }

    private slots:
        void replyFinished(QNetworkReply *reply);
        void error(const QList<QSslError> err);
};

#endif // NETWORKING_H

