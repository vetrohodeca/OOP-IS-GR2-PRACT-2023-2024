#include "Student.h"

void Student::copy(const Student& other)
{
    name = new char[strlen(other.name) + 1];

    strcpy(name, other.name);
    strcpy(facultyNumber, other.facultyNumber);
    specilaty = other.specilaty;
}

void Student::move(Student&& other)
{
    name = other.name;
    other.name = nullptr;

    specilaty = other.specilaty;
    other.specilaty = Specialty::DEFAULT;

    strcpy(facultyNumber, other.facultyNumber);
    other.facultyNumber[0] = '\0';
}

void Student::free()
{
    delete[] name;
}

Student::Student(const char* name, const char* facultyNumber, Specialty specialty)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    if (strlen(facultyNumber) > 9)
    {
        throw std::logic_error("Faculty number len must be less than 10");
    }

    strcpy(this->facultyNumber, facultyNumber);

    this->specilaty = specialty;
}

Student::Student(const Student& other)
{
    copy(other);
}

Student::Student(Student&& other)
{
    move(std::move(other));
}

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }

    return *this;
}

Student& Student::operator=(Student&& other)
{
    if (this != &other)
    {
        free();
        move(std::move(other));
    }
    return *this;
}

Student::~Student()
{
    free();
}
