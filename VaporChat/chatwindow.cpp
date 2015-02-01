#include "chatwindow.h"
#include "ui_chatwindow.h"
#include "networking.h"
#include "global.h"
#include <QTimer>
#include <QMessageBox>


chatWindow::chatWindow(QString title, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(title + "Chat");
    ui->userLabel->setText(title);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(3000);

    connect(ui->sendButton, SIGNAL(clicked(bool)), this, SLOT(sendChat()));
    connect(ui->textInput, SIGNAL(returnPressed()), ui->sendButton, SIGNAL(clicked()));
}

extern QStringList *msgArray;

void chatWindow::sendChat(){

    QString messageText = ui->textInput->text();
    *msgArray << messageText;

    myNetwork *n = new myNetwork(this);
    QString filename = QString::fromUtf8("saveMsg.php");
    QStringList l;
    l << "username" << g_username;
    l << "msg" << messageText;

    n->network(filename, l, SLOT(postRecieved(QNetworkReply*)), this);

    QStringList list = *msgArray;
    QStringList::iterator it = list.begin();
    ui->textEdit->setText("");
    while (it != list.end()) {
        ui->textEdit->append(*it);
        ++it;
    }

    ui->textInput->setText("");
}

chatWindow::~chatWindow()
{
    delete ui;
}

void chatWindow::update(){
    /*myNetwork *n = new myNetwork(this);
    QString filename = QString::fromUtf8("getLatest.php");
    QStringList l;
    l << "username" << g_username;

    n->network(filename, l, SLOT(postRecieved(QNetworkReply*)), this);*/


}

void chatWindow::postRecieved(QNetworkReply* r){

}
