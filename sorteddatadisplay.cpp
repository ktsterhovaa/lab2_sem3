#include "sorteddatadisplay.h"
#include "ui_sorteddatadisplay.h"
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>

SortedDataDisplay::SortedDataDisplay(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SortedDataDisplay)
{
    setWindowTitle("Sorted Data");
    setFixedSize(400, 300);
    listWidget = new QListWidget(this);
    QPushButton *closeButton = new QPushButton("Close", this);
    connect(closeButton, &QPushButton::clicked, this, &SortedDataDisplay::accept);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
    layout->addWidget(closeButton);
    setLayout(layout);

}

SortedDataDisplay::~SortedDataDisplay()
{
    delete ui;
}
void SortedDataDisplay::displayData(MutableArraySequence<Person>* seq) {
    listWidget->clear();
    for (int i = 0; i < seq->getLength(); ++i) {
        const Person& person = seq->get(i);
        listWidget->addItem(QString::fromStdString(person.surname + " " + person.name + " " +
                                                   std::to_string(person.birthYear) + " " +
                                                   std::to_string(person.height) + " " +
                                                   std::to_string(person.weight)));
    }
}
