#pragma once

#include <QWidget>
#include "Client.h"
#include "ui_LoginWidget.h"

class LoginWidget : public QWidget
{
	Q_OBJECT

public:
	LoginWidget(QWidget *parent = nullptr);
	~LoginWidget();

	static LoginWidget* getInstance();

signals:
	void loginSuccess(const QString &);

public slots:
	void connectRes(const ConnectRes &);
	void loginRes(const LoginRes&);

	void on_connBtn_clicked();
	void on_loginBtn_clicked();

private:
	Ui::LoginWidgetClass ui;

	static LoginWidget* m_instance;
};
