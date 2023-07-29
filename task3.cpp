      // ***STUDENT GRADING SYSTEM***
/* Create a program that manages student grades. Allow the user
to input student names and their corresponding grades.
Calculate the average grade and display it along with the highest
and lowest grades */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students;
    int numStudents;

    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    // Input student names and grades
    for (int i = 0; i < numStudents; ++i) {
        Student student;
        std::cout << "Enter name of student " << i + 1 << ": ";
        std::cin.ignore(); // Ignore newline character left in the input buffer
        std::getline(std::cin, student.name);
        std::cout << "Enter grade of student " << i + 1 << ": ";
        std::cin >> student.grade;
        students.push_back(student);
    }

    // Calculate the average grade
    double sumGrades = 0.0;
    for (const auto& student : students) {
        sumGrades += student.grade;
    }
    double averageGrade = sumGrades / numStudents;

    // Find highest and lowest grades
    double highestGrade = students[0].grade;
    double lowestGrade = students[0].grade;
    for (const auto& student : students) {
        highestGrade = std::max(highestGrade, student.grade);
        lowestGrade = std::min(lowestGrade, student.grade);
    }

    // Display results
    std::cout << "\nStudent Grades Summary:\n";
    for (const auto& student : students) {
        std::cout << student.name << ": " << student.grade << std::endl;
    }

    std::cout << "\nAverage Grade: " << averageGrade << std::endl;
    std::cout << "Highest Grade: " << highestGrade << std::endl;
    std::cout << "Lowest Grade: " << lowestGrade << std::endl;

    return 0;
}