/********************************************************************************
** Form generated from reading UI file 'LoginWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidgetClass
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *portEdit;
    QLineEdit *addrEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *connBtn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *LoginWidgetClass)
    {
        if (LoginWidgetClass->objectName().isEmpty())
            LoginWidgetClass->setObjectName("LoginWidgetClass");
        LoginWidgetClass->resize(420, 200);
        LoginWidgetClass->setMinimumSize(QSize(420, 200));
        LoginWidgetClass->setMaximumSize(QSize(420, 200));
        gridLayout = new QGridLayout(LoginWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(LoginWidgetClass);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(50, -1, 50, -1);
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        portEdit = new QLineEdit(page);
        portEdit->setObjectName("portEdit");

        gridLayout_2->addWidget(portEdit, 1, 1, 1, 1);

        addrEdit = new QLineEdit(page);
        addrEdit->setObjectName("addrEdit");

        gridLayout_2->addWidget(addrEdit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        connBtn = new QPushButton(page);
        connBtn->setObjectName("connBtn");

        horizontalLayout->addWidget(connBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 2);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(50, -1, 50, -1);
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        nameEdit = new QLineEdit(page_2);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout_2->addWidget(nameEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        loginBtn = new QPushButton(page_2);
        loginBtn->setObjectName("loginBtn");

        horizontalLayout_3->addWidget(loginBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 2);
        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(LoginWidgetClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *LoginWidgetClass)
    {
        LoginWidgetClass->setWindowTitle(QCoreApplication::translate("LoginWidgetClass", "LoginWidget", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWidgetClass", "Port:", nullptr));
        label->setText(QCoreApplication::translate("LoginWidgetClass", "Address:", nullptr));
        connBtn->setText(QCoreApplication::translate("LoginWidgetClass", "Connect", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWidgetClass", "User name: ", nullptr));
        loginBtn->setText(QCoreApplication::translate("LoginWidgetClass", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidgetClass: public Ui_LoginWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
