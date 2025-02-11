#ifndef CHOOSEDATASOURCE_H
#define CHOOSEDATASOURCE_H
#include <QListWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QWidget>
#include "enternumberofpeople.h"
#include "choosesortingmethod.h"
#include "ISorter.h"
#include "QuickSorter.h"
#include "MergeSorter.h"
#include "SelectionSorter.h"
#include "sorteddatadisplay.h"
#include <QFileDialog>
#include "persongenerator.h"
#include "MergeSorterOpt.h"

namespace Ui {
class ChooseDataSource;
}

class ChooseDataSource : public QDialog
{
    Q_OBJECT
public:
    explicit ChooseDataSource(QWidget *parent = nullptr);
    ~ChooseDataSource();
    void updateDataDisplay(MutableArraySequence<Person>* seq);
private slots:
    void on_randomDataButton_clicked();
    void on_readFromFileButton_clicked();

private:
    Ui::ChooseDataSource *ui;
    EnterNumberOfPeople *enterNumberOfPeopleWindow;
    MutableArraySequence<Person> loadPeopleFromFile(const std::string& filename);
};

#endif // CHOOSEDATASOURCE_H
