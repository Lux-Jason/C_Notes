#include "ClientAPI.h"
#include <QTcpSocket>

ClientAPI::ClientAPI(QObject *parent) 
    : QObject(parent), socket(new QTcpSocket(this)), recvThread_(new QThread(this)) {
    
    connect(socket, &QTcpSocket::connected, [this]() {
        emit connectionStatusChanged(true);
    });
    
    connect(socket, &QTcpSocket::disconnected, [this]() {
        emit connectionStatusChanged(false);
    });
    
    connect(socket, &QTcpSocket::readyRead, [this]() {
        emit messageReceived(QString::fromUtf8(socket->readAll()));
    });
}

void ClientAPI::Connect(const QString &ip, quint16 port) {
    socket->connectToHost(ip, port);
}

void ClientAPI::SendMessage(const QString &message) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8());
        socket->flush();
    }
}
