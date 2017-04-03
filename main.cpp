#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "PropertySpy.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<PropertySpy> ("PropertySpy", 1, 0, "PropertySpy");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
