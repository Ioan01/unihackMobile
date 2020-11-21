#ifndef QUERYMANAGER_H
#define QUERYMANAGER_H

#include <QObject>
#include <QRunnable>
#include <QtConcurrent/QtConcurrentRun>
#include <QString>
#include <queue>
#include <QJsonDocument>


class queryManager : public QObject
{
    Q_OBJECT
    std::queue<QString>queryQueue;

    std::list<QByteArray*>arrayList;
private:

signals:
    void newQuery(QByteArray *arr);
    void queryResponse(QJsonDocument doc);
public slots:
    void handleQuery(QString query);
    void networkFinished();
    void _queryResponse(QByteArray *arr);

public:
    queryManager();
};

#endif // QUERYMANAGER_H
