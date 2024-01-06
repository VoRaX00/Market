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

    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(addProductInList(QModelIndex)));
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
    file.close();
}

void MarketWindow::addProductInList(QModelIndex index){
    QAbstractItemModel* model = ui->tableView->model();
    int row = index.row();
    const int countColumn = 3;
    QStringList list;
    for(int i=0; i < countColumn; i++){
        QModelIndex idx = model->index(row, i);
        QVariant data = model->data(idx);
        list.append(data.toString());
        if(i==1 && data.toInt() != 0){
            model->setData(idx, QVariant(data.toInt() - 1));
        }else if(i== 1 && data.toInt() == 0){
            return;
        }
    }
    Product p(list.at(0), list.at(2).toUInt());
    buyProducts[p]++;

    qDebug() << p.getName() << p.getCount() << p.getPrice();
    qDebug() << buyProducts[p];
}

void MarketWindow::on_orderButton_clicked()
{
    if(buyProducts.empty())
        return;

    QFile file(":/purchase/cheque.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append)){
        QTextStream stream(&file);

        for(auto i : buyProducts.keys()){
            QString date = "";
            date += i.getName();

        }
    }
    else{
        qDebug() << "file don't open!";
    }
}

