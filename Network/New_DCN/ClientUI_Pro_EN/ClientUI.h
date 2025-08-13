#pragma once

#include <QtWidgets/QWidget>
#include <QMenu>
#include <QAction>
#include "GroupNameWidget.h"
#include "ui_ClientUI.h"

class ClientUI : public QWidget
{
    Q_OBJECT

public:
    ClientUI(QWidget *parent = nullptr);
    ~ClientUI();

    void updateUsersList(const QStringList &);
    void updateGroupsList(const QStringList &);
    void updateGroupsMemberList(const QStringList &);
    void updateGroupsMutedList(const QStringList&);

public slots:
	void onCustomContextMenuRequested_group(const QPoint & pos);
    void onCustomContextMenuRequested_member(const QPoint& pos);
    void onCustomContextMenuRequested_muted(const QPoint& pos);

    void onDisbandAct();
    void onJoinAct();
    void onLeaveAct();
    void onKickAct();
    void onMuteAct();
    void onUnmuteAct();

    void onLoginSuccess(const QString &);

    void onRecvSys(const std::string&);
    void onRecvUsers(const std::string &);
    void onRecvPrivateMsg(const std::string& name, const std::string& msg);
    void onRecvGroups(const std::string &);
    void onRecvGroupMsg(const std::string& group, const std::string& name, const std::string& msg);
    void onRecvPublicMsg(const std::string& name, const std::string& msg);
    void onRecvDisbandRes(const std::string&);
    void onRecvJoinRes(const std::string&);
    void onRecvLeaveRes(const std::string&);
    void onRecvCreateRes(const bool&, const std::string&);
    void onRecvMembers(const std::string&);
    void onRecvMuted(const std::string&);
    void onRecvKickRes(const std::string&);
    void onRecvKicked(const std::string&);
    void onRecvMuteRes(const std::string&);
    void onRecvUnmuteRes(const std::string&);
    void onRecvNewMember(const std::string&);
    void onRecvReduceMember(const std::string&);
    void onRecvGroupDisbanded(const std::string &);
    void onMutedInfo(const std::string &);
    void onRecvDeleteUserRes(const std::string &);
    void onRecvAssignRes(const std::string &);

    void on_userBtn_clicked();
    void on_allGroupBtn_clicked();
	void on_createGroupBtn_clicked();
	void on_refreshBtn_clicked();

    void getNewGroupName(const QString &);

    void on_sendBtn_clicked();
    void on_publicSendBtn_clicked();
    void changeChatWidget(QListWidgetItem* item);

    void on_memberBtn_clicked();

private:
    void saveToTempFile(const bool &isMy, const QString &fileName, const QString &name, const QString &msg);
    QStringList loadTempFile(const QString& fileName);

private:
    Ui::ClientUIClass ui;

    QString currentChatName;
    bool isUserList;

    GroupNameWidget* m_groupNameWidget;

    QMenu *groupMenu;           //群组列表中的菜单
    QAction* disbandAct;
    QAction* joinAct;
    QAction* leaveAct;

    QListWidgetItem* groupMenuItem;
    QListWidgetItem* memberMenuItem;
    QListWidgetItem* mutedMenuItem;

    QMenu* memberMenu;          //群成员列表中的菜单
    QAction* kickAct;
    QAction* muteAct;

    QMenu* mutedMenu;          //禁言列表中的菜单
    QAction* unmuteAct;
};
