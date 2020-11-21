#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QRunnable>
#include <QThreadPool>
#include <QTcpSocket>
#include <QHostAddress>
#include <QtConcurrent/QtConcurrentRun>



class connection : public QObject,public QRunnable
{
    Q_OBJECT
    unsigned int index;
    QTcpSocket *sock;
    bool lostConnection = 0;
    QByteArray arr;
    QByteArray externalArr;

    QFuture<void>dataHandle;
    // 0 to read, 1 to write
    bool runMode = 0;
    bool finishedReading = 1;
    bool finishedWriting = 1;

    size_t toRead = 0;
signals:
    void disconnected(unsigned int id);
    void receivedQuery(QByteArray *query,unsigned int selfId);

public slots:
    void startRead();
    void onDisconnect();

    void sendQueryData(char *array);

public:
    void read();
    void write();
    void queryDataSent();

    void run() override;
    unsigned int clientId(){return index;}
    void setId(const unsigned int index){qDebug() << this->index << " renamed to " << index;this->index = index;}
    connection(const unsigned int index,QTcpSocket *sock,QObject *parent = nullptr);
    ~connection();
};

#endif // CONNECTION_H
