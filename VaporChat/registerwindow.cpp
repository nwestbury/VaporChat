#include <QApplication>
#include "registerwindow.h"
#include "ui_registerwindow.h"

registerWindow::registerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);
    connect(ui->registerButton, SIGNAL(clicked(bool)), this, SLOT(execRegister()));
}

void registerWindow::execRegister()
{
    delete ui;
}

registerWindow::~registerWindow()
{
    delete ui;
}
