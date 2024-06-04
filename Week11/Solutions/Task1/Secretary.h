#pragma once
#include "Employee.h"

class Secretary : public Employee {
private:
    char** languages;
    int numLanguages;

public:
    Secretary();
    Secretary(const char* name, const char* EGN, const char* departmentName, double salary, const char** languages, int numLanguages);
    Secretary(const Secretary& other);
    Secretary& operator=(const Secretary& other);
    ~Secretary();

    void printInfo() const;
    Secretary* clone() const override;
};
 