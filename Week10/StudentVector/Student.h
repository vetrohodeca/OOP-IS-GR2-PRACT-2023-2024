#pragma once
#pragma warning (disable: 4996)
#include <iostream>

enum class Specialty : char
{
	DEFAULT, IS, SI, KN, I
};
class Student
{
	char* name = nullptr;
	char facultyNumber[10];
	Specialty specilaty = Specialty::DEFAULT;

	void copy(const Student& other);
	void move(Student&& other);
	void free();

public:
	Student() = default;
	Student(const char* name, const char* facultyNumber, Specialty specialty);
	Student(const Student& other);
	Student(Student&& other);

	Student& operator=(const Student& other);
	Student& operator=(Student&& other);

	~Student();

};

