#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QObject>
#include <QtQml>

class loginScreen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword)
    QML_ELEMENT

    QString _username;
    QString _password;
public:
    explicit loginScreen(QObject *parent = nullptr);

    //getters
    inline const QString getUsername() const { return this->_username; }
    inline const QString getPassword() const { return this->_password; }

    //setters
    void setUsername(const QString& username) { this->_username = username; }
    void setPassword(const QString& password) { this->_password = password; }

signals:
    void sendQuery(const QString& query);
    void faultyLogin();
    void loginSuccess();
    void loginFailed();

public slots:
    bool handleResponse(const QJsonDocument& json);

};

#endif // LOGINSCREEN_H
