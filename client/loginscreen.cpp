#include "loginscreen.h"

loginScreen::loginScreen(QObject *parent) : QObject(parent)
{

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
