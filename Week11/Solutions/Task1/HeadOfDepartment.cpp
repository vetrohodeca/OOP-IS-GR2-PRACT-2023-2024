#include "HeadOfDepartment.h"

HeadOfDepartment::HeadOfDepartment() : Specialist(), managedDepartment(nullptr), departmentEmployees(nullptr), numEmployees(0) {}

HeadOfDepartment::HeadOfDepartment(const char* name, const char* EGN, const char* departmentName, double salary, const char* specialty, const char* managedDepartment)
	: Specialist(name, EGN, departmentName, salary, specialty), managedDepartment(nullptr), departmentEmployees(nullptr), numEmployees(0) 
{
	setManagedDepartment(managedDepartment);
}

HeadOfDepartment::HeadOfDepartment(const HeadOfDepartment& other)
	: Specialist(other), managedDepartment(nullptr), departmentEmployees(nullptr), numEmployees(other.numEmployees) 
{
	setManagedDepartment(other.managedDepartment);
	if (numEmployees > 0) 
	{
		copyEmployees(other.departmentEmployees.get(), numEmployees);
	}
}

HeadOfDepartment& HeadOfDepartment::operator=(const HeadOfDepartment& other) 
{
	if (this != &other) 
	{
		Specialist::operator=(other);
		setManagedDepartment(other.managedDepartment);

		departmentEmployees.reset(); 

		numEmployees = other.numEmployees;
		if (numEmployees > 0) {
			copyEmployees(other.departmentEmployees.get(), numEmployees);
		}
	}
	return *this;
}

HeadOfDepartment::~HeadOfDepartment() 
{
	delete[] managedDepartment;
}

void HeadOfDepartment::setManagedDepartment(const char* newManagedDepartment) 
{
	delete[] managedDepartment;
	if (newManagedDepartment) 
	{
		managedDepartment = new char[strlen(newManagedDepartment) + 1];
		strcpy(managedDepartment, newManagedDepartment);
	}
	else {
		managedDepartment = nullptr;
	}
}

void HeadOfDepartment::addEmployee(std::unique_ptr<Employee> employee) 
{
	std::unique_ptr<std::unique_ptr<Employee>[]> temp(new std::unique_ptr<Employee>[numEmployees + 1]);
	for (int i = 0; i < numEmployees; i++) 
	{
		temp[i] = std::move(departmentEmployees[i]);
	}
	temp[numEmployees] = std::move(employee);
	departmentEmployees = std::move(temp);
	++numEmployees;
}

void HeadOfDepartment::printInfo() const 
{
	Specialist::printInfo();
	std::cout << "\nManaged Department: " << managedDepartment << "\n";
	std::cout << "Employees in Department:\n";
	for (int i = 0; i < numEmployees; i++) 
	{
		departmentEmployees[i]->printInfo();
	}
}

double HeadOfDepartment::getSalary() const
{
	double total = this->salary;
	for (int i = 0; i < numEmployees; i++)
	{
		total += departmentEmployees[i]->getSalary();
	}
	return total;
}

void HeadOfDepartment::copyEmployees(const std::unique_ptr<Employee>* source, int count) {
	departmentEmployees = std::make_unique<std::unique_ptr<Employee>[]>(count);
	for (int i = 0; i < count; i++) 
	{
		departmentEmployees[i] = std::unique_ptr<Employee>(source[i]->clone());
	}
}

HeadOfDepartment* HeadOfDepartment::clone() const 
{
	HeadOfDepartment* newObj = new HeadOfDepartment(*this);
	return newObj;
}