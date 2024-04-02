#pragma once
#include "Projection.h"
#include <iostream>

class Festival 
{
private:
    static const int MAX_PROJECTIONS = 100; 

    char festivalName[31]; 
    Projection projections[MAX_PROJECTIONS]; 
    int numProjections;

public:
    Festival(const char* festivalName);

    void setFestivalName(const char* festivalName);
    void addProjection(const Projection& projection);

    const char* getFestivalName() const;
    const Projection* getProjections() const;
    int getNumProjections() const;
};