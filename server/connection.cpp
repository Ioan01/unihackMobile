#include "connection.h"

void connection::startRead()
{
    QThreadPool::globalInstance()->tryStart(this);
}

void connection::onDisconnect()
{
    toRead = 0;
    emit disconnected(index);
}


void connection::sendQueryData(QByteArray *array)
{
    externalArr = array;
}

void connection::read()
{
    sock->read((char*)&toRead,sizeof(size_t));

    while (sock->bytesAvailable())
    {
        while(arr.size() < toRead)
        {
            toRead -= sock->bytesAvailable();
            arr.append(sock->readAll());
        }
    }
    if (arr.size())
        emit receivedQuery(&arr);
}

void connection::write()
{
    sock->write(*externalArr);
    while (sock->bytesToWrite())
    {

    }
    //emit dataSent
}

void connection::run()
{
    if (!runMode)
        read();
    else write();

}

connection::connection(const unsigned int index, QTcpSocket *sock, QObject *parent) :QObject(parent),index(index),sock(sock)
{
    sock->connect(sock,&QTcpSocket::disconnected,this,&connection::onDisconnect);
    sock->connect(sock,&QTcpSocket::readyRead,this,&connection::startRead);
}

connection::~connection()
{
    qDebug() << "Client " << index << " deleted";
}




