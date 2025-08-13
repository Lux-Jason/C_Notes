#include "GroupNameWidget.h"
#include <QMessageBox>

GroupNameWidget::GroupNameWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowModality(Qt::ApplicationModal);
}

GroupNameWidget::~GroupNameWidget()
{}

void GroupNameWidget::on_okBtn_clicked()
{
	QString group = ui.nameEdit->text();
	if (group.isEmpty())
	{
		QMessageBox::information(this, 
			QString::fromLocal8Bit("信息"), QString::fromLocal8Bit("请输入群名！"));
		return;
	}

	emit sendGroupName(group);
	on_cancelBtn_clicked();
}

void GroupNameWidget::on_cancelBtn_clicked()
{
	ui.nameEdit->clear();
	this->close();
}
