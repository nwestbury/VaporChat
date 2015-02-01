#include <QApplication>
#include <QMessageBox>
#include <QPixmap>

#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "networking.h"

registerWindow::registerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);

    QPixmap icon = QPixmap(123, 109);
    icon.load(":/img/VaporIcon.png");
    ui->iconLabel->setPixmap(icon);

    ui->registerButton->setStyleSheet("background-color: rgb(200, 10, 10, 70%);");

    ui->errorLabel->setHidden(true);
    ui->errorLabel->setStyleSheet("color: red");
    connect(ui->registerButton, SIGNAL(clicked(bool)), this, SLOT(execRegister()));
}

void registerWindow::execRegister()
{
    QString username = ui->regUsernameEdit->text();
    QString password = ui->regPasswordLineEdit->text();
    QString confirm = ui->regConfirmPasswordEdit->text();

    //Check if all inputs are present
    if((username == "") || (password == "") || (confirm == "")) {
        ui->errorLabel->setHidden(false);
        ui->errorLabel->setText("Error: Missing Input");
        return;
    }

    //Check if passwords match
    if(password == confirm){
        ui->errorLabel->setHidden(false);
        ui->errorLabel->setText("*Error: Passwords don't match");
        return;
    }

    myNetwork *n = new myNetwork(this);
    QString filename = QString::fromUtf8("createUser.php");
    QStringList l;
    l << "username" << username;
    l << "password" << password;

    n->network(filename, l, SLOT(postRecieved(QNetworkReply*)), this);
}

registerWindow::~registerWindow()
{
    delete ui;
}

void registerWindow::postRecieved( QNetworkReply* reply){
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(str.startsWith("Fail")){
        QMessageBox messageBox;
        messageBox.setText(str);
        messageBox.exec();
    }
}
