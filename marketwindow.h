#ifndef MARKETWINDOW_H
#define MARKETWINDOW_H

#include <QMainWindow>

namespace Ui {
class MarketWindow;
}

class MarketWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MarketWindow(QWidget *parent = nullptr);
    ~MarketWindow();

private:
    Ui::MarketWindow *ui;
};

#endif // MARKETWINDOW_H
