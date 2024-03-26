#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include<cstring>

enum Department { Algebra, Geometry, ComputerScience };

struct Student {
private:
    char firstName[30];
    char lastName[30];
    int facultyNumber;
    int marks[32];
    int marksCount = 0;

public:
    Student()
    {
        setFirstName("");
        setLastName("");
        setFacultyNumber(0);
        const int defaultMarks[] = { 5, 4, 6, 3, 5 };
        setMarks(defaultMarks, 32);
        setMarksCount(0);
    }

    Student(const char* firstName, const char* lastName, int facultyNumber, const int* marks, int marksCount)
    {
        setFirstName(firstName);
        setLastName(lastName);
        setFacultyNumber(facultyNumber);
        setMarks(marks, 32);
        setMarksCount(marksCount);
    }

    void setFirstName(const char* firstName)
    {
        strcpy(this->firstName, firstName);
    }

    void setLastName(const char* lastName)
    {
        strcpy(this->lastName, lastName);
    }

    void setFacultyNumber(const int facultyNumber)
    {
        this->facultyNumber = facultyNumber;
    }

    void setMarks(const int* marks, const int size)
    {
        for (int i = 0; i < size && i < 32; i++)
        {
            this->marks[i] = marks[i];
        }
        this->marksCount = size;
    }

    void setMarksCount(int marksCount)
    {
        if (marksCount > 0)
        {
            this->marksCount = marksCount;
        }
        else
        {
            this->marksCount = 0;
        }
    }

    const char* getFirstName() const
    {
        return this->firstName;
    }

    const char* getLastName() const
    {
        return this->lastName;
    }

    const int getFacultyNumber() const
    {
        return this->facultyNumber;
    }

    const int* getMarks() const
    {
        return this->marks;
    }

    const int getMarksCount() const
    {
        return this->marksCount;
    }


    void addMark(int mark)
    {
        if (marksCount < 32)
        {
            marks[marksCount++] = mark;
        }
        else
        {
            std::cout << "This student has more than 32 grades!";
        }
    }

    void removeMark(int mark)
    {
        for (int i = 0; i < marksCount; i++)
        {
            if (marks[i] == mark) {
                for (int j = i; j < marksCount - 1; j++)
                {
                    marks[j] = marks[j + 1];
                }
                marksCount--;
                break;
            }
        }
    }

    float calculateAverageMark()
    {
        int sum = 0;
        for (int i = 0; i < marksCount; i++)
        {
            sum += marks[i];
        }
        return (float)sum / marksCount;
    }
};

struct Teacher {
private:
    char firstName[30];
    char lastName[30];
    Department department;

public:
    Teacher()
    {
        strcpy(firstName, "");
        strcpy(lastName, "");
        setDepartment(Department::Algebra);
    }

    Teacher(const char* firstName, const char* lastName, Department department)
    {
        strcpy(this->firstName, firstName);
        strcpy(this->lastName, lastName);
        setDepartment(department);
    }
    void setDepartment(const Department department)
    {
        this->department = department;
    }

    const char* getFirstName() const
    {
        return this->firstName;
    }

    const char* getLastName() const
    {
        return this->lastName;
    }

    const char* getDepartment() const 
    {
        switch (department) 
        {
        case Department::Algebra:
            return "Algebra";
        case Department::Geometry:
            return "Geometry";
        case Department::ComputerScience:
            return "Computer Science";
        default:
            return "Unknown";
        }
    }
};

struct Subject {
private:
    Student students[100];
    int studentCount = 0;
    Teacher teacher;

public:

    Subject()
    {
        setStudentCount(studentCount);
        Student students[100];
        setStudents(students, 0);
        setTeacher(Teacher());

    }

    Subject(Student* students, int studentCount, Teacher teacher)
    {
        setStudentCount(studentCount);
        setStudents(students, this->studentCount);
        setTeacher(teacher);
    }

    void addStudent(const Student& student)
    {
        if (studentCount < 100)
        {
            students[studentCount++] = student;
        }
        else
        {
            std::cout << "There are more than 100 students!";
        }
    }

    void setTeacher(const Teacher& newTeacher)
    {
        teacher = newTeacher;
    }

    void setStudentCount(int studentCount)
    {
        this->studentCount = studentCount;
    }

    void setStudents(Student* students, int count)
    {
        studentCount = count;
        for (int i = 0; i < count; ++i) {
            this->students[i] = students[i];
        }
    }

    int getStudentCount() const
    {
        return this->studentCount;
    }

    const Student* getStudents() const
    {
        return this->students;
    }

    const Teacher getTeacher() const
    {
        return this->teacher;
    }

    void serialize(const char* destinationFile)
    {
        std::ofstream out(destinationFile);

        if (!out) {
            std::cerr << "Cannot open the file.\n";
            return;
        }

        for (int i = 0; i < studentCount; i++)
        {
            out << students[i].getFirstName() << ' ' << students[i].getLastName() << ' ';
            out << students[i].getFacultyNumber() << ' ' << students[i].getMarksCount() << ' ';

            const int* marks = students[i].getMarks();
            for (int j = 0; j < students[i].getMarksCount(); j++)
            {
                out << marks[j] << ' ';
            }
            out << '\n';
        }

        out << teacher.getFirstName() << ' ' << teacher.getLastName() << ' ';
        out << teacher.getDepartment();

        out.close();
    }

    void deserialize(const char* sourceFile)
    {
        std::ifstream in(sourceFile);
        if (!in)
        {
            std::cerr << "Cannot open the file.\n";
            return;
        }

        studentCount = 0;

        while (!in.eof())
        {
            char firstName[30];
            char lastName[30];
            int facultyNumber;
            int marksCount;

            in >> firstName >> lastName >> facultyNumber >> marksCount;

            Student temp;
            temp.setFirstName(firstName);
            temp.setLastName(lastName);
            temp.setFacultyNumber(facultyNumber);
            temp.setMarksCount(marksCount);

            int marks[32];
            for (int j = 0; j < marksCount; j++)
            {
                in >> marks[j];
            }
            temp.setMarks(marks, marksCount);

            if (studentCount < this->studentCount)
            {
                students[studentCount++] = temp;
            }
            else
            {
                std::cout << "Number of students exceeds 100!\n";
                return;
            }
        }

        in.close();
    }
};

//task 2
struct BankAccount {
private:
    char holderName[51];
    char IBAN[36];
    double balance;
    double savingsBalance;
    bool isLocked;

public:

    const char* getIBAN() const
    {
        return this->IBAN;
    }

    double getBalance() const
    {
        return this->balance;
    }

    double getSavingsBalance() const
    {
        return this->savingsBalance;
    }

    void setHolderName(const char* name)
    {
        if (strlen(name) > 5)
        {
            strcpy(this->holderName, name);
        }
    }

    void setIBAN(const char* IBAN)
    {
        if (strlen(IBAN) > 10)
        {
            strcpy(this->IBAN, IBAN);
        }
    }

    void setBalance(double balance)
    {
        if (balance > 0)
        {
            this->balance = balance;
        }
    }
    void setSavingsBalance(double savingsBalance)
    {
        if (savingsBalance > 0)
        {
            this->savingsBalance = savingsBalance;
        }
    }

    void addMoney(double money)
    {
        if (money > 0)
        {
            this->balance += money;
        }
        else
        {
            std::cout << "You can not add negative number!";
        }
    }

    void withdrawMoney(double money)
    {
        if (money > this->balance)
        {
            std::cout << "There are not enough money in the account!";
        }
        else
        {
            this->balance -= money;
        }
    }

    void addMoneyToSavings(double money)
    {
        if (money > balance)
        {
            std::cout << "There are not enough money in the account!";
        }
        else
        {
            this->savingsBalance += money;
            this->balance -= money;
        }
    }

    void withdrawFromSavings(double money)
    {
        if (money > savingsBalance)
        {
            std::cout << "There are not enough money in the savings!";
        }
        else
        {
            this->savingsBalance -= money;
            this->balance += money;
        }
    }
    void unlockAccount()
    {
        this->isLocked = true;
    }
    void lockAccount()
    {
        this->isLocked = false;
    }

    void deleteAccount()
    {
        this->balance = 0;
        this->savingsBalance = 0;
        holderName[0] = '\0';
        for (int i = 0; i < 36; i++)
        {
            IBAN[i] = 0;
        }
    }
};

class Bank {
private:
    char name[20];
    BankAccount accounts[1000];
    int numberOfAccounts;

public:
    Bank()
    {
        strcpy(this->name, "");
        this->numberOfAccounts = 0;
    }

    Bank(const char* bankName)
    {
        strcpy(this->name, bankName);
        this->numberOfAccounts = 0;
    }

    void addAccount(const BankAccount& account)
    {
        if (numberOfAccounts < 1000)
        {
            accounts[numberOfAccounts++] = account;
        }
    }

    void removeAccount(const char* iban)
    {
        for (int i = 0; i < numberOfAccounts; ++i)
        {
            if (strcmp(accounts[i].getIBAN(), iban) == 0)
            {
                for (int j = i; j < numberOfAccounts - 1; ++j)
                {
                    accounts[j] = accounts[j + 1];
                }
                numberOfAccounts--;
                break;
            }
        }
    }

    double getTotalBalance() const
    {
        double totalBalance = 0.0;
        for (int i = 0; i < numberOfAccounts; ++i)
        {
            totalBalance += accounts[i].getBalance();
            totalBalance += accounts[i].getSavingsBalance();
        }
        return totalBalance;
    }

    void transferMoney(const char* fromIBAN, const char* toIBAN, double amount)
    {
        for (int i = 0; i < numberOfAccounts; ++i) {
            if (strcmp(accounts[i].getIBAN(), fromIBAN) == 0)
            {
                accounts[i].withdrawMoney(amount);
            }
            else if (strcmp(accounts[i].getIBAN(), toIBAN) == 0)
            {
                accounts[i].addMoney(amount);
            }
        }
    }

    void lockAccount(const char* iban) {
        for (int i = 0; i < numberOfAccounts; ++i)
        {
            if (strcmp(accounts[i].getIBAN(), iban) == 0)
            {
                accounts[i].lockAccount();
                break;
            }
        }
    }

    void unlockAccount(const char* iban)
    {
        for (int i = 0; i < numberOfAccounts; ++i)
        {
            if (strcmp(accounts[i].getIBAN(), iban) == 0)
            {
                accounts[i].unlockAccount();
                break;
            }
        }
    }
};

//Task 3
struct Message {
private:
    char content[100];
    char sender[30];
    char receiver[30];
    bool isRead;

public:

    Message()
    {
        setContent("");
        setReceiver("");
        setSender("");
        this->isRead = false;
    }
    Message(const char* sender, const char* receiver, const char* content)
    {
        setContent(content);
        setReceiver(receiver);
        setSender(sender);
        this->isRead = false;
    }

    const char* getContent() const
    {
        return content;
    }

    const char* getSender() const
    {
        return sender;
    }

    const char* getReceiver() const
    {
        return receiver;
    }

    bool getIsRead() const
    {
        return isRead;
    }

    void setSender(const char* sender)
    {
        std::strcpy(this->sender, sender);
    }

    void setReceiver(const char* receiver)
    {
        std::strcpy(this->receiver, receiver);
    }

    void setContent(const char* content)
    {
        std::strcpy(this->content, content);
    }

    void setIsRead(bool isRead)
    {
        this->isRead = isRead;
    }

    void markAsRead()
    {
        this->isRead = true;
    }
};

struct User {
private:
    char username[30];
    char email[20];
    char password[10];
    Message sentMessages[20];
    Message receivedMessages[20];
    int sentCount;
    int receivedCount;

public:

    User()
    {
        setUsername("");
        setEmail("");
        setPassword("");
        this->sentCount = 0;
        this->receivedCount = 0;
    }
    User(const char* username, const char* email, const char* password)
    {
        setUsername(username);
        setEmail(email);
        setPassword(password);
        this->sentCount = 0;
        this->receivedCount = 0;
    }

    const char* getUsername() const
    {
        return username;
    }

    const char* getEmail() const
    {
        return email;
    }

    const char* getPassword() const
    {
        return password;
    }

    void setUsername(const char* username)
    {
        std::strcpy(this->username, username);
    }

    void setEmail(const char* email)
    {
        std::strcpy(this->email, email);
    }

    void setPassword(const char* password)
    {
        std::strcpy(this->password, password);
    }

    void sendMessage(User& receiver, const char* message)
    {
        if (sentCount < 100 && receiver.receivedCount < 100)
        {
            Message msg(this->username, receiver.username, message);
            this->sentMessages[this->sentCount++] = msg;
            receiver.receivedMessages[receiver.receivedCount++] = msg;
        }
        else
        {
            std::cout << "Inbox full. Message not sent!";
        }
    }
};

struct SocialMedia {
private:
    char name[30];
    User users[100];
    int userCount;

public:

    SocialMedia()
    {
        std::strcpy(this->name, "");
        this->userCount = 0;
    }

    SocialMedia(const char* name)
    {
        std::strcpy(this->name, name);
        this->userCount = 0;
    }

    void registerUser(const char* username, const char* email, const char* password)
    {
        if (userCount < 100)
        {
            users[userCount++] = User(username, email, password);
            std::cout << "User " << username << " registered successfully.";
        }
        else
        {
            std::cout << "Cannot register more users. Maximum limit reached.";
        }
    }

    User* login(const char* email, const char* password)
    {
        for (int i = 0; i < userCount; ++i)
        {
            if (std::strcmp(users[i].getEmail(), email) == 0 && std::strcmp(users[i].getPassword(), password) == 0)
            {
                std::cout << "User " << users[i].getUsername() << " logged in successfully.\n";
                return &users[i];
            }
        }
        std::cout << "Invalid email or password. Login failed.\n";
        return nullptr;
    }

    void sendMessage(User& sender, User& receiver, const char* message)
    {
        sender.sendMessage(receiver, message);
    }
};


int main()
{
    int AliceMarks[32] = {4,5,6};
    Student alice("Alice", "Smith", 12345, AliceMarks, 0);
    Student bob("Bob", "Johnson", 54321, AliceMarks, 0);
    Student carol("Carol", "Williams", 67890, AliceMarks, 0);

    // Adding marks to students
    alice.addMark(5);
    alice.addMark(4);
    alice.addMark(6);
    bob.addMark(3);
    bob.addMark(5);
    carol.addMark(6);
    carol.addMark(6);

    // Creating teacher
    Teacher mathTeacher("John", "Doe", Department::Algebra);

    // Creating subject
    Subject math;
    math.addStudent(alice);
    math.addStudent(bob);
    math.addStudent(carol);
    math.setTeacher(mathTeacher);

    // Serializing to file
    math.serialize("math_subject.txt");

    // Deserializing from file
    Subject mathFromFile;
    mathFromFile.deserialize("math_subject.txt");

    // Displaying data from deserialized object
    std::cout << "Teacher: " << mathFromFile.getTeacher().getFirstName() << " " << mathFromFile.getTeacher().getLastName() << std::endl;
    std::cout << "Department: " << mathFromFile.getTeacher().getDepartment() << std::endl;
    std::cout << "Students: " << std::endl;
    for (int i = 0; i < mathFromFile.getStudentCount(); ++i) 
    {
        std::cout << "Student " << i + 1 << ": " << mathFromFile.getStudents()[i].getFirstName() << " " << mathFromFile.getStudents()[i].getLastName() << std::endl;
        std::cout << "Faculty Number: " << mathFromFile.getStudents()[i].getFacultyNumber() << std::endl;
        std::cout << "Marks: ";
        const int* marks = mathFromFile.getStudents()[i].getMarks();
        for (int j = 0; j < mathFromFile.getStudents()[i].getMarksCount(); ++j) {
            std::cout << marks[j] << " ";
        }
        std::cout << std::endl;
    }

    //Task 1


    //Task 2
    //Bank bank("BestBank");

    //BankAccount account1;
    //account1.setHolderName("Ivan Petrov");
    //account1.setIBAN("BG12345678901234567890");
    //account1.setBalance(1200);
    //account1.setSavingsBalance(300);
    //account1.unlockAccount();

    //BankAccount account2;
    //account2.setHolderName("Georgi Hristob");
    //account2.setIBAN("BG09876543210987654321");
    //account2.setBalance(1300);
    //account2.setSavingsBalance(400);
    //account2.unlockAccount();

    //bank.addAccount(account1);
    //bank.addAccount(account2);

    //std::cout << "Total balance in the bank: " << bank.getTotalBalance() << std::endl;

    //bank.transferMoney("GB12345678901234567890", "GB09876543210987654321", 200.0);

    //std::cout << "Total balance in the bank after transfer: " << bank.getTotalBalance() << std::endl;

    //task 3
    //SocialMedia socialMedia("MySocialMedia");

    //socialMedia.registerUser("Ivancho", "vanio@abv.bg", "password1");
    //socialMedia.registerUser("Mariika", "mimi@maiil.bg", "password2");

    //User* loggedInUser1 = socialMedia.login("vanio@abv.bg", "password1");
    //User* loggedInUser2 = socialMedia.login("mimi@maiil.bg", "password2");

    //if (loggedInUser1 && loggedInUser2)
    //{
    //    socialMedia.sendMessage(*loggedInUser1, *loggedInUser2, "Hello from user 1");
    //    socialMedia.sendMessage(*loggedInUser2, *loggedInUser1, "Hello from user 2");
    //}

    return 0;
}