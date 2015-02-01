#include <QApplication>
#include <QMessageBox>
#include <QPixmap>

#include "registerwindow.h"
#include "ui_registerwindow.h"

registerWindow::registerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);

    QPixmap icon = QPixmap(100, 100);
    icon.load(":/img/smokeicon.png");
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
    if(strcmp(password.toLocal8Bit(), confirm.toLocal8Bit())){
        ui->errorLabel->setHidden(false);
        ui->errorLabel->setText("*Error: Passwords don't match");
        return;
    }
}

registerWindow::~registerWindow()
{
    delete ui;
}
