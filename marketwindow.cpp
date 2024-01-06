#include "marketwindow.h"
#include "ui_marketwindow.h"
#include <fstream>
#include <QRegularExpression>
#include <QDebug>
#include <string>
#include <QFile>
#include <QStandardItemModel>
#include <QStringListModel>

MarketWindow::MarketWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarketWindow)
{
    ui->setupUi(this);
    drawProduct();
}

MarketWindow::~MarketWindow()
{
    delete ui;
}

void MarketWindow::drawProduct()
{
    readFile();


    QStandardItemModel* model = new QStandardItemModel(this);

    QStringList nameColumn = {"Название" , "Количество" , "Цена"};
    model->setHorizontalHeaderLabels(nameColumn);

    ui->tableView->setModel(model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //блокировка возможности изменения ячеек внутри приложения
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //растягивает коллонки под размер таблицы


    QList<QStandardItem*>list;
    for(auto i : products){
        list.append(new QStandardItem(i.getName()));
        list.append(new QStandardItem(QString::number(i.getCount())));
        list.append(new QStandardItem(QString::number(i.getPrice())));
        model->appendRow(list);
        list.clear();
    }
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
