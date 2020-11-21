#include "network.h"

void network::read()
{
    QByteArray*arr = new QByteArray;

    size_t packetSize;

    while (sock->bytesAvailable() && connected)
    {
        sock->read((char*)&packetSize,sizeof(size_t));

        while (arr->size() < packetSize && connected)
        {
            arr->append(sock->readAll());
        }
    }
    qDebug() << "arr:" << *arr;
    if (arr->size() == packetSize)
        emit receivedData(arr);
}

void network::write()
{
    size_t packetSize = strlen(toWrite);
    sock->write((char*)&packetSize,sizeof(packetSize));
    sock->write(toWrite);

    while (sock->bytesToWrite())
    {

    }

    emit sentData();
}

void network::onConnect()
{
    qDebug() << "Connected to " << sock->peerAddress();
    connected = 1;
}

void network::onDisconnect()
{
    qDebug()<< "Disconnected";
    connected = 0;
    while (!connected)
    {
        qDebug() << connected;
        sock->connectToHost("192.168.1.195",2020);
        sock->waitForConnected();
    }
}

void network::sendData(QByteArray *array)
{
    if (running.isRunning())
        running.waitForFinished();
    mode = 1;
    toWrite = array->data();
    running = QtConcurrent::run(this,&network::run);
}

void network::receiveData()
{
    if (running.isRunning())
        running.waitForFinished();
    mode =0;
    running = QtConcurrent::run(this,&network::run);
}



void network::run()
{
    if (!mode)
        read();
    else write();
}

network::network(QObject *parent) : QObject(parent)
{
    sock = new QTcpSocket;
    connect(sock,&QTcpSocket::disconnected,this,&network::onDisconnect);
    connect(sock,&QTcpSocket::connected,this,&network::onConnect);
    connect(sock,&QTcpSocket::readyRead,this,&network::receiveData);
    // connect idk .....this,network,senddata
    onDisconnect();

    connect(&manager,&queryManager::newQuery,this,&network::sendData);
    connect(this,&network::sentData,&manager,&queryManager::networkFinished);
    connect(this,&network::receivedData,&manager,&queryManager::_queryResponse);
    //QThreadPool::globalInstance()->start(this);
}
