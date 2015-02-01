#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>

#include "ui_chatwindow.h"

class chatWindow : public QMainWindow, Ui::chatWindow
{
    Q_OBJECT

public:
    explicit chatWindow(QWidget *parent = 0);
    ~chatWindow();

private:
    Ui::chatWindow *ui;
    void updateDisplay();
    QStringList *msgArray = new QStringList;

private slots:
    void sendChat();
};

#endif // CHATWINDOW_H
