#pragma once
#pragma warning(disable : 4996)

class Customer
{
	char* name;
	int age;
	double money;
	int countOfWhiskeys;
	int countOfVodkas;
	bool wantsKaraoke;
	int countOfDJWanted;
	char* singerNameWanted;
	char* prefferedMusic;

	void copyFrom(const Customer& other);
	void free();
public:
	Customer();
	Customer(const char* name, int age, double money, int  countOfVodkas, int countOfWhiskeys, bool wantsKaraoke, int countOfDJWanted, const char* singerNameWanted, const char* prefferedMusic);
	Customer(const Customer& other);
	Customer& operator=(const Customer& other);
	~Customer();

	char* getPrefferedMusic() const;
	bool wantKaraoke() const;
	int getCountOfDJWanted() const;
	char* getSingerNameWanted() const;
	double getMoney() const;
	int getWhiskeyCount() const;
	int getVodkaCount() const;
};

