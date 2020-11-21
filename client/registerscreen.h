#ifndef REGISTERSCREEN_H
#define REGISTERSCREEN_H

#include <QObject>
#include <QtQml>

class registerScreen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword)
    QML_ELEMENT

    QString _username;
    QString _password;
public:
    explicit registerScreen(QObject *parent = nullptr);

    //getters
    inline const QString getUsername() const { return this->_username; }
    inline const QString getPassword() const { return this->_password; }

    //setters
    void setUsername(const QString& username) { this->_username = username; }
    void setPassword(const QString& password) { this->_password = password; }

    // functions from QML
    Q_INVOKABLE void activate();
    Q_INVOKABLE void deactivate();
    Q_INVOKABLE void Register(QString username,QString password, QString confirmedPassword);

signals:
    // signals to c++
    void sendQuery(QString query);


    // signals to QML
    void loginSuccess();
    void loginFailed();
    void differentPasswords();

public slots:
    // slots from C++
    bool handleResponse(const QJsonDocument& json);
    //slots from QML
};

#endif // REGISTERSCREEN_H
