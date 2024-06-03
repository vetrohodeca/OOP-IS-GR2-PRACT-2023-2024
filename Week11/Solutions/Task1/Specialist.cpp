#include "Specialist.h"

Specialist::Specialist(): Employee()
{
    setSpecialty("");
}

Specialist::Specialist(const char* name, const char* EGN, const char* departmentName, double salary, const char* specialty)
    : Employee(name, EGN, departmentName, salary), specialty(nullptr) 
{
    setSpecialty(specialty);
}

Specialist::Specialist(const Specialist& other)
    : Employee(other), specialty(nullptr) 
{
    setSpecialty(other.specialty);
}

Specialist& Specialist::operator=(const Specialist& other) 
{
    if (this != &other) {
        Employee::operator=(other);
        setSpecialty(other.specialty);
    }
    return *this;
}

Specialist::~Specialist() 
{
    delete[] specialty;
}

void Specialist::setSpecialty(const char* newSpecialty) 
{
    delete[] specialty;
    if (newSpecialty) 
    {
        specialty = new char[strlen(newSpecialty) + 1];
        strcpy(specialty, newSpecialty);
    }
    else 
    {
        specialty = nullptr;
    }
}

void Specialist::printInfo() const 
{
    Employee::printInfo();
    std::cout << "Specialty: " << specialty;
}

double Specialist::getSalary()
{
    return salary;
}