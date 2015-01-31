#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "registerwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    connect(ui->loginButton, SIGNAL(clicked(bool)), this, SLOT(login()));
    connect(ui->logRegisterButton, SIGNAL(clicked(bool)), this, SLOT(openRegisterWindow()));
}

void loginWindow::login()
{
    delete ui;
}

void loginWindow::openRegisterWindow()
{
    registerWindow regWindow;
    regWindow.show();
}

loginWindow::~loginWindow()
{
    delete ui;
}
