#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QThreadPool>
#include "connection.h"
#include "query.h"
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
    void handleQuery(QByteArray* query);

};

#endif // SERVER_H
