/********************************************************************************
** Form generated from reading UI file 'GroupNameWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPNAMEWIDGET_H
#define UI_GROUPNAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupNameWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *GroupNameWidgetClass)
    {
        if (GroupNameWidgetClass->objectName().isEmpty())
            GroupNameWidgetClass->setObjectName("GroupNameWidgetClass");
        GroupNameWidgetClass->resize(486, 127);
        verticalLayout = new QVBoxLayout(GroupNameWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(50, -1, 50, -1);
        label = new QLabel(GroupNameWidgetClass);
        label->setObjectName("label");
        label->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(GroupNameWidgetClass);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okBtn = new QPushButton(GroupNameWidgetClass);
        okBtn->setObjectName("okBtn");

        horizontalLayout_2->addWidget(okBtn);

        cancelBtn = new QPushButton(GroupNameWidgetClass);
        cancelBtn->setObjectName("cancelBtn");

        horizontalLayout_2->addWidget(cancelBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(GroupNameWidgetClass);

        QMetaObject::connectSlotsByName(GroupNameWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *GroupNameWidgetClass)
    {
        GroupNameWidgetClass->setWindowTitle(QCoreApplication::translate("GroupNameWidgetClass", "GroupNameWidget", nullptr));
        label->setText(QCoreApplication::translate("GroupNameWidgetClass", "please enter the group name: ", nullptr));
        okBtn->setText(QCoreApplication::translate("GroupNameWidgetClass", "Confirm", nullptr));
        cancelBtn->setText(QCoreApplication::translate("GroupNameWidgetClass", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupNameWidgetClass: public Ui_GroupNameWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPNAMEWIDGET_H
