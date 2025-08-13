#include "ClientUI.h"
#include "LoginWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	ClientUI w;
	w.hide();

    LoginWidget::getInstance()->show();
    
    return a.exec();
}
