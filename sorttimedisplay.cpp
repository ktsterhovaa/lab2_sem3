#include "sorttimedisplay.h"
#include "ui_sorttimedisplay.h"
#
SortTimeDisplay::SortTimeDisplay(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SortTimeDisplay)
{
    ui->setupUi(this);
}

SortTimeDisplay::~SortTimeDisplay()
{
    delete ui;
}
void SortTimeDisplay::setOutput(const QString &output) {
    ui->outputTextEdit->setPlainText(output);
}
