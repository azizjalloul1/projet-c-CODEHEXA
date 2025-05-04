#include "PathWindow.h"
#include <QQmlContext>
#include <QQuickView>

void PathWindow::showPath(const QGeoCoordinate &from, const QGeoCoordinate &to) {
    QQuickView *view = new QQuickView;
    view->setResizeMode(QQuickView::SizeRootObjectToView);

    QQmlContext *context = view->rootContext();
    context->setContextProperty("fromCoord", from);
    context->setContextProperty("toCoord", to);

    view->setSource(QUrl("qrc:/PathView.qml"));
    view->show();
}
