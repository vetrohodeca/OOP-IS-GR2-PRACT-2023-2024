#include "Employee.h"

Employee::Employee()
    : name(nullptr), EGN(nullptr), departmentName(nullptr), salary(0.0) 
{
    setName("");
    setEGN("");
    setDepartmentName("");
}

Employee::Employee(const char* name, const char* EGN, const char* departmentName, double salary)
    : name(nullptr), EGN(nullptr), departmentName(nullptr), salary(salary) 
{
    setName(name);
    setEGN(EGN);
    setDepartmentName(departmentName);;
}

Employee::Employee(const Employee& other)
    : name(nullptr), EGN(nullptr), departmentName(nullptr), salary(other.salary) 
{
    copyFrom(other);
}

Employee& Employee::operator=(const Employee& other) 
{
    if (this != &other) 
    {
        copyFrom(other);
        salary = other.salary;
    }
    return *this;
}

Employee::~Employee()
{
    free();
}

void Employee::setName(const char* newName) 
{
    delete[] name;
    if (newName) 
    {
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
    else
    {
        name = nullptr;
    }
}

void Employee::setEGN(const char* newEGN) 
{
    delete[] EGN;
    if (newEGN) 
    {
        EGN = new char[strlen(newEGN) + 1];
        strcpy(EGN, newEGN);
    }
    else 
    {
        EGN = nullptr;
    }
}

void Employee::setDepartmentName(const char* newDepartmentName) 
{
    delete[] departmentName;
    if (newDepartmentName) 
    {
        departmentName = new char[strlen(newDepartmentName) + 1];
        strcpy(departmentName, newDepartmentName);
    }
    else 
    {
        departmentName = nullptr;
    }
}

double Employee::getSalary() const 
{
    return salary;
}

void Employee::printInfo() const 
{
    std::cout << "Name: " << name << "\nEGN: " << EGN << "\nDepartment: " << departmentName << "\nSalary: " << salary<<std::endl;
}

void Employee::copyFrom(const Employee& other)
{
    setName(other.name);
    setEGN(other.EGN);
    setDepartmentName(other.departmentName);
}

void Employee::free()
{
    delete[] name;
    delete[] EGN;
    delete[] departmentName;
}