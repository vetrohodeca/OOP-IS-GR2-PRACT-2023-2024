#pragma once
#include "Student.h"
#include "Athlete.h"

class StudentAthlete : public Student, public Athlete{
    char* coachName;
    int playedMatches;

    void copyFrom(const StudentAthlete& other);
    void free();

public:
    StudentAthlete(const char* name = "", int age = 0, bool isMale = true, const char* sport = "", int rank = 0, int experienceYears = 0, bool isProfessional = false, const char* universityName = "", const char* FN = "", const char* major = "", Degree degree = Bachelor, const char* coachName = "", int playedMatches = 0);
    StudentAthlete(const StudentAthlete& other);
    StudentAthlete& operator=(const StudentAthlete& other);
    ~StudentAthlete();
};