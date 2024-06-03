#pragma once
#include <memory>
#include "Secretary.h"

class Director : public Employee {
private:
    Secretary secretary;
    std::unique_ptr<std::unique_ptr<Employee>[]> employees;
    int numEmployees;

    void copyEmployees(const std::unique_ptr<Employee>* source, int count);

public:
    Director();
    Director(const char* name = "", const char* EGN = "", const char* departmentName = "", double salary = 0.0, const Secretary& secretary = Secretary());
    Director(const Director& other);
    Director& operator=(const Director& other);
    ~Director() = default;

    void addEmployee(std::unique_ptr<Employee> employee);
    double calculateTotalSalary() const;
    void printInfo() const;
};
