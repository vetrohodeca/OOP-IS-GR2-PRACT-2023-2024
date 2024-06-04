#include "RockClub.h"

RockClub::RockClub() : Club(), hasKaraoke(false) {}

RockClub::RockClub(const char* name, int size, int capacity, bool hasKaraoke)
    : Club(name, size, capacity), hasKaraoke(hasKaraoke) 
{
	vodkaPrice = 7;
	whiskeyPrice = 9;
}

RockClub::RockClub(const RockClub& other) : Club(other) 
{
    hasKaraoke = other.hasKaraoke;
}

RockClub& RockClub::operator=(const RockClub& other) 
{
    if (this != &other)
    {
        Club::operator=(other);
        hasKaraoke = other.hasKaraoke;
    }
    return *this;
}

RockClub::~RockClub() {}

bool RockClub::canEnter(const Customer& customer) 
{
	if (strcmp(customer.getPrefferedMusic() ,"Rock")==0 || strcmp(customer.getPrefferedMusic() , "All") == 0 &&
		customer.wantKaraoke() == this->hasKaraoke &&
		customer.getMoney() >= whiskeyPrice * customer.getWhiskeyCount() + vodkaPrice * customer.getVodkaCount() &&
		currentVisitorsCount < capacity)
	{
		capacity++;
		return true;
	}
	return false;
}
