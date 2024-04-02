#pragma once
#include<iostream>
#pragma warning (disable:4996)

enum Alloy
{
    Steel,
    Aluminium,
    Carbon,
    Magnesium
};

class Wheel
{
    unsigned radius;
    Alloy alloy;

public:
    unsigned getRadius() const;
    Alloy getAlloy() const;

    void setRadius(int radius);
    void setAlloy(Alloy aloy);
};