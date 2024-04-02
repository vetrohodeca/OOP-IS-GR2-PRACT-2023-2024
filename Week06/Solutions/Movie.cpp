#include "Movie.h"

Movie::Movie()
{
    setTitle(" ");
    setDirector(" ");
    setLength(0);
}
Movie::Movie(const char* title, const char* director, int length)
{
    setTitle(title);
    setDirector(director);
    setLength(length);
}

const char* Movie::getTitle() const
{
    return title;
}

const char* Movie::getDirector() const
{
    return director;
}

int Movie::getLength() const {
    return length;
}

void Movie::setTitle(const char* title)
{
    if (title && strlen(title) < 30)
    {
        strcpy(this->title, title);
    }
}

void Movie::setDirector(const char* director)
{
    if (director && strlen(director) < 30)
    {
        strcpy(this->director, director);
    }
}

void Movie::setLength(int length)
{
    this->length = length;
}
