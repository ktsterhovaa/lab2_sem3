#ifndef ENTERNUMBEROFPEOPLE_H
#define ENTERNUMBEROFPEOPLE_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "persongenerator.h"
#include "choosesortingmethod.h"

namespace Ui {
class EnterNumberOfPeople;
}

class EnterNumberOfPeople : public QDialog
{
    Q_OBJECT

public:
    explicit EnterNumberOfPeople(QWidget *parent = nullptr);
    ~EnterNumberOfPeople();
    int getNumberOfPeople() const;

private slots:
    void on_enterButton_clicked();

private:
    Ui::EnterNumberOfPeople *ui;
    QLineEdit *numberInput;
    QPushButton *enterButton;
};

#endif // ENTERNUMBEROFPEOPLE_H
