#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QObject>
#include <qqml.h>

class loginScreen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername)
    QML_ELEMENT
public:
    explicit loginScreen(QObject *parent = nullptr);

    //getters
    inline const QString getUsername() const;

    //setters
    void setUsername(const QString& username);

signals:
    void sendQuery(const QString& query);
};

#endif // LOGINSCREEN_H
