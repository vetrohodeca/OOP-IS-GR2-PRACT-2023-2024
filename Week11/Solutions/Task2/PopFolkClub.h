#pragma once
#include "Club.h"
class PopFolkClub : Club
{
	char* singerName;
public:
	PopFolkClub();
	PopFolkClub(const char* name, int size, int capacity, const char* singer);
	PopFolkClub(const PopFolkClub& other);
	PopFolkClub& operator=(const PopFolkClub& other);
	~PopFolkClub();

	bool canEnter(const Customer& customer);
};

