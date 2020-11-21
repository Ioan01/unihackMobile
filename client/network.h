#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrentRun>
#include <QHostAddress>
#include "querymanager.h"


class network : public QObject, public QRunnable
{
    Q_OBJECT
    QTcpSocket *sock;
    QFuture<void>running;
    bool connected = 0;


    char *toWrite = nullptr;
    // 0 for read, 1 for write
    bool mode = 0;

    queryManager manager;
private:
    void read();
    void write();
signals:
    void receivedData(QByteArray *arr);
    void sentData();

public slots:
    void onConnect();

    void onDisconnect();

    void sendData(QByteArray *array);

    void receiveData();

public:
    void run() override;

    network(QObject* parent);
};

#endif // NETWORK_H
