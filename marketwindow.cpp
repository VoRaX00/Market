#include "marketwindow.h"
#include "ui_marketwindow.h"
#include <fstream>
#include <QRegularExpression>
#include <QDebug>
#include <string>
#include <QFile>

MarketWindow::MarketWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarketWindow)
{
    ui->setupUi(this);
}

MarketWindow::~MarketWindow()
{
    delete ui;
}

void MarketWindow::drawProduct()
{
    readFile();
}

void MarketWindow::readFile()
{
    QFile file(":/available/product.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!file.atEnd()){
            QString str = file.readLine();
            Product product;

            QString name = str.left(str.indexOf(" - "));
            str = str.right(str.size() - str.indexOf(" - ") - 3);
            product.setName(name);

            product.setCount(str.left(str.indexOf(" | ")).toUInt());
            str = str.right(str.size() - str.indexOf(" | ") - 3);

            product.setPrice(str.toUInt());

            products.append(product);
        }
    }
    else{
        qDebug() << "file don't open";
    }

}

void MarketWindow::on_pushButton_clicked()
{
    drawProduct();
}

