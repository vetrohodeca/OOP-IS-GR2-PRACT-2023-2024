#pragma once
#include <iostream>
class Cake
{
    double flourAmount;
    double waterAmount;
    double sugarAmount;
    int maxSlices;
    int currentSlices;


public:
    Cake();
    Cake(double, double, double);
    Cake(const Cake& other);

    double getFlourAmount() const;
    double getWaterAmount() const;
    double getSugarAmount() const;
    int getMaxSlices() const;
    int getCurrentSlices() const;

    void setFlourAmount(double amount);
    void setWaterAmount(double amount);
    void setSugarAmount(double amount);
    void setMaxSlices(int slices);
    void setCurrentSlices(int slices);

    Cake& operator -=(int numberOfSlices);
    Cake& operator /=(int numberOfSlices);
    Cake& operator +=(int numberOfSlices);
    friend bool operator==(const Cake& firstCake, const Cake& secondCake);
    friend bool operator!=(const Cake& firstCake, const Cake& secondCake);
};


Cake operator/(const Cake& cake, int numberOfSlices);
Cake operator-(const Cake& cake, int numberOfSlices);
Cake operator+(const Cake& cake, int numberOfSlices);
