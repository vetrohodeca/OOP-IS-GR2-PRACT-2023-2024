#include <iostream>

// Task1
enum Month {
	InvalidMonth = 0,
	January = 1,
	Febuary,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	Octomber,
	November,
	December
};
struct Calendar
{
	Month mnth;
	unsigned year;
};
void PrintMonth(const Month& mnth)
{
	switch (mnth)
	{
	case January:  std::cout << "January";
		break;
	case Febuary: std::cout << "Febuary";
		break;
	case March:std::cout << "March";
		break;
	case April:std::cout << "April";
		break;
	case May:std::cout << "May";
		break;
	case June:std::cout << "June";
		break;
	case July:std::cout << "July";
		break;
	case August:std::cout << "August";
		break;
	case September:std::cout << "September";
		break;
	case Octomber:std::cout << "Octomber";
		break;
	case November:std::cout << "November";
		break;
	case December:std::cout << "December";
		break;
	default:std::cout << "Incorrect month";
		break;
	}
}
void PrintDate(const Calendar& date)
{
	PrintMonth(date.mnth);
	std::cout << " " << date.year;
}
void PrintPreviousMounthYear(const Calendar& date)
{
	Month previousMnth;
	unsigned previousYear;

	if (date.mnth == January)
	{
		previousMnth = December;
	}
	else
	{
		previousMnth = (Month)(date.mnth - 1);
	}

	if (date.year == 0)
	{
		std::cout << "There isn't previous year\n";
	}
	else
	{
		previousYear = date.year - 1;
	}

	std::cout << "Previous year: " << previousYear << std::endl << "Previous month";
	PrintMonth(previousMnth);
}

void PrintNextMounthYear(const Calendar& date)
{
	Month nextMnth;
	unsigned nextYear;

	if (date.mnth == December)
	{
		nextMnth = January;
	}
	else
	{
		nextMnth = (Month)(date.mnth + 1);
	}

	nextYear = date.year + 1;

	std::cout << "Next year: " << nextYear << std::endl << "Next month";
	PrintMonth(nextMnth);
}

// Task 2
struct Product
{
	unsigned id;
	Calendar loadingdate;
	Calendar selldate{ InvalidMonth, 0 };
};

void sell(Product& product, Calendar selldate)
{
	if (product.loadingdate.year < selldate.year || (product.loadingdate.year == selldate.year && product.loadingdate.mnth <= selldate.mnth))
	{
		product.selldate = selldate;
	}
	else
	{
		std::cout << "invalid operation, the product was not load";
	}
}

// Task 3
enum class Gender : char {
	female = 'f',
	male = 'm'
};

struct Person
{
	char UIN[11];
	unsigned postCode;
	Gender gender;
};

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool isFourDigitNumber(unsigned number)
{
	return number > 999 && number < 10000;
}

bool isUINvalid(const char* UIN)
{
	for (int i = 0; i <= 10; i++)
	{
		if (!isDigit(UIN[i]))
		{
			return false;
		}
	}

	return true;
}

bool isPersonValid(const Person& person)
{
	return isUINvalid(person.UIN) && isFourDigitNumber(person.postCode);
}

enum class Manifactor
{
	Mercedes,
	Audi,
	BMW,
	Fiat,
	Opel,
	Ford
};

struct Car
{
	Manifactor manifactor;
	unsigned price;
	Calendar firstRegistrationDate;
	Person owner;
};

bool hasGreaterValue(const Car& lhs, const Car& rhs)
{
	return lhs.price * lhs.firstRegistrationDate.year * 0.1 > rhs.price * rhs.firstRegistrationDate.year * 0.1;
}

//Task 4
struct ComplexNumber
{
	double realPart = 0;
	double imaginaryPart = 0;
};

void printComplexNumber(const ComplexNumber& complexNumber)
{
	std::cout << complexNumber.realPart << " + " << complexNumber.imaginaryPart << "i" << std::endl;
}

double getAbsoluteValue(const ComplexNumber& complexNumber)
{
	return std::sqrt(complexNumber.realPart * complexNumber.realPart + complexNumber.imaginaryPart * complexNumber.imaginaryPart);
}

void addComplexNumber(ComplexNumber& lhs, const ComplexNumber& rhs)
{
	lhs.realPart += rhs.realPart;
	lhs.imaginaryPart += rhs.imaginaryPart;
}

void multiplyComplexNumber(ComplexNumber& lhs, const ComplexNumber& rhs)
{
	lhs.realPart = lhs.realPart * rhs.realPart + lhs.imaginaryPart * rhs.imaginaryPart;
	lhs.imaginaryPart = lhs.realPart * rhs.imaginaryPart + lhs.imaginaryPart * rhs.realPart;
}

 // Task 5
union Number {
    int intNum;
    double doubleNum;
};

// Task 6
union ByteNumber {
    int fullNum;
    char bytes[sizeof(int)];
};


int main() 
{
   // Task 5
    // Declare a Number
    Number number;

    // Assign an integer to it
	number.intNum = 13;
    std::cout << "Integer: " << number.intNum << std::endl;

    // Assign a double to it
	number.doubleNum = 12.24;
    std::cout << "Double: " << number.doubleNum << std::endl; // Outputs 12.24

    // Re-Accessing the integer
    std::cout << "Integer: " << number.intNum << std::endl; // Will not output 13, because the memory space is now occupied by doubleNum

    //Task 6
    ByteNumber num;

    num.fullNum = 12345678;

    std::cout << "Full number: " << num.fullNum << '\n';
    int result = 0;
    for (size_t i = 0; i < sizeof(num.fullNum); ++i) {
        result |= ((0xff & num.bytes[i])) << (i * 8);
    }

    std::cout << "Number using bytes: " << result << '\n';

    return 0;
}