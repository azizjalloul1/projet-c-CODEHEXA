#ifndef PATHWINDOW_H
#define PATHWINDOW_H

#include <QMainWindow>
#include <QGeoCoordinate>

class PathWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit PathWindow(QGeoCoordinate from, QGeoCoordinate to, QWidget *parent = nullptr);
    ~PathWindow();
};

#endif // PATHWINDOW_H
