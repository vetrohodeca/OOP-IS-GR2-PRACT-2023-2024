#pragma once
#include <iostream>
#include <string>

enum class State : char
{
	DEFAULT,
	SOLVED,
	IN_PROGRESS,
	UNSOLVED
};

class Task {
	std::string name = "DEFAULT";
	std::string description = "DEFAULT";
	State state = State::DEFAULT;

public:
	Task() = default;
	Task(const std::string& name, const std::string& description, State state);

	std::string getName() const;
	std::string getDescription() const;
	State getState() const;

	void setName(std::string& name);
	void setDescription(std::string& description);
	void setState(State state);

	void print() const;

};

std::string printState(State state);
