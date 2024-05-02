#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "Course.h"
#include "University.h"
#include "Student.h"
#include "User.h"
#include <vector>
#include "AcademicStaff.h"
using namespace std;

class menu
{
private:
    University Uni_SelectFunction;
    vector<Student> Student_Information;
    vector<AcademicStaff> AcademicStaff_Information;
    vector <Course> CoursesEnrolled;
    Course course_obj;
    User Admin_Information;
    Student student;
    AcademicStaff academicStaff;
    string User_inputPassword;
    vector <int> Courses_Numbers;
    int User_inputId;
    int User_Index = 0;
    bool authentication;
    char Courses_added_char;

public:
    void displayMenu()
    {
        cout << "\n=======================================\n"
            << "Welcome to University Management System\n"
            << "=================MENU==================\n"
            << "1-University options\n"
            << "2-Students options\n"
            << "3-Academic Staff options\n"
            << "4-Admin options\n"
            << "5-Exit\n";
    }
    int selectOption()
    {
        int option;
        do
        {
            displayMenu();
            cout << "Enter your choice: ";
            while (!(cin >> option))
            {
                cout << "Invalid input. Please enter a valid integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (option)
            {
            case 1:
                system("CLS");
                Uni_SelectFunction.User_sellectOption();
                break;
            case 2:
                system("CLS");
                authentication = login();
                if (!authentication) {
                    break;
                }
                student_SelectOptions();
                break;
            case 3:
                system("CLS");
                authentication = login();
                if (!authentication) {
					break;
				}
                AcademicStaff_SelectOptions();
                break;
            case 4:
                system("CLS");
                authentication = adminLogin();
                if (!authentication) {
                    break;
                }
                adminOption();
                break;
            case 5:
                system("CLS");
                break;
            default:
                cout << "Invalid option. Please choose again.\n";
                break;
            }
        } while (option != 5);

        return option;
    }
    bool adminLogin()
    {
        string adminUsername;
        string adminPassword;

        cout << "Enter admin username: ";
        cin.ignore();
        getline(cin, adminUsername);
        cout << endl;
        cout << "Enter admin password: ";
        getline(cin, adminPassword);
        cout << endl;


        if (adminUsername == Admin_Information.getUserName() && adminPassword == Admin_Information.getUserPassword())
        {
            cout << "Login successful. Welcome, " << Admin_Information.getUserID() << "!" << endl;
            return true;
        }
        else
        {
            cout << "Login failed. Invalid username or password.\n";
            return false;
        }
    }
    void executeOption()
    {

    }
    bool login()
    {
        cout << "Enter your ID: ";
        cin >> User_inputId;
        cin.ignore();
        cout << "Enter Your password: ";
        getline(cin, User_inputPassword);

        if (authenticateUser())
        {
            if (User_Index > 0 && User_Index <= Student_Information.size()) {
                cout << "Login successful. Welcome, " << Student_Information[User_Index - 1].getUserName() << "!" << endl;
            }
            else if (User_Index > 0 && User_Index <= AcademicStaff_Information.size()) {
                cout << "Login successful. Welcome, " << AcademicStaff_Information[User_Index - 1].getUserName() << "!" << endl;
            }
            return true;
        }
        else
        {
            cout << "Login failed. Invalid ID or password.\n" << "please try again....\n" << endl;
            return false;
        }
    }
    bool authenticateUser()
    {
        for (User_Index = 0; User_Index < Student_Information.size(); User_Index++)
        {
            if (User_inputId == Student_Information[User_Index].getUserID() &&
                User_inputPassword == Student_Information[User_Index].getUserPassword())
            {
                return true;
            }
        }
        for (User_Index = 0; User_Index < AcademicStaff_Information.size(); User_Index++)
        {
            if (User_inputId == AcademicStaff_Information[User_Index].getUserID() &&
                User_inputPassword == AcademicStaff_Information[User_Index].getUserPassword())
            {
                return true;
            }
        }
        return false;
    }
    void adminMenu()
    {
        cout << "\n=========Admin options==========\n"
            << "1-Add Student\n"
            << "2-Remove Student\n"
            << "3-Display Student\n"
            << "4-Add Academic Staff\n"
            << "5-Remove Academic Staff\n"
            << "6-Display Academic Staff\n"
            << "7-Add courses\n"
            << "8-Display courses\n"
            << "9-University options\n"
            << "10-Change admin information\n"
            << "11-Exit\n";
    }
    void adminOption()
    {
        int option;

        do
        {
            adminMenu();
            cout << "Enter your choice: ";

            while (!(cin >> option))
            {
                cout << "Invalid input. Please enter a valid integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (option)
            {
            case 1:
                system("CLS");
                addStudents();
                break;
            case 2:
                system("CLS");
                removeStudent();
                break;
            case 3:
                system("CLS");
                displayStudents();
                break;
            case 4:
                system("CLS");
                addAcademicStaff();
                break;
            case 5:
                system("CLS");

                break;
            case 6:
                system("CLS");
                displayAcademicStaff();
                break;
            case 7:
                system("CLS");
                Add_Courses();
                break;
            case 8:
                system("CLS");
                getAddedCourses();
                break;
            case 9:
                system("CLS");
                Uni_SelectFunction.admin_UniSelectOption();
                break;
            case 10:
                system("CLS");
                changeAdminInformation();
                break;
            case 11:
                system("CLS");
                break;
            default:
                cout << "Invalid option. Please choose again.\n";
                break;
            }
        } while (option != 11);
    }
    void addStudents()
    {
        student.SetStudent_information();
        Student_Information.push_back(student);
    }
    void displayStudents()
    {
        for (int i = 0; i < Student_Information.size(); i++)
        {
            cout << "====================\n" << "Student " << i + 1 << endl << "====================\n";
            Student_Information[i].GetStudent_information();

        }
    }
    void addAcademicStaff()
	{
		academicStaff.setAcademicStaff_information();
		AcademicStaff_Information.push_back(academicStaff);
	}
    void displayAcademicStaff() {
        for (int i = 0; i < AcademicStaff_Information.size(); i++)
		{
			cout << "====================\n" << "Academic Staff " << i + 1 << endl << "====================\n";
			AcademicStaff_Information[i].getAcademicStaff_information();
		}
    }
    void removeStudent()
    {
        authentication = login();
        if (!authentication) {
            return;
        }
        displayStudents();
        int index;
        cout << "Enter the index of the student you want to remove: ";
        cin >> index;
        Student_Information.erase(Student_Information.begin() + index);
    }
    void Add_Courses() {
        do {
            course_obj.setCourse();
            CoursesEnrolled.push_back(course_obj);
            cout << "Do you want to add another course (y/n): ";
            cin >> Courses_added_char;
            if (Courses_added_char == 'n' || Courses_added_char == 'N') {
                break;
            }
        } while (true);
    }
    void getAddedCourses() {
        cout << "The Courses are :\n";
        for (int i = 0; i < CoursesEnrolled.size(); i++) {
            cout << i + 1 << "- " << CoursesEnrolled[i].getCourseName() << endl;
        }
    }
    void changeAdminInformation() {
        string newUsername;
        string newPassword;

        cout << "Enter new admin username: ";
        cin.ignore();
        getline(cin, newUsername);
        cout << endl;
        cout << "Enter new admin password: ";
        getline(cin, newPassword);
        cout << endl;

        Admin_Information.setUserName(newUsername);
        Admin_Information.setUserPassword(newPassword);

        cout << "Admin information changed successfully.\n";
    }
    void AcademicStaff_SelectOptions()
    {
        int option;
        do {
            academicStaff.AcademicStaff_Menu();
            cout << "Please enter the number of the option you would like to select: ";
            while (!(cin >> option))
            {
                cout << "Invalid input. Please enter a valid integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (option) {
            case 1:
                system("CLS");
                AcademicStaff_DisplayTeachingCourses();
                break;
            case 2:
                system("CLS");
                AcademicStaff_SetTeachingCourses();
                break;
            case 3:
                system("CLS");
                /*AcademicStaff_Information[User_Index].updateGrade();*/
                break;
            case 4:
                system("CLS");
                AcademicStaff_Information[User_Index].changePassword();
                break;
            case 5:
                system("CLS");
                break;
            case 6:
                cout << "Exiting Academic Staff Menu" << endl;
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
            }
        } while (option != 6);
    }
    void AcademicStaff_SetTeachingCourses() {
        cout << "The Courses are :\n";
        for (int i = 0; i < CoursesEnrolled.size(); i++) {
            cout << i + 1 << "- " << CoursesEnrolled[i].getCourseName() << endl;
        }
        do {
            cout << "Please enter the number of the option you would like to select: ";
            int option;
            while (!(cin >> option))
            {
                cout << "Invalid input. Please enter a valid integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if(option > 0 && option <= CoursesEnrolled.size()) {
                AcademicStaff_Information[User_Index].Set_TeachCourse(option);
				cout << "Course added successfully" << endl;
			}
            else if (CoursesEnrolled.size() == 0) {
                cout << "No courses available" << endl;
            }
            else{
				cout << "Invalid input, please try again" << endl;
                continue;
			}
            Courses_added_char = 'y';
            cout << "Do you want to add another course (y/n): ";
            cin >> Courses_added_char;
            if (Courses_added_char == 'n' || Courses_added_char == 'N') {
				break;
			}
        } while (true);
    }
    void AcademicStaff_DisplayTeachingCourses() {
        Courses_Numbers = AcademicStaff_Information[User_Index].get_CoursesTaught();
        cout << "The Courses are :\n";
        for (int i = 0; i < Courses_Numbers.size(); i++) {
            cout << i + 1 << "- " << CoursesEnrolled[Courses_Numbers[i]].getCourseName() << endl;
        }
    }
    void Student_SetEnrolledCourses() {
        cout << "The Courses are :\n";
        for (int i = 0; i < CoursesEnrolled.size(); i++) {
            cout << i + 1 << "- " << CoursesEnrolled[i].getCourseName() << endl;
        }
        do {
			cout << "Please enter the number of the option you would like to select: ";
			int option;
			while (!(cin >> option))
			{
				cout << "Invalid input. Please enter a valid integer.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
            if (option > 0 && option <= CoursesEnrolled.size()) {
                Student_Information[User_Index].SetEnrollCourse(option);
            }else if (CoursesEnrolled.size() == 0) {
				cout << "No courses available" << endl;
			}
            else {
				cout << "Invalid input, please try again" << endl;
                continue;
			}
            Courses_added_char = 'y';
            cout << "Do you want to add another course (y/n): ";
			cin >> Courses_added_char;
            if (Courses_added_char == 'n' || Courses_added_char == 'N') {
                break;
            }
        } while (true);
    }
    void Student_DisplayEnrolledCourses() {
		Courses_Numbers = Student_Information[User_Index].get_CoursesEnrolled();
		cout << "The Courses are :\n";
		for (int i = 0; i < Courses_Numbers.size(); i++) {
			cout << i + 1 << "- " << CoursesEnrolled[Courses_Numbers[i]].getCourseName() << endl;
		}
	}
    void student_SelectOptions() {

        int option;
        do {
            Student_Information[User_Index].studentMenu();
            cout << "Please enter the number of the option you would like to select: ";
            cin >> option;
            switch (option) {
            case 1:
                system("CLS");
                Student_DisplayEnrolledCourses();
                break;
            case 2:
                system("CLS");
                /*Student_Information[User_Index].calculateGPA();*/
                break;
            case 3:
                system("CLS");
                /*Student_Information[User_Index].updateGrade();*/
                break;
            case 4:
                system("CLS");
                Student_Information[User_Index].changePassword();
                break;
            case 5:
                cout << "You have been logged out\n";
                break;
            default:
                cout << "Invalid option\n";
                break;
            }
        } while (option != 5);

    }
};
#endif