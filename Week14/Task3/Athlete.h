#pragma once
#include "Person.h"

class Athlete : virtual  public Person {
	void copyFrom(const Athlete& other);
	void free();
protected:
	char* sport;
	int rank;
	int experienceYears;
	bool isProffessional;

public:
	Athlete(const char* name = "", int age = 0, bool isMale = true, const char* sport = "", int rank = 0, int experienceYears = 0, bool isProfessional = false);
	Athlete(const Athlete& other);
	Athlete& operator=(const Athlete& other);
	~Athlete();

	int getRank() const;
	int getExperienceYears() const;
	bool getIsProffessional() const;
	char* getSport() const;
};