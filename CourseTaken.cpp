#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "CourseTaken.h"

CourseTaken::CourseTaken(string course, string term, int year, string grade)
	: courseCode(course), termTaken(term), yearTaken(year), finalGrade(grade)
{	
}

void CourseTaken::print() const
{
	cout<<"Course Code: "<<courseCode<<endl;
	cout<<"Term Taken: "<<termTaken<<endl;
	cout<<"Year Taken: "<<yearTaken<<endl;
	cout<<"Final Grade Attained: "<<finalGrade<<endl;
}

string CourseTaken::getCourseCode() const { return courseCode; }
string CourseTaken::getTermTaken() const {	return termTaken; }
int CourseTaken::getYearTaken() const {	return yearTaken; }
string CourseTaken::getFinalGrade() const {	return finalGrade; }

void CourseTaken::setCourseCode(string course) {	courseCode = course; }
void CourseTaken::setTermTaken(string term) {	termTaken = term; }
void CourseTaken::setYearTaken(int year) {	yearTaken = year; }
void CourseTaken::setFinalGrade(string grade) {	finalGrade = grade; }

//error checking TO DO list:
//for courseCode, check if first 4 letters are all caps letters, next 4 numbers 0-9
//for term taken, check if string matches exactly to Summer Winter or Fall
//for year taken check if year is between Carleton's first year opened and present year
//for final grade check if first letter is all caps A and second letter either -, , or + (can't have lower than A- to apply)

int CourseTaken::verifyCourseCode()
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

int CourseTaken::verifyTermTaken()
{
	if (termTaken.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = termTaken.find_first_not_of("WinterFallSummer");
	cout << termTaken << endl;
	if (validChars != string::npos) {
		cout << "Invalid term: your options are either Fall, Winter or Summer. Please re-enter the term in which you took the course." << endl;
		return 0;
	}
	else return 1;
}

int CourseTaken::verifyYearTaken() //Carleton opened in 1942
{
	if (yearTaken < 1942 || yearTaken > 2013) {
		cout << "Year must in between 1942 and 2013." << endl;
		return 0;
	}
	else return 1;
}

int CourseTaken::verifyFinalGrade()
{
	if (finalGrade.empty()) {
		cout << "A valid course code has exactly 8 characters; eg: ABCD1000. Please try again." << endl;
		return 0;
	}
	if (finalGrade[0] != 'A' && (finalGrade[1] != '-' || finalGrade[1] != '+')) {
		cout << "To apply to be a TA, you must have attained an A-, A or A+ in the course. Please try again or if you do not fulfill that requirement, choose a different course." << endl;
		return 0;
	}
	else return 1;
}

void CourseTaken::writeToFile(int appNum) const
{
	ostringstream fileName;
	fileName << "applications/" << appNum << ".txt";
	ofstream outFile(fileName.str().c_str(), ios::app);
	
	if(!outFile) {
		cout<<"Could not open " << fileName.str() << " file"<<endl;
		exit(1);
	}
	
	outFile<<"Course Taken"<<endl;
	outFile<<courseCode<<endl;
	outFile<<termTaken<<endl;
	outFile<<yearTaken<<endl;
	outFile<<finalGrade<<endl;

}
