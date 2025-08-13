#include "ClientUI.h"
#include "Client.h"
#include "LoginWidget.h"
#include "UserItemWidget.h"
#include <QMessageBox>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>
#include <QDebug>

ClientUI::ClientUI(QWidget *parent)
    : QWidget(parent),
	  groupMenuItem(nullptr),
	  memberMenuItem(nullptr),
	  mutedMenuItem(nullptr)
{
    ui.setupUi(this);

	m_groupNameWidget = new GroupNameWidget;
	connect(m_groupNameWidget, &GroupNameWidget::sendGroupName, this, &ClientUI::getNewGroupName);

	ui.listWidget->setProperty("contextMenuPolicy", Qt::CustomContextMenu);
	ui.memberListWidget->setProperty("contextMenuPolicy", Qt::CustomContextMenu);
	ui.memberListWidget->setProperty("contextMenuPolicy", Qt::CustomContextMenu);
	ui.mutedListWidget->setProperty("contextMenuPolicy", Qt::CustomContextMenu);

    connect(LoginWidget::getInstance(), &LoginWidget::loginSuccess, this, &ClientUI::onLoginSuccess);

	connect(Client::getInstance(), &Client::recv_sys, this, &ClientUI::onRecvSys);
    connect(Client::getInstance(), &Client::recv_users, this, &ClientUI::onRecvUsers);
    connect(Client::getInstance(), &Client::recv_private_msg, this, &ClientUI::onRecvPrivateMsg);
    connect(Client::getInstance(), &Client::recv_groups, this, &ClientUI::onRecvGroups);
    connect(Client::getInstance(), &Client::recv_group_msg, this, &ClientUI::onRecvGroupMsg);
	connect(Client::getInstance(), &Client::recv_public_msg, this, &ClientUI::onRecvPublicMsg);
	connect(Client::getInstance(), &Client::recv_disband_res, this, &ClientUI::onRecvDisbandRes);
	connect(Client::getInstance(), &Client::recv_join_res, this, &ClientUI::onRecvJoinRes);
	connect(Client::getInstance(), &Client::recv_leave_res, this, &ClientUI::onRecvLeaveRes);
	connect(Client::getInstance(), &Client::recv_create_res, this, &ClientUI::onRecvCreateRes);
	connect(Client::getInstance(), &Client::recv_members, this, &ClientUI::onRecvMembers);
	connect(Client::getInstance(), &Client::recv_muted, this, &ClientUI::onRecvMuted);
	connect(Client::getInstance(), &Client::recv_kick_res, this, &ClientUI::onRecvKickRes);
	connect(Client::getInstance(), &Client::recv_kicked, this, &ClientUI::onRecvKicked);
	connect(Client::getInstance(), &Client::recv_mute_res, this, &ClientUI::onRecvMuteRes);
	connect(Client::getInstance(), &Client::recv_unmute_res, this, &ClientUI::onRecvUnmuteRes);
	connect(Client::getInstance(), &Client::recv_new_member, this, &ClientUI::onRecvNewMember);

    connect(ui.listWidget, &QListWidget::itemClicked, this, &ClientUI::changeChatWidget);
	connect(ui.listWidget, &QListWidget::customContextMenuRequested, this, &ClientUI::onCustomContextMenuRequested_group);
	connect(ui.memberListWidget, &QListWidget::customContextMenuRequested, this, &ClientUI::onCustomContextMenuRequested_member);
	connect(ui.mutedListWidget, &QListWidget::customContextMenuRequested, this, &ClientUI::onCustomContextMenuRequested_muted);

	groupMenu = new QMenu(ui.listWidget);

	disbandAct = new QAction(QString::fromLocal8Bit("解散"), groupMenu);
	joinAct = new QAction(QString::fromLocal8Bit("加入"), groupMenu);
	leaveAct = new QAction(QString::fromLocal8Bit("离开"), groupMenu);
	groupMenu->addAction(disbandAct);
	groupMenu->addAction(joinAct);
	groupMenu->addAction(leaveAct);
	connect(disbandAct, &QAction::triggered, this, &ClientUI::onDisbandAct);
	connect(joinAct, &QAction::triggered, this, &ClientUI::onJoinAct);
	connect(leaveAct, &QAction::triggered, this, &ClientUI::onLeaveAct);

	memberMenu = new QMenu(ui.memberListWidget);
	kickAct = new QAction(QString::fromLocal8Bit("踢出"), memberMenu);
	muteAct = new QAction(QString::fromLocal8Bit("禁言"), memberMenu);
	memberMenu->addAction(kickAct);
	memberMenu->addAction(muteAct);
	connect(kickAct, &QAction::triggered, this, &ClientUI::onKickAct);
	connect(muteAct, &QAction::triggered, this, &ClientUI::onMuteAct);

	mutedMenu = new QMenu(ui.mutedListWidget);
	QAction* unmuteAct = new QAction(QString::fromLocal8Bit("解禁"), mutedMenu);
	mutedMenu->addAction(unmuteAct);
	connect(unmuteAct, &QAction::triggered, this, &ClientUI::onUnmuteAct);

    QDir dir("./chatRec/");
    if (!dir.exists())
    {
        dir.mkdir(QDir::currentPath() + "/" + "chatRec");
    }
}

ClientUI::~ClientUI()
{
	if (m_groupNameWidget != nullptr)
	{
		m_groupNameWidget->deleteLater();
	}

	QDir folder(QDir::currentPath() + "/" + "chatRec");
	if (folder.exists())
	{
		QStringList files = folder.entryList(QDir::Files);
		for (const QString& file : files)
		{
			QString filePath = folder.filePath(file);
			QFile::remove(filePath);
		}
	}

    Client::getInstance()->stop();
}

void ClientUI::updateUsersList(const QStringList &userList)
{
    ui.listWidget->clear();

    for (int i = 0; i < userList.size(); ++i)
    {
		QListWidgetItem* pItem = new QListWidgetItem("");
        pItem->setSizeHint(QSize(100, 60));
		ui.listWidget->addItem(pItem);
		UserItemWidget* tmpItem = new UserItemWidget;
        tmpItem->setName(userList.at(i));
        tmpItem->setNewInfoVisible(false);
		ui.listWidget->setItemWidget(pItem, tmpItem);
    }
}

void ClientUI::updateGroupsList(const QStringList& groupList)
{
	ui.listWidget->clear();

	for (int i = 0; i < groupList.size(); ++i)
	{
		QListWidgetItem* pItem = new QListWidgetItem("");
		pItem->setSizeHint(QSize(100, 60));
		ui.listWidget->addItem(pItem);
		UserItemWidget* tmpItem = new UserItemWidget;
		tmpItem->setName(groupList.at(i));
		tmpItem->setNewInfoVisible(false);
		tmpItem->setProperty("group", groupList.at(i).left(groupList.at(i).indexOf(QString::fromLocal8Bit(" ("))));
		ui.listWidget->setItemWidget(pItem, tmpItem);
	}
}

void ClientUI::updateGroupsMemberList(const QStringList &memList)
{
	ui.memberListWidget->clear();

	for (int i = 0; i < memList.size(); ++i)
	{
		QListWidgetItem* pItem = new QListWidgetItem("");
		pItem->setSizeHint(QSize(100, 60));
		ui.memberListWidget->addItem(pItem);
		UserItemWidget* tmpItem = new UserItemWidget;
		tmpItem->setName(memList.at(i));
		tmpItem->setNewInfoVisible(false);
		ui.memberListWidget->setItemWidget(pItem, tmpItem);
	}
}

void ClientUI::updateGroupsMutedList(const QStringList &mutedList)
{
	ui.mutedListWidget->clear();

	for (int i = 0; i < mutedList.size(); ++i)
	{
		QListWidgetItem* pItem = new QListWidgetItem("");
		pItem->setSizeHint(QSize(100, 60));
		ui.mutedListWidget->addItem(pItem);
		UserItemWidget* tmpItem = new UserItemWidget;
		tmpItem->setName(mutedList.at(i));
		tmpItem->setNewInfoVisible(false);
		ui.mutedListWidget->setItemWidget(pItem, tmpItem);
	}
}

void ClientUI::onCustomContextMenuRequested_group(const QPoint& pos)
{
	if (isUserList)
	{
		return;
	}

	QModelIndex tmIdx = ui.listWidget->indexAt(pos);
	groupMenuItem = ui.listWidget->item(tmIdx.row());
	if (groupMenuItem)
	{
		UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.listWidget->itemWidget(groupMenuItem));
		QString name = widget->getName();
		name = name.left(name.indexOf(QString::fromLocal8Bit(" (")));
		bool isJoined = Client::getInstance()->isJoinedGroup(std::string(name.toLocal8Bit()));
		bool isOwned = Client::getInstance()->isOwnedGroup(std::string(name.toLocal8Bit()));
		if (isOwned)
		{
			disbandAct->setVisible(true);
			joinAct->setVisible(false);
			leaveAct->setVisible(true);
		}
		else
		{
			disbandAct->setVisible(false);

			if (isJoined)
			{
				joinAct->setVisible(false);
				leaveAct->setVisible(true);
			}
			else
			{
				joinAct->setVisible(true);
				leaveAct->setVisible(false);
			}
		}

		groupMenu->exec(QCursor::pos());
	}
}

void ClientUI::onCustomContextMenuRequested_member(const QPoint& pos)
{
	bool isOwned = Client::getInstance()->isOwnedGroup(std::string(currentChatName.toLocal8Bit()));
	if (!isOwned)
	{
		return;
	}

	QModelIndex tmIdx = ui.memberListWidget->indexAt(pos);
	memberMenuItem = ui.memberListWidget->item(tmIdx.row());
	UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.memberListWidget->itemWidget(memberMenuItem));
	QString name = widget->getName();
	if (name == ui.nameLabel->text())
	{
		return;
	}

	if (memberMenuItem)
	{
		memberMenu->exec(QCursor::pos());
	}
}

void ClientUI::onCustomContextMenuRequested_muted(const QPoint& pos)
{
	bool isOwned = Client::getInstance()->isOwnedGroup(std::string(currentChatName.toLocal8Bit()));
	if (!isOwned)
	{
		return;
	}

	QModelIndex tmIdx = ui.mutedListWidget->indexAt(pos);
	mutedMenuItem = ui.mutedListWidget->item(tmIdx.row());
	UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.mutedListWidget->itemWidget(mutedMenuItem));
	QString name = widget->getName();
	if (name.contains(QString::fromLocal8Bit("无禁言成员")))
	{
		return;
	}

	if (mutedMenuItem)
	{
		mutedMenu->exec(QCursor::pos());
	}
}

void ClientUI::onDisbandAct()
{
	if (groupMenuItem)
	{
		UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.listWidget->itemWidget(groupMenuItem));
		QString name = widget->getName();
		name = name.left(name.indexOf(QString::fromLocal8Bit(" (")));
		Client::getInstance()->disbandGroup(std::string(name.toLocal8Bit()));

		on_allGroupBtn_clicked();
	}
}

void ClientUI::onJoinAct()
{
	if (groupMenuItem)
	{
		UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.listWidget->itemWidget(groupMenuItem));
		QString name = widget->getName();
		name = name.left(name.indexOf(QString::fromLocal8Bit(" (")));
		Client::getInstance()->joinGroup(std::string(name.toLocal8Bit()));
	}
}

void ClientUI::onLeaveAct()
{
	if (groupMenuItem)
	{
		UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.listWidget->itemWidget(groupMenuItem));
		QString name = widget->getName();
		name = name.left(name.indexOf(QString::fromLocal8Bit(" (")));
		Client::getInstance()->leaveGroup(std::string(name.toLocal8Bit()));
	}
}

void ClientUI::onKickAct()
{
	UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.memberListWidget->itemWidget(memberMenuItem));
	QString name = widget->getName();

	Client::getInstance()->kick(std::string(currentChatName.toLocal8Bit()), std::string(name.toLocal8Bit()));
}

void ClientUI::onMuteAct()
{
	UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.memberListWidget->itemWidget(memberMenuItem));
	QString name = widget->getName();

	Client::getInstance()->mute(std::string(currentChatName.toLocal8Bit()), std::string(name.toLocal8Bit()));
}

void ClientUI::onUnmuteAct()
{
	UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.mutedListWidget->itemWidget(mutedMenuItem));
	QString name = widget->getName();

	Client::getInstance()->unmute(std::string(currentChatName.toLocal8Bit()), std::string(name.toLocal8Bit()));
}

void ClientUI::onLoginSuccess(const QString &name)
{
    ui.nameLabel->setText(name);
    Client::getInstance()->listUser();
    ui.groupBox_2->setTitle(QString::fromLocal8Bit("在线用户"));
    this->show();
    isUserList = true;

	ui.memberStkWidget->hide();
	ui.label_3->hide();
	ui.line->hide();
}

void ClientUI::onRecvSys(const std::string &content)
{
	QString qContent = QString::fromLocal8Bit(content.data());
	ui.sysEdit->append(qContent);
	ui.sysEdit->append("\n");
}

void ClientUI::onRecvUsers(const std::string &users)
{
    QString qUsers = QString::fromLocal8Bit(users.data());
    QStringList usrList = qUsers.split("\n");
    updateUsersList(usrList);
}

void ClientUI::onRecvPrivateMsg(const std::string& name, const std::string& msg)
{
    QString qName = QString::fromLocal8Bit(name.data());
    QString qMsg = QString::fromLocal8Bit(msg.data());
    saveToTempFile(false, qName, qName, qMsg);

    if (isUserList)
    {
		if (currentChatName == QString::fromStdString(name))
		{
			QString htmlStr = QString("<div style=\"margin:5px; padding:8px;color:#6e8acf; display:inline-block;\">%1</div>")
				.arg(qName + QString::fromLocal8Bit("：") + qMsg);

			ui.chatEdit->moveCursor(QTextCursor::End);
			ui.chatEdit->insertHtml(htmlStr);
			ui.chatEdit->append("\n");

			return;
		}

		int cot = ui.listWidget->count();
		bool flag = false;
		for (int i = 0; i < cot; ++i)
		{
			QListWidgetItem* tmpItem = ui.listWidget->item(i);
			UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.listWidget->itemWidget(tmpItem));
			if (widget->getName() == qName)
			{
				flag = true;
				widget->setNewInfoVisible(true);
			}
		}

		if (!flag)    //没刷新，新增
		{
			QListWidgetItem* pItem = new QListWidgetItem("");
			pItem->setSizeHint(QSize(100, 60));
			ui.listWidget->addItem(pItem);
			UserItemWidget* tmpItem = new UserItemWidget;
			tmpItem->setName(qName);
			tmpItem->setNewInfoVisible(true);
			ui.listWidget->setItemWidget(pItem, tmpItem);
		}
    }
}

void ClientUI::onRecvGroups(const std::string &groups)
{
	QString qGroups = QString::fromLocal8Bit(groups.data());
	QStringList usrList = qGroups.split("\n");
	updateGroupsList(usrList);
}

void ClientUI::onRecvGroupMsg(const std::string& group, const std::string& name, const std::string& msg)
{
    QString qGroup = QString::fromLocal8Bit(group.data());
	QString qName = QString::fromLocal8Bit(name.data());
	QString qMsg = QString::fromLocal8Bit(msg.data());
	saveToTempFile(false, qGroup, qName, qMsg);

	if (!isUserList)
	{
		if (currentChatName == qGroup)
		{
			QString htmlStr = QString("<div style=\"margin:5px; padding:8px;color:#6e8acf; display:inline-block;\">%1</div>")
				.arg(qName + QString::fromLocal8Bit("：") + qMsg);

			ui.chatEdit->moveCursor(QTextCursor::End);
			ui.chatEdit->insertHtml(htmlStr);
			ui.chatEdit->append("\n");

			return;
		}

		int cot = ui.listWidget->count();
		for (int i = 0; i < cot; ++i)
		{
			QListWidgetItem* tmpItem = ui.listWidget->item(i);
			UserItemWidget* widget = dynamic_cast<UserItemWidget*>(ui.listWidget->itemWidget(tmpItem));
			if (widget->property("group").toString() == qGroup)
			{
				widget->setNewInfoVisible(true);
			}
		}
	}
}

void ClientUI::onRecvPublicMsg(const std::string& name, const std::string& msg)
{
	QString qName = QString::fromLocal8Bit(name.data());
	QString qMsg = QString::fromLocal8Bit(msg.data());

	QString htmlStr = QString("<div style=\"margin:5px; padding:8px;color:#6e8acf; display:inline-block;\">%1</div>")
		.arg(qName + QString::fromLocal8Bit("：") + qMsg);

	ui.publicEdit->moveCursor(QTextCursor::End);
	ui.publicEdit->insertHtml(htmlStr);
	ui.publicEdit->append("\n");
}

void ClientUI::onRecvDisbandRes(const std::string &res)
{
	ui.sysEdit->append(QString::fromLocal8Bit(res.data()));
	ui.sysEdit->append("\n");
	on_allGroupBtn_clicked();
}

void ClientUI::onRecvJoinRes(const std::string &res)
{
	ui.sysEdit->append(QString::fromLocal8Bit("已成功加入群组 ") + QString::fromLocal8Bit(res.data()));
	ui.sysEdit->append("\n");
}

void ClientUI::onRecvLeaveRes(const std::string &res)
{
	ui.sysEdit->append(QString::fromLocal8Bit("已成功离开群组 ") + QString::fromLocal8Bit(res.data()));
	ui.sysEdit->append("\n");
	on_allGroupBtn_clicked();
}

void ClientUI::onRecvCreateRes(const bool &state, const std::string &res)
{
	QString qRes = QString::fromLocal8Bit(res.data());
	if (state)
	{
		on_allGroupBtn_clicked();
		ui.sysEdit->append(QString::fromLocal8Bit("创建群组成功 ") + qRes);
		ui.sysEdit->append("\n");
	}
	else
	{
		ui.sysEdit->append(QString::fromLocal8Bit("群组名已存在，请选择其他名称"));
		ui.sysEdit->append("\n");
	}
}

void ClientUI::onRecvMembers(const std::string &content)
{
	QString qContent = QString::fromLocal8Bit(content.data());
	qContent = qContent.remove(QString::fromLocal8Bit("群组成员：")).simplified();
	QStringList memList = qContent.split(" ");

	updateGroupsMemberList(memList);
}

void ClientUI::onRecvMuted(const std::string &content)
{
	QString qContent = QString::fromLocal8Bit(content.data()).simplified();
	QStringList mutedList = qContent.split(" ");

	updateGroupsMutedList(mutedList);
}

void ClientUI::onRecvKickRes(const std::string &res)
{
	QString qContent = QString::fromLocal8Bit(res.data());
	ui.sysEdit->append(qContent);
	ui.sysEdit->append("\n");

	on_memberBtn_clicked();
}

void ClientUI::onRecvKicked(const std::string &res)
{
	QString qContent = QString::fromLocal8Bit(res.data());
	ui.sysEdit->append(qContent);
	ui.sysEdit->append("\n");

	QString group = qContent.simplified().split(" ").at(1);
	if (!isUserList && currentChatName == group)
	{
		on_allGroupBtn_clicked();
	}
}

void ClientUI::onRecvMuteRes(const std::string &res)
{
	QString qContent = QString::fromLocal8Bit(res.data());
	ui.sysEdit->append(qContent);
	ui.sysEdit->append("\n");

	Client::getInstance()->listMembers(std::string(currentChatName.toLocal8Bit()));
	Client::getInstance()->listMuted(std::string(currentChatName.toLocal8Bit()));
}

void ClientUI::onRecvUnmuteRes(const std::string &res)
{
	QString qContent = QString::fromLocal8Bit(res.data());
	ui.sysEdit->append(qContent);
	ui.sysEdit->append("\n");

	Client::getInstance()->listMembers(std::string(currentChatName.toLocal8Bit()));
	Client::getInstance()->listMuted(std::string(currentChatName.toLocal8Bit()));
}

void ClientUI::onRecvNewMember(const std::string &content)
{
	QString qContent = QString::fromLocal8Bit(content.data());
	ui.sysEdit->append(qContent);
	ui.sysEdit->append("\n");

	QString group = qContent.simplified().split(" ").last();
	if (!isUserList && currentChatName == group)
	{
		Client::getInstance()->listMembers(std::string(currentChatName.toLocal8Bit()));
	}
}

void ClientUI::onRecvReduceMember(const std::string &content)
{
	QString qContent = QString::fromLocal8Bit(content.data());
	ui.sysEdit->append(qContent);
	ui.sysEdit->append("\n");

	QString group = qContent.simplified().split(" ").last();
	if (!isUserList && currentChatName == group)
	{
		Client::getInstance()->listMembers(std::string(currentChatName.toLocal8Bit()));
	}
}

void ClientUI::on_userBtn_clicked()
{
	isUserList = true;
    Client::getInstance()->listUser();
    ui.chatStkWidget->setCurrentIndex(0);
    currentChatName.clear();
    ui.groupBox_2->setTitle(QString::fromLocal8Bit("在线用户"));

	ui.memberStkWidget->hide();
	ui.label_3->hide();
	ui.line->hide();
}

void ClientUI::on_allGroupBtn_clicked()
{
	isUserList = false;
	Client::getInstance()->listGroup();
	ui.chatStkWidget->setCurrentIndex(0);
	currentChatName.clear();
	ui.groupBox_2->setTitle(QString::fromLocal8Bit("所有群组"));

	ui.memberStkWidget->hide();
	ui.label_3->hide();
	ui.line->hide();
}

void ClientUI::on_createGroupBtn_clicked()
{
	m_groupNameWidget->show();
}

void ClientUI::on_refreshBtn_clicked()
{
	if (isUserList)
	{
		on_userBtn_clicked();
	}
	else
	{
		on_allGroupBtn_clicked();
	}
}

void ClientUI::getNewGroupName(const QString &gName)
{
	Client::getInstance()->createGroup(std::string(gName.toLocal8Bit()));
}

void ClientUI::on_sendBtn_clicked()
{
    QString chatStr = ui.sendEdit->toPlainText();
    if (chatStr.isEmpty())
    {
        QMessageBox::information(this, QString::fromLocal8Bit("信息"), QString::fromLocal8Bit("请输入内容！"));
        return;
    }

    if (currentChatName.isEmpty())
    {
		QMessageBox::information(this, QString::fromLocal8Bit("信息"), QString::fromLocal8Bit("请选择发送对象！"));
		return;
    }

	if (isUserList)
	{
		saveToTempFile(true, currentChatName, QString::fromLocal8Bit("我"), chatStr);
		QString htmlStr = QString("<div style=\"margin:5px; padding:8px; color:#468b58; display:inline-block;\">%1</div>")
			.arg(QString::fromLocal8Bit("我：") + chatStr);

		ui.chatEdit->moveCursor(QTextCursor::End);
		ui.chatEdit->insertHtml(htmlStr);
		ui.chatEdit->append("\n");

		Client::getInstance()->sendChat(std::string(currentChatName.toLocal8Bit()), std::string(chatStr.toLocal8Bit()));
	}
	else
	{
		if (Client::getInstance()->isJoinedGroup(std::string(currentChatName.toLocal8Bit())))
		{
			saveToTempFile(true, currentChatName, QString::fromLocal8Bit("我"), chatStr);
			QString htmlStr = QString("<div style=\"margin:5px; padding:8px; color:#468b58; display:inline-block;\">%1</div>")
				.arg(QString::fromLocal8Bit("我：") + chatStr);

			ui.chatEdit->moveCursor(QTextCursor::End);
			ui.chatEdit->insertHtml(htmlStr);
			ui.chatEdit->append("\n");

			Client::getInstance()->sendGroupChat(std::string(currentChatName.toLocal8Bit()), std::string(chatStr.toLocal8Bit()));
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("信息"),
				QString::fromLocal8Bit("您不是该群组成员，请先加入！"));
		}
	}
}

void ClientUI::on_publicSendBtn_clicked()
{
	QString chatStr = ui.sendEdit->toPlainText();
	if (chatStr.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("信息"), QString::fromLocal8Bit("请输入内容！"));
		return;
	}

	QString htmlStr = QString("<div style=\"margin:5px; padding:8px; color:#468b58; display:inline-block;\">%1</div>")
		.arg(QString::fromLocal8Bit("我：") + chatStr);

	ui.publicEdit->moveCursor(QTextCursor::End);
	ui.publicEdit->insertHtml(htmlStr);
	ui.publicEdit->append("\n");

	Client::getInstance()->sendPublicChat(std::string(chatStr.toLocal8Bit()));
}

void ClientUI::changeChatWidget(QListWidgetItem* item)
{
    ui.chatEdit->clear();

    UserItemWidget* widget = dynamic_cast<UserItemWidget *>(ui.listWidget->itemWidget(item));
	if (isUserList)
	{
		currentChatName = widget->getName();
	}
	else
	{
		QString name = widget->getName();
		currentChatName = name.left(name.indexOf(QString::fromLocal8Bit(" (")));
		
		if (Client::getInstance()->isJoinedGroup(std::string(currentChatName.toLocal8Bit())))
		{
			ui.memberStkWidget->show();
			ui.memberStkWidget->setCurrentIndex(0);
			ui.label_3->show();
			ui.line->show();
		}
		else
		{
			ui.memberStkWidget->hide();
			ui.label_3->hide();
			ui.line->hide();
		}
	}

    widget->setNewInfoVisible(false);
    ui.chatStkWidget->setCurrentIndex(1);

    QStringList recList = loadTempFile(currentChatName);
    for (int i = 0; i < recList.size(); ++i)
    {
		ui.chatEdit->moveCursor(QTextCursor::End);
		ui.chatEdit->insertHtml(recList.at(i));
		ui.chatEdit->append("\n");
    }
}

void ClientUI::on_memberBtn_clicked()
{
	Client::getInstance()->listMembers(std::string(currentChatName.toLocal8Bit()));
	Client::getInstance()->listMuted(std::string(currentChatName.toLocal8Bit()));

	ui.memberStkWidget->setCurrentIndex(1);
	ui.tabWidget->setCurrentIndex(0);
}

void ClientUI::saveToTempFile(const bool& isMy, const QString& fileName, const QString& name, const QString& msg)
{
	QFile f(QString("./chatRec/%1.json").arg(fileName));
    if (!f.exists())
    {
		QJsonArray array;
		QJsonObject obj;
		obj["name"] = name;
		obj["msg"] = msg;
		obj["isMy"] = isMy;
		array.append(obj);

        QJsonDocument doc(array);
		f.open(QIODevice::WriteOnly);
		f.write(doc.toJson());
		f.close();

        return;
    }

    f.open(QIODevice::ReadOnly);

    QJsonDocument doc = QJsonDocument::fromJson(f.readAll());
    QJsonArray array = doc.array();
    QJsonObject obj;
    obj["name"] = name;
    obj["msg"] = msg;
    obj["isMy"] = isMy;
    array.append(obj);

    doc = QJsonDocument(array);
    f.close();

    f.open(QIODevice::WriteOnly);
    f.write(doc.toJson());
	f.close();
}

QStringList ClientUI::loadTempFile(const QString& fileName)
{
    QFile f(QString("./chatRec/%1.json").arg(fileName));
    if (!f.exists())
    {
        return QStringList();
    }

    QStringList recList;
	f.open(QIODevice::ReadOnly);

	QJsonDocument doc = QJsonDocument::fromJson(f.readAll());
	QJsonArray array = doc.array();
    for (int i = 0; i < array.size(); ++i)
    {
        QString name = array[i].toObject()["name"].toString();
        QString msg = array[i].toObject()["msg"].toString();
        bool isMy = array[i].toObject()["isMy"].toBool();

        QString infoStr;
        if (isMy)
        {
            infoStr = QString("<div style=\"margin:5px; padding:8px; color:#468b58; display:inline-block;\">%1</div>")
				.arg(name + QString::fromLocal8Bit("：") + msg);
        }
        else
        {
			infoStr = QString("<div style=\"margin:5px; padding:8px; color:#6e8acf; display:inline-block;\">%1</div>")
				.arg(name + QString::fromLocal8Bit("：") + msg);
		}

        recList << infoStr;
    }

    return recList;
}
