#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User{
protected:
     string Username;
     int UserID;
     int Role;
     string Email;
     string Password;
     int RoleChoice;
     string college;
public:

     User() {
		 Username = "admin";
		 Password = "admin";
		 UserID = 0;
	 }

     void setUserName(string name) {

         Username = name;

     }
     string getUserName() {

         return Username;

     }

     void setUserID(int id) {

         UserID = id;

     }

     int getUserID() const {

         return UserID;

     }

     void setUserPassword(string pw) {

         Password = pw;

     }

     string getUserPassword() {

		 return Password;

	 }

     void setUserMail(string em) {

         Email = em;

     }

     string getUserMail() {

         return Email;

     }

     void setUserRole(int R) {

         Role = R;

     }

     int getUserRole() const {

         return Role;

     }

     void setUserCollege(string col) {

		 college = col;

	 }

     string getUserCollege() {

         return college;

     }

     void changePassword() {
         
		 string newPass;
		 cout << "Enter new password: ";
		 cin >> newPass;
		 Password = newPass;

     }
     
};

#endif