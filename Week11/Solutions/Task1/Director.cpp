#include "Director.h"

void Director::copyEmployees(const std::unique_ptr<Employee>* source, int count) 
{
    employees = std::make_unique<std::unique_ptr<Employee>[]>(count);
    for (int i = 0; i < count; i++) 
    {
        employees[i] = std::unique_ptr<Employee>(source[i]->clone());
    }
}

Director::Director(): Employee(), secretary(), employees(nullptr), numEmployees(0) {}

Director::Director(const char* name, const char* EGN, const char* departmentName, double salary, const Secretary& secretary)
    : Employee(name, EGN, departmentName, salary), secretary(secretary), employees(nullptr), numEmployees(0) {}

Director::Director(const Director& other)
    : Employee(other), secretary(other.secretary), employees(nullptr), numEmployees(other.numEmployees) 
{
    if (numEmployees > 0) 
    {
        copyEmployees(other.employees.get(), numEmployees);
    }
}

Director& Director::operator=(const Director& other)
{
    if (this != &other) 
    {
        Employee::operator=(other);
        secretary = other.secretary;
        employees.reset(); 
        numEmployees = other.numEmployees;
        if (numEmployees > 0) {
            copyEmployees(other.employees.get(), numEmployees);
        }
    }
    return *this;
}

void Director::addEmployee(std::unique_ptr<Employee> employee)
{
    std::unique_ptr<std::unique_ptr<Employee>[]> temp(new std::unique_ptr<Employee>[numEmployees + 1]);
    for (int i = 0; i < numEmployees; i++) 
    {
        temp[i] = std::move(employees[i]);
    }
    temp[numEmployees] = std::move(employee);
    employees = std::move(temp);
    ++numEmployees;
}

double Director::calculateTotalSalary() const 
{
    double total = getSalary();  
    total += secretary.getSalary();
    for (int i = 0; i < numEmployees; i++) 
    {
        total += employees[i]->getSalary();
    }
    return total;
}

void Director::printInfo() const
{
    std::cout << "Director: \n";
    Employee::printInfo();
    std::cout <<"Secretary: \n";
    secretary.printInfo();
    std::cout << "Company Employees: \n";
    for (int i = 0; i < numEmployees; i++)
    {
        employees[i]->printInfo();
    }
}

Director* Director::clone() const  
{ 
    Director* newObj =  new Director(*this);
    return newObj;
}