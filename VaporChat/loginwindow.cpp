#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWindow)
{
    setupUi(this);
    connect(loginButton, SIGNAL(clicked(bool)), this, SLOT(login());
    connect(logRegisterButton, SIGNAL(clicked(bool)), this, SLOT(openRegisterWindow());
}

loginWindow::login()
{
    ~loginWindow();
}

loginWindow::~loginWindow()
{
    delete ui;
}
