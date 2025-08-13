QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Client.cpp \
    ClientUI.cpp \
    DES_c.cpp \
    GroupNameWidget.cpp \
    LoginWidget.cpp \
    UserItemWidget.cpp \
    main.cpp

HEADERS += \
    Client.h \
    ClientUI.h \
    DES_c.h \
    GroupNameWidget.h \
    LoginWidget.h \
    UserItemWidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ClientUI.qrc

FORMS += \
    ClientUI.ui \
    GroupNameWidget.ui \
    LoginWidget.ui \
    UserItemWidget.ui
