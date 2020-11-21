#include "querymanager.h"

#include <QJsonDocument>


void queryManager::handleQuery(QString query)
{

    if (queryQueue.empty())
    {
        emit newQuery(new QByteArray(query.toUtf8()));
    }
    else
    {
        arrayList.push_front(new QByteArray(query.toUtf8()));
        queryQueue.push(query);
    }


}

void queryManager::networkFinished()
{
    arrayList.pop_back();
    if (!queryQueue.empty())
    {
        emit newQuery(arrayList.back());
    }
}

void queryManager::_queryResponse(QByteArray *arr)
{
    QJsonDocument doc;
    doc.fromBinaryData(*arr);

    emit queryResponse(doc);
}



queryManager::queryManager()
{

}
