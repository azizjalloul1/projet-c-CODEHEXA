#include "statswindow.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>

StatsWindow::StatsWindow(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Statistiques des Établissements");

    resize(700, 500); // 💡 Taille agrandie
    QPieSeries *series = new QPieSeries();

    QSqlQuery query("SELECT TYPE_ETABLISSEMENT, COUNT(*) FROM ETABLISSEMENT GROUP BY TYPE_ETABLISSEMENT");

    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(type, count);
    }

    for (QPieSlice *slice : series->slices()) {
        slice->setLabel(QString("%1 (%2%)")
                            .arg(slice->label())
                            .arg(slice->percentage() * 100.0, 0, 'f', 1));
        slice->setLabelVisible(true);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des types d'établissements");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
}

StatsWindow::~StatsWindow() {}
