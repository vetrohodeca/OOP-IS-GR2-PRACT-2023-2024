#include "TaskList.h"

void TaskList::copy(const TaskList& other)
{
    tasks = new Task[other.capacity];
    
    for (int i = 0; i < other.size; i++)
    {
        tasks[i] = other.tasks[i];
    }

    capacity = other.capacity;
    size = other.capacity;
}

void TaskList::free()
{
    delete[] tasks;
}

void TaskList::resize(unsigned newCapacity)
{
    Task* temp = new Task[newCapacity];

    for (int i = 0; i < size; i++)
    {
        temp[i] = tasks[i];
    }

    free();
    tasks = temp;
    capacity = newCapacity;
}

TaskList::TaskList()
{
    tasks = new Task[capacity];
}

TaskList::TaskList(unsigned capacity)
{
    tasks = new Task[capacity];
    this->capacity = capacity;
}

TaskList::TaskList(Task* tasks, unsigned size, unsigned capacity)
{
    this->tasks = new Task[capacity];
    this->capacity = capacity;
    this->size = size;

    for (int i = 0; i < size; i++)
    {
        this->tasks[i] = tasks[i];
    }
}

TaskList::TaskList(const TaskList& other)
{
    copy(other);
}

TaskList& TaskList::operator=(const TaskList& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
}

TaskList::~TaskList()
{
    free();
}

void TaskList::addTask(const Task& toAdd)
{
    if (size >= capacity)
    {
        resize(capacity * 2);
    }

    tasks[size++] = toAdd;
}

void TaskList::removeTask(const Task& toRemove)
{
    for (int i = 0; i < size; i++)
    {
        if (tasks[i].getName() == toRemove.getName())
        {
            //std::swap(const_cast<const Task&>(tasks[i]), toRemove)

            Task temp = tasks[i];
            tasks[i] = tasks[size - 1];
            tasks[size - 1] = temp;
        }
    }
}

void TaskList::changeTaskByIndex(unsigned index, const std::string& newName, const std::string& newDescription, State newState)
{
    tasks[index] = Task(newName, newDescription, newState);
}

TaskList TaskList::getTasksByState(State state) const
{
    TaskList result;

    for (int i = 0; i < size;i++)
    {
        if (tasks[i].getState() == state)
        {
            result.addTask(tasks[i]);
        }
    }

    return result;
}

void TaskList::print() const
{
    for (int i = 0; i < size; i++)
    {
        tasks[i].print();
    }
}
