#pragma once
#include"Club.h"
class RockClub : Club
{
	bool hasKaraoke;
public:
	RockClub();
	RockClub(const char* name, int size, int capacity, bool hasKaraoke);
	RockClub(const RockClub& other);
	RockClub& operator=(const RockClub& other);
	~RockClub();
	bool canEnter(const Customer& customer);
};

