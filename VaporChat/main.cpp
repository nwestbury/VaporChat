#include "mainwindow.h"
#include "networking.h"
#include <QApplication>

#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>
#include <QtNetwork/QNetworkAccessManager>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.show();

    myNetwork n;
    n.network();

    return a.exec();
}
