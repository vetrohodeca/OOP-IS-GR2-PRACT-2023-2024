#include "Secretary.h"

Secretary::Secretary()
    : Employee(), languages(nullptr), numLanguages(0) {}

Secretary::Secretary(const char* name, const char* EGN, const char* departmentName, double salary, const char** languages, int numLanguages)
    : Employee(name, EGN, departmentName, salary), languages(nullptr), numLanguages(numLanguages) 
{
    this->languages = new char* [numLanguages];
    for (int i = 0; i < numLanguages; i++) {
        this->languages[i] = new char[strlen(languages[i]) + 1];
        strcpy(this->languages[i], languages[i]);
    }
}

Secretary::Secretary(const Secretary& other)
    : Employee(other), languages(nullptr), numLanguages(other.numLanguages) 
{
    languages = new char* [numLanguages];
    for (int i = 0; i < numLanguages; i++) 
    {
        languages[i] = new char[strlen(other.languages[i]) + 1];
        strcpy(languages[i], other.languages[i]);
    }
}

Secretary& Secretary::operator=(const Secretary& other) 
{
    if (this != &other) 
    {
        Employee::operator=(other);
        for (int i = 0; i < numLanguages; i++)
        {
            delete[] languages[i];
        }
        delete[] languages;

        numLanguages = other.numLanguages;
        languages = new char* [numLanguages];
        for (int i = 0; i < numLanguages; i++)
        {
            languages[i] = new char[strlen(other.languages[i]) + 1];
            strcpy(languages[i], other.languages[i]);
        }
    }
    return *this;
}

Secretary::~Secretary()
{
    for (int i = 0; i < numLanguages; i++) {
        delete[] languages[i];
    }
    delete[] languages;
}

void Secretary::printInfo() const 
{
    Employee::printInfo();
    std::cout << "Languages: ";
    for (int i = 0; i < numLanguages; i++)
    {
        std::cout << languages[i] << " ";
    }
    std::cout << std::endl;
}

Secretary* Secretary::clone() const
{
    Secretary* newObj = new Secretary(*this);
    return newObj;
}