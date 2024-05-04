#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
using namespace std;
class Course
{
private:
	string courseName;
	string courseCode;
	int creditHours;
	string department;
	int course_num;
public:
	Course(){
		courseName = " ";
		courseCode = " ";
		creditHours = 0;
		department = " ";
	}
	void setCourseName(string name) {
		courseName = name;
	}
	string getCourseName() {
		return courseName;
	}
	void setCourseCode(string code) {
		courseCode = code;
	}
	string getCourseCode() {
		return courseCode;
	}
	void setCreditHours(int hours) {
		creditHours = hours;
	}
	int getCreditHours() {
		return creditHours;
	}
	void setDepartment(string dept) {
		department = dept;
	}
	string getDepartment() {
		return department;
	}
	void displayCourse() {
		cout << "Course Name: " << courseName << endl;
		cout << "Course Code: " << courseCode << endl;
		cout << "Credit Hours: " << creditHours << endl;
		cout << "Department: " << department << endl;
	}
	void setCourse() {
		cout << "Enter the name of the course: ";
		cin.ignore();
		getline(cin, courseName);
		cout << "Enter the department: ";
		cin.ignore();
		getline(cin, department);
		cout << "Enter the course code: ";
		cin.ignore();
		getline(cin, courseCode);
		do {
			cout << "Enter the credit hour of the course (0:4): ";
			if (!(cin >> course_num)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a number (0:4).\n";
				continue;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (course_num >= 0 && course_num <= 4) {
				creditHours = course_num;
				break;
			}
			else {
				cout << "The credit hour is not valid\n";
			}
		} while (creditHours >= 0 || creditHours <= 4);
	}
};
#endif