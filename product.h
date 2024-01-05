#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>

class Product
{
public:
    Product();
    Product(QString _name, unsigned _count, unsigned _price);

    void setName(QString& _name);
    QString getName() const;

    void setCount(unsigned _count);
    unsigned getCount() const;

    void setPrice(unsigned _price);
    unsigned getPrice() const;

private:
    QString name;
    unsigned count;
    unsigned price;
};

#endif // PRODUCT_H
