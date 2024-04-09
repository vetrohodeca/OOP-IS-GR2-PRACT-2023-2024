#pragma once
#include <iostream>
#include "string"

class Product {
	std::string name = "DEFAULT";
	double price = 0.0;
	unsigned quantities = 0;

public:
	Product(const std::string& name, double price, unsigned quantities);
	Product() = default;

	std::string getName() const;
	double getPrice() const;
	unsigned getQuantities() const;

	void setName(const std::string& name);
	void setPrice(double price);
	void setQuantites(unsigned quantities);

	double calculateSumPrice() const;
	void printProduct() const;
};
