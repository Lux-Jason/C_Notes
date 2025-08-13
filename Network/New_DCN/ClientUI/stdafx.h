// stdafx.h: 标准系统包含文件的包含文件
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0A00  // Windows 10
#include <windows.h>

// C++ 标准库
#include <vector>
#include <string>
#include <memory>

// Qt 必要头文件
#include <QApplication>
#include <QWidget>
#include <QObject>
#include <QThread>
#include <QtCore/QtGlobal>
#include <QtCore/QString>
#include <QtCore/QMetaType>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
