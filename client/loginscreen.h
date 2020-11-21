#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QObject>
#include <QtQml>

class loginScreen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername)
    QML_ELEMENT

    QString _username;
public:
    explicit loginScreen(QObject *parent = nullptr);

    //getters
    inline const QString getUsername() const { return this->_username; }

    //setters
    void setUsername(const QString& username) { this->_username = username; }

signals:
    void sendQuery(const QString& query);
};

#endif // LOGINSCREEN_H
