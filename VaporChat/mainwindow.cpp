#include <QApplication>
#include <QMessageBox>
#include <QListWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networking.h"
#include "chatwindow.h"
#include "openssl/rsa.h"

mainWindow::mainWindow() {
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

    connect(friendList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
    connect(&logWin, SIGNAL(loginSuccessful()), this, SLOT(swapLogin()));
}

mainWindow::~mainWindow()
{
}

void mainWindow::getFriendList(){
    friends << "Nico" << "James" << "Nathan";
}

void mainWindow::swapLogin(){
    logWin.hide();
    this->show();
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

void mainWindow::onItemClicked(QListWidgetItem *item)
{
    QString frnd = item->text();

    if(!childWindows.contains(frnd))
        childWindows[frnd] = new chatWindow(frnd);
    else
        childWindows[frnd]->show();
}
