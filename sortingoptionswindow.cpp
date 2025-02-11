#include "sortingoptionswindow.h"
#include "ui_sortingoptionswindow.h"

SortingOptionsWindow::SortingOptionsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SortingOptionsWindow)
{
    ui->setupUi(this);
}

SortingOptionsWindow::~SortingOptionsWindow()
{
    delete ui;
}

QString SortingOptionsWindow::getSortingMethod() const {
    return ui->sortingMethodComboBox->currentText();
}

QString SortingOptionsWindow::getSortingParameter() const {
    return ui->sortingParameterComboBox->currentText();
}

int SortingOptionsWindow::getStep() const {
    return ui->stepSpinBox->value();
}

int SortingOptionsWindow::getMaxLength() const {
    return ui->maxLengthSpinBox->value();
}

void SortingOptionsWindow::on_confirmButton_clicked() {
    emit optionsConfirmed(getSortingMethod(), getSortingParameter(), getStep(), getMaxLength());

    accept();
}
