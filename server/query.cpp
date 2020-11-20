#include "query.h"



void query::run()
{
    QSqlQuery que = db->exec(QString(comm));

    while (que.next()) {
        qDebug() << que.value(0).toJsonObject();
    }



}

query::query(QSqlDatabase *db, char *query) : db(db), comm(query)
{

    QThreadPool::globalInstance()->start(this);
}
