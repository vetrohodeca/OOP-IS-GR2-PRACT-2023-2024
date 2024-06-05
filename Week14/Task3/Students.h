#pragma once
#include "StudentAthlete.h"

class Students {
    StudentAthlete* students;
    int size;
    int capacity;

    void copyFrom(const Students& other);
    void free();
    void resize();

public:
    Students();
    Students(const Students& other);
    Students& operator=(const Students& other);
    ~Students();

    void addStudent(const StudentAthlete& student);
    void printBestTeam(const char* sportName, const char* universityName);
};
