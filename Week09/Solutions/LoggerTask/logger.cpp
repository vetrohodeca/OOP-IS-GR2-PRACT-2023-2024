// logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Logger.h"


void Logger::setLastMessege(const char* newLastMessege)
{
    lastMessege = new char[strlen(newLastMessege) + 1];
    strcpy(lastMessege, newLastMessege);
}

Logger::~Logger()
{
    delete Logger::instance;
}

std::ofstream& Logger::log(const char* messege)
{
    std::ofstream ofs(Logger::fileName);

    if (!ofs)
        return;

    ofs << messege << std::endl;    

    delete[] lastMessege;

    setLastMessege(messege);

    return ofs;
}

unsigned Logger::getCountOfMessege() const
{
    return Logger::countMessege;
}

Logger* Logger::getInstance()
{
    if (!Logger::instance)
    {
        instance = new Logger();
    }

    return instance;
}

std::ofstream& operator<<(const Logger& log, std::ofstream& stream)
{
    if (!stream)
        return stream;
    
    char buffer[1024];

    std::ifstream ifs(Logger::fileName);

    int currentIndexInStream = ifs.tellg();
    ifs.seekg(std::ios::beg);

    while (ifs.getline(buffer, 1024))
    {
        stream << buffer;
    }

    ifs.seekg(currentIndexInStream);

    ifs.close();
    
    return stream;
}

std::ofstream& operator>>(Logger& log, const char* messege)
{
    return log.log(messege);
}

const char* operator*(const Logger& log)
{
    return log.lastMessege;
}
