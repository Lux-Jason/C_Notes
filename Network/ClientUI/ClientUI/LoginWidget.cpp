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
		QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("�Ѱ�ȫ���ӵ������� %1:%2 [DES����������]").arg(ui.addrEdit->text()).arg(ui.portEdit->text()));
		ui.stackedWidget->setCurrentIndex(1);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("���ӷ�����ʧ�ܣ�"));
	}
}

void LoginWidget::loginRes(const LoginRes &res)
{
	if (res == LoginRes::LOGIN_SUCCESS)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("��¼�ɹ���"));
		emit loginSuccess(ui.nameEdit->text());
		close();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("�û����ѱ�ʹ�ã���ѡ���������ƣ�"));
	}
}

void LoginWidget::on_connBtn_clicked()
{
	QString addrStr = ui.addrEdit->text();
	QString portStr = ui.portEdit->text();
	if (addrStr.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("�������ַ��"));
		return;
	}
	else if (portStr.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("������˿ںţ�"));
		return;
	}

	Client::getInstance()->start(addrStr.toStdString(), portStr.toInt());
}

void LoginWidget::on_loginBtn_clicked()
{
	QString userName = ui.nameEdit->text();
	if (userName.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("�����û�����"));
		return;
	}
	Client::getInstance()->login(std::string(userName.toLocal8Bit()));
}
