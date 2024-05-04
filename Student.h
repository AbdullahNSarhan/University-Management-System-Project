#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <string>
#include <iostream>
#include "user.h"
#include "Course.h"
using namespace std;

class Student : public User
{
private:
     vector <int> Courses_Enrolled;
     vector <double> Courses_Grades;
     Course course_obj;
     string Student_department;
     char Courses_Enrolled_char;
     int course_num;
public:     
     void SetEnrollCourse(int course_num){
		 Courses_Enrolled.push_back(course_num);
         Courses_Grades.push_back(0);
     }
     vector <int> get_CoursesEnrolled() {
         return Courses_Enrolled;
     }
     void SetGrade(double grade) {
		 Courses_Grades.push_back(grade);
	 }
	 vector <double> get_Grades() {
		 return Courses_Grades;
	 }
     void Edited_Grade(vector <double> new_grade) {
		 Courses_Grades = new_grade;
	 }
     void studentMenu() {
         cout << "============================\n";
         cout << "Welcome to the Student Menu\n"
              << "============================\n"
              << "Hello " << getUserName() << endl;
         if(getUserRole() == 1){
		 cout << "Role : Student\n";
		 }
		 else if(getUserRole() == 2){
		 cout << "Role : Teacher\n";
		 }
		 else if(getUserRole() == 3){
		 cout << "Role : Admin\n";}
         cout << "ID : " << getUserID() << endl
              << "College : " << getUserCollege() << endl
              << "Department : " << Student_department << endl
              << "Email : " << getUserMail() << endl
              << "Password : " << getUserPassword() << endl;
         cout << "============================\n";
         cout << "\n=========options=========\n"
              << "1- Show Enrolled Course\n"
			  << "2- Calculate GPA\n"
			  << "3- Show course Grade\n"
              << "4- change password\n"
			  << "5- Logout\n";
     }
     void SetStudent_information() {

         cout << "Enter student name: ";
         cin.ignore();
         getline(cin, Username);
         cout << "Enter student ID: ";
         cin >> UserID;
         cout << "Enter student college: ";
         cin.ignore();
         getline(cin, college);
         cout << "Enter student department: ";
         getline(cin, Student_department);
         cout << "Enter student role (1-Student, 2-Teacher, 3-Admin): ";
         cin >> Role;
         cout << "Enter student email: ";
         cin.ignore();
         getline(cin, Email);
         cout << "Enter student password: ";
         getline(cin, Password);

	 }
	 void GetStudent_information() {
		 cout << "Student name: " << Username << endl
			  << "Student ID: " << UserID << endl
              << "Student college: " << college << endl
			  << "Student department: " << Student_department << endl
			  << "Student role: " << Role << endl
			  << "Student email: " << Email << endl
			  << "Student password: " << Password << endl
              << "============================\n";
	 }
     void Edit_StudentInformation() {
         int choice = 0;
         do{   
             system("cls");
             GetStudent_information();
		 cout << "what do you want to edit?\n"
			  << "1- Name\n"
			  << "2- ID\n"
			  << "3- College\n"
			  << "4- Department\n"
			  << "5- Role\n"
			  << "6- Email\n"
			  << "7- Password\n"
              << "8- Exit \n";
         cin >> choice;
         switch (choice) {
         case 1:
             cout << "Enter new name: ";
             cin.ignore();
             getline(cin, Username);
             break;
         case 2:
             cout << "Enter new ID: ";
             cin >> UserID;
             break;
         case 3:
             cout << "Enter new college: ";
             cin.ignore();
             getline(cin, college);
             break;
         case 4:
             cout << "Enter new department: ";
             cin.ignore();
             getline(cin, Student_department);
             break;
         case 5:
             cout << "Enter new role: ";
             cin >> Role;
             break;
         case 6:
             cout << "Enter new email: ";
             cin.ignore();
             getline(cin, Email);
             break;
         case 7:
             cout << "Enter new password: ";
             cin.ignore();
             getline(cin, Password);
             break;
         case 8:
             break;
         default:
             cout << "Invalid choice\n";
             break;
         }
		 } while (choice != 8);
	 }
};
#endif