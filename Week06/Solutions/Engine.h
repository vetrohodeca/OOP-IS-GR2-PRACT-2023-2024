#pragma once
#include<iostream>
#pragma warning (disable:4996)

class Engine
{
    int power;
    int displacement;
    char VIN[18];

public:
    int getPower() const;
    int getDisplacement() const;
    const char* getVIN() const;

    void setPower(int power);
    void setDisplacement(int displacement);
    void setVIN(const char* VIN);
};