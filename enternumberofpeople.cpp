#include "enternumberofpeople.h"
#include "ui_enternumberofpeople.h"

#include <QMessageBox>
#include "choosesortingmethod.h"
#include "choosedatasource.h"


EnterNumberOfPeople::EnterNumberOfPeople(QWidget *parent) : QDialog(parent) {
    QLabel *label = new QLabel("Enter number of people:", this);
    numberInput = new QLineEdit(this);
    enterButton = new QPushButton("Enter", this);
    connect(enterButton, &QPushButton::clicked, this, &EnterNumberOfPeople::on_enterButton_clicked);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(numberInput);
    layout->addWidget(enterButton);
    setLayout(layout);
}

int EnterNumberOfPeople::getNumberOfPeople() const {
    return numberInput->text().toInt();
}

EnterNumberOfPeople::~EnterNumberOfPeople()
{
    delete ui;
}

void EnterNumberOfPeople::on_enterButton_clicked()
{
    bool ok;
    int number = numberInput->text().toInt(&ok);
    if (ok && number > 0) {
        accept();
    }
}

