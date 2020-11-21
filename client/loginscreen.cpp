#include "loginscreen.h"

#include <string>

loginScreen::loginScreen(QObject *parent) : QObject(parent)
{

}

void loginScreen::activate()
{
    connect(this,&loginScreen::sendQuery,&manager,&queryManager::handleQuery);
    connect(&manager,&queryManager::queryResponse,this,&loginScreen::handleResponse);
}

void loginScreen::deactivate()
{
    disconnect(this,&loginScreen::sendQuery,&manager,&queryManager::handleQuery);
}

void loginScreen::login(QString username, QString password)
{
    QString loginQuery;
    loginQuery = QString("SELECT username, password FROM users WHERE username=""") + username + QString(""" AND """) + password +QString(""";");
    emit sendQuery(loginQuery);
}




bool loginScreen::handleResponse(const QJsonDocument &json)
{
    QJsonObject obj = json.object();
    QJsonArray arr;
    QJsonObject userData;
    if(obj.value("users").isArray())
    {
        arr = obj.value("users").toArray();
    }
    else
    {
        emit loginFailed();
        return false;
    }
    if(arr.at(0).isObject())
    {
        userData = arr.at(0).toObject();
        if(userData.isEmpty())
        {
            emit loginFailed();
            return false;
        }
    }
    else
    {
        emit loginFailed();
        return false;
    }
    emit loginSuccess();
    return true;
}
