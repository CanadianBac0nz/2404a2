#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "CourseTaught.h"

CourseTaught::CourseTaught(string course, string term, int year, string sup)
	: courseCode(course), termTaught(term), yearTaught(year), supervisor(sup)
{	
}

void CourseTaught::print() const
{
	cout<<"Course Code: "<<courseCode<<endl;
	cout<<"Term Taught: "<<termTaught<<endl;
	cout<<"Year Taught: "<<yearTaught<<endl;
	cout<<"Supervisor: "<<supervisor<<endl;
}

string CourseTaught::getCourseCode() const { return courseCode; }
string CourseTaught::getTermTaught() const {	return termTaught; }
int CourseTaught::getYearTaught() const {	return yearTaught; }
string CourseTaught::getSupervisor() const {	return supervisor; }

void CourseTaught::setCourseCode(string course) {	courseCode = course; }
void CourseTaught::setTermTaught(string term) {	termTaught = term; }
void CourseTaught::setYearTaught(int year) {	yearTaught = year; }
void CourseTaught::setSupervisor(string sup) {	supervisor = sup; }

//error checking TO DO list:
//for courseCode, check if first 4 letters are all caps letters, next 4 numbers 0-9
//for term taken, check if string matches exactly to Summer Winter or Fall
//for year taken check if year is between Carleton's first year opened and present year
//for supervisor check if input passes same criteria as first/last name for Student

int CourseTaught::verifyCourseCode() const
{
	if (courseCode.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}
	if (courseCode.length() != 8) {
		 cout << "A valid course code has exactly 8 characters; eg: ABCD1000. Please try again." << endl;
	}
	string subString1 = courseCode.substr(0, 4);
	string subString2 = courseCode.substr(4, 4);
	cout << subString1 << endl;	
	cout << subString2 << endl;

	unsigned validChars1 = subString1.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	unsigned validChars2 = subString2.find_first_not_of("0123456789");

	if (validChars1 != string::npos) {
		cout << "A valid course code's first 4 characters are all-caps letters. Please enter your course code as listed in Carleton Central again, eg: ABCD1000" << endl;
		return 0;
	}
	else if (validChars2 != string::npos) {
		cout << "A valid course code's last 4 characters are integers. Please enter your course code as listed in Carleton Central again, eg: ABCD1000" << endl;
		return 0;
	}
	else {
		cout << "OKAY" << endl;
		return 1;
	}
}

int CourseTaught::verifyTermTaught() const
{
	if (termTaught.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = termTaught.find_first_not_of("WinterFallSummer");
	cout << termTaught << endl;
	if (validChars != string::npos) {
		cout << "Invalid term: your options are either Fall, Winter or Summer. Please re-enter the term in which you took the course." << endl;
		return 0;
	}
	else return 1;
}

int CourseTaught::verifyYearTaught() const //Carleton opened in 1942
{
	if (yearTaught < 1942 || yearTaught > 2013) {
		cout << "Year must in between 1942 and 2013." << endl;
		return 0;
	}
	else return 1;
}

int CourseTaught::verifySupervisor() const
{
	if (supervisor.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = supervisor.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-' ");
  
	if (validChars != string::npos) {
		cout << "You entered a non-alphabetical character, " << supervisor[validChars];
		cout << ", at position " << validChars << endl;
		return 0;
    }
	else return 1;
}

void CourseTaught::writeToFile(int appNum) const
{
	ostringstream fileName;
	fileName << "applications/" << appNum << ".txt";
	ofstream outFile(fileName.str().c_str(), ios::app);
	
	if(!outFile) {
		cout<<"Could not open " << fileName.str() << " file"<<endl;
		exit(1);
	}
	
	outFile<<"Course Taught"<<endl;
	outFile<<courseCode<<endl;
	outFile<<termTaught<<endl;
	outFile<<yearTaught<<endl;
	outFile<<supervisor<<endl;

}
