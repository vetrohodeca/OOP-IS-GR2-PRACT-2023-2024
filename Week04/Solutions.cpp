
#pragma warning (disable : 4996)

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;


// TASK 1

void writeToFile(const char* fileName)
{
    unsigned count;
    std::cin >> count;

    int* arayy = new int[count];

    for (int i = 0; i < count; i++)
    {
        std::cin>> arayy[i];
    }

    std::ofstream ofs(fileName, std::ios::binary);

    ofs.write((const char*)(&count), sizeof(count));
    ofs.write((const char*)(arayy), sizeof(arayy));

    ofs.close();
    ofs.flush();

    delete[] arayy;
}

//TASK 2
//read array from binary file

int* readFromFile(const char* fileName)
{
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs.is_open())
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return nullptr;
    }

    unsigned count;

    ifs.read((char*)(&count), sizeof(count));

    int* arayy = new int[count];

    ifs.read((char*)arayy, sizeof(int) * count);

    return arayy;
}


// TASK 3

int findLargestNumber(const char* fileName)
{
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs.is_open() || !ifs)
    {
        std::cerr << "Error opening the file" << std::endl;
        return 0;
    }

    int largestNumber;

    if (!ifs.read((char*)&largestNumber, sizeof(largestNumber))) // can be also used the min value of int
    {
        std::cerr<<"Error occurred"<<std::endl;
    }

    int currentNumber;

    while (ifs.read((char*)&currentNumber, sizeof(currentNumber)))
    {
        if (currentNumber > largestNumber)
        {
            largestNumber = currentNumber;
        }
    }

    return largestNumber;
}

// TASK 4

struct Customer
{
    char* customerName = nullptr;
    unsigned customerId = 0;
    unsigned age = 0;
};

void writeCustomerToFile(const Customer& customer, ofstream& ofs)
{
    unsigned customerNameLen = strlen(customer.customerName); 
    ofs.write((const char*)&customerNameLen, sizeof(customerNameLen));
    ofs.write(customer.customerName, customerNameLen);
    ofs.write((const char*)&customer.customerId, sizeof(customer.customerId));   
    ofs.write((const char*)&customer.age, sizeof(customer.age));
}

Customer readCustomer(ifstream& ifs)
{
    Customer customer;

    unsigned customerNameLen;
    ifs.read((char*)&customerNameLen, sizeof(customerNameLen));

    customer.customerName = new char[customerNameLen + 1];
    ifs.read(customer.customerName, customerNameLen);
    customer.customerName[customerNameLen] = '\0'; // Null-terminate the string

    ifs.read((char*)&customer.age, sizeof(customer.age));
    ifs.read((char*)&customer.customerId, sizeof(customer.customerId));

    ifs.clear();

    return customer;
}

struct Order
{
    double price = 0;
    double vat;
    Customer customer;
};

void writeOrderToFile(std::ofstream& ofs, const Order& order)
{
    ofs.write((const char*)&order.price, sizeof(order.price));
    ofs.write((const char*)&order.vat, sizeof(order.vat));
    writeCustomerToFile(order.customer, ofs);
}

void writeOrdersToFile(std::ofstream& ofs, Order* orders, size_t numOrders)
{
    if (!ofs.is_open() || !ofs.good())
    {
        std::cerr << "Error opening file: " << std::endl;
        return;
    }

    ofs.write((const char*)&numOrders, sizeof(numOrders));

    for (int i = 0; i < numOrders; i++)
    {
        writeOrderToFile(ofs, orders[i]);
    }

}

Order readOrderFromFile(std::ifstream& ifs)
{
    Order result;

    ifs.read((char*)&result.price, sizeof(result.price));
    ifs.read((char*)&result.vat, sizeof(result.vat));

    result.customer = readCustomer(ifs);

    return result;
}

Order* readOrdersFromFile(std::ifstream& ifs)
{
    size_t numOrders;
    ifs.read((char*)&numOrders, sizeof(numOrders));

    Order* orders = new Order[numOrders];
    for (size_t i = 0; i < numOrders; ++i)
    {
        orders[i] = readOrderFromFile(ifs);
    }

    return orders;
}

// TASK 5

enum class Degree : unsigned char
{
    BACHELOR = 0, 
    MASTER = 1, 
    DOCTORATE = 2
};

enum class EducationForm : unsigned char 
{ 
    REGULAR = 0,
    PART_TIME = 1 
};

enum class Specialty : unsigned char
{
    COMPUTER_SCIENCE = 0,
    MATHEMATICS = 1,
    INFORMATION_SYSTEM = 2,
    SOFTWARE_ENGINEERING = 3,
    INFORMATICS = 4
};

const char* degreeToString(Degree degree) {
    switch (degree) {
    case Degree::BACHELOR: return "Bachelor";
    case Degree::MASTER: return "Master";
    case Degree::DOCTORATE: return "Doctorate";
    default: return "Unknown";
    }
}

const char* educationFormToString(EducationForm form) {
    switch (form) {
    case EducationForm::REGULAR: return "Regular";
    case EducationForm::PART_TIME: return "Part-Time";
    default: return "Unknown";
    }
}

const char* specialtyToString(Specialty specialty) {
    switch (specialty) {
    case Specialty::COMPUTER_SCIENCE: return "Computer Science";
    case Specialty::MATHEMATICS: return "Mathematics";
    case Specialty::INFORMATION_SYSTEM: return "Information System";
    case Specialty::SOFTWARE_ENGINEERING: return "Software Engineering";
    case Specialty::INFORMATICS: return "Informatics";
    default: return "Unknown";
    }
}


struct Student
{
    char* name;
    char facultyNumber[11];
    Specialty major;
    Degree degree;
    EducationForm educationForm;
};

void freeStudent(Student& student)
{
    delete[] student.name;
}

void writeStudentToFile(std::ofstream& ofs, const Student& student)
{
    unsigned nameLen = strlen(student.name);

    ofs.write((const char*)&nameLen, sizeof(nameLen));
    ofs.write(student.name, nameLen);
    ofs.write(student.facultyNumber, 10);
    ofs.write((const char*)&student.major, sizeof(student.major));
    ofs.write((const char*)&student.degree, sizeof(student.degree));
    ofs.write((const char*)&student.educationForm, sizeof(student.educationForm));
}

Student readStudentFromFile(std::ifstream& ifs)
{
    Student student;

    unsigned nameLen;
    ifs.read((char*)&nameLen, sizeof(nameLen));

    student.name = new char[nameLen + 1];

    ifs.read(student.name, nameLen);
    student.name[nameLen] = '\0';
    ifs.read(student.facultyNumber, 10);
    student.facultyNumber[10] = '\0';
    ifs.read((char*)&student.major, sizeof(student.major));
    ifs.read((char*)&student.degree, sizeof(student.degree));
    ifs.read((char*)&student.educationForm, sizeof(student.educationForm));

    return student;
}

constexpr unsigned UNIVERSITY_CAPACITY = 128;

struct University
{
    char* name;
    Student students[UNIVERSITY_CAPACITY];
    unsigned size = 0;
};

void addStudentToUniversity(University& university, const char* name, const char* facultyNumber, Specialty major, Degree degree, EducationForm educationForm)
{
    if (university.size >= UNIVERSITY_CAPACITY)
    {
        std::cerr << "University capacity exceeded." << std::endl;
        return;
    }

    Student newStudent;
    newStudent.name = new char[strlen(name) + 1];
    strcpy(newStudent.name, name);
    strcpy(newStudent.facultyNumber, facultyNumber);
    newStudent.major = major;
    newStudent.degree = degree;
    newStudent.educationForm = educationForm;

    university.students[university.size++] = newStudent;
}

void printUniversityStudents(const University& university)
{
    std::cout << "Students in " << university.name << ":" << std::endl;

    for (unsigned i = 0; i < university.size; ++i)
    {
        const Student& student = university.students[i];
        std::cout << "Name: " << student.name << std::endl;
        std::cout << "Faculty Number: " << student.facultyNumber << std::endl;
        std::cout << "Major: " << specialtyToString(student.major) << std::endl;
        std::cout << "Degree: " << degreeToString(student.degree) << std::endl;
        std::cout << "Education Form: " << educationFormToString(student.educationForm) << std::endl << std::endl;
    }
}

void saveUniversityToFile(const University& university, const char* filename)
{
    std::ofstream ofs(filename, std::ios::binary);

    if (!ofs.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    ofs.write((const char*)&university.size, sizeof(university.size));

    unsigned universityNameLen = strlen(university.name);
    ofs.write((const char*)&universityNameLen, sizeof(universityNameLen));
    ofs.write(university.name, universityNameLen);

    for (unsigned i = 0; i < university.size; ++i)
    {
        writeStudentToFile(ofs, university.students[i]);
    }

    ofs.close();
}

University loadUniversityFromFile(const char* filename)
{
    University university;

    std::ifstream ifs(filename, std::ios::binary);

    if (!ifs.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return university;
    }

    ifs.read((char*)&university.size, sizeof(university.size));

    unsigned universityNameLen;
    ifs.read((char*)&universityNameLen, sizeof(universityNameLen));

    university.name = new char[universityNameLen + 1];
    ifs.read(university.name, universityNameLen);
    university.name[universityNameLen] = '\0'; // Null-terminate the string

    for (unsigned i = 0; i < university.size; ++i)
    {
        university.students[i] = readStudentFromFile(ifs);
    }

    ifs.close();

    return university;
}

void freeUniversity(University& uni)
{
    for (int i = 0; i < uni.size; i++)
        freeStudent(uni.students[i]);
}

int main()
{
    University fmi;
    fmi.name = new char[50];
    strcpy(fmi.name, "Faculty of Mathematics and Informatics");

    addStudentToUniversity(fmi, "John Doe", "1234567890", Specialty::COMPUTER_SCIENCE, Degree::BACHELOR, EducationForm::REGULAR);
    addStudentToUniversity(fmi, "Jane Smith", "0987654321", Specialty::INFORMATICS, Degree::MASTER, EducationForm::PART_TIME);

    printUniversityStudents(fmi);

    saveUniversityToFile(fmi, "university.dat");

    University loadedUniversity = loadUniversityFromFile("university.dat");
   
    printUniversityStudents(loadedUniversity);

    freeUniversity(fmi);
    freeUniversity(loadedUniversity);
 
    return 0;

}
