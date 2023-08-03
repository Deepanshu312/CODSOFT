      // ***STUDENT GRADING SYSTEM***
/* Create a program that manages student grades. Allow the user
to input student names and their corresponding grades.
Calculate the average grade and display it along with the highest
and lowest grades */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    double grade;
};

int main() {
    vector<Student> students;
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Input student names and their corrsponding grades.
    for (int i = 0; i < numStudents; ++i) {
        Student student;
        cout << "Enter name of student " << i + 1 << ": "<<endl;
        cin >> student.name;
        cout << "Enter grade of student " << i + 1 << ": "<<endl;
        cin >> student.grade;
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
        highestGrade = max(highestGrade, student.grade);
        lowestGrade = min(lowestGrade, student.grade);
    }

    // Display results
    cout << "\nStudent Grades Summary:\n";
    for (const auto& student : students) {
        cout << student.name << ": " << student.grade << endl;
    }

    cout << "\nAverage Grade: " << averageGrade << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}