#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_BEGIN_NAMESPACE
namespace Ui { class StatsWindow; }
QT_END_NAMESPACE

class StatsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatsWindow(QWidget *parent = nullptr);
    ~StatsWindow();

private:
    Ui::StatsWindow *ui;
};

#endif // STATSWINDOW_H
