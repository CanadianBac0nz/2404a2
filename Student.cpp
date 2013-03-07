#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "Student.h"

Student::Student(string first, string last, string email, string mjr,
				 int sid, int year, double c, double m, int appNum, string stat, string course)
	: firstName(first), lastName(last), emailAddress(email), majorDegree(mjr), studentNumber(sid),
	  yearStanding(year), cgpa(c), mgpa(m), studentApplication(appNum,stat,course)
{	
}

void Student::print() const
{
	cout.precision(2);
	cout<<fixed;
	cout<<"First Name: "<<firstName<<endl;
	cout<<"Last Name: "<<lastName<<endl;
	cout<<"Email: "<<emailAddress<<endl;
	cout<<"Major: "<<majorDegree<<endl;
	cout<<"Student Number: "<<studentNumber<<endl;
	cout<<"Year Standing: "<<yearStanding<<endl;
	cout<<"CGPA: "<<cgpa<<endl;
	cout<<"MGPA: "<<mgpa<<endl;
	studentApplication.print();
}

string Student::getFirstName() const { return firstName; }
string Student::getLastName() const {	return lastName; }
string Student::getEmailAddress() const {	return emailAddress; }
string Student::getMajor() const {	return majorDegree; }
int Student::getStudentNumber() const {	return studentNumber; }
int Student::getYearStanding() const {	return yearStanding;}
double Student::getCGPA() const {	return cgpa; }
double Student::getMGPA() const {	return mgpa; }
int Student::getAppNum() const { return studentApplication.getAppNum(); }
///////////
//setters//
///////////
void Student::setFirstName(string first) {	firstName = first; }
void Student::setLastName(string last) {	lastName = last; }
void Student::setEmailAddress(string email) {	emailAddress = email; }
void Student::setMajor(string mjr) {	majorDegree = mjr; }
void Student::setStudentNumber(int sid) {	studentNumber = sid; }
void Student::setYearStanding(int yr) {	yearStanding = yr; }
void Student::setCGPA(double c) {	cgpa = c; }
void Student::setMGPA(double m) {	mgpa = m; }
void Student::setCourse(string s) {	studentApplication.setCourse(s); }
void Student::setStatus(int i) {  studentApplication.setStatus(i); }
/////////////
//verifiers//
/////////////
int Student::verifyFirstName() const
{
	if (firstName.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = firstName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ-'");
  
	if (validChars != string::npos) {
		cout << "You entered a non-alphabetical character, " << firstName[validChars];
		cout << ", at position " << validChars << endl;
		return 0;
    }
	else return 1;
}

int Student::verifyLastName() const
{
	if (lastName.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = lastName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ-'");
  
	if (validChars != string::npos) {
		cout << "You entered a non-alphabetical character, " << lastName[validChars];
		cout << ", at position " << validChars << endl;
		return 0;
    }
	else return 1;
}

int Student::verifyEmailAddress() const
{
	if (emailAddress.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	string stringToFind1("@cmail.carleton.ca");
	
	unsigned validChars1 = emailAddress.find(stringToFind1);

	if (validChars1 == string::npos) {
		cout << "Invalid e-mail address. Please enter your Carleton e-mail address (yourname@cmail.carleton.ca) to register." << endl;
		return 0;
	}
	else return 1;
}

//verifyMajor & verifyStudentNumber needs to be done
int Student::verifyMajor() const
{
	if (majorDegree.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = majorDegree.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ- ");
  
	if (validChars != string::npos) {
		cout << "You entered a non-alphabetical character, " << majorDegree[validChars];
		cout << ", at position " << validChars << endl;
		return 0;
    }
	else return 1;
}

int Student::verifyStudentNumber()
{
	string studentNumberString;
	std::ostringstream convert;
	convert << studentNumber;
	studentNumberString = convert.str();

	if (studentNumberString.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = studentNumberString.find_first_not_of("0123456789");
  
	if (validChars != string::npos) {
		cout << "You entered a character which is not a number between 0-9: " << studentNumberString[validChars];
		cout << ", at position " << validChars << "Please re-enter your student number." << endl;
		return 0;
    }

	if (studentNumberString.length() != 9) {
		cout << "A valid student number has exactly 9 characters. Please re-enter your student number." << endl;
		return 0;
	}
	else {
		int validStuNum = atoi(studentNumberString.c_str());
		studentNumber = validStuNum;
		return 1;
	}
}

int Student::verifyCGPA() const
{
	if (cgpa < 0.0 || cgpa > 12.0) {
		cout << "CGPA entered must be in between 0.0 and 12.0" << endl;
		return 0;
	}
	else return 1;
}

int Student::verifyMGPA() const
{
	if (mgpa < 0.0 || mgpa > 12.0) {
		cout << "MGPA entered must be in between 0.0 and 12.0" << endl;
		return 0;
	}
	else return 1;
}

int Student::verifyYearStanding() const
{
	if (yearStanding < 1 || yearStanding > 4) {
		cout << "Year standing must be either 1, 2, 3, or 4. Please try again" << endl; 
		return 0;
	}
	else return 1;
}


void Student::newApplication()
{
	studentApplication.generateAppNumber();
}

void Student::write(ofstream &outFile) const
{
	outFile.precision(2);
	outFile<<fixed;
	outFile<<firstName<<endl;
	outFile<<lastName<<endl;
	outFile<<emailAddress<<endl;
	outFile<<majorDegree<<endl;
	outFile<<studentNumber<<endl;
	outFile<<yearStanding<<endl;
	outFile<<cgpa<<endl;
	outFile<<mgpa<<endl;
}

void Student::writeToFile() const
{
	ostringstream fileName;
	fileName << "applications/" << studentApplication.getAppNum() << ".txt";
	ofstream outFile(fileName.str().c_str(), ios::app);
	ofstream searchFile("applications.txt", ios::app);
	
	if(!outFile) {
		cout<<"Could not open file"<<endl;
		exit(1);
	}
	
	studentApplication.writeToFile();
	searchFile<<studentApplication.getAppNum()<<endl;
	searchFile<<studentNumber<<endl;
	searchFile<<firstName<<endl;
	searchFile<<lastName<<endl;
	searchFile<<studentApplication.getCourse()<<endl;
	write(outFile);

}

void Student::writeToFile(string s) const
{
	ostringstream fileName;
	fileName << s << ".txt";
	ofstream outFile(fileName.str().c_str(), ios::in);
	
	if(!outFile) {
		cout<<"Could not open " << fileName.str() << " file"<<endl;
		exit(1);
	}
	
	write(outFile);
}