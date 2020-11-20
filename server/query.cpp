#include "query.h"

#include <QSqlRecord>
#include <QJsonObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlDriver>
#include <QSqlRecord>


void query::run()
{
    qDebug() << "Query = " << comm;
    QSqlQuery que = db->exec(QString(comm));
    int i = 0;
    QString buffer="{\n";
    QSqlDriver* driver = db->driver();
    while(que.next())
    {
        i=0;

        while(que.value(i).isValid())
        {
            qDebug()<<driver->record("users").fieldName(i);
            //qDebug()<<"i este: "<<i;
            if(i)
            {

            }
            qDebug()<<que.value(i).toString();
            i++;

        }
    }


}

void query::start()
{
    // do stuff with query
}

query::query(QSqlDatabase *db, char *query) : db(db), comm(query)
{


}
