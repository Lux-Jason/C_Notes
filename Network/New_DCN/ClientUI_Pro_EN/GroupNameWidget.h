#pragma once

#include <QWidget>
#include "ui_GroupNameWidget.h"

class GroupNameWidget : public QWidget
{
	Q_OBJECT

public:
	GroupNameWidget(QWidget *parent = nullptr);
	~GroupNameWidget();

signals:
	void sendGroupName(const QString &);

public slots:
	void on_okBtn_clicked();
	void on_cancelBtn_clicked();

private:
	Ui::GroupNameWidgetClass ui;
};
