#include "Task.h"

Task::Task(const std::string& name, const std::string& description, State state) : name(name),
description(description), state(state)
{
}

std::string Task::getName() const
{
    return name;
}

std::string Task::getDescription() const
{
    return description;
}

State Task::getState() const
{
    return state;
}

void Task::setName(std::string& name)
{
    this->name = name;
}

void Task::setDescription(std::string& description)
{
    this->description = description;
}

void Task::setState(State state)
{
    this->state = state;
}

void Task::print() const
{
    std::cout << "Name: " << name << std::endl << "Description: "
        << description << std::endl << "State: " << printState(state) << std::endl;
}

std::string printState(State state)
{
    switch (state)
    {
    case State::DEFAULT: return "DEFAULT";
        break;
    case State::SOLVED: return "SOLVED";
        break;
    case State::IN_PROGRESS: return "IN PROGRESS";
        break;
    case State::UNSOLVED: return "UNSOLVED";
        break;
    default: return "INCORRECT";
        break;
    }
}
