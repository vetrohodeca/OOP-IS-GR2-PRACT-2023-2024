#pragma once
class Track
{
    unsigned slowCorners;
    unsigned fastCorners;
    unsigned straightLength;

public:
    unsigned getSlowCorners() const;
    unsigned getFastCorners() const;
    unsigned getStraightLength() const;

    void setSlowCorners(unsigned slowCorenrs);
    void setFastCorners(unsigned fastCorners);
    void setStraightLength(unsigned straightLength);
};
