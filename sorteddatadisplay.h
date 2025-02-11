#ifndef SORTEDDATADISPLAY_H
#define SORTEDDATADISPLAY_H
#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include "MutableArraySequence.h"
#include "Person.h"

namespace Ui {
class SortedDataDisplay;
}

class SortedDataDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit SortedDataDisplay(QWidget *parent = nullptr);
    ~SortedDataDisplay();
    void displayData(MutableArraySequence<Person>* seq);

private:
    Ui::SortedDataDisplay *ui;
    QListWidget *listWidget;
};

#endif // SORTEDDATADISPLAY_H
