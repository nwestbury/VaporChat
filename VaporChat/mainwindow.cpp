#include <QApplication>
#include <QMessageBox>
#include <QListWidget>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QThread>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networking.h"
#include "chatwindow.h"
#include "openssl/rsa.h"


QString frnd;

typedef struct st_friend{
    bool isOnline;
    QString friendName;
    RSA *pubkey;
} myFriend;

mainWindow::mainWindow()
{
    getFriendList();

    //loginWindow * loginWin = new loginWindow;

    setupUi(this);

    for(int i=0; i<friends.size(); ++i){
        QListWidgetItem *item = new QListWidgetItem (QIcon(":img/online.png"), friends.at(i), friendList);
        friendList->addItem(item);
    }

    friendList->setSortingEnabled(true);
    //friendList->sortingEnabled(true);

    connect(friendList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
}

mainWindow::~mainWindow()
{
}

void mainWindow::getFriendList(){
    friends << "Nico" << "James" << "Nathan";
}

void mainWindow::onItemClicked(QListWidgetItem *item)
{
    frnd = item->text();

    if(!childWindows.contains(frnd))
        childWindows[frnd] = new chatWindow(frnd);
    else
        childWindows[frnd]->show();

    myNetwork *n = new myNetwork(this);
    QString x = QString::fromUtf8("getMessages.php");
    QStringList l;
    l << "username" << frnd;

    n->network(x,l, SLOT(postRecieved(QNetworkReply*)), this);
}

void mainWindow::postRecieved(QNetworkReply* reply){
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());

    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonArray jsonArray = jsonResponse.array();

    QJsonValue sessionID = jsonArray.at(0);
    QJsonValue lastMsgID = jsonArray.at(1);

    childWindows[frnd]->session = sessionID.toInt();
    childWindows[frnd]->lastMsg = lastMsgID.toInt();

    for (int i = 2; i<jsonArray.size(); i++){
        QJsonValue value = jsonArray.at(i);
        QJsonArray valueArray = value.toArray();
        childWindows[frnd]->msgArray->append(valueArray.at(0).toString());
        childWindows[frnd]->msgArray->append(valueArray.at(1).toString()+"\n");
    }

    QStringList::iterator it = childWindows[frnd]->msgArray->begin();
    childWindows[frnd]->ui->textEdit->setText("");
    while (it != childWindows[frnd]->msgArray->end()) {
        childWindows[frnd]->ui->textEdit->append(*it);
        ++it;
    }
}
