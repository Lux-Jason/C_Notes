#include "LoginWidget.h"
#include <QMessageBox>

LoginWidget* LoginWidget::m_instance = nullptr;

LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(Client::getInstance(), &Client::connect_res, this, &LoginWidget::connectRes);
	connect(Client::getInstance(), &Client::login_res, this, &LoginWidget::loginRes);
}

LoginWidget::~LoginWidget()
{}

LoginWidget* LoginWidget::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new LoginWidget;
	}

	return m_instance;
}

void LoginWidget::connectRes(const ConnectRes &res)
{
	if (res == ConnectRes::CONNECT_SUCCESS)
	{
        QMessageBox::information(this, QString::fromLocal8Bit("Information"), QString::fromLocal8Bit("Connected securely to the server %1:%2 [DES encryption has been enabled]").arg(ui.addrEdit->text()).arg(ui.portEdit->text()));
		ui.stackedWidget->setCurrentIndex(1);
	}
	else
	{
        QMessageBox::information(this, QString::fromLocal8Bit("Information"), QString::fromLocal8Bit("Connection to the server failed!"));
	}
}

void LoginWidget::loginRes(const LoginRes &res)
{
	if (res == LoginRes::LOGIN_SUCCESS)
	{
        QMessageBox::information(this, QString::fromLocal8Bit("Information"), QString::fromLocal8Bit("Login successfully!"));
		emit loginSuccess(ui.nameEdit->text());
		close();
	}
	else
	{
        QMessageBox::information(this, QString::fromLocal8Bit("Information"), QString::fromLocal8Bit("The username has been taken. Please choose another name"));
	}
}

void LoginWidget::on_connBtn_clicked()
{
	QString addrStr = ui.addrEdit->text();
	QString portStr = ui.portEdit->text();
	if (addrStr.isEmpty())
	{
        QMessageBox::information(this, QString::fromLocal8Bit("Information"), QString::fromLocal8Bit("Please input the address!"));
		return;
	}
	else if (portStr.isEmpty())
	{
        QMessageBox::information(this, QString::fromLocal8Bit("Information"), QString::fromLocal8Bit("Please input the port!"));
		return;
	}

	Client::getInstance()->start(addrStr.toStdString(), portStr.toInt());
}

void LoginWidget::on_loginBtn_clicked()
{
	QString userName = ui.nameEdit->text();
	if (userName.isEmpty())
	{
        QMessageBox::information(this, QString::fromLocal8Bit("Information"), QString::fromLocal8Bit("Please input the user name!"));
		return;
	}
	Client::getInstance()->login(std::string(userName.toLocal8Bit()));
}
