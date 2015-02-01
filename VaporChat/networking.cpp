#include "networking.h"
#include <QMessageBox>

void myNetwork::network(){

     QNetworkAccessManager *manager = new QNetworkAccessManager(this);

     /*// Read the SSL certificate
     QFile file(":/ssl/api.xyz.com.crt");
     file.open(QIODevice::ReadOnly);
     const QByteArray bytes = file.readAll();

     // Create a certificate object
     const QSslCertificate certificate(bytes);

     // Add this certificate to all SSL connections
     QSslSocket::addDefaultCaCertificate(certificate);*/

     connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

     QNetworkRequest request;
     request.setUrl(QUrl("http://107.181.166.77"));
     request.setRawHeader("User-Agent", "FakeBrowser 1.0");

     QSslConfiguration sslConfiguration;
     sslConfiguration.setProtocol(QSsl::SslV3);

     request.setSslConfiguration(sslConfiguration);

    QNetworkReply * reply = manager->get(request);

    QMessageBox messageBox;
    messageBox.setText("WHAT?!");
    messageBox.exec();
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
