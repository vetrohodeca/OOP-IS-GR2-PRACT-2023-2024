#pragma once
#include "Club.h"
class HouseClub : Club
{
	int countOfDJ;
public:
	HouseClub();
	HouseClub(const char* name, int size, int capacity, int countOfDJ);
	HouseClub(const HouseClub& other);
	HouseClub& operator=(const HouseClub& other);
	~HouseClub();

	bool canEnter(const Customer& customer);
};

