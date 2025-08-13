/********************************************************************************
** Form generated from reading UI file 'UserItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERITEMWIDGET_H
#define UI_USERITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserItemWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *newInfoLabel;

    void setupUi(QWidget *UserItemWidgetClass)
    {
        if (UserItemWidgetClass->objectName().isEmpty())
            UserItemWidgetClass->setObjectName("UserItemWidgetClass");
        UserItemWidgetClass->resize(507, 60);
        UserItemWidgetClass->setMinimumSize(QSize(0, 60));
        UserItemWidgetClass->setMaximumSize(QSize(16777215, 60));
        verticalLayout = new QVBoxLayout(UserItemWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        nameLabel = new QLabel(UserItemWidgetClass);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout->addWidget(nameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        newInfoLabel = new QLabel(UserItemWidgetClass);
        newInfoLabel->setObjectName("newInfoLabel");

        horizontalLayout_2->addWidget(newInfoLabel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(UserItemWidgetClass);

        QMetaObject::connectSlotsByName(UserItemWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *UserItemWidgetClass)
    {
        UserItemWidgetClass->setWindowTitle(QCoreApplication::translate("UserItemWidgetClass", "UserItemWidget", nullptr));
        nameLabel->setText(QCoreApplication::translate("UserItemWidgetClass", "TextLabel", nullptr));
        newInfoLabel->setText(QCoreApplication::translate("UserItemWidgetClass", "New message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserItemWidgetClass: public Ui_UserItemWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERITEMWIDGET_H
