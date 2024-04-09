#pragma once
#include "Product.h"

class ShopingCart {
	Product* products = nullptr;
	unsigned capacity = 8;
	unsigned size = 0;

	void free();
	void copy(const ShopingCart& other);
	void resize(unsigned newCapacity);

public:
	ShopingCart();
	ShopingCart(const ShopingCart& other);
	ShopingCart& operator=(const ShopingCart& other);
	~ShopingCart();

	void addProduct(const Product& toAdd);
	void removeProduct(const Product& toRemove);

	void print() const;
	double calculateSum() const;
};
