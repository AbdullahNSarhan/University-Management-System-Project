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
     Course course_obj;
     string Student_department;
     char Courses_Enrolled_char;
     int course_num;

public:
     
     void SetEnrollCourse(int course_num){
		 Courses_Enrolled.push_back(course_num);      
     }
     vector <int> get_CoursesEnrolled() {
         return Courses_Enrolled;
     }
     /*void calculateGPA(){
         double sum1 = 0,sum2 = 0;
		 for (int i = 0; i < CoursesEnrolled.size(); i++) {
             if(CoursesEnrolled[i].getGrade() >= 93 && CoursesEnrolled[i].getGrade() <= 100) sum1 += 4.0 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 89 && CoursesEnrolled[i].getGrade() <= 93) sum1 += 3.67 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 84 && CoursesEnrolled[i].getGrade() <= 89) sum1 += 3.33 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 80 && CoursesEnrolled[i].getGrade() <= 84) sum1 += 3.0 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 76 && CoursesEnrolled[i].getGrade() <= 80) sum1 += 2.67 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 73 && CoursesEnrolled[i].getGrade() <= 76) sum1 += 2.33 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 70 && CoursesEnrolled[i].getGrade() <= 73) sum1 += 2.0 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 67 && CoursesEnrolled[i].getGrade() <= 70) sum1 += 1.67 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 64 && CoursesEnrolled[i].getGrade() <= 67) sum1 += 1.33 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 60 && CoursesEnrolled[i].getGrade() <= 64) sum1 += 1.0 * CoursesEnrolled[i].getCreditHours();
             else if(CoursesEnrolled[i].getGrade() >= 0  && CoursesEnrolled[i].getGrade() <= 60) sum1 += 0.0 * CoursesEnrolled[i].getCreditHours();
             sum2 += CoursesEnrolled[i].getCreditHours();
		 }
         cout << "Your GPA is : " << sum1/sum2 << endl;
     }    
     void updateGrade() {
         do {
             cout << "Your Enrolled Courses grades is :\n";
             for (int i = 0; i < CoursesEnrolled.size(); i++) {
                 cout << i + 1 << "- " << CoursesEnrolled[i].getCourseName() << " grade is: " << CoursesEnrolled[i].getGrade() << "/100" << endl;
             }
             cout << "Choose the course you want to update the grade for: ";
             cin >> course_num;
             if (course_num < 1 || course_num > CoursesEnrolled.size()) {
                 cout << "The course number is not valid\n";
                 continue;
             }
             do{
                 CoursesEnrolled[course_num - 1].setGrade();
             if (CoursesEnrolled[course_num - 1].getGrade() >= 0 && CoursesEnrolled[course_num - 1].getGrade() <= 100) {
                 cout << "The grade has been updated successfully\n";
                 break;
             } else {
                 cout << "The grade is not valid\n";
             }
             } while (CoursesEnrolled[course_num - 1].getGrade() < 0 || CoursesEnrolled[course_num - 1].getGrade() > 100);
             cout << "Do you want to update another grade (y/n): ";
             cin >> Courses_Enrolled_char;
             if (Courses_Enrolled_char == 'n' || Courses_Enrolled_char == 'N') {
                 break;
             }
         } while (true);
     }*/
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
			  << "3- Update Grade\n"
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
			  << "Student password: " << Password << endl;
	 }
};
#endif