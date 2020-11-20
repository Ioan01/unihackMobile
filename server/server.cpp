#include "server.h"



server::server(QObject *parent) : QObject(parent)
{


    _server = new QTcpServer(this);


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
}

void server::handleQuery(QByteArray *data)
{
    query *_query = new query(&this->database,data->data());



    data->clear();
}
