#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QRunnable>
#include <QThreadPool>
#include <QTcpSocket>



class connection : public QObject,public QRunnable
{
    Q_OBJECT
    unsigned int index;
    QTcpSocket *sock;
    QByteArray arr;

    QByteArray* externalArr;
    // 0 to read, 1 to write
    bool runMode = 0;


    size_t toRead = 0;
signals:
    void disconnected(unsigned int id);
    void receivedQuery(QByteArray *query);
public slots:
    void startRead();
    void onDisconnect();

    void sendQueryData(QByteArray *array);
public:
    void read();
    void write();

    void run() override;
    void setId(const unsigned int index){qDebug() << this->index << " renamed to " << index;this->index = index;}
    connection(const unsigned int index,QTcpSocket *sock,QObject *parent = nullptr);
    ~connection();
};

#endif // CONNECTION_H
