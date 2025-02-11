#ifndef SORTTIMEDISPLAY_H
#define SORTTIMEDISPLAY_H

#include <QDialog>

namespace Ui {
class SortTimeDisplay;
}

class SortTimeDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit SortTimeDisplay(QWidget *parent = nullptr);
    ~SortTimeDisplay();
    void setOutput(const QString &output);

private:
    Ui::SortTimeDisplay *ui;
};

#endif // SORTTIMEDISPLAY_H
