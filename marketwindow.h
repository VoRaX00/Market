#ifndef MARKETWINDOW_H
#define MARKETWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QHash>
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

private:
    void drawProduct();
    void readFile();

public slots:
    void addProductInList(QModelIndex index);

private slots:
    void on_orderButton_clicked();

private:
    QList<Product> products;
    QHash<Product, unsigned> buyProducts;
    Ui::MarketWindow *ui;
};

#endif // MARKETWINDOW_H
