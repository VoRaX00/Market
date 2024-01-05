#ifndef MARKETWINDOW_H
#define MARKETWINDOW_H

#include <QMainWindow>
#include "product.h"

namespace Ui {
class MarketWindow;
}

class MarketWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MarketWindow(QWidget *parent = nullptr);
    ~MarketWindow();

private slots:
    void on_pushButton_clicked();

private:
    void drawProduct();
    void readFile();

private:
    QList<Product> products;
    Ui::MarketWindow *ui;
};

#endif // MARKETWINDOW_H
