/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_registerWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *iconLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *regUsernameLabel;
    QLineEdit *regUsernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *regPasswordLabel;
    QLineEdit *regPasswordLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *regConfirmLabel;
    QLabel *regConPasswordLabel;
    QLineEdit *regConfirmPasswordEdit;
    QPushButton *registerButton;

    void setupUi(QWidget *registerWindow)
    {
        if (registerWindow->objectName().isEmpty())
            registerWindow->setObjectName(QStringLiteral("registerWindow"));
        registerWindow->resize(275, 365);
        verticalLayout = new QVBoxLayout(registerWindow);
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        iconLabel = new QLabel(registerWindow);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));

        verticalLayout->addWidget(iconLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        regUsernameLabel = new QLabel(registerWindow);
        regUsernameLabel->setObjectName(QStringLiteral("regUsernameLabel"));
        regUsernameLabel->setMinimumSize(QSize(0, 20));
        regUsernameLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(regUsernameLabel);

        regUsernameEdit = new QLineEdit(registerWindow);
        regUsernameEdit->setObjectName(QStringLiteral("regUsernameEdit"));
        regUsernameEdit->setMinimumSize(QSize(200, 20));
        regUsernameEdit->setMaximumSize(QSize(200, 20));

        horizontalLayout->addWidget(regUsernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        regPasswordLabel = new QLabel(registerWindow);
        regPasswordLabel->setObjectName(QStringLiteral("regPasswordLabel"));
        regPasswordLabel->setMinimumSize(QSize(0, 20));
        regPasswordLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(regPasswordLabel);

        regPasswordLineEdit = new QLineEdit(registerWindow);
        regPasswordLineEdit->setObjectName(QStringLiteral("regPasswordLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(regPasswordLineEdit->sizePolicy().hasHeightForWidth());
        regPasswordLineEdit->setSizePolicy(sizePolicy);
        regPasswordLineEdit->setMinimumSize(QSize(200, 20));
        regPasswordLineEdit->setMaximumSize(QSize(200, 20));
        regPasswordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(regPasswordLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        regConfirmLabel = new QLabel(registerWindow);
        regConfirmLabel->setObjectName(QStringLiteral("regConfirmLabel"));

        verticalLayout_2->addWidget(regConfirmLabel);

        regConPasswordLabel = new QLabel(registerWindow);
        regConPasswordLabel->setObjectName(QStringLiteral("regConPasswordLabel"));

        verticalLayout_2->addWidget(regConPasswordLabel);


        horizontalLayout_3->addLayout(verticalLayout_2);

        regConfirmPasswordEdit = new QLineEdit(registerWindow);
        regConfirmPasswordEdit->setObjectName(QStringLiteral("regConfirmPasswordEdit"));
        sizePolicy.setHeightForWidth(regConfirmPasswordEdit->sizePolicy().hasHeightForWidth());
        regConfirmPasswordEdit->setSizePolicy(sizePolicy);
        regConfirmPasswordEdit->setMinimumSize(QSize(200, 20));
        regConfirmPasswordEdit->setMaximumSize(QSize(200, 20));
        regConfirmPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(regConfirmPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        registerButton = new QPushButton(registerWindow);
        registerButton->setObjectName(QStringLiteral("registerButton"));

        verticalLayout->addWidget(registerButton);


        retranslateUi(registerWindow);

        QMetaObject::connectSlotsByName(registerWindow);
    } // setupUi

    void retranslateUi(QWidget *registerWindow)
    {
        registerWindow->setWindowTitle(QApplication::translate("registerWindow", "Form", 0));
        iconLabel->setText(QString());
        regUsernameLabel->setText(QApplication::translate("registerWindow", "Username:", 0));
        regPasswordLabel->setText(QApplication::translate("registerWindow", "Password:", 0));
        regConfirmLabel->setText(QApplication::translate("registerWindow", "Confirm", 0));
        regConPasswordLabel->setText(QApplication::translate("registerWindow", "Password:", 0));
        regConfirmPasswordEdit->setText(QString());
        registerButton->setText(QApplication::translate("registerWindow", "Register", 0));
    } // retranslateUi

};

namespace Ui {
    class registerWindow: public Ui_registerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
