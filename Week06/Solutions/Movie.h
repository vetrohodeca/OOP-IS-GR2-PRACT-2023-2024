#pragma once 
#include<iostream>
#pragma warning (disable:4996)

class Movie 
{
private:
    char title[31];
    char director[31];
    int length;

public:
    Movie(const char* title, const char* director, int length);
    Movie();

    const char* getTitle() const;
    const char* getDirector() const;
    int getLength() const;

    void setTitle(const char* title);
    void setDirector(const char* director);
    void setLength(int length);

};