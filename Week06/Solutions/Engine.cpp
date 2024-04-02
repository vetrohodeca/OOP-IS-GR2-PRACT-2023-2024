#include "Engine.h"

int Engine::getPower() const 
{
    return power;
}

int Engine::getDisplacement() const 
{
    return displacement;
}

const char* Engine::getVIN() const 
{
    return VIN;
}

void Engine::setPower(int power) 
{
    this->power = power;
}

void Engine::setDisplacement(int displacement) 
{
    this->displacement = displacement;
}

void Engine::setVIN(const char* VIN)
{
    if (VIN&& strlen(VIN)<18) 
    {
        strcpy(this->VIN, VIN);
    }
}