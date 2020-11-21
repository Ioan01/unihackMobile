#ifndef QUERY_H
#define QUERY_H

#include <QRunnable>
#include <QObject>
#include <QThreadPool>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QJsonObject>
#include <QJsonValue>
#include <QVariantMap>

class query : public QObject,public QRunnable
{
    Q_OBJECT
    QSqlDatabase *db;
    char *comm;
    unsigned int connId;
private:
    QByteArray* parseJson();

signals:
    void finishedParsing(QByteArray *data,unsigned int id,void *selfPtr);

public:
    void run() override;
    void start();
    query(QSqlDatabase *db,char *query,unsigned int connId);
};

#endif // QUERY_H
