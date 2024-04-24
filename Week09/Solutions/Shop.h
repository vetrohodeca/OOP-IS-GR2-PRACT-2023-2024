#pragma once
#include "Product.h"
class Shop 
{
	MyString name;
	Product** productList;
	size_t capacity; 
	size_t size = 0; 

	void free();
	void copyFrom(const Shop& other);
	void resize(size_t newCap);
	
public: 
	Shop();
	Shop(const MyString& shopName);
	Shop(const Shop& other);
	Shop& operator=(const Shop& other);
	~Shop();

	void setName(const MyString&);
	MyString getName() const;
	unsigned getSize() const;
	Product** getProductList() const;

	void addProducts(Product** productList);
    void removeProduct(Product& product);
};