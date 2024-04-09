#include "Product.h"

Product::Product(const std::string& name, double price, unsigned quantities) : name(name), quantities(quantities)
{
    setPrice(price);
}

std::string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

unsigned Product::getQuantities() const
{
    return quantities;
}

void Product::setName(const std::string& name)
{
    this->name = name;
}

void Product::setPrice(double price)
{
    if (price < 0.0)
    {
        price = 0.0;
    }

    this->price = price;
}

void Product::setQuantites(unsigned quantities)
{
    this->quantities = quantities;
}

double Product::calculateSumPrice() const
{
    return price * quantities;
}

void Product::printProduct() const
{
    std::cout << "Name: " << name << std::endl
        << "Price: " << price << std::endl <<
        "Quantites: " << quantities << std::endl;
}
