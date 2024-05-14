#pragma once
#include "Student.h"
#include <exception>

class StudentVector
{
	Student* data;
	size_t size;
	size_t capacity;

	void copy(const StudentVector& other);
	void move(StudentVector&& other);
	void free();

	void resize(size_t newCapacity);

	void rearrangeArray();

public:
	StudentVector();
	StudentVector(const StudentVector& other);
	StudentVector(StudentVector&& other);

	StudentVector& operator=(const StudentVector& other);
	StudentVector& operator=(StudentVector&& other);

	~StudentVector();

	void pushBack(const Student& other);
	void pushBack(Student&& other);

	void pushFront(const Student& other);
	void pushFront(Student&& other);

	const Student& getBack() const;
	const Student& getFront() const;

	const Student& at(size_t index) const;
	size_t getSize() const;

};

