#include "mainwindow.h"
#include "networking.h"
#include <QApplication>
#include <QFile>
#include <QMessageBox>


/*#include "crypto.h"

void nathan_tests() {
    init_crypto();

    char *pub, *priv;
    createKeyPair("test", pub, priv);
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.show();

	
    /*if(strcmp(getenv("USERNAME"),"Jacob") == 0)
        nathan_tests();*/

    return a.exec();
}
