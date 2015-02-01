#include <QPixmap>
#include <QRect>
#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "registerwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    QPixmap icon = QPixmap(100, 100);
    icon.load(":/img/smokeicon.png");
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

    //Check if inputs are valid here

    //Forward to chat window

    //this->hide();
    cWindow.show();
}

void loginWindow::openRegisterWindow()
{
    regWindow.show();
}

loginWindow::~loginWindow()
{
    delete ui;
}
