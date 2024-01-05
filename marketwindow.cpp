#include "marketwindow.h"
#include "ui_marketwindow.h"

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
