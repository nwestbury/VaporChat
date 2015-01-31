#include "mainwindow.h"
#include <QApplication>


#include "crypto.h"

void nathan_tests() {
    init_crypto();

    char *pub, *priv;
    createKeyPair("test", pub, priv);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    nathan_tests();

    return a.exec();
}
