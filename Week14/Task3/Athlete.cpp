#include "Athlete.h"
#include <cstring>

Athlete::Athlete(const char* name, int age, bool isMale, const char* sport, int rank, int experienceYears, bool isProffessional)
    : Person(name, age, isMale), rank(rank), experienceYears(experienceYears), isProffessional(isProffessional)
{
    this->sport = new char[strlen(sport) + 1];
    strcpy(this->sport, sport);
}

Athlete::Athlete(const Athlete& other) 
{
    copyFrom(other);
}

Athlete& Athlete::operator=(const Athlete& other) 
{
    if (this != &other) 
    {
        copyFrom(other);
    }
    return *this;
}

void Athlete::copyFrom(const Athlete& other)
{
    Person::operator=(other);
    delete[] sport;
    sport = new char[strlen(other.sport) + 1];
    strcpy(sport, other.sport);
    rank = other.rank;
    experienceYears = other.experienceYears;
    isProffessional = other.isProffessional;
}

void Athlete::free()
{
    delete[] sport;
}
Athlete::~Athlete() 
{
    free();
}

int Athlete::getRank() const
{
    return this->rank;
}
int Athlete::getExperienceYears() const
{
    return this->experienceYears;
}
bool Athlete::getIsProffessional() const
{
    return this->isProffessional;
}

char* Athlete::getSport() const
{
    return this->sport;
}
