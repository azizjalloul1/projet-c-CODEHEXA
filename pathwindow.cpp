#include "PathWindow.h"
#include <QQuickWidget>
#include <QQmlContext>

PathWindow::PathWindow(QGeoCoordinate from, QGeoCoordinate to, QWidget *parent)
    : QMainWindow(parent)
{
    QQuickWidget *view = new QQuickWidget;
    view->setResizeMode(QQuickWidget::SizeRootObjectToView);

    view->rootContext()->setContextProperty("fromCoord", QVariant::fromValue(from));
    view->rootContext()->setContextProperty("toCoord", QVariant::fromValue(to));

    view->setSource(QUrl(QStringLiteral("qrc:/PathView.qml")));
    setCentralWidget(view);
    resize(1000, 700);
    setWindowTitle("Trajet entre utilisateur et établissement");
}

PathWindow::~PathWindow() {}
