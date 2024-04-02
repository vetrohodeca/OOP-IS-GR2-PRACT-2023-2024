#include "Race.h"
void Race::setTrack(Track track)
{
    this->track = track;
}

void Race::setCars(Car* cars)
{
    for (int i = 0; i < 10; ++i)
    {
        this->cars[i] = cars[i];
    }
}

void Race::addCar(Car car)
{
    if (numberOfCars < 10)
    {
        cars[numberOfCars++] = car;
    }
    else
    {
        std::cout << "Cannot add more cars. Race is already full." << std::endl;
    }
}

double Race::calculateResult(Car car)
{
    double result = 0;
    double slowCornersResult = car.getAcceleration() * track.getSlowCorners();
    if (car.getDrivetrain() == Drivetrain::AllWheelDrive)
    {
        slowCornersResult *= 1.2;
    }
    double fastCornersResult = car.getHandling() * track.getFastCorners();
    if (car.getDrivetrain() == Drivetrain::Front)
    {
        fastCornersResult *= 0.9;
    }
    double StraightResult = car.getTopSpeed()*track.getStraightLength()/100;

    return slowCornersResult+fastCornersResult+StraightResult;
}

void Race::classify()
{
    Car sortedCars[10];
    double results[10];

    for (int i = 0; i < numberOfCars; ++i)
    {
        results[i] = calculateResult(cars[i]);
        sortedCars[i] = cars[i];
    }

    for (int i = 0; i < numberOfCars - 1; ++i)
    {
        for (int j = i + 1; j < numberOfCars; ++j)
        {
            if (results[j] < results[i])
            {
                Car tempCar = sortedCars[i];
                sortedCars[i] = sortedCars[j];
                sortedCars[j] = tempCar;

                double tempResult = results[i];
                results[i] = results[j];
                results[j] = tempResult;
            }
        }
    }

    std::cout << "Classification of cars in the race:" << std::endl;
    for (int i = 0; i < numberOfCars; ++i)
    {
        const Car& car = sortedCars[i];
        std::cout << car.getManufacturer() << " " << car.getModel() << std::endl;
    }
}