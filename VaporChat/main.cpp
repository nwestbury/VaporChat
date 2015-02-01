#include "loginwindow.h"
#include "mainwindow.h"
#include "networking.h"
#include <QApplication>
#include <QMessageBox>

#include "crypto.h"
#include "stdio.h"


void nathan_tests() {
    init_crypto();

    QMessageBox msg;

    /*char *hexout;
    bin2hex("test123 test 123", 18, &hexout);

    msg.setText(hexout);
    msg.exec();

    char *binout;
    hex2bin(hexout, &binout);

    msg.setText(binout);
    msg.exec();*/

    char keybuf[32] = {0};
    generateRandAESKey(keybuf, sizeof(keybuf));

    char *hexkey;
    bin2hex(keybuf, 32, &hexkey);

    msg.setTextInteractionFlags(Qt::TextSelectableByMouse);
    msg.setText(hexkey);
    msg.exec();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    loginWindow w;
    w.show();
	
    if(strcmp(getenv("USERNAME"), "Jacob") == 0)
        nathan_tests();

    return a.exec();
}
