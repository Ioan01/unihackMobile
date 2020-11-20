#include "server.h"



server::server(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(THREAD_COUNT);
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:\\database\\sqlite.db");
    database.open();
    _server = new QTcpServer(this);

    _server->listen(QHostAddress::Any,2020);
    connect(_server,&QTcpServer::newConnection,this,&server::onNewConnection);
}

void server::onNewConnection()
{
   connections.push_back(new connection(connections.size(),_server->nextPendingConnection(),this));
   connect(connections.back(),&connection::disconnected,this,&server::onDisconnect);
   connect(connections.back(),&connection::receivedQuery,this,&server::handleQuery);
}

void server::onDisconnect(unsigned int id)
{
    connections[id]->deleteLater();
    for (uint32_t i=id+1;i<connections.size();i++)
    {
        connections[i]->setId(i-1);
    }

    connections.erase(connections.begin() + id);
}

void server::handleQuery(QByteArray *dat,unsigned int id)
{
    query *_query = new query(&this->database,dat->data());
    QFuture<void>dataQuery = QtConcurrent::run(_query,&query::run);

    dataQuery.waitForFinished();


    //_query= new query(&this->database,dat->data());
}
