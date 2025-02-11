#ifndef CHOOSESORTINGMETHOD_H
#define CHOOSESORTINGMETHOD_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class ChooseSortingMethod;
}

class ChooseSortingMethod : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseSortingMethod(QWidget *parent = nullptr);
    ~ChooseSortingMethod();
    QString getSelectedSortType() const;
    QString getSelectedSortParameter() const;

private slots:
    void on_confirmButton_clicked();
private:
    Ui::ChooseSortingMethod *ui;
    QComboBox *sortMethodComboBox;
    QComboBox *sortParameterComboBox;
    QPushButton *confirmButton;
};

#endif // CHOOSESORTINGMETHOD_H
