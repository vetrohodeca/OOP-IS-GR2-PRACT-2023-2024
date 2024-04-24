#include <iostream>

class MyString
{
	char* _data;
	size_t size;

	void copyFrom(const MyString& data);
	void free();
public:

	MyString();
	MyString(const char* data);


	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	size_t length() const;
	MyString& operator+=(const MyString& other);

	char& operator[](size_t index);
	char operator[](size_t index) const;
	~MyString();
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend bool operator==(const MyString& lhs, const MyString& rhs);

};
MyString operator+(const MyString& lhs, const MyString& rhs);

