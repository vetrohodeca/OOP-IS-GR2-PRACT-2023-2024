#include "Student.h"
#include <cstring>



Student::Student(const char* name, int age, bool isMale, const char* universityName, const char* FN, const char* major, Degree degree)
    : Person(name, age, isMale), degree(degree) 
{
    this->universityName = new char[strlen(universityName) + 1];
    strcpy(this->universityName, universityName);
    this->FN = new char[strlen(FN) + 1];
    strcpy(this->FN, FN);
    this->major = new char[strlen(major) + 1];
    strcpy(this->major, major);
}

Student::Student(const Student& other) : Person(other) 
{
    copyFrom(other);
}

Student& Student::operator=(const Student& other) 
{
    if (this != &other) 
    {
        Person::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Student::~Student() 
{
    free();
}

Degree Student::getDegree() const
{
    return this->degree;
}

char* Student::getUniversity() const
{
    return this->universityName;
}

void Student::copyFrom(const Student& other)
{
    universityName = new char[strlen(other.universityName) + 1];
    strcpy(universityName, other.universityName);
    FN = new char[strlen(other.FN) + 1];
    strcpy(FN, other.FN);
    major = new char[strlen(other.major) + 1];
    strcpy(major, other.major);
    degree = other.degree;
}

void Student::free() 
{
    delete[] universityName;
    delete[] FN;
    delete[] major;
}