#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrentRun>
#include "connection.h"
#include "query.h"




#define THREAD_COUNT 200

class server : public QObject
{
    Q_OBJECT
    QSqlDatabase database;
    QTcpServer *_server;
    std::vector<connection*>connections;

public:
    server(QObject *parent = nullptr);
public slots:

    void onNewConnection();
    void onDisconnect(unsigned int id);
    void handleQuery(QByteArray* query,unsigned int clientId);
    void sendJson(QByteArray* json,unsigned int clientId,void* queryPtr);
};

#endif // SERVER_H
