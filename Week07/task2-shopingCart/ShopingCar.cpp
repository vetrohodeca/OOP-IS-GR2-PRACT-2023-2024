#include "ShopingCar.h"

void ShopingCart::print() const
{
    for (int i = 0; i < size; i++)
    {
        products[i].printProduct();
    }
}

double ShopingCart::calculateSum() const
{
    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum += products[i].calculateSumPrice();
    }

    return sum;
}

void ShopingCart::free()
{
    delete[] products;
}

void ShopingCart::copy(const ShopingCart& other)
{
    products = new Product[other.capacity];

    for (int i = 0; i < other.size;i++)
    {
        products[i] = other.products[i];
    }

    size = other.size;
    capacity = other.capacity;
}

void ShopingCart::resize(unsigned newCapacity)
{
    Product* temp = new Product[newCapacity];

    for (int i = 0; i < size; i++)
    {
        temp[i] = products[i];
    }

    capacity = newCapacity;
    free();
    products = temp;
}

ShopingCart::ShopingCart()
{
    products = new Product[capacity];
}

ShopingCart::ShopingCart(const ShopingCart& other)
{
    copy(other);
}

ShopingCart& ShopingCart::operator=(const ShopingCart& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }

    return *this;
}

ShopingCart::~ShopingCart()
{
    free();
}

void ShopingCart::addProduct(const Product& toAdd)
{
    if (size >= capacity)
    {
        resize(capacity * 2);
    }

    products[size++] = toAdd;
}

void ShopingCart::removeProduct(const Product& toRemove)
{
    for (int i = 0; i < size; i++)
    {
        if (products[i].getName() == toRemove.getName())
        {
            Product temp = products[i];
            products[i] = products[size];
            products[i] = temp;
            size--;

            return;
        }
    }
}
