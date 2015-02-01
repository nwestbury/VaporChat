#include <QApplication>
#include <QMessageBox>
#include <QListWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networking.h"
#include "openssl/rsa.h"

typedef struct st_friend{
    bool isOnline;
    QString friendName;
    RSA *pubkey;
} myFriend;

typedef struct st_childChatWindow{
    QString sessionkey;
    //chatWindow window;
}childChatWindow;

mainWindow::mainWindow()
{
    getFriendList();

    //loginWindow * loginWin = new loginWindow;

    setupUi(this);

    logWin.show();

    for(int i=0; i<friends.size(); ++i){
        QListWidgetItem *item = new QListWidgetItem (QIcon(":img/online.png"), friends.at(i), friendList);
        friendList->addItem(item);
    }

    /*myNetwork *n = new myNetwork(this);
    QString x = QString::fromUtf8("getMessages.php");
    QStringList l;
    l << "username" << "Nico";

    n->network(x,l, SLOT(postRecieved(QNetworkReply*)), this);*/

    friendList->setSortingEnabled(true);
    //friendList->sortingEnabled(true);
}

mainWindow::~mainWindow()
{
}

void mainWindow::getFriendList(){
    friends << "Nico" << "James" << "Nathan";
}

void mainWindow::postRecieved( QNetworkReply* reply){
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QMessageBox messageBox;
    messageBox.setText(str);
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    messageBox.exec();
}
