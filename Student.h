#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <string>
#include <iostream>
#include "user.h"
using namespace std;

class Student : public User
{
private:

     vector <string> CoursesEnrolled;
     vector <int> CoursesEnrolled_CreditHour;
     vector <double> Grades;
     string Courses_Enrolled;
     string department;
     int course_num;
     char Courses_Enrolled_char;

public:
     
     void setEnrollCourse(){
         do {
             cout << "Enter the name of the enrolled course: ";
             if (!CoursesEnrolled.empty()) {
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
             }
             getline(cin, Courses_Enrolled);
             CoursesEnrolled.push_back(Courses_Enrolled);
             Grades.push_back(0);
             do {
                 cout << "Enter the credit hour of the enrolled course: ";
                 if (!(cin >> course_num)) {
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     cout << "Invalid input. Please enter a number.\n";
                     continue;
                 }
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');

                 if (course_num >= 0 && course_num <= 4) {
                     CoursesEnrolled_CreditHour.push_back(course_num);
                     break;
                 }
                 else {
                     cout << "The credit hour is not valid\n";
                 }
             } while (course_num >= 0 || course_num <= 4);
             cout << "Do you want to enroll another course (y/n): ";
             cin >> Courses_Enrolled_char;
             if (Courses_Enrolled_char == 'n' || Courses_Enrolled_char == 'N') {
                 break;
             }
         } while (true);
     }

     void getEnrollCourse() {

         cout << "Your Enrolled Courses is : \n";
         for (int i = 0; i < CoursesEnrolled.size(); i++) {
           
             cout << i + 1 << "- " << CoursesEnrolled[i] << endl
                  << " Credit Hour : " << CoursesEnrolled_CreditHour[i] << endl;

         }

     }
        
     void calculateGPA(){

         double sum1 = 0,sum2 = 0;
		 for (int i = 0; i < Grades.size(); i++) {

             if(Grades[i] >= 93 && Grades[i] <= 100) sum1 += 4.0 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 89 && Grades[i] <= 93) sum1 += 3.67 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 84 && Grades[i] <= 89) sum1 += 3.33 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 80 && Grades[i] <= 84) sum1 += 3.0 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 76 && Grades[i] <= 80) sum1 += 2.67 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 73 && Grades[i] <= 76) sum1 += 2.33 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 70 && Grades[i] <= 73) sum1 += 2.0 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 67 && Grades[i] <= 70) sum1 += 1.67 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 64 && Grades[i] <= 67) sum1 += 1.33 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 60 && Grades[i] <= 64) sum1 += 1.0 * CoursesEnrolled_CreditHour[i];
             else if(Grades[i] >= 0 && Grades[i] <= 60) sum1 += 0.0 * CoursesEnrolled_CreditHour[i];
             sum2 += CoursesEnrolled_CreditHour[i];

		 }

         cout << "Your GPA is : " << sum1/sum2 << endl;

     }
     
     void updateGrade() {
         do {
             cout << "Your Enrolled Courses grades is :\n";
             for (int i = 0; i < Grades.size(); i++) {
                 cout << i + 1 << "- " << CoursesEnrolled[i] << " grade is: " << Grades[i] << "/100" << endl;
             }
             cout << "Choose the course you want to update the grade for: ";
             cin >> course_num;
             if (course_num < 1 || course_num > Grades.size()) {
                 cout << "The course number is not valid\n";
                 continue;
             }
             do{
             cout << "Enter the new grade (0:100): ";
             cin >> Grades[course_num - 1];
             if (Grades[course_num - 1] >= 0 && Grades[course_num - 1] <= 100) {
                 cout << "The grade has been updated successfully\n";
                 break;
             } else {
                 cout << "The grade is not valid\n";
             }
             }while(Grades[course_num - 1] < 0 || Grades[course_num - 1] > 100);
             cout << "Do you want to update another grade (y/n): ";
             cin >> Courses_Enrolled_char;
             if (Courses_Enrolled_char == 'n' || Courses_Enrolled_char == 'N') {
                 break;
             }
         } while (true);
     }

     void studentMenu() {

         cout << "Welcome to the Student Menu\n"
              << "Hello " << getUserName() << endl;

         if(getUserRole() == 1){
			 cout << "Role : Student\n";
		 }
		 else if(getUserRole() == 2){
			 cout << "Role : Teacher\n";
		 }
		 else if(getUserRole() == 3){
			 cout << "Role : Admin\n";}

         cout << "id : " << getUserID() << endl
              << "college : " << getUserCollege() << endl
              << "department : " << department << endl
              << "email : " << getUserMail() << endl
              << "password : " << getUserPassword() << endl;
         cout << "\n=========options=========\n"
              << "1- Show Enrolled Course\n"
			  << "2- Calculate GPA\n"
			  << "3- Update Grade\n"
              << "4- change password\n"
			  << "5- Logout\n";

     }

     void studentOptions() {

		 int option;
		 do {
			 studentMenu();
			 cout << "Enter your option : ";
			 cin >> option;
			 switch (option) {
			 case 1:
				 getEnrollCourse();
				 break;
			 case 2:
				 calculateGPA();
				 break;
			 case 3:
				 updateGrade();
				 break;
			 case 4:
				 changePassword();
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
         getline(cin, department);
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
			  << "Student department: " << department << endl
			  << "Student role: " << Role << endl
			  << "Student email: " << Email << endl
			  << "Student password: " << Password << endl;

	 }
};

#endif