#include "UserItemWidget.h"

UserItemWidget::UserItemWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

UserItemWidget::~UserItemWidget()
{}

void UserItemWidget::setName(const QString& name)
{
	ui.nameLabel->setText(name);
}

void UserItemWidget::setNewInfoVisible(const bool& state)
{
	if (state)
	{
		ui.newInfoLabel->show();
	}
	else
	{
		ui.newInfoLabel->hide();
	}
}

QString UserItemWidget::getName()
{
	return ui.nameLabel->text();
}
