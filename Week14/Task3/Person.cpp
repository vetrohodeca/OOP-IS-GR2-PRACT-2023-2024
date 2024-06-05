#include "Person.h"


Person::Person(const char* name, int age, bool isMale) : age(age), isMale(isMale)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Person::Person(const Person& other)
{
    copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
    if (this != &other) 
    {
        free();
        copyFrom(other);
    }
    return *this;
}

void Person::copyFrom(const Person& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    age = other.age;
    isMale = other.isMale;
}

Person::~Person()
{
    free();
}

void Person::free()
{
    delete[] name;
}

int Person::getAge() const
{
    return this->age;
}

char* Person::getName() const
{
    return this->name;
}