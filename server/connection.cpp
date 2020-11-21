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


void connection::sendQueryData(char *array)
{

    while (!finishedWriting && !lostConnection)
    {

    }
    externalArr.append(array);

    runMode = 1;
   // if (dataHandle.isRunning())
    //    dataHandle.waitForFinished();
    run();
}

void connection::queryDataSent()
{
    externalArr.clear();
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
            qDebug() << "stuck";
        }
        qDebug() << "stuck";
    }
    qDebug() << "Packet: " << arr;
    if (arr.size() > 0)
        emit receivedQuery(&arr,index);
   finishedReading = 1;
}

void connection::write()
{
    finishedWriting = 0;
    size_t size = externalArr.size();
    sock->write((char*)&size,sizeof(size_t));
    sock->write(externalArr);
    qDebug() << "ext:" << externalArr;

    while (sock->bytesToWrite() && !lostConnection)
    {
        sock->flush();
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




