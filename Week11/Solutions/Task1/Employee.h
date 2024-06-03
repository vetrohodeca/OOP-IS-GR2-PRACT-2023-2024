#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>

class Employee {
private:
    char* name;
    char* EGN;
    char* departmentName;

public:
    Employee();
    Employee(const char* name, const char* EGN, const char* departmentName, double salary);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    ~Employee();

    void setName(const char* newName);
    void setEGN(const char* newEGN);
    void setDepartmentName(const char* newDepartmentName);
    virtual double getSalary() const;
    virtual void printInfo() const;

protected:
    double salary;
};
