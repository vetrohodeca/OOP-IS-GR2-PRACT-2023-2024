#include "Track.h"

unsigned Track::getSlowCorners() const
{
    return slowCorners;
}

unsigned Track::getFastCorners() const
{
    return fastCorners;
}

unsigned Track::getStraightLength() const
{
    return straightLength;
}

void Track::setSlowCorners(unsigned slowCorners)
{
    this->slowCorners = slowCorners;
}

void Track::setFastCorners(unsigned fastCorners)
{
    this->fastCorners = fastCorners;
}

void Track::setStraightLength(unsigned straightLength)
{
    this->straightLength = straightLength;
}