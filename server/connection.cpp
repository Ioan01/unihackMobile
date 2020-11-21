#include "connection.h"

void connection::startRead()
{
    while (!finishedReading)
    {

    }
    qDebug() << "Got new packet";
    runMode = 0;
    //QThreadPool::globalInstance()->start(this);

    dataHandle = QtConcurrent::run(this,&connection::run);
}

void connection::onDisconnect()
{
    lostConnection = 1;
    toRead = 0;
    emit disconnected(index);
}


void connection::sendQueryData(QByteArray *array)
{
    while (!finishedWriting)
    {

    }
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
    finishedReading = 0;
    while (sock->bytesAvailable() && !lostConnection)
    {
        sock->read((char*)&toRead,sizeof(size_t));
        while(arr.size() < toRead && !lostConnection)
        {
            toRead -= sock->bytesAvailable();
            arr.append(sock->readAll());
        }
    }
    qDebug() << "Packet: " << arr;
    if (arr.size() > 0)
        emit receivedQuery(&arr,index);
   finishedReading = 1;
}

void connection::write()
{
    finishedWriting = 0;
    sock->write(*externalArr);
    while (sock->bytesToWrite() && !lostConnection)
    {

    }
    queryDataSent();
    finishedWriting = 1;
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




