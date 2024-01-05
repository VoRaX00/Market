#include "product.h"

Product::Product()
{

}

Product::Product(QString _name, unsigned int _count, unsigned int _price) : name(_name), count(_count), price(_price){}

void Product::setName(QString &_name)
{
    name = _name;
}

QString Product::getName() const
{
    return name;
}

void Product::setCount(unsigned _count)
{
    count = _count;
}

unsigned Product::getCount() const
{
    return count;
}

void Product::setPrice(unsigned int _price)
{
    price = _price;
}

unsigned int Product::getPrice() const
{
    return price;
}
