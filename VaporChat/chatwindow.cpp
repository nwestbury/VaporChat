#include "chatwindow.h"
#include "ui_chatwindow.h"

chatWindow::chatWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatWindow)
{
    ui->setupUi(this);

    connect(ui->sendButton, SIGNAL(clicked(bool)), this, SLOT(sendChat()));
    connect(ui->textInput, SIGNAL(returnPressed()), ui->sendButton, SIGNAL(clicked()));
}

extern QStringList *msgArray;

void chatWindow::sendChat()
{
    QString messageText = ui->textInput->text();
    *msgArray << messageText;

    QStringList list = *msgArray;
    QStringList::iterator it = list.begin();
    ui->textEdit->setText("");
    while (it != list.end()) {
        ui->textEdit->append(*it);
        ++it;
    }

    ui->textInput->setText("");
}

void chatWindow::updateDisplay()
{

}

chatWindow::~chatWindow()
{
    delete ui;
}
