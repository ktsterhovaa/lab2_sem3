#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testSortersButton_clicked()
{
    hide();
    chooseDataSourceWindow = new ChooseDataSource(this);
    chooseDataSourceWindow->show();
}

void MainWindow::on_testSortingTimeButton_clicked()
{
    hide();
    SortingOptionsWindow *optionsWindow = new SortingOptionsWindow(this);
    connect(optionsWindow, &SortingOptionsWindow::optionsConfirmed, this, &MainWindow::showSortingGraphs);
    optionsWindow->exec();
    delete optionsWindow;
}

void MainWindow::showSortingGraphs(const QString &sortingMethod, const QString &sortingParameter, int step, int maxLength) {
    PersonGenerator personGenerator;
    QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries();
    std::function<int(const Person&, const Person&)> cmp;
    if (sortingParameter == "Name") {
        cmp = [](const Person &a, const Person &b) {
            return a.name.compare(b.name);
        };
    } else if (sortingParameter == "Surname") {
        cmp = [](const Person &a, const Person &b) {
            return a.surname.compare(b.surname);
        };
    } else if (sortingParameter == "Birth Year") {
        cmp = [](const Person &a, const Person &b) {
            return a.birthYear - b.birthYear;
        };
    } else if (sortingParameter == "Height") {
        cmp = [](const Person &a, const Person &b) {
            return (a.height < b.height) ? -1 : (a.height > b.height) ? 1 : 0;
        };
    } else if (sortingParameter == "Weight") {
        cmp = [](const Person &a, const Person &b) {
            return (a.weight < b.weight) ? -1 : (a.weight > b.weight) ? 1 : 0;
        };
    }
    for (int length = step; length <= maxLength; length += step) {
        MutableArraySequence<Person> people;
        personGenerator.generateRandomPerson(&people, length);
        auto start = std::chrono::high_resolution_clock::now();
        if (sortingMethod == "Quick Sort") {
            QuickSorter<Person> sorter;
            sorter.Sort(&people, cmp);
        } else if (sortingMethod == "Merge Sort") {
            MergeSorter<Person> sorter;
            sorter.Sort(&people, cmp);
        } else if (sortingMethod == "Selection Sort") {
            SelectionSorter<Person> sorter;
            sorter.Sort(&people, cmp);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        series->append(length, elapsed.count());
    }
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Sorting Time vs Number of Elements");
    chart->axes(Qt::Horizontal).first()->setTitleText("Number of Elements");
    chart->axes(Qt::Vertical).first()->setTitleText("Time (seconds)");
    QWidget *chartWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(chartWidget);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);
    chartWidget->setLayout(layout);
    chartWidget->resize(800, 600);
    chartWidget->show();
}
