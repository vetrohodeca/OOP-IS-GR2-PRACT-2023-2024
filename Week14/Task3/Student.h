#pragma once
#include "Athlete.h"

enum Degree {
    Bachelor,
    Master,
    PhD
};

class Student : virtual  public Person {
    void copyFrom(const Student& other);
    void free();
protected:
    char* universityName;
    char* FN;
    char* major;
    Degree degree;

public:
    const int startAge = 19;
    Student(const char* name, int age, bool isMale, const char* universityName, const char* FN, const char* major, Degree degree);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    Degree getDegree() const;
    char* getUniversity() const;
};
