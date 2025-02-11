#ifndef SORTINGOPTIONSWINDOW_H
#define SORTINGOPTIONSWINDOW_H

#include <QDialog>

namespace Ui {
class SortingOptionsWindow;
}

class SortingOptionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SortingOptionsWindow(QWidget *parent = nullptr);
    ~SortingOptionsWindow();
    QString getSortingMethod() const;
    QString getSortingParameter() const;
    int getStep() const;
    int getMaxLength() const;

private slots:
    void on_confirmButton_clicked();
signals:
    void optionsConfirmed(const QString &sortingMethod, const QString &sortingParameter, int step, int maxLength);

private:
    Ui::SortingOptionsWindow *ui;
};

#endif // SORTINGOPTIONSWINDOW_H
