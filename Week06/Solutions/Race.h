#pragma once
#include"Track.h"
#include "Car.h"
class Race
{
    Track track;
    Car cars[10];
    int numberOfCars = 0;

    double calculateResult(Car car);
public:
    void setTrack(Track track);
    void setCars(Car* cars);
    void addCar(Car car);

    void classify();
};

