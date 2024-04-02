#include "Projection.h"

Projection::Projection()
{
    setHallName(" ");
    setDatetime("1.01.2024 18:30");
}
Projection::Projection(const Movie& movie, const char* datetime, const char* hallName) : movie(movie)
{
    setDatetime(datetime);
    setHallName(hallName);
}

void Projection::setMovie(const Movie& movie)
{
    this->movie = movie;
}

void Projection::setDatetime(const char* datetime)
{
    if (datetime && strlen(datetime) < 17)
    {
        strcpy(this->datetime, datetime);
    }
}

void Projection::setHallName(const char* hallName)
{
    if (hallName && strlen(hallName) < 15)
    {
        strcpy(this->hallName, hallName);
    }
}

const Movie& Projection::getMovie() const
{
    return movie;
}

const char* Projection::getDatetime() const
{
    return datetime;
}

const char* Projection::getHallName() const
{
    return hallName;
}