#pragma once
#include<iostream>
#include"Customer.h"
#pragma warning(disable : 4996)

class Club
{
protected:
	char* name;
	int currentVisitorsCount;
	int capacity;
	double vodkaPrice;
	double whiskeyPrice;
private:
	void copyFrom(const Club& other);
	void free();
public:
	Club();
	Club(const char* name, int size, int capacity);
	Club(const Club& other);
	Club& operator= (const Club& other);
	~Club();

	void setName(const char* newName);
	void setCapacity(int newCapacity);
	virtual bool canEnter(const Customer& customer) = 0;
};

