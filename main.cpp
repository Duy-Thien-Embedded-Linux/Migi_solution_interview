#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "studentmodel.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    StudentModel studentModel;
    engine.rootContext()->setContextProperty("studentModel", &studentModel);
    engine.load(QUrl(QStringLiteral("qrc:/Student_Management/main.qml")));

    return app.exec();
}
