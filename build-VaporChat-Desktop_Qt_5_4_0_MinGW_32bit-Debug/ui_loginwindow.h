/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *iconLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *logUsernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *logPasswordEdit;
    QPushButton *loginButton;
    QPushButton *logRegisterButton;

    void setupUi(QWidget *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QStringLiteral("loginWindow"));
        loginWindow->resize(268, 350);
        loginWindow->setMinimumSize(QSize(262, 350));
        loginWindow->setMaximumSize(QSize(268, 350));
        verticalLayout = new QVBoxLayout(loginWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        iconLabel = new QLabel(loginWindow);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iconLabel->sizePolicy().hasHeightForWidth());
        iconLabel->setSizePolicy(sizePolicy);
        iconLabel->setMinimumSize(QSize(250, 180));
        iconLabel->setMaximumSize(QSize(250, 180));

        verticalLayout->addWidget(iconLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(loginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(50, 20));

        horizontalLayout->addWidget(label_2);

        logUsernameEdit = new QLineEdit(loginWindow);
        logUsernameEdit->setObjectName(QStringLiteral("logUsernameEdit"));
        logUsernameEdit->setMinimumSize(QSize(200, 20));
        logUsernameEdit->setMaximumSize(QSize(200, 20));

        horizontalLayout->addWidget(logUsernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(loginWindow);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(55, 20));
        label->setMaximumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(label);

        logPasswordEdit = new QLineEdit(loginWindow);
        logPasswordEdit->setObjectName(QStringLiteral("logPasswordEdit"));
        sizePolicy.setHeightForWidth(logPasswordEdit->sizePolicy().hasHeightForWidth());
        logPasswordEdit->setSizePolicy(sizePolicy);
        logPasswordEdit->setMinimumSize(QSize(200, 20));
        logPasswordEdit->setMaximumSize(QSize(200, 20));
        logPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(logPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        loginButton = new QPushButton(loginWindow);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        verticalLayout->addWidget(loginButton);

        logRegisterButton = new QPushButton(loginWindow);
        logRegisterButton->setObjectName(QStringLiteral("logRegisterButton"));

        verticalLayout->addWidget(logRegisterButton);


        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QWidget *loginWindow)
    {
        loginWindow->setWindowTitle(QApplication::translate("loginWindow", "Form", 0));
        iconLabel->setText(QString());
        label_2->setText(QApplication::translate("loginWindow", "Username:", 0));
        label->setText(QApplication::translate("loginWindow", "Password:", 0));
        loginButton->setText(QApplication::translate("loginWindow", "Login", 0));
        logRegisterButton->setText(QApplication::translate("loginWindow", "Register", 0));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
