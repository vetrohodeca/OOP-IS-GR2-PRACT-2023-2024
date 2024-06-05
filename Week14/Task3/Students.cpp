#include "Students.h"
#include <iostream>
#include <cstring>
const int bachelorYears = 4;
const int masterYears = 6;
const int PhDYears = 9;
void Students::resize()
{
	StudentAthlete* temp = new StudentAthlete[capacity * 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = students[i];
	}
	free();
	students = temp;
	capacity *= 2;
}

Students::Students() : size(0), capacity(2)
{
	students = new StudentAthlete[capacity];
}

Students::Students(const Students& other)
{
	copyFrom(other);
}

Students& Students::operator=(const Students& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Students::~Students()
{
	free();
}

void Students::addStudent(const StudentAthlete& student)
{
	if (size == capacity)
	{
		resize();
	}
	students[size++] = student;
}

void Students::printBestTeam(const char* sportName, const char* universityName)
{
	StudentAthlete* filteredStudents = new StudentAthlete[size];
	int filteredSize = 0;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(students[i].getSport(), sportName) == 0 && 
			strcmp(students[i].getUniversity(), universityName) == 0 &&
			!students[i].getIsProffessional())
		{
			int yearsToGraduate = 0;
			switch (students[i].getDegree())
			{
			case Bachelor:
				yearsToGraduate = this->students[i].startAge + bachelorYears - this->students[i].getAge();
				break;
			case Master:
				yearsToGraduate = this->students[i].startAge + masterYears - this->students[i].getAge();
				break;
			case PhD:
				yearsToGraduate = this->students[i].startAge + PhDYears - this->students[i].getAge();
				break;
			}
			if (yearsToGraduate>=1)
			{
				filteredStudents[filteredSize++] = students[i];
			}
		}
	}

	for (int i = 0; i < filteredSize - 1; i++) 
	{
		for (int j = 0; j < filteredSize - i - 1; j++) 
		{
			if (filteredStudents[j].getRank() > filteredStudents[j + 1].getRank())
			{
				StudentAthlete temp = filteredStudents[j];
				filteredStudents[j] = filteredStudents[j + 1];
				filteredStudents[j + 1] = temp;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < filteredSize && count < 5; i++) 
	{
		std::cout << "Name: " << filteredStudents[i].getName() << ", Rank: " << filteredStudents[i].getRank() << std::endl;
		count++;
	}

	delete[] filteredStudents;
}

void Students::copyFrom(const Students& other)
{
	students = new StudentAthlete[other.capacity];
	for (int i = 0; i < other.size; i++) 
	{
		students[i] = other.students[i];
	}
	size = other.size;
	capacity = other.capacity;
}

void Students::free()
{
	delete[] students;
}
