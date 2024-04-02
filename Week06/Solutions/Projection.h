#pragma once
#include "Movie.h"
#include <iostream>

class Projection {
private:
    Movie movie;
    char datetime[18];
    char hallName[21];

public:
    Projection();
    Projection(const Movie& movie, const char* datetime, const char* hallName);

    void setMovie(const Movie& movie);
    void setDatetime(const char* datetime);
    void setHallName(const char* hallName);

    const Movie& getMovie() const;
    const char* getDatetime() const;
    const char* getHallName() const;
};
