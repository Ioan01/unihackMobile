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

    if (arr->size() == packetSize)
        emit receivedData(arr);
}

void network::write()
{
    while (sock->bytesToWrite())
    {

    }
}

void network::onConnect()
{
    qDebug() << "Connected to " << sock->peerAddress();
    connected = 1;
    size_t size = 27;

    sock->write((char*)&size,sizeof(size_t));
    sock->write("SELECT username FROM users");

    sock->waitForBytesWritten();
}

void network::onDisconnect()
{
    qDebug()<< "Disconnected";
    connected = 0;
    while (!connected)
    {
        qDebug() << connected;
        sock->connectToHost("127.0.0.1",2020);
        sock->waitForConnected();
    }
    //char a[] = "SELECT username FROM users";
    size_t size = 27;

    sock->write((char*)&size,sizeof(size_t));
    sock->write("SELECT username FROM users");
}

void network::sendData(QByteArray *array)
{
    running.waitForFinished();
    mode = 1;
    running = QtConcurrent::run(this,&network::run);
}

void network::receiveData()
{
    running.waitForFinished();
    mode =0;
    running = QtConcurrent::run(this,&network::run);
}

void network::run()
{
    static bool firsRun = 1;


    if (firsRun)
        onDisconnect();
    else
    {
        if (!mode)
            read();
        else write();
    }

}

network::network(QObject *parent) : QObject(parent)
{
    sock = new QTcpSocket;
    connect(sock,&QTcpSocket::disconnected,this,&network::onDisconnect);
    connect(sock,&QTcpSocket::connected,this,&network::onConnect);
    connect(sock,&QTcpSocket::readyRead,this,&network::receiveData);
    // connect idk .....this,network,senddata
    onDisconnect();
    //QThreadPool::globalInstance()->start(this);
}
