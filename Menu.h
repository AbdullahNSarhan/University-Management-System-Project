#ifndef MENU_H
#define MENU_H
#include "University.h"
#include "Student.h"
#include "User.h"
#include <vector>
using namespace std;

class menu
{
private:
    University Uni_SelectFunction;
    vector<Student> Student_Information;
   // vector<AcademicStaff> AcademicStaff_Information;
    User Admin_Information;
    Student student;
    string User_inputPassword;
    int User_inputId;
    int User_Index = 0;
    bool authentication;

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
                Uni_SelectFunction.User_sellectOption();
                break;
            case 2:
				authentication = login();
				if (!authentication) {
					break;
				}
               Student_Information[User_Index].studentOptions();
               
                break;
            case 3:
               
                break;
            case 4:
                authentication = adminLogin();
                if (!authentication) {
					break;
				}
                adminOption();
                break;
            case 5:
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
        return false;
    }

    void adminMenu()
    {
        cout << "1-Add Student\n"
             << "2-Remove Student\n"
             << "3-Update Student\n"
             << "4-Display Student\n"
             << "5-university options\n"
             << "6-Exit\n";
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
                addStudents();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                updateStudents();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                Uni_SelectFunction.admin_UniSelectOption();
                break; 
            case 6:
                    break;
            default:
                cout << "Invalid option. Please choose again.\n";
                break;
            }
        } while (option != 6);
    }

    void addStudents()
    {
        student.SetStudent_information();
        Student_Information.push_back(student);
    }
    void updateStudents()
    {
        authentication = login();
        if(!authentication){
			return;
		}
        Student_Information[User_Index].setEnrollCourse();
    }
    void displayStudents()
	{
		for (int i = 0; i < Student_Information.size(); i++)
		{
            cout << "====================\n" << "Student " << i + 1 << endl << "====================\n";
            Student_Information[i].GetStudent_information();
            
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
};
#endif