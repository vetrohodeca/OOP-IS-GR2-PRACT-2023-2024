// streamtask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <fstream>

constexpr int MAX_LINE_SIZE = 1024;
constexpr int MAX_WORD_SIZE = 128;



bool copyFile(const char* source_filename, const char* destination_filename) {

    std::ifstream source_file(source_filename);
    if (!source_file.is_open()) 
    {
        std::cerr << "Error opening source file." << std::endl;
        return false;
    }

    std::ofstream destination_file(destination_filename);
    if (!destination_file.is_open()) 
    {
        std::cerr << "Error opening destination file." << std::endl;
        source_file.close(); 
        return false;
    }

    char line[MAX_LINE_SIZE];

    while (source_file.getline(line, MAX_LINE_SIZE)) 
    {
        destination_file << line << std::endl;
    }

    source_file.close();
    destination_file.close();

    std::cout << "File copied successfully." << std::endl;

    return true;
}

size_t getLinesCount(std::ifstream& file)
{
    size_t count = 0;

    while (!file.eof())
    {
        char buff[MAX_LINE_SIZE];
        file.getline(buff, MAX_LINE_SIZE);
        count++;
    }

    file.seekg(0, std::ios::beg); //resets the stream's get position.
    file.clear();

    return count;

}

unsigned getWordsCount(const char* fileName)
{
    std::ifstream ifs(fileName);
    if (!ifs.is_open())
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 0;
    }

    unsigned counter = 0;
    char word[MAX_WORD_SIZE];

    while (ifs >> word)
    {
        ++counter;
    }

    ifs.close();

    return counter;

}


struct Person {
    char name[64];
    bool gender;
    unsigned age;
};

void writePersonsToFile(const Person* persons, size_t size, const char* fileName) {
    std::ofstream ofs(fileName);
    if (!ofs.is_open()) 
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    for (size_t i = 0; i < size; ++i) 
    {
        ofs << persons[i].name << ' ' << persons[i].gender << ' ' << persons[i].age << std::endl;
    }

    ofs.close();
}

Person* readPersonsFromFile(const char* fileName) 
{
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) 
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return nullptr;
    }

    size_t size = getLinesCount(ifs); 
    Person* persons = new Person[size];

    for (size_t i = 0; i < size; ++i) 
    {
        ifs >> persons[i].name >> persons[i].gender >> persons[i].age;
        ifs.ignore();
    }

    ifs.close();

    return persons;
}


const int CONVERT_LETTER = 'a' - 'A';

bool isCapsLetter(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isSmallLetter(char ch) {
    return ch >= 'a' && ch <= 'z';
}

void convertLetters(char* buffer, bool toCaps)
{
    int index = 0;

    while (buffer[index] != '\0')
    {
        if (toCaps)
        {
            if (isSmallLetter(buffer[index]))
            {
                buffer[index] -= CONVERT_LETTER;
            }
        }
        else
        {
            if (isCapsLetter(buffer[index]))
            {
                buffer[index] += CONVERT_LETTER;
            }
        }

        index++;
    }
}

void convertLettersCaseInFile(const char* fileName, bool toCaps) 
{
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        std::cerr << "Error opening input file: " << fileName << std::endl;
        return;
    }

    std::ofstream ofs("temp.txt");
    if (!ofs.is_open()) {
        std::cerr << "Error opening temporary file." << std::endl;
        ifs.close();
        return;
    }

    char buffer[MAX_LINE_SIZE];

    while (ifs.getline(buffer, MAX_LINE_SIZE)) {
        convertLetters(buffer, toCaps);
        ofs << buffer << std::endl;
    }

    ifs.close();
    ofs.close();

    copyFile("temp.txt", fileName);
}


int main()
{
}
