#include "StudentAthlete.h"
#include <cstring>

StudentAthlete::StudentAthlete(const char* name, int age, bool isMale, const char* sport, int rank, int experienceYears, bool isProfessional, const char* universityName, const char* FN, const char* major, Degree degree, const char* coachName, int playedMatches)
    : Person(name, age, isMale), Student(name, age, isMale, universityName, FN, major, degree), Athlete(name, age, isMale, sport, rank, experienceYears, isProfessional), playedMatches(playedMatches)
{
    this->coachName = new char[strlen(coachName) + 1];
    strcpy(this->coachName, coachName);
}

StudentAthlete::StudentAthlete(const StudentAthlete& other)
    : Person(other), Student(other), Athlete(other)
{
    copyFrom(other);
}

StudentAthlete& StudentAthlete::operator=(const StudentAthlete& other) 
{
    if (this != &other) 
    {
        Student::operator=(other);
        Athlete::operator=(other);
        Person::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

StudentAthlete::~StudentAthlete() 
{
    free();
}


void StudentAthlete::copyFrom(const StudentAthlete& other)
{
    coachName = new char[strlen(other.coachName) + 1];
    strcpy(coachName, other.coachName);
    playedMatches = other.playedMatches;
}

void StudentAthlete::free()
{
    delete[] coachName;
}