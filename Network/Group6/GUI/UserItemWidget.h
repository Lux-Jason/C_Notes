#pragma once

#include <QWidget>
#include "ui_UserItemWidget.h"

class UserItemWidget : public QWidget
{
	Q_OBJECT

public:
	UserItemWidget(QWidget *parent = nullptr);
	~UserItemWidget();

	void setName(const QString &);
	void setNewInfoVisible(const bool &);
	QString getName();

private:
	Ui::UserItemWidgetClass ui;
};
