#include "networking.h"

void network (){
    QNetworkAccessManager *manager;

    manager->get(QNetworkRequest(QUrl("http://qt.nokia.com")));
}
