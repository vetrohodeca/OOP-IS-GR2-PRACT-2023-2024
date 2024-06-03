#include "Director.h"
#include "HeadOfDepartment.h"
#include <iostream>

int main() {
    const char* languages[] = { "English", "French", "German" };
    Secretary secretary("Georgi Petrov", "0987654321", "Administration", 50000, languages, 3);

    Director director("Diyana Georgieva", "1234567890", "Management", 100000, secretary);

    HeadOfDepartment headOfDept("Kaloyan Boyanov", "5566778899", "IT", 90000, "IT Management", "IT Department");

    Specialist specialist1("Ivan Simeonov", "1122334455", "IT", 70000, "Software Engineering");
    Specialist specialist2("Boris Nikolov", "9988776655", "IT", 65000, "Network Engineering");
    Specialist specialist3("Rangel Conev", "9988776644", "IT", 55000, "Data Engineering");

    headOfDept.addEmployee(std::make_unique<Specialist>(specialist1));
    headOfDept.addEmployee(std::make_unique<Specialist>(specialist2));
    headOfDept.addEmployee(std::make_unique<Specialist>(specialist3));

    director.addEmployee(std::make_unique<HeadOfDepartment>(headOfDept));

    std::cout << "Company Information:" << std::endl;
    director.printInfo();
    std::cout <<std::endl<< "Total Salary Required: " << director.calculateTotalSalary() << std::endl;

    return 0;
}
