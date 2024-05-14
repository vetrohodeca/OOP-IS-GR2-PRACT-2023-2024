#include "StudentVector.h"

void StudentVector::copy(const StudentVector& other)
{
    data = new Student[other.capacity];
    
    for (int i = 0; i < other.size; i++)
    {
        data[i] = other.data[i];
    }

    capacity = other.capacity;
    size = other.size;

}

void StudentVector::move(StudentVector&& other)
{
    data = other.data;
    other.data = nullptr;

    capacity = other.capacity;
    other.capacity = 0;

    size = other.size;
    other.size = 0;
}

void StudentVector::free()
{
    delete[] data;
}

void StudentVector::resize(size_t newCapacity)
{
    try {
        Student* newData = new Student[newCapacity];

        for (int i = 0; i < size; i++)
            newData[i] = data[i];

        capacity = newCapacity;
        delete[] data;
        data = newData;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what();

        delete[] data;
    }
}

void StudentVector::rearrangeArray()
{
    for (int i = size-1; i >= 0; i--)
    {
        data[i + 1] = data[i];
    }
}

StudentVector::StudentVector() : capacity(8), size(0)
{
    data = new Student[capacity];
}

StudentVector::StudentVector(const StudentVector& other)
{
    copy(other);
}

StudentVector::StudentVector(StudentVector&& other)
{
    move(std::move(other));
}

StudentVector& StudentVector::operator=(const StudentVector& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }

    return *this;
}

StudentVector& StudentVector::operator=(StudentVector&& other) 
{
    if (this != &other)
    {
        free();
        move(std::move(other));
    }

    return *this;
}

StudentVector::~StudentVector()
{
    free();
}

void StudentVector::pushBack(const Student& other)
{
    if (size == capacity)
        resize(capacity * 2);

    data[size++] = other;
}

void StudentVector::pushBack(Student&& other)
{
    if (size == capacity)
        resize(capacity * 2);

    data[size++] = std::move(other);
}

void StudentVector::pushFront(const Student& other)
{
    if (size == capacity)
        resize(capacity * 2);

    rearrangeArray();
    data[0] = other;
    size++;
}

void StudentVector::pushFront(Student&& other)
{
    if (size == capacity)
        resize(capacity * 2);

    rearrangeArray();
    data[0] = std::move(other);
    size++;

}

const Student& StudentVector::getBack() const
{
    return at(size - 1);
}

const Student& StudentVector::getFront() const
{
    return at(0);
}

const Student& StudentVector::at(size_t index) const
{
    if (index > size)
    {
        throw std::logic_error("Index out of range\n");
    }

    return data[index];
}

size_t StudentVector::getSize() const
{
    return size;
}
