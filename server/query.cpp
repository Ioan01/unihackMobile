#include "query.h"

#include <QSqlRecord>



void query::run()
{
    qDebug() << "Query = " << comm;
    QSqlQuery que = db->exec(QString(comm));


    // after json is finished
    // store array in this
    QByteArray *jsonArr;
    delete comm;
    emit finishedParsing(jsonArr,connId,this);
}

void query::start()
{
    // do stuff with query
}

query::query(QSqlDatabase *db, char *query, unsigned int connId) : db(db), comm(query), connId(connId)
{


}
