#include "Stock.h"

const char* Stock::getAbbreviation() const
{
    return this->abbreviation;
}

const char* Stock::getName() const
{
    return this->name;
}

const double* Stock::getPrices() const
{
    return this->prices;
}

void Stock::setAbreviation(const char* abbreviation)
{
    if (abbreviation && strlen(abbreviation) >= 3 && strlen(abbreviation) <= 3)
    {
        strcpy(this->abbreviation, abbreviation);
    }
}

void Stock::setName(const char* name)
{
    if (name && strlen(name) <= 20)
    {
        strcpy(this->name, name);
    }
}

void Stock::setPrices(double* prices)
{
    for (int i = 0; i < 12; i++)
    {
        if (prices[i] < 0)
        {
            prices[i] = 0;
        }
        this->prices[i] = prices[i];
    }
}

bool Stock::isProfitable() const
{
    int countOfRaisingMonths = 0;

    for (int i = 1; i < 12; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            countOfRaisingMonths++;
        }
        else
        {
            countOfRaisingMonths--;
        }
    }
    return countOfRaisingMonths > 0 && prices[11] >= std::round(1.1 * prices[0]);
}
