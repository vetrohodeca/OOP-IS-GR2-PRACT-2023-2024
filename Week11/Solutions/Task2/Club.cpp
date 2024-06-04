#include "Club.h"
#include <cstring>
#pragma warning(disable : 4996)

void Club::copyFrom(const Club& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    currentVisitorsCount = other.currentVisitorsCount;
    capacity = other.capacity;
    vodkaPrice = other.vodkaPrice;
    whiskeyPrice = other.whiskeyPrice;
}

void Club::free() 
{
    delete[] name;
}

Club::Club() : name(nullptr), currentVisitorsCount(0), capacity(0), vodkaPrice(0), whiskeyPrice(0) {}

Club::Club(const char* name, int currentVisitorsCount, int capacity)
    : currentVisitorsCount(currentVisitorsCount), capacity(capacity), vodkaPrice(0), whiskeyPrice(0) 
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Club::Club(const Club& other)
{
    copyFrom(other);
}

Club& Club::operator=(const Club& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Club::~Club() 
{
    free();
}

void Club::setName(const char* newName) 
{
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void Club::setCapacity(int newCapacity)
{
    capacity = newCapacity;
}
