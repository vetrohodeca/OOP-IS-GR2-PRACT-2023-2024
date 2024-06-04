#include "PopFolkClub.h"
#include <cstring>

PopFolkClub::PopFolkClub() : Club(), singerName(nullptr) {}

PopFolkClub::PopFolkClub(const char* name, int size, int capacity, const char* singer)
	: Club(name, size, capacity)
{
	this->vodkaPrice = 10;
	this->whiskeyPrice = 12;
	this->singerName = new char[strlen(singer) + 1];
	strcpy(this->singerName, singer);
}

PopFolkClub::PopFolkClub(const PopFolkClub& other) : Club(other)
{
	singerName = new char[strlen(other.singerName) + 1];
	strcpy(singerName, other.singerName);
}

PopFolkClub& PopFolkClub::operator=(const PopFolkClub& other)
{
	if (this != &other)
	{
		Club::operator=(other);
		delete[] singerName;
		singerName = new char[strlen(other.singerName) + 1];
		strcpy(singerName, other.singerName);
	}
	return *this;
}

PopFolkClub::~PopFolkClub()
{
	delete[] singerName;
}

bool PopFolkClub::canEnter(const Customer& customer) 
{
	if (strcmp(customer.getPrefferedMusic() , "PopFolk") ==0 || strcmp(customer.getPrefferedMusic() , "All") ==0 &&
		 customer.getSingerNameWanted() == this->singerName &&
		customer.getMoney() >= whiskeyPrice*customer.getWhiskeyCount() + vodkaPrice*customer.getVodkaCount() &&
		currentVisitorsCount < capacity)
	{
		capacity++;
		return true;
	}
	return false;
}
