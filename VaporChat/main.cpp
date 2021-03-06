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
    EVP_CIPHER_CTX ekey, dkey;

    generateKeyRandBytes(keybuf, sizeof(keybuf));
    AES_InitKeys((unsigned char *)keybuf, sizeof(keybuf), &ekey, &dkey);

    char text[] = "abcdefghijklmnopqrstuvwxyz";
    int msglen = sizeof(text);
    char *cyphertext, *plaintext;
    AESEncrypt(&ekey, (unsigned char *)text, (unsigned char **)&cyphertext, &msglen);
    AESDecrypt(&dkey, (unsigned char *)cyphertext, (unsigned char **)&plaintext, &msglen);

    msg.setTextInteractionFlags(Qt::TextSelectableByMouse);
    msg.setText(plaintext);
    msg.exec();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWindow w;
    w.show();
	
    //if(strcmp(getenv("USERNAME"), "Jacob") == 0)
    //nathan_tests();

    return a.exec();
}
