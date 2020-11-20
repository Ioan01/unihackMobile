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
class query : public QObject,public QRunnable
{
    Q_OBJECT
    QSqlDatabase *db;
    char *comm;
private:
    void converToJson();
signals:

public:

    void run() override;
    query(QSqlDatabase *db,char *query);
};

#endif // QUERY_H
