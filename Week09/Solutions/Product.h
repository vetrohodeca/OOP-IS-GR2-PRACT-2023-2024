#pragma once
#include"MyString.h"

enum Type {
	Food,
	Drink,
	Other
};
class Product
{
	MyString name;
	Type type;
	unsigned weight;
	unsigned count;
	float price;

public:
	Product(const MyString& name, Type type, unsigned weight, unsigned count, float price);
	Product();

	static unsigned differentProductsCount;
	static unsigned allProductsCount;

	MyString getName() const;
	Type getType() const;
	unsigned getWeight() const;
	unsigned getCount() const;
	float getPrice() const;

	void setName(const MyString&);
	void setType(Type);
	void setWeight(unsigned);
	void setCount(unsigned);
	void setPrice(float);

	void printProduct() const;
	static void addProduct(const Product&);
	static void sellProduct(const Product&, unsigned);
};
bool operator==(const Product& lhs, const Product& rhs);
