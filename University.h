#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class University {
private:

    string name = " MSA University ";
    string location = " 6th of October ";
    vector <string> colleges;
    vector <vector<string>> departments;
    int choice;

public:

    void User_UniMenu() {

        cout << "\n==========Options:==========\n";
        cout << "1- About University\n";
        cout << "2- View all colleges\n";
        cout << "3- View departments of a college\n";
        cout << "4- Exit\n";
        cout << "\nEnter your choice: ";

    }
    void admin_UniMenu() {

		cout << "\n==========Options:==========\n";
		cout << "1- Edit About University\n";
		cout << "2- Add a college\n";
		cout << "3- Add a department to a college\n";
		cout << "4- View all colleges\n";
		cout << "5- View departments of a college\n";
		cout << "6- Exit\n";
		cout << "\nEnter your choice: ";

	}
    void addCollege() {

        string collegeName;
        cout << "Enter the name of the college: ";
        getline(cin, collegeName);
        cin.ignore();
        colleges.push_back(collegeName);
        departments.push_back(vector<string>());
        cout << "College added successfully.\n";
    }
    void addDepartment() {

        if (colleges.empty()) {
            cout << "No colleges added yet. Please add a college first.\n";
            return;
        }

        int collegeIndex;
        cout << "Select the college to add the department to:\n";
        for (size_t i = 0; i < colleges.size(); ++i) {
            cout << i + 1 << "- " << colleges[i] << endl;
        }
        cout << "Enter the college number: ";
        while (!(cin >> collegeIndex) || collegeIndex < 1 || collegeIndex > static_cast<int>(colleges.size())) {
            cout << "Invalid college number. Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        string departmentName;
        cout << "Enter the name of the department: ";
        getline(cin, departmentName);
        departments[collegeIndex - 1].push_back(departmentName);
        cout << "Department added successfully to " << colleges[collegeIndex - 1] << ".\n";
    }
    void getColleges() {

        cout << "\nCurrent list of colleges:\n";

        if (colleges.empty()) {
            cout << "No colleges added yet.\n";
        }
        else {
            for (size_t i = 0; i < colleges.size(); ++i) {
                cout << i + 1 << "- " << colleges[i] << endl;
            }
        }

    }
    void getDepartments() {

        cout << "\nDepartments in each college:\n";
        for (size_t i = 0; i < colleges.size(); ++i) {
            if (departments[i].empty()) {
                cout << "No departments added yet.\n";
            }
            else {
                cout << "College: " << colleges[i] << endl;
                for (size_t j = 0; j < departments[i].size(); ++j) {
                    cout << "- " << departments[i][j] << endl;
                }
            }
            cout << endl;
        }
    }
    void admin_UniSelectOption() {
        
        do {

            admin_UniMenu();
            while (!(cin >> choice)) {
                cout << "Invalid input. Please enter a valid integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            switch (choice) {
            case 1: {
                system("CLS");
                cout << "\nName : " << name << endl;
                cout << "Location : " << location << endl;
                Edit_About_University();
                break;
            }
            case 2: {
                system("CLS");
                addCollege();
                break;
            }
            case 3: {
                system("CLS");
                addDepartment();
                break;
            }
            case 4: {
                system("CLS");
                getColleges();
                break;
            }
            case 5: {
                system("CLS");
                getDepartments();
                break;
            }
            case 6: {
                system("CLS");
                cout << "Exiting..........\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 6);

    }
    void User_sellectOption() {

		do {

			User_UniMenu();
			while (!(cin >> choice)) {
				cout << "Invalid input. Please enter a valid integer.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cin.ignore();

			switch (choice) {
			case 1: {
                system("CLS");
				cout << "\nName : " << name << endl;
				cout << "Location : " << location << endl;
				break;
			}
			case 2: {
                system("CLS");
				getColleges();
				break;
			}
			case 3: {
                system("CLS");
				getDepartments();
				break;
			}
			case 4: {
                system("CLS");
				cout << "Exiting..........\n";
				break;
			}
			default:
				cout << "Invalid choice. Please try again.\n";
			}

		} while (choice != 4);

	}
    void Edit_About_University() {
        cout << "Enter the new name of the university: ";
        getline(cin, name);
        cin.ignore();
        cout << "Enter the new location of the university: ";
        getline(cin, location);
        cin.ignore();
        cout << "University information updated successfully.\n";
    }
};
#endif