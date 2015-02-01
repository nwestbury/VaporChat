#include <QSslSocket>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>

class DummyClient : public QObject {
    Q_OBJECT
public:
    DummyClient(QTextStream& log)
        : _log(log),
          _sock(new QSslSocket(this)) {
        connect(_sock, SIGNAL(encrypted()), this, SLOT(onEncrypted()));
        connect(_sock, SIGNAL(sslErrors(QList<QSslError>)),
                this, SLOT(onSslErrors(QList<QSslError>)));
        connect(_sock, SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(onErrors(QAbstractSocket::SocketError)));

        // Trust store: which CAs or self-signed certs we are going to trust.
        //
        // We use setCaCertificates() instead than QSslSocket::addCaCertificates()
        // because we don't want to trust the ~200 default CAs.
        QList<QSslCertificate> trustedCas = QSslCertificate::fromPath(":/ssl/certificate.crt");
        if (trustedCas.empty()) {
            qFatal("Error: no trusted Cas");
        }
        _sock->setCaCertificates(trustedCas);

        bool mutualAuth = false;
        if (mutualAuth) {
            // Our identity
            _sock->setPrivateKey("client-key.pem");
            _sock->setLocalCertificate("client-cert.pem");
        }

        _log << "Connecting" << endl;
        // Note: serverName must match the cert CN or alternative name.
        QString serverName = "myserver.example.org";
        _sock->connectToHostEncrypted(serverName, 995);
    }

signals:
    void done();

private slots:
    void onEncrypted() {
        _log << "onEncrypted" << endl;

        /* Everything is good. Start communicating. */

        emit done();
    }

    void onSslErrors(QList<QSslError> errors) {
        QSslError first = errors.takeFirst();
        _log << "onSslErrors: " << first.errorString() << endl;

        /* Something went wrong in the TLS handshake. Inform the user and quit! */

        emit done();
    }

    void onErrors(QAbstractSocket::SocketError) {
        _log << "onErrors: " << _sock->errorString() << endl;
        emit done();
    }

private:
    QTextStream& _log;
    QSslSocket* _sock;
};
