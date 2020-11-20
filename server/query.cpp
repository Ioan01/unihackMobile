#include "query.h"

#include <QSqlRecord>



void query::run()
{
    qDebug() << "Query = " << comm;
    QSqlQuery que = db->exec(QString(comm));


}

void query::start()
{
    // do stuff with query
}

query::query(QSqlDatabase *db, char *query) : db(db), comm(query)
{


}
