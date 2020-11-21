#include "registerscreen.h"

registerScreen::registerScreen(QObject *parent) : QObject(parent)
{

}

void registerScreen::Register(QString username, QString password, QString confirmedPassword)
{
    if(password==confirmedPassword)
    {
        QString registerQuery;
        registerQuery = QString("INSERT INTO users (username, age) values (""") + username + QString(""", """) + password +QString(""";");
        emit sendQuery(registerQuery);
    }
    else
    {
        emit differentPasswords();
    }

}
