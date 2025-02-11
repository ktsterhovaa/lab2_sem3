#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QVBoxLayout>
#include <QWidget>
#include <chrono>
#include "choosedatasource.h"
#include "choosesortingmethod.h"
#include "sortingoptionswindow.h"
#include "persongenerator.h"
#include "mergesorter.h"
#include "quicksorter.h"
#include "selectionsorter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_testSortersButton_clicked();
    void on_testSortingTimeButton_clicked();
    void showSortingGraphs(const QString &sortingMethod, const QString &sortingParameter, int step, int maxLength);

private:
    Ui::MainWindow *ui;
    ChooseDataSource *chooseDataSourceWindow;
    ChooseSortingMethod *chooseSortingMethodWindow;

};
#endif // MAINWINDOW_H
