#pragma once
#include <iostream>
#include <fstream>

class Logger {
protected:
	static Logger* instance;
	Logger() = default;
	const static char fileName[8];
	static unsigned countMessege;

	char* lastMessege = nullptr;
	void setLastMessege(const char* newLastMessege);

public:
	Logger(const Logger& other) = delete;
	Logger& operator=(const Logger& other) = delete;
	~Logger();

	std::ofstream& log(const char* messege);
	unsigned getCountOfMessege() const;

	static Logger* getInstance();

	friend std::ofstream& operator<<(const Logger& log, std::ofstream& stream);
	friend std::ofstream& operator>>(Logger& log, const char* messege);
	friend const char* operator*(const Logger& log);
};
Logger* Logger::instance = nullptr;
const char Logger::fileName[8] = "log.txt";
unsigned Logger::countMessege = 0;