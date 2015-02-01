#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>

#include "ui_chatwindow.h"

class chatWindow : public QMainWindow, Ui::chatWindow
{
    Q_OBJECT

    QString sessionkey;

public:
    explicit chatWindow(QString title, QWidget *parent = 0);
    ~chatWindow();

    QStringList *msgArray = new QStringList;
    Ui::chatWindow *ui;
    int lastMsg;
    int session;

private slots:
    void sendChat();
    void update();
    void postRecieved(QNetworkReply*);
};

#endif // CHATWINDOW_H
