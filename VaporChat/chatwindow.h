#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>

#include "ui_chatwindow.h"

class chatWindow : public QMainWindow, Ui::chatWindow
{
    Q_OBJECT

    QString sessionkey;
    QStringList *msgArray = new QStringList;

public:
    explicit chatWindow(QString title, QWidget *parent = 0);
    ~chatWindow();

private:
    Ui::chatWindow *ui;

private slots:
    void sendChat();
};

#endif // CHATWINDOW_H
