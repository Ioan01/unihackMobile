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
    query *_query = new query(&this->database,dat->data(),id);
    QFuture<void>dataQuery = QtConcurrent::run(_query,&query::run);
    connect(_query,&query::finishedParsing,this,&server::sendJson);



    //_query= new query(&this->database,dat->data());
}

void server::sendJson(QByteArray *json, unsigned int clientId,void *queryPtr)
{
    for (uint32_t i=0;i<connections.size();i++)
        if (connections[i]->clientId() == clientId)
        {
            connections[i]->sendQueryData(json);
            break;
        }

    delete (query*)queryPtr;
}
