#include "Wheel.h"

unsigned Wheel::getRadius() const
{
    return radius;
}

Alloy Wheel::getAlloy() const
{
    return alloy;
}

void Wheel::setRadius(int radius) 
{
    this->radius = radius;
}

void Wheel::setAlloy(Alloy alloy)
{
    this->alloy = alloy;
}