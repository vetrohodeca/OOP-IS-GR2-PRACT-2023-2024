#include "HouseClub.h"

HouseClub::HouseClub() : Club(), countOfDJ(0) {}

HouseClub::HouseClub(const char* name, int size, int capacity, int countOfDJ)
	: Club(name, size, capacity), countOfDJ(countOfDJ)
{
	vodkaPrice = 15;
	whiskeyPrice = 17;
}

HouseClub::HouseClub(const HouseClub& other) : Club(other)
{
	countOfDJ = other.countOfDJ;
}

HouseClub& HouseClub::operator=(const HouseClub& other)
{
	if (this != &other)
	{
		Club::operator=(other);
		countOfDJ = other.countOfDJ;
	}
	return *this;
}

HouseClub::~HouseClub() {}

bool HouseClub::canEnter(const Customer& customer)
{
	if (strcmp(customer.getPrefferedMusic() , "House") == 0 || strcmp( customer.getPrefferedMusic() , "All") == 0 &&
		customer.getCountOfDJWanted() >= this->countOfDJ &&
		customer.getMoney() >= whiskeyPrice * customer.getWhiskeyCount() + vodkaPrice * customer.getVodkaCount() &&
		currentVisitorsCount < capacity)
	{
		capacity++;
		return true;
	}
	return false;
}
