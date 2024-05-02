#ifndef ACADEMICSTAFF_H
#define ACADEMICSTAFF_H
#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Student.h"
#include "Course.h"
#include "menu.h"
using namespace std;

class AcademicStaff : public User {
private:
    vector<int> CoursesTaught;
    string department;
    char char_check;
	int int_check;	
public:   
    void Set_TeachCourse(int course_num) {     
		CoursesTaught.push_back(course_num);
    }
    void viewStudentList() {
    }
    void update_studentsGrade() {
	}
    void Schedule_OfficeHours() {
    }
    void AcademicStaff_Menu() {
		cout << "Welcome to the Academic Staff Menu" << endl;
		cout << "1-View Courses Taught" << endl;
        cout << "2-Teach Course" << endl;
		cout << "3-Grade Assignment" << endl;
		cout << "4-Change password" << endl;
		cout << "5-Schedule Office Hours" << endl;
		cout << "6-Exit" << endl;
	}
    void setAcademicStaff_information() {
         cout << "Enter Staff name: ";
         cin.ignore();
         getline(cin, Username);
         cout << "Enter Staff ID: ";
         cin >> UserID;
         cout << "Enter Staff college: ";
         cin.ignore();
         getline(cin, college);
         cout << "Enter Staff department: ";
         getline(cin, department);
         cout << "Enter role (1-Student, 2-Teacher, 3-Admin): ";
         cin >> Role;
         cout << "Enter Staff email: ";
         cin.ignore();
         getline(cin, Email);
         cout << "Enter Staff password: ";
         getline(cin, Password);
    }
    void getAcademicStaff_information() {
		cout << "Staff name: " << Username << endl;
		cout << "Staff ID: " << UserID << endl;
		cout << "Staff college: " << college << endl;
		cout << "Staff department: " << department << endl;
		cout << "Staff role: " << Role << endl;
		cout << "Staff email: " << Email << endl;
		cout << "Staff password: " << Password << endl;
	}
    vector <int> get_CoursesTaught() {
        return CoursesTaught;
    }
};
#endif