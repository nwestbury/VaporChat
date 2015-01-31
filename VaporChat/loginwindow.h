#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class loginWindow;
}

class loginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

private:
    Ui::loginWindow *ui;

private slots:
    void login();
    void openRegisterWindow();
};

#endif // LOGINWINDOW_H
