#ifndef PATHWINDOW_H
#define PATHWINDOW_H

#include <QQuickView>
#include <QGeoCoordinate>
#include <QQmlApplicationEngine>
#include <QWidget>

class PathWindow {
public:
    static void showPath(const QGeoCoordinate &from, const QGeoCoordinate &to);
};

#endif // PATHWINDOW_H
