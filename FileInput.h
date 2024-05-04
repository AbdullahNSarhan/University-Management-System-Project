#ifndef FILEINPUT_H
#define FILEINPUT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Menu.h"
#include "AcademicStaff.h"
#include "Student.h"
#include "Course.h"
#include "User.h"
using namespace std;

class FileInput
{
private:
	vector <AcademicStaff> academicStaff;
	vector <Student> student;
	vector <Course> course;
	User Admin;
public:
	FileInput(){}
	void readAcademicStaff(vector <AcademicStaff> aca_Staff){
		academicStaff = aca_Staff;
	}
	void readStudent(vector <Student> std){
		student = std;
	}
	void readCourse(vector <Course> cou){
		course = cou;
	}
	void readAdmin(User adm){
		Admin = adm;
	}
	void writeAcademicStaff() {
		ofstream file;
		file.open("AcademicStaff.txt");
		for (int i = 0; i < academicStaff.size(); i++) {
			file << "====================" << endl
				 << "Academic Staff no." << i + 1 << endl
				 << "====================" << endl
				 << "Name: " <<academicStaff[i].getUserName() << endl
				 << "ID: " <<academicStaff[i].getUserID() << endl
				 << "Mail: " <<academicStaff[i].getUserMail() << endl
				 << "Password: " <<academicStaff[i].getUserPassword() << endl
				 << "College: " <<academicStaff[i].getUserCollege() << endl;
		}
	}
	void writeStudent() {
		ofstream file;
		file.open("Student.txt");
		for (int i = 0; i < student.size(); i++) {
			file << "====================" << endl
				 << "Student no." << i + 1 << endl
				 << "====================" << endl
				 << "Name: " <<student[i].getUserName() << endl
				 << "ID: " <<student[i].getUserID() << endl
				 << "Mail: " <<student[i].getUserMail() << endl
				 << "Password: " <<student[i].getUserPassword() << endl
				 << "College: " <<student[i].getUserCollege() << endl
				 << "Department: " <<student[i].getStudentDepartment()<< endl;
		}
	}
	void writeCourse() {
		ofstream file;
		file.open("Course.txt");
		for (int i = 0; i < course.size(); i++) {
			file << "====================" << endl
				 << "Course no." << i + 1 << endl
				 << "====================" << endl
				 << "Course Name: " <<course[i].getCourseName() << endl
				 << "Course Code: " <<course[i].getCourseCode() << endl
				 << "Course Credit: " <<course[i].getCreditHours() << endl
				 << "Course Department: " <<course[i].getDepartment() << endl;
		}
	}
	void writeAdmin() {
		ofstream file;
		file.open("Admin.txt");
		file << "====================" << endl
			 << "Admin" << endl
			 << "====================" << endl
			 << "Name: " <<Admin.getUserName() << endl
			 << "ID: " <<Admin.getUserID() << endl
			 << "Mail: " <<Admin.getUserMail() << endl
			 << "Password: " <<Admin.getUserPassword() << endl
			 << "College: " <<Admin.getUserCollege() << endl;
	}
};
#endif