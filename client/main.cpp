#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "network.h"
#include "loginscreen.h"
#include <QtQml>


int main(int argc, char *argv[])
{
    qmlRegisterType<loginScreen>("widgets",1,0,"Login");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    loginScreen login;
    engine.rootContext()->setContextProperty("login",&login);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);




    engine.load(url);
    network net(&app);
    return app.exec();
}
