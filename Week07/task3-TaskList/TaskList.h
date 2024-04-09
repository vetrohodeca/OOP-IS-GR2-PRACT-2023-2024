#pragma once
#include "Task.h"

class TaskList {
	Task* tasks = nullptr;
	unsigned size = 0;
	unsigned capacity = 8;

	void copy(const TaskList& other);
	void free();
	void resize(unsigned newCapacity);

public:
	TaskList();
	TaskList(unsigned capacity);
	TaskList(Task* tasks, unsigned size, unsigned capacity);
	TaskList(const TaskList& other);
	TaskList& operator=(const TaskList& other);
	~TaskList();

	void addTask(const Task& toAdd);
	void removeTask(const Task& toRemove);
	void changeTaskByIndex(unsigned index, const std::string& newName, const std::string& newDescription, State newState);

	TaskList getTasksByState(State state) const;
	void print() const;
};
