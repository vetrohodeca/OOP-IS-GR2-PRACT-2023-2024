// TasksWeek01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Task 1
void resize(int& capacity, int& size, int*& arr)
{
    capacity *= 2;
    int* newArr = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}

void pushFront(int*& arr, int& capacity, int& size, int& number)
{
    if (size == capacity)
    {
        resize(capacity, size, arr);
    }

    for (int i = 0; i < size; i++)
    {
        arr[size - i] = arr[size - (i + 1)];
    }

    arr[0] = number;
    size++;
}

// Task 2

void popFront(int*& arr, int& size)
{
    size--;

    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}

// Task 3

enum class BankAccountType
{
    Payment,
    Recruitment,
    Deposit
};

enum class Currency
{
    BGN,
    EUR,
    USD,
    CHF,
    GBP
};

struct BankAccount
{
    long number;
    double balance;
    BankAccountType type;
    Currency currency;

    void depositMoney(double moneyAmmount)
    {
        balance += moneyAmmount;
    }
    void withdraw(double moneyAmmount)
    {
        if (moneyAmmount <= balance)
        {
            balance -= moneyAmmount;
        }
        else
        {
            std::cout << "Transaction unsuccessful! There is not enough amount.";
        }
    }
    void changeCurrency(Currency newCurrency)
    {
        currency = newCurrency;
    }
};

//Task 4

enum Colors : unsigned char {
    RED = 4,
    GREEN = 2,
    BLUE = 1,
};

struct Color {
    unsigned char color : 3;
};

void printColor(const Color& col) {

    switch (col.color) {
    case BLUE: std::cout << "BLUE"; break;
    case GREEN: std::cout << "GREEN"; break;
    case RED: std::cout << "RED"; break;
    default: std::cout << "NOT BASIC COLOR";
    }
}
void oppositeColor(Color& col)
{
    col.color = ~col.color; // changes the member of color 
}
void removeColor(Color& col1, const Color& col2)
{
    col1.color = col1.color & (~col2.color); // removes col2 from col1
}
void fusesOfColor(Color& col1, const Color& col2)
{
    col1.color = col1.color | col2.color;
}

// Task 5

struct Point {
    int x;
    int y;

    void print() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }
};

// Task 6

struct Line {
    Point p1, p2;

    double length() const
    {
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    void print() const
    {
        std::cout << "P1";
        p1.print();
        std::cout << ", P2";
        p2.print();
        std::cout << "Length is " << length() << std::endl;
    }
};
bool isEqual(const Line& line1, const Line& line2)
{
    return line1.length() == line2.length();
}

// Task 7

struct Triangle {
    Line line1, line2, line3;


    bool isValid() const
    {
        double len1 = line1.length();
        double len2 = line2.length();
        double len3 = line3.length();

        // check if triangle with such sides exists
        if (len1 + len2 <= len3 || len1 + len3 <= len2 || len2 + len3 <= len1)
        {
            return false;
        }
        if (((line1.p1.x != line2.p1.x || line1.p1.y != line2.p2.y) ||
            (line2.p2.x != line3.p2.x || line2.p2.y != line3.p2.y) ||
            (line3.p1.x != line1.p2.x || line3.p1.y != line1.p2.y)))
        {
            return false;
        }


        return true;
    }

    double perimeter() const
    {
        return line1.length() + line2.length() + line3.length();
    }

    double area() const
    {
        double s = this->perimeter() / 2;
        return sqrt(s * (s - line1.length()) * (s - line2.length()) * (s - line3.length()));
    }

    void print() const
    {
        std::cout << "Triangle: " << std::endl;
        std::cout << "Line1: " << "Start: (" << line1.p1.x << ", " << line1.p1.x << "), End: (" << line1.p2.x << ", " << line1.p2.y << ")" << std::endl;
        std::cout << "Line2: " << "Start: (" << line2.p1.x << ", " << line2.p1.y << "), End: (" << line2.p2.x << ", " << line2.p2.y << ")" << std::endl;
        std::cout << "Line3: " << "Start: (" << line3.p1.x << ", " << line3.p1.y << "), End: (" << line3.p2.x << ", " << line3.p2.y << ")" << std::endl;
    }
};

//Task 8

struct Pyramid
{
    Triangle base;
    double height;

    double volume() const
    {
        return base.area()*height/3;
    }
};

// Task 8
int main()
{
    // Task 1

    //int capacity = 5, size = 0;
    //int* arr = new int[capacity];

    //for (int i = 0; i < 10; i++)
    //{
    //	pushFront(arr, capacity, size, i);

    //	std::cout << "CAP = " << capacity << "\n";
    //	std::cout << "SIZE= " << size << "\n";
    //	for (int j = 0; j < size; j++)
    //	{
    //		std::cout << arr[j] << ' ';
    //	}
    //	std::cout << "\n";
    //}

    // Task 2

    //int capacity = 5, size = 0;
    //int* arr = new int[capacity];

    //for (int i = 0; i < 10; i++)
    //{
    //    pushFront(arr, capacity, size, i);
    //}

    //for (int i = 0; i < 10; i++)
    //{
    //    popFront(arr, size);

    //    std::cout << "CAP = " << capacity << "\n";
    //    std::cout << "SIZE= " << size << "\n";
    //    for (int j = 0; j < size; j++)
    //    {
    //        std::cout << arr[j] << ' ';
    //    }
    //    std::cout << "\n";
    //}

    // Task 3

    //BankAccount bankAccount;
    //bankAccount.number = 123456789;
    //bankAccount.balance = 1000.0;
    //bankAccount.currency = Currency::BGN;
    //std::cout << "Before deposit, balance: " << bankAccount.balance << " " << std::endl;
    //bankAccount.depositMoney(500.0);
    //std::cout << "After deposit, balance: " << bankAccount.balance << " " << std::endl;
    //bankAccount.changeCurrency(Currency::USD);
    //if (bankAccount.currency == Currency::USD)
    //{
    //    std::cout << "The current currency is USD";
    //}

    // Task 4

    //Color col1;
    //col1.color = BLUE;
    //Color col2;
    //col2.color = RED;

    //fusesOfColor(col1, col2);
    //std::cout << (int)(col1.color) << std::endl; // 5, col1.color is 101
    //oppositeColor(col1);
    //std::cout << (int)(col1.color) << std::endl;// 2, col1.color is 010
    //Color col3;
    //col3.color = GREEN;
    //removeColor(col2, col3);
    //std::cout << (int)(col2.color) << std::endl; // 4, col3.color is not contained in col2.color
    //removeColor(col1, col3);
    //std::cout << (int)col1.color << std::endl; // 0

    // Task 5

    //Point p;
    //p.x = 5;
    //p.y = 10;
    //p.print();

    // Task 6

    //Line line1{ {1, 2}, {4, 6} };
    //Line line2{ {2, 3}, {5, 7} };

    //line1.print();
    //line2.print();

    //if (isEqual(line1, line2)) 
    //{
    //    std::cout << "The lines are equal in length." << std::endl;
    //}
    //else 
    //{
    //    std::cout << "The lines are not equal in length." << std::endl;
    //}

    // Task 7
    
    //to be valied the triangle should be declared in the way that the beginning of the line 1 and line 2 are the same and the line 3 starts from the end of line 1 and end at the end of line 2
    //Line line1{ {0, 0}, {0, 4} };
    //Line line2{ {0, 0}, {3, 0} };
    //Line line3{ {0, 4}, {3, 0} };
    //Triangle triangle;
    //triangle.line1 = line1;
    //triangle.line2 = line2;
    //triangle.line3 = line3;
    //std::cout << "Trangle is valid: " << std::boolalpha << triangle.isValid() << std::endl;
    //std::cout << "Triangle area is: " << triangle.area() << std::endl;
    //std::cout << "Triangle perimeter is: " << triangle.perimeter() << std::endl;

    //Task  8
    Line line1{ {0, 0}, {0, 4} };
    Line line2{ {0, 0}, {3, 0} };
    Line line3{ {0, 4}, {3, 0} };
    Triangle triangle;
    triangle.line1 = line1;
    triangle.line2 = line2;
    triangle.line3 = line3;
    Pyramid pyramid;
    pyramid.base = triangle;
    pyramid.height = 3;
    std::cout << "Pyramid volume is: " << pyramid.volume() << std::endl;

    return 0;
}
