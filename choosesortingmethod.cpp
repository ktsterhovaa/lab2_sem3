#include "choosesortingmethod.h"
#include "ui_choosesortingmethod.h"


ChooseSortingMethod::ChooseSortingMethod(QWidget *parent) : QDialog(parent) {
    QLabel *sortMethodLabel = new QLabel("Choose sorting method:", this);
    sortMethodComboBox = new QComboBox(this);
    sortMethodComboBox->addItem("Quick Sort");
    sortMethodComboBox->addItem("Selection Sort");
    sortMethodComboBox->addItem("Merge Sort");
    QLabel *sortParameterLabel = new QLabel("Choose sorting parameter:", this);
    sortParameterComboBox = new QComboBox(this);
    sortParameterComboBox->addItem("Name");
    sortParameterComboBox->addItem("Surname");
    sortParameterComboBox->addItem("Birth Year");
    sortParameterComboBox->addItem("Height");
    sortParameterComboBox->addItem("Weight");
    confirmButton = new QPushButton("Confirm", this);
    connect(confirmButton, &QPushButton::clicked, this, &ChooseSortingMethod::on_confirmButton_clicked);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(sortMethodLabel);
    layout->addWidget(sortMethodComboBox);
    layout->addWidget(sortParameterLabel);
    layout->addWidget(sortParameterComboBox);
    layout->addWidget(confirmButton);
    setLayout(layout);
}

QString ChooseSortingMethod::getSelectedSortType() const {
    return sortMethodComboBox->currentText();
}

QString ChooseSortingMethod::getSelectedSortParameter() const {
    return sortParameterComboBox->currentText();
}
ChooseSortingMethod::~ChooseSortingMethod()
{
    delete ui;
}

void ChooseSortingMethod::on_confirmButton_clicked()
{
    accept();
}
