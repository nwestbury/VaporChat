#include "networking.h"
#include <QMessageBox>

// Parameters is an array of strings where each even index is the key and each odd is the data
void myNetwork::network(QString &file, QStringList &parameters, const char * funcName, QMainWindow *obj){

    /*QFile file(":/ssl/certificate.crt");
    file.open(QIODevice::ReadOnly);
    const QByteArray bytes = file.readAll();

    // Create a certificate object
    const QSslCertificate certificate(bytes);
    const QList<QSslCertificate> list;
    list << certificate;

    // Add this certificate to all SSL connections
    QSslConfiguration sslConfig;
    sslConfig.setLocalCertificate(certificate);
    sslConfig.setCaCertificates(list);
    sslConfig.setProtocol(QSsl::TlsV1_2);
    QSslSocket::addDefaultCaCertificate(certificate);*/

     QNetworkAccessManager *manager = new QNetworkAccessManager(this);
     manager->setNetworkAccessible(QNetworkAccessManager::Accessible);

      connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
     //connect(manager, SIGNAL(finished(QNetworkReply*)), obj, funcName);

     QNetworkRequest request;

     //request.setSslConfiguration(sslConfig);
     QString urlString = "http://107.181.166.77/" + file;

     request.setUrl(QUrl(urlString));
     request.setRawHeader("User-Agent", "FakeBrowser 1.0");

    QUrlQuery params;
    for(int i=0; i<parameters.size(); i+=2){
        params.addQueryItem(parameters[i], parameters[i+1]);
    }
    QByteArray data;
    data.append(params.toString());
    QNetworkReply * reply = manager->post(request, data);

    QNetworkReply::NetworkError err = reply->error();

    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(error(QList<QSslError>)));
}

void myNetwork::replyFinished(QNetworkReply *reply){
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QMessageBox messageBox;
    messageBox.setText(str);
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    messageBox.exec();
}

void myNetwork::error(const QList<QSslError> err){
    QMessageBox msgBox;
    msgBox.setText(err[0].errorString());
    msgBox.exec();
}
