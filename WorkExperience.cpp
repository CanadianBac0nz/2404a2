#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "WorkExperience.h"

WorkExperience::WorkExperience(string t, string resp, int dur, string start, string end)
	: title(t), responsibilities(resp), duration(dur), startDate(start), endDate(end)
{
}

void WorkExperience::print() const
{
	cout<<"Title: "<<title<<endl;
	cout<<"Responsibilities: "<<responsibilities<<endl;
	cout<<"Duration: "<<duration<<endl;
	cout<<"Start Date: "<<startDate<<endl;
	cout<<"End Date: "<<endDate<<endl;
}

string WorkExperience::getResponsibilities() const { return responsibilities; }
int WorkExperience::getDuration() const {	return duration; }
string WorkExperience::getStartDate() const {	return startDate; }
string WorkExperience::getEndDate() const {	return endDate; }

void WorkExperience::setResponsibilities(string resp) {	responsibilities = resp; }
void WorkExperience::setDuration(int dur) {	duration = dur; }
void WorkExperience::setStartDate(string start) {	startDate = start; }
void WorkExperience::setEndDate(string end) {	endDate = end; }

int WorkExperience::verifyTitle() const
{
	if (title.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}
	return 1;
}

int WorkExperience::verifyResponsibilities() const
{
	if (responsibilities.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}
	return 1;
}

int WorkExperience::verifyDuration() const
{
	if (duration < 0) {
		cout << "Cannot have negative integer metric of duration. Please re-enter." << endl;
		return 0;
	}
	return 1;
}

int WorkExperience::verifyStartDate() const
{
	if (startDate.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = startDate.find_first_not_of("0123456789/");
  
	if (validChars != string::npos) {
		cout << "You entered an invalid character, " << startDate[validChars];
		cout << ", at position. " << validChars << "Please re-enter in format DD/MM/YY." << endl;
		return 0;
    }
	else return 1;
}

int WorkExperience::verifyEndDate() const
{
	if (endDate.empty()) {
		cout << "You did not enter anything for this field. Please try again." << endl;
		return 0;
	}

	unsigned validChars = endDate.find_first_not_of("0123456789/");
  
	if (validChars != string::npos) {
		cout << "You entered an invalid character, " << endDate[validChars];
		cout << ", at position " << validChars << ". Please re-enter in format DD/MM/YY." << endl;
		return 0;
    }
	else return 1;
}

void WorkExperience::writeToFile(int appNum) const
{
	ostringstream fileName;
	fileName << "applications/" << appNum << ".txt";
	ofstream outFile(fileName.str().c_str(), ios::app);
	
	if(!outFile) {
		cout<<"Could not open " << fileName.str() << " file"<<endl;
		exit(1);
	}
	
	outFile<<"Work Experience"<<endl;
	outFile<<title<<endl;
	outFile<<duration<<endl;
	outFile<<startDate<<endl;
	outFile<<endDate<<endl;
	outFile<<responsibilities<<endl;
}

