#ifndef CLIENTAPI_H
#define CLIENTAPI_H

#include <QObject>
#include <QThread>

class ClientAPI : public QObject {
    Q_OBJECT
public:
    explicit ClientAPI(QObject *parent = nullptr);
    
    // 添加线程成员声明
    QThread *recvThread_;
    
signals:
    void connectionStatusChanged(bool connected);
    void messageReceived(const QString &message);
    
public slots:
    void Connect(const QString &ip, quint16 port);
    void SendMessage(const QString &message);
};

#endif // CLIENTAPI_H
