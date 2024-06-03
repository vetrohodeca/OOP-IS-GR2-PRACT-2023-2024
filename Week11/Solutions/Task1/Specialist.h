#pragma once
#include "Employee.h"

class Specialist : public Employee {
private:
    char* specialty;

public:
    Specialist();
    Specialist(const char* name, const char* EGN, const char* departmentName, double salary, const char* specialty);
    Specialist(const Specialist& other);
    Specialist& operator=(const Specialist& other);
    ~Specialist();

    void setSpecialty(const char* newSpecialty);
    double getSalary();
    void printInfo() const;
};