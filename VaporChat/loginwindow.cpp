#include <QPixmap>
#include <QRect>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>


#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"

#include "registerwindow.h"
#include "networking.h"

#include "global.h"

loginWindow::loginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    QPixmap icon = QPixmap(123, 109);
    icon.load(":/img/VaporIcon.png");
    ui->iconLabel->setPixmap(icon);

    ui->loginButton->setStyleSheet("background-color: rgb(28, 184, 65, 70%)");
    ui->logRegisterButton->setStyleSheet("background-color: rgb(200, 10, 10, 70%)");

    ui->errorLabel->setHidden(true);
    ui->errorLabel->setStyleSheet("color: red");

    connect(ui->loginButton, SIGNAL(clicked(bool)), this, SLOT(login()));
    connect(ui->logRegisterButton, SIGNAL(clicked(bool)), this, SLOT(openRegisterWindow()));
}

void loginWindow::login()
{
    QString username = ui->logUsernameEdit->text();
    QString password = ui->logPasswordEdit->text();

    //Check if inputs are complete
    if((username == "") || (password == "")) {
        ui->errorLabel->setHidden(false);
        ui->errorLabel->setText("Error: Missing Input");
        return;
    }

    myNetwork *n = new myNetwork(this);
    QString filename = QString::fromUtf8("login.php");
    QStringList l;
    l << "username" << username;
    l << "password" << password;

    n->network(filename, l, SLOT(postRecieved(QNetworkReply*)), this);


    //Check if inputs are valid here
}

void loginWindow::openRegisterWindow()
{
    regWindow.show();
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::postRecieved( QNetworkReply* reply){
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(str.startsWith("Fail")){
        QMessageBox messageBox;
        messageBox.setText(str);
        messageBox.exec();
        return;
    }

    QJsonDocument d = QJsonDocument::fromJson(bytes);
    QJsonArray a = d.array();

    privateKey = a.at(0).toString();
    publicKey = a.at(1).toString();

    for(int i=2; i<a.size(); i+=2){
        QString name = a.at(i).toString();
        QString rsa = a.at(i+1).toString();
        friendHash[name] = rsa;
    }

}
