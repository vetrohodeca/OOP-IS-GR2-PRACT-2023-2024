#include "Cake.h"

Cake::Cake() : flourAmount(0), waterAmount(0), sugarAmount(0), maxSlices(0), currentSlices(0) {}

Cake::Cake(double flour, double water, double sugar)
    : flourAmount(flour), waterAmount(water), sugarAmount(sugar), maxSlices(8), currentSlices(8) {}

Cake::Cake(const Cake& other)
    : flourAmount(other.flourAmount), waterAmount(other.waterAmount), sugarAmount(other.sugarAmount),
    maxSlices(other.maxSlices), currentSlices(other.currentSlices) {}

double Cake::getFlourAmount() const
{
    return flourAmount;
}

double Cake::getWaterAmount() const
{
    return waterAmount;
}

double Cake::getSugarAmount() const
{
    return sugarAmount;
}

int Cake::getMaxSlices() const
{
    return maxSlices;
}

int Cake::getCurrentSlices() const
{
    return currentSlices;
}

void Cake::setFlourAmount(double amount)
{
    if (amount >= 0)
        flourAmount = amount;
    else
        flourAmount = 100;
}

void Cake::setWaterAmount(double amount)
{
    if (amount >= 0)
        waterAmount = amount;
    else
        waterAmount = 100;
}

void Cake::setSugarAmount(double amount)
{
    if (amount >= 0)
        sugarAmount = amount;
    else
        sugarAmount = 100;
}

void Cake::setMaxSlices(int slices)
{
    if (slices >= 0)
        maxSlices = slices;
    else
        maxSlices = 1;
}

void Cake::setCurrentSlices(int slices)
{
    if (slices >= 0 && slices <= maxSlices)
        currentSlices = slices;
    else
        currentSlices = 1;
}

Cake& Cake::operator+=(int numberOfSlices)
{
    if (this->maxSlices == 0 || this->currentSlices + numberOfSlices > this->maxSlices)
    {
        std::cout << "There is not enough space to add " << numberOfSlices << " slices" << std::endl;
    }
    else
    {
        this->currentSlices += numberOfSlices;
    }
    return *this;
}

Cake& Cake::operator-=(int numberOfSlices)
{
    if (this->currentSlices < numberOfSlices)
    {
        std::cout << "There is not enough pieces of cake to get " << numberOfSlices << " slices" << std::endl;
    }
    else
    {
        this->currentSlices -= numberOfSlices;
    }
    return *this;
}
Cake& Cake::operator/=(int numberOfSlices)
{
    if (this->maxSlices == 0)
    {
        maxSlices == 2;
    }
    else if (numberOfSlices % maxSlices != 0)
    {
        std::cout << "Can not devide Cake with " << maxSlices << " slices " << " into " << numberOfSlices << "slices " << std::endl;
    }
    else
    {
        currentSlices = currentSlices * (numberOfSlices / maxSlices);
        this->maxSlices = numberOfSlices;
    }
    return *this;
}
Cake operator/(const Cake& cake, int numberOfSlices)
{
    Cake temp(cake);
    temp /= numberOfSlices;
    return temp;
}

Cake operator-(const Cake& cake, int numberOfSlices)
{
    Cake temp(cake);
    temp-=numberOfSlices;
    return temp;
}

Cake operator+(const Cake& cake, int numberOfSlices)
{
    Cake temp(cake);
    temp += numberOfSlices;
    return temp;
}

bool operator==(const Cake& firstCake, const Cake& secondCake)
{
    return firstCake.currentSlices == secondCake.currentSlices
        && firstCake.maxSlices == secondCake.maxSlices
        && firstCake.flourAmount == secondCake.flourAmount
        && firstCake.sugarAmount == secondCake.sugarAmount
        && firstCake.waterAmount == secondCake.waterAmount;
}
bool operator!=(const Cake& firstCake, const Cake& secondCake)
{
    return !(firstCake == secondCake);
}



