#include "Car.h"

const char* Car::getRegNumber() const
{
    return this->regNumber;
}

void Car::setRegNumber(const char* regNumber)
{
    if (regNumber && strlen(regNumber) <= 9)
    {
        strcpy(this->regNumber, regNumber);
    }
}

const char* Car::getManufacturer() const
{
    return this->manufacturer;
}

void Car::setManufacturer(const char* manu)
{
    if (manu && strlen(manu) < 21)
    {
        strcpy(manufacturer, manu);
    }
}

const char* Car::getModel() const
{
    return this->model;
}

void Car::setModel(const char* model)
{
    if (model && strlen(model) < 21)
    {
        strcpy(this->model, model);
    }
}

const double* Car::getFuelConsumption() const
{
    return this->fuelConsumption;
}

double Car::getAverageFuelConsumption() const
{
    return (fuelConsumption[0] + fuelConsumption[1] + fuelConsumption[2]) / 3;
}
void Car::setFuelConsumption(const double* fuelCons)
{
    if (fuelCons)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (fuelCons[i] >= 0)
            {
                fuelConsumption[i] = fuelCons[i];
            }
            else
            {
                fuelConsumption[i] = 10;
            }
        }
    }
}

bool Car::isFuelEfficient() const
{
    return getAverageFuelConsumption() <= 6;
}

bool Car::isMoreFuelElficient(const Car& other)
{
    return this->getAverageFuelConsumption() < other.getAverageFuelConsumption();
}

const Engine& Car::getEngine() const
{
    return this->engine;
}

const Wheel& Car::getWheel(int index) const
{
    return this->wheels[index];
}

const unsigned Car::getAcceleration() const
{
    return this->acceleration;
}

const unsigned Car::getTopSpeed() const
{
    return this->topSpeed;
}

const unsigned Car::getHandling() const
{
    return this->handilng;
}

const Drivetrain Car::getDrivetrain() const
{
    return this-> drivetrain;
}

void Car::setDrivetrain(Drivetrain drivetrain)
{
    this->drivetrain=drivetrain;
}

void Car::setAcceleration(unsigned acceleration)
{
    if (acceleration > 100)
    {
        this->acceleration = 100;
    }
    else
    {
        this->acceleration = acceleration;
    }
}

void Car::setTopSpeed(unsigned topSpeed)
{
    if (topSpeed > 100)
    {
        this->topSpeed = 100;
    }
    else
    {
        this->topSpeed = topSpeed;
    }
}

void Car::setHandling(unsigned handling)
{
    if (handilng > 100)
    {
        this->handilng = 100;
    }
    else
    {
        this->handilng = handilng;
    }
}

void Car::setEngine(const Engine& engine)
{
    this->engine = engine;
}

void Car::setWheels(const Wheel wheels[4])
{
    this->wheels[0] = wheels[0];
    this->wheels[1] = wheels[1];
    this->wheels[2] = wheels[2];
    this->wheels[3] = wheels[3];
}