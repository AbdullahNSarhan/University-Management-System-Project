#ifndef ACADEMICSTAFF_H
#define ACADEMICSTAFF_H
#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Student.h"
using namespace std;

class AcademicStaff : public User {

private:

    vector<string> CoursesTaught;
    string department;
    char char_check;

public:
    
    void Set_TeachCourse() {
		do {
			cout << "Enter the name of the course you want to teach: ";
			if (!CoursesTaught.empty()) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			getline(cin, department);
			CoursesTaught.push_back(department);
			cout << "Do you want to teach another course (y/n): ";
			cin >> char_check;
			if (char_check == 'n' || char_check == 'N') {
				break;
			}
		} while (true);
    }
    void get_TeachCourse() {
		cout << "The courses you are teaching are: \n";
		for (int i = 0; i < CoursesTaught.size(); i++) {
			cout << CoursesTaught[i] << endl;
		}
	}

    void gradeAssignment() {
        
    }

    void viewStudentList() {
    }

    void Schedule_OfficeHours() {
    }

};

#endif