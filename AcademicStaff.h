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
		getAcademicStaff_information();
		cout << "Welcome to the Academic Staff Menu" << endl;
		cout << "1-View Courses Taught" << endl;
        cout << "2-Teach Course" << endl;
		cout << "3-Set Student Grades" << endl;
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
    void EditAcademicStaff_information() {
		do {
			system("CLS");
			getAcademicStaff_information();
			cout << "====================================" << endl;
			cout << "What would you like to edit?" << endl;
			cout << "1-Staff name" << endl;
			cout << "2-Staff ID" << endl;
			cout << "3-Staff college" << endl;
			cout << "4-Staff department" << endl;
			cout << "5-Staff role" << endl;
			cout << "6-Staff email" << endl;
			cout << "7-Staff password" << endl;
			cout << "8-Exit" << endl;
			cin >> int_check;
			switch (int_check) {
			case 1:
				cout << "Enter new Staff name: ";
				cin.ignore();
				getline(cin, Username);
				break;
			case 2:
				cout << "Enter new Staff ID: ";
				cin >> UserID;
				break;
			case 3:
				cout << "Enter new Staff college: ";
				cin.ignore();
				getline(cin, college);
				break;
			case 4:
				cout << "Enter new Staff department: ";
				cin.ignore();
				getline(cin, department);
				break;
			case 5:
				cout << "Enter new Staff role: ";
				cin >> Role;
				break;
			case 6:
				cout << "Enter new Staff email: ";
				cin.ignore();
				getline(cin, Email);
				break;
			case 7:
				cout << "Enter new Staff password: ";
				cin.ignore();
				getline(cin, Password);
				break;
			case 8:
				break;
			default:
				cout << "Invalid input" << endl;
				break;
			}
		} while (int_check != 8);
	}
};
#endif