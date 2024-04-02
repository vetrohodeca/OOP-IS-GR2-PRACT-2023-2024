#pragma once
#include <iostream>
#include "Wheel.h"
#include "Engine.h"
#pragma warning (disable:4996)

enum Drivetrain
{
    Front,
    Rear,
    AllWheelDrive
};

class Car
{
    char regNumber[9];
    char manufacturer[21];
    char model[21];
    double fuelConsumption[3];
    Engine engine;
    Wheel wheels[4];
    unsigned acceleration;
    unsigned topSpeed;
    unsigned handilng;
    Drivetrain drivetrain;

    public:
    const char* getRegNumber() const;
    const char* getManufacturer() const;
    const char* getModel() const;
    const double* getFuelConsumption() const;
    const Engine& getEngine() const;
    const Wheel& getWheel(int index) const;
    const unsigned getAcceleration() const;
    const unsigned getTopSpeed() const;
    const unsigned getHandling() const;
    const Drivetrain getDrivetrain() const;

    void setDrivetrain(Drivetrain drivertrain);
    void setAcceleration(unsigned acceleration);
    void setTopSpeed(unsigned topSpeed);
    void setHandling(unsigned handling);

    void setEngine(const Engine& engine);
    void setWheels(const Wheel wheels[4]);
    void setRegNumber(const char* regNum);
    void setManufacturer(const char* manufacturer);
    void setModel(const char* model);
    double getAverageFuelConsumption() const;
    void setFuelConsumption(const double* fuelConsumption);
    bool isFuelEfficient() const;
    bool isMoreFuelElficient(const Car& other);
};
