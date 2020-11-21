#include "query.h"

#include <QSqlRecord>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "JsonLibraries.h"


void query::run()
{
    qDebug() << "Query = " << comm;
    QByteArray* jsonArr = parseJson();
    emit finishedParsing(jsonArr,connId,this);
}

void query::start()
{
    // do stuff with query
}

QByteArray* query::parseJson()
{
    //query e necesar ca sa extragem numele tabelului
    QSqlQuery que = db->exec(QString(comm));
    QJsonObject test; //obiectul json final
    int i = 0; //necesar pt parcurgerea tuturor coloanelor de pe un rand
    QJsonArray buffer; //facem un array in json
    QJsonObject row; //un element dintr-un array
    QSqlDriver* driver = db->driver(); //trebe sa existe, nu stergeti


    while(que.next())
    {
        i=0; //resetam i

        while(que.value(i).isValid())
        {
            row.insert(driver->record("users").fieldName(i),QJsonValue(que.value(i).toString())); //introducem o coloana in buffer-ul ce rprezinta un obiect din array(ex: "ID":"1")
            i++;                                                                                  //de asemenea, valorile isi dau overwrite, similar cu un map, deci nu trebuie resetat
        }
        buffer.append(QJsonValue(row)); //dam append la elementul de array
        //qDebug()<<buffer;
        //buffer+="}";

    }
    test.insert("users",buffer);//fisierul json complet

    // after json is finished
    // store array in this

    QJsonDocument j_doc = QJsonDocument(test);
    //qDebug()<<j_doc;
    //QVariant var = j_doc.toVariant();
    //qDebug()<<var.toByteArray();
    QByteArray* jsonArr = new QByteArray(j_doc.toJson());
    return jsonArr;
}

query::query(QSqlDatabase *db, char *query, unsigned int connId) : db(db), comm(query), connId(connId)
{


}
