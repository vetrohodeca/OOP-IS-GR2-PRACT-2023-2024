#include  "Product.h"

unsigned Product::differentProductsCount = 0;
unsigned Product::allProductsCount = 0;

Product::Product() : name(""), type(Other), weight(0), count(0), price(0.0f)
{
}

Product::Product(const MyString& name, Type type, unsigned weight, unsigned count, float price)
	: name(name), type(type), weight(weight), count(count), price(price) 
{
}

MyString Product::getName() const
{
	return name;
}

Type Product::getType() const
{
	return type;
}

unsigned Product::getWeight() const
{
	return weight;
}

unsigned Product::getCount() const 
{
	return count;
}

float Product::getPrice() const 
{
	return price;
}

void Product::setName(const MyString& newName)
{
	name = newName;
}

void Product::setType(Type newType) {
	type = newType;
}

void Product::setWeight(unsigned newWeight) {
	weight = newWeight;
}

void Product::setCount(unsigned newCount)
{
	allProductsCount += newCount - count;
	count = newCount;
}

void Product::setPrice(float newPrice)
{
	price = newPrice;
}

void Product::printProduct() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Type: ";
	switch (type) {
	case Food:
		std::cout << "Food";
		break;
	case Drink:
		std::cout << "Drink";
		break;
	case Other:
		std::cout << "Other";
		break;
	}
	std::cout << std::endl;
	std::cout << "Weight: " << weight << "g" << std::endl;
	std::cout << "Count: " << count << std::endl;
	std::cout << "Price: $" << price << std::endl;
}

void Product::addProduct(const Product& product)
{
	differentProductsCount++;
	allProductsCount += product.count;
}

void Product::sellProduct(const Product& product, unsigned count) 
{
	if (count == product.count)
	{
		differentProductsCount--;
	}
	allProductsCount -= count;
}
bool operator==(const Product& lhs, const Product& rhs)
{
	return lhs.getName() == rhs.getName()
		&& lhs.getType() == rhs.getType()
		&& lhs.getWeight() == rhs.getWeight();
}
