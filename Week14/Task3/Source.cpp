#include "Students.h"
#include<iostream>
int main() {
    Students studentsCollection;

    studentsCollection.addStudent(StudentAthlete("Ivan Ivanov", 20, true, "Football", 5, 2, false, "Sofia University", "12345", "Informatics", Bachelor, "Coach Ivanov", 10));
    studentsCollection.addStudent(StudentAthlete("Georgi Georgiev", 21, true, "Football", 8, 3, false, "Sofia University", "23456", "Mathematics", Bachelor, "Coach Petrov", 15));
    studentsCollection.addStudent(StudentAthlete("Dimitar Dimitrov", 22, true, "Football", 1, 4, false, "Sofia University", "34567", "Physics", Bachelor, "Coach Dimitrov", 20));
    studentsCollection.addStudent(StudentAthlete("Nikola Nikolov", 23, true, "Football", 6, 1, true, "Sofia University", "45678", "Chemistry", Master, "Coach Ivanov", 5));
    studentsCollection.addStudent(StudentAthlete("Kiril Kirilov", 19, true, "Football", 7, 1, false, "Ruse University", "56789", "Mechanics", Bachelor, "Coach Simeonov", 12));
    studentsCollection.addStudent(StudentAthlete("Vasil Vasilev", 24, true, "Football", 3, 5, false, "Sofia University", "67890", "Biology", PhD, "Coach Stoyanov", 25));
    studentsCollection.addStudent(StudentAthlete("Petar Petrov", 20, true, "Football", 4, 2, false, "Sofia University", "78901", "Computer Science", Bachelor, "Coach Ivanov", 14));
    studentsCollection.addStudent(StudentAthlete("Angel Angelov", 22, true, "Football", 2, 3, false, "Plovdiv University", "89012", "Engineering", Master, "Coach Georgiev", 10));
    studentsCollection.addStudent(StudentAthlete("Stefan Stefanov", 21, true, "Football", 9, 1, false, "Varna University", "90123", "Medicine", Bachelor, "Coach Dimitrov", 8));
    studentsCollection.addStudent(StudentAthlete("Hristo Hristov", 23, true, "Football", 10, 4, false, "Sofia University", "01234", "Law", Master, "Coach Simeonov", 18));

    std::cout << "Best Football Team:" << std::endl;
    studentsCollection.printBestTeam("Football", "Sofia University");

    return 0;
}
