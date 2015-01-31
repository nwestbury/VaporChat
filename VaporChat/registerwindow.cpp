#include "registerwindow.h"
#include "ui_registerwindow.h"

registerWindow::registerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerWindow)
{
    setupUi(this);
    connect(registerButton, SIGNAL(clicked(bool)), this, SLOT(execRegister());
}

registerWindow::execRegister()
{
    ~registerWindow();
}

registerWindow::~registerWindow()
{
    delete ui;
}
