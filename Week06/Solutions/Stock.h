#pragma once
#include<iostream>
#pragma warning (disable:4996)

class Stock
{
private:
    char abbreviation[6];
    char name[21];
    double prices[12];

public:
    const char* getAbbreviation() const;
    const char* getName() const;
    const double* getPrices() const;


    void setAbreviation(const char* abbreviation);
    void setName(const char* name);
    void setPrices(double* prices);
    bool isProfitable() const;
};