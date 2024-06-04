#include "Customer.h"
#include <cstring>

void Customer::copyFrom(const Customer& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
	money = other.money;
	countOfVodkas = other.countOfVodkas;
	countOfWhiskeys = other.countOfWhiskeys;
	wantsKaraoke = other.wantsKaraoke;
	countOfDJWanted = other.countOfDJWanted;
	singerNameWanted = new char[strlen(other.singerNameWanted) + 1];
	strcpy(singerNameWanted, other.singerNameWanted);
	prefferedMusic = new char[strlen(other.prefferedMusic) + 1];
	strcpy(prefferedMusic, other.prefferedMusic);
}

void Customer::free() {
	delete[] name;
	delete[] singerNameWanted;
	delete[] prefferedMusic;
}

Customer::Customer() : name(nullptr), age(0), money(0), countOfVodkas(0), countOfWhiskeys(0), wantsKaraoke(false),
countOfDJWanted(0), singerNameWanted(nullptr), prefferedMusic(nullptr) {}

Customer::Customer(const char* name, int age, double money, int  countOfVodkas, int countOfWhiskeys, bool wantsKaraoke,
	int countOfDJWanted, const char* singerNameWanted, const char* prefferedMusic)
	: age(age), money(money), countOfVodkas(countOfVodkas), countOfWhiskeys(countOfWhiskeys), wantsKaraoke(wantsKaraoke),
	countOfDJWanted(countOfDJWanted)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->singerNameWanted = new char[strlen(singerNameWanted) + 1];
	strcpy(this->singerNameWanted, singerNameWanted);
	this->prefferedMusic = new char[strlen(prefferedMusic) + 1];
	strcpy(this->prefferedMusic, prefferedMusic);
}

Customer::Customer(const Customer& other)
{
	copyFrom(other);
}

Customer& Customer::operator=(const Customer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Customer::~Customer()
{
	free();
}

char* Customer::getPrefferedMusic() const
{
	return this->prefferedMusic;
}
bool Customer::wantKaraoke() const
{
	return this->wantsKaraoke;
}
int Customer::getCountOfDJWanted()const
{
	return this->countOfDJWanted;
}
char* Customer::getSingerNameWanted()const
{
	return this->singerNameWanted;
}

double Customer::getMoney() const
{
	return this->money;
}

int Customer::getWhiskeyCount() const
{
	return this->countOfWhiskeys;
}

int Customer::getVodkaCount() const
{
	return this->countOfVodkas;
}