#include "connection.h"

void connection::startRead()
{
    qDebug() << "Got new packet";
    runMode = 0;
    //QThreadPool::globalInstance()->start(this);
    if (dataHandle.isRunning())
        dataHandle.waitForFinished();
    dataHandle = QtConcurrent::run(this,&connection::run);
}

void connection::onDisconnect()
{
    toRead = 0;
    emit disconnected(index);
}


void connection::sendQueryData(QByteArray *array)
{
    externalArr = array;
    runMode = 1;
    if (dataHandle.isRunning())
        dataHandle.waitForFinished();
    dataHandle = QtConcurrent::run(this,&connection::run);
}

void connection::queryDataSent()
{
    delete externalArr;
}


void connection::read()
{
    while (sock->bytesAvailable())
    {
        sock->read((char*)&toRead,sizeof(size_t));
        while(arr.size() < toRead)
        {
            toRead -= sock->bytesAvailable();
            arr.append(sock->readAll());
        }
    }
    qDebug() << arr.size();
    if (arr.size() > 0)
        emit receivedQuery(&arr,index);
   // sock->flush()
}

void connection::write()
{
    sock->write(*externalArr);
    while (sock->bytesToWrite())
    {

    }
    queryDataSent();
}

void connection::run()
{
    if (!runMode)
        read();
    else write();

}

connection::connection(const unsigned int index, QTcpSocket *sock, QObject *parent) :QObject(parent),index(index),sock(sock)
{
    qDebug() << "New connection from " << sock->peerAddress() << " with index " << index;
    sock->connect(sock,&QTcpSocket::disconnected,this,&connection::onDisconnect);
    sock->connect(sock,&QTcpSocket::readyRead,this,&connection::startRead);
}

connection::~connection()
{
    qDebug() << "Client " << index << " deleted";
}




