#pragma once
#pragma warning(disable : 4996)
#include <cstring>

class Person {
    void copyFrom(const Person& other);
    void free();
protected:
    char* name;
    int age;
    bool isMale;
public:
    Person(const char* name = "", int age = 0, bool isMale = true);
    Person(const Person& other);
    Person& operator=(const Person& other);
    virtual ~Person();
    int getAge() const;
    char* getName() const;
};