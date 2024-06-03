#pragma once
#include <memory>
#include "Specialist.h"

class HeadOfDepartment : public Specialist {
private:
    char* managedDepartment;
    std::unique_ptr<std::unique_ptr<Employee>[]> departmentEmployees;
    int numEmployees;

    void copyEmployees(const std::unique_ptr<Employee>* source, int count);

public:
    HeadOfDepartment();
    HeadOfDepartment(const char* name, const char* EGN, const char* departmentName, double salary, const char* specialty, const char* managedDepartment);
    HeadOfDepartment(const HeadOfDepartment& other);
    HeadOfDepartment& operator=(const HeadOfDepartment& other);
    ~HeadOfDepartment();
    void setManagedDepartment(const char* newManagedDepartment);
    void addEmployee(std::unique_ptr<Employee> employee);
    void printInfo() const; 
    double getSalary() const;
};
