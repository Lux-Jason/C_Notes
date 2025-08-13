/********************************************************************************
** Form generated from reading UI file 'ClientUI.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTUI_H
#define UI_CLIENTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientUIClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QPushButton *userBtn;
    QPushButton *allGroupBtn;
    QPushButton *createGroupBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *refreshBtn;
    QPushButton *exitBtn;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QStackedWidget *chatStkWidget;
    QWidget *page;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *chatEdit;
    QTextEdit *sendEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *publicSendBtn;
    QPushButton *sendBtn;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTextEdit *sysEdit;
    QFrame *line_2;
    QLabel *label_2;
    QTextEdit *publicEdit;
    QFrame *line;
    QLabel *label_3;
    QStackedWidget *memberStkWidget;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QPushButton *memberBtn;
    QWidget *page_4;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QListWidget *memberListWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QListWidget *mutedListWidget;

    void setupUi(QWidget *ClientUIClass)
    {
        if (ClientUIClass->objectName().isEmpty())
            ClientUIClass->setObjectName("ClientUIClass");
        ClientUIClass->resize(932, 597);
        horizontalLayout_2 = new QHBoxLayout(ClientUIClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        groupBox = new QGroupBox(ClientUIClass);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nameLabel);

        userBtn = new QPushButton(groupBox);
        userBtn->setObjectName("userBtn");
        userBtn->setMinimumSize(QSize(50, 50));
        userBtn->setMaximumSize(QSize(50, 50));

        verticalLayout->addWidget(userBtn);

        allGroupBtn = new QPushButton(groupBox);
        allGroupBtn->setObjectName("allGroupBtn");
        allGroupBtn->setMinimumSize(QSize(50, 50));
        allGroupBtn->setMaximumSize(QSize(50, 50));

        verticalLayout->addWidget(allGroupBtn);

        createGroupBtn = new QPushButton(groupBox);
        createGroupBtn->setObjectName("createGroupBtn");
        createGroupBtn->setMinimumSize(QSize(50, 50));
        createGroupBtn->setMaximumSize(QSize(50, 50));

        verticalLayout->addWidget(createGroupBtn);

        verticalSpacer = new QSpacerItem(20, 258, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        refreshBtn = new QPushButton(groupBox);
        refreshBtn->setObjectName("refreshBtn");
        refreshBtn->setMinimumSize(QSize(50, 50));
        refreshBtn->setMaximumSize(QSize(50, 50));

        verticalLayout->addWidget(refreshBtn);

        exitBtn = new QPushButton(groupBox);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setMinimumSize(QSize(50, 50));
        exitBtn->setMaximumSize(QSize(50, 50));

        verticalLayout->addWidget(exitBtn);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ClientUIClass);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName("listWidget");

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);

        chatStkWidget = new QStackedWidget(ClientUIClass);
        chatStkWidget->setObjectName("chatStkWidget");
        page = new QWidget();
        page->setObjectName("page");
        chatStkWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        chatEdit = new QTextEdit(page_2);
        chatEdit->setObjectName("chatEdit");
        chatEdit->setReadOnly(true);

        verticalLayout_2->addWidget(chatEdit);

        sendEdit = new QTextEdit(page_2);
        sendEdit->setObjectName("sendEdit");

        verticalLayout_2->addWidget(sendEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        publicSendBtn = new QPushButton(page_2);
        publicSendBtn->setObjectName("publicSendBtn");

        horizontalLayout->addWidget(publicSendBtn);

        sendBtn = new QPushButton(page_2);
        sendBtn->setObjectName("sendBtn");

        horizontalLayout->addWidget(sendBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);
        chatStkWidget->addWidget(page_2);

        horizontalLayout_2->addWidget(chatStkWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(ClientUIClass);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        sysEdit = new QTextEdit(ClientUIClass);
        sysEdit->setObjectName("sysEdit");
        sysEdit->setReadOnly(true);

        verticalLayout_3->addWidget(sysEdit);

        line_2 = new QFrame(ClientUIClass);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line_2);

        label_2 = new QLabel(ClientUIClass);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        publicEdit = new QTextEdit(ClientUIClass);
        publicEdit->setObjectName("publicEdit");
        publicEdit->setReadOnly(true);

        verticalLayout_3->addWidget(publicEdit);

        line = new QFrame(ClientUIClass);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line);

        label_3 = new QLabel(ClientUIClass);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        memberStkWidget = new QStackedWidget(ClientUIClass);
        memberStkWidget->setObjectName("memberStkWidget");
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        memberBtn = new QPushButton(page_3);
        memberBtn->setObjectName("memberBtn");

        gridLayout_2->addWidget(memberBtn, 0, 0, 1, 1);

        memberStkWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        gridLayout_3 = new QGridLayout(page_4);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(page_4);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        memberListWidget = new QListWidget(tab);
        memberListWidget->setObjectName("memberListWidget");

        gridLayout_4->addWidget(memberListWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName("gridLayout_5");
        mutedListWidget = new QListWidget(tab_2);
        mutedListWidget->setObjectName("mutedListWidget");

        gridLayout_5->addWidget(mutedListWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        memberStkWidget->addWidget(page_4);

        verticalLayout_3->addWidget(memberStkWidget);

        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(4, 1);
        verticalLayout_3->setStretch(7, 2);

        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 1);

        retranslateUi(ClientUIClass);

        chatStkWidget->setCurrentIndex(0);
        memberStkWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientUIClass);
    } // setupUi

    void retranslateUi(QWidget *ClientUIClass)
    {
        ClientUIClass->setWindowTitle(QCoreApplication::translate("ClientUIClass", "ClientUI", nullptr));
        groupBox->setTitle(QString());
        nameLabel->setText(QCoreApplication::translate("ClientUIClass", "TextLabel", nullptr));
        userBtn->setText(QCoreApplication::translate("ClientUIClass", "Online\n"
"user", nullptr));
        allGroupBtn->setText(QCoreApplication::translate("ClientUIClass", "All\n"
"group\n"
"chats", nullptr));
        createGroupBtn->setText(QCoreApplication::translate("ClientUIClass", "Create\n"
"group\n"
"chats", nullptr));
        refreshBtn->setText(QCoreApplication::translate("ClientUIClass", "Refresh\n"
"list", nullptr));
        exitBtn->setText(QCoreApplication::translate("ClientUIClass", "exit", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ClientUIClass", "GroupBox", nullptr));
        publicSendBtn->setText(QCoreApplication::translate("ClientUIClass", "Braodcast send", nullptr));
        sendBtn->setText(QCoreApplication::translate("ClientUIClass", "Send", nullptr));
        label->setText(QCoreApplication::translate("ClientUIClass", "System messages:", nullptr));
        label_2->setText(QCoreApplication::translate("ClientUIClass", "Broadcast message\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("ClientUIClass", "Group members:", nullptr));
        memberBtn->setText(QCoreApplication::translate("ClientUIClass", "View members", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ClientUIClass", "All", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ClientUIClass", "Muted", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientUIClass: public Ui_ClientUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTUI_H
