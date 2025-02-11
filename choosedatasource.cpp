#include "choosedatasource.h"
#include "ui_choosedatasource.h"

ChooseDataSource::ChooseDataSource(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChooseDataSource)
{
    ui->setupUi(this);
}

ChooseDataSource::~ChooseDataSource()
{
    delete ui;
}

void ChooseDataSource::on_randomDataButton_clicked() {
    hide();
    EnterNumberOfPeople enterNumberOfPeopleWindow(this);
    if (enterNumberOfPeopleWindow.exec() == QDialog::Accepted) {
        int numberOfPeople = enterNumberOfPeopleWindow.getNumberOfPeople();
        MutableArraySequence<Person> *seq = new MutableArraySequence<Person>();
        PersonGenerator generator;
        generator.generateRandomPerson(seq, numberOfPeople);
        ChooseSortingMethod sortingMethodDialog(this);
        if (sortingMethodDialog.exec() == QDialog::Accepted) {
            QString selectedSortType = sortingMethodDialog.getSelectedSortType();
            QString selectedSortParameter = sortingMethodDialog.getSelectedSortParameter();
            std::function<int(const Person&, const Person&)> cmp = nullptr;
            if (selectedSortParameter == "Name") {
                cmp = [](const Person& a, const Person& b) { return a.name.compare(b.name); };
            } else if (selectedSortParameter == "Surname") {
                cmp = [](const Person& a, const Person& b) { return a.surname.compare(b.surname); };
            } else if (selectedSortParameter == "Birth Year") {
                cmp = [](const Person& a, const Person& b) { return a.birthYear < b.birthYear; };
            } else if (selectedSortParameter == "Height") {
                cmp = [](const Person& a, const Person& b) { return a.height < b.height; };
            } else if (selectedSortParameter == "Weight") {
                cmp = [](const Person& a, const Person& b) { return a.weight < b.weight; };
            }
            if (!cmp) {

                delete seq;
                return;
            }
            ISorter<Person>* sorter = nullptr;
            if (selectedSortType == "Quick Sort") {
                sorter = new QuickSorter<Person>();
            } else if (selectedSortType == "Selection Sort") {
                sorter = new SelectionSorter<Person>();
            } else if (selectedSortType == "Merge Sort") {
                sorter = new MergeSorter<Person>();
            }
            if (sorter) {
                sorter->Sort(seq, cmp);
                delete sorter;
            }
            updateDataDisplay(seq);
        }
        delete seq;
    }
}

void ChooseDataSource::updateDataDisplay(MutableArraySequence<Person>* seq) {
    SortedDataDisplay *sortedDataDisplay = new SortedDataDisplay(this);
    sortedDataDisplay->displayData(seq);
    sortedDataDisplay->exec();
}

void ChooseDataSource::on_readFromFileButton_clicked()
{
    hide();
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    if (filename.isEmpty()) {
        return;
    }
    PersonGenerator generator;
    MutableArraySequence<Person> people = generator.loadPeopleFromFile(filename.toStdString());
    ChooseSortingMethod sortingMethodDialog(this);
    if (sortingMethodDialog.exec() == QDialog::Accepted) {
        QString selectedSortType = sortingMethodDialog.getSelectedSortType();
        QString selectedSortParameter = sortingMethodDialog.getSelectedSortParameter();
        std::function<int(const Person&, const Person&)> cmp = nullptr;

        if (selectedSortParameter == "Name") {
            cmp = [](const Person& a, const Person& b) { return a.name.compare(b.name); };
        } else if (selectedSortParameter == "Surname") {
            cmp = [](const Person& a, const Person& b) { return a.surname.compare(b.surname); };
        } else if (selectedSortParameter == "Birth Year") {
            cmp = [](const Person& a, const Person& b) { return a.birthYear < b.birthYear; };
        } else if (selectedSortParameter == "Height") {
            cmp = [](const Person& a, const Person& b) { return a.height < b.height; };
        } else if (selectedSortParameter == "Weight") {
            cmp = [](const Person& a, const Person& b) { return a.weight < b.weight; };
        }
        ISorter<Person>* sorter = nullptr;
        if (selectedSortType == "Quick Sort") {
            sorter = new QuickSorter<Person>();
        } else if (selectedSortType == "Selection Sort") {
            sorter = new SelectionSorter<Person>();
        } else if (selectedSortType == "Merge Sort") {
            sorter = new MergeSorter<Person>();
        }
        if (sorter) {
            sorter->Sort(&people, cmp);

            delete sorter;
        }
        updateDataDisplay(&people);
    }
}
