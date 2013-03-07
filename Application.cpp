using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "Application.h"
#define MAX_BUF 10


Application::Application(int appNum, string status, string course)
	: applicationNumber(appNum), applicationStatus(status), applicationCourse(course)
{
}

void Application::generateAppNumber()
{
	char number[MAX_BUF];
	
	ifstream inFile("applicationCounter.txt", ios::in);
	
	if (!inFile) {
		cout<<"Could not open file"<<endl;
		exit(1);
	}
	
	inFile >> number;
	
	applicationNumber = atoi(number);
	applicationNumber = applicationNumber++;
	//cout<<applicationNumber<<endl;
}

int Application::getAppNum() const
{
	return applicationNumber;
}

string Application::getCourse() const
{
	return applicationCourse;
}

void Application::setStatus(int s)
{
	switch(s)
	{
		case 0:
			applicationStatus = "";
			break;
		case 1:
			applicationStatus = "pending";
			break;
		case 2:
			applicationStatus = "accepted";
			break;
	}
}

void Application::setCourse(string s)
{
	applicationCourse = s;
}
void Application::writeToFile() const
{
	ostringstream fileName;
	fileName << "applications/" << applicationNumber << ".txt";
	ofstream outFile(fileName.str().c_str(), ios::app);
	ofstream appFile("applicationCounter.txt", ios::out);
	
	if(!outFile || !appFile) {
		cout<<"Could not open file"<<endl;
		exit(1);
	}
	appFile<<applicationNumber<<endl;
	outFile<<applicationNumber<<endl;
	outFile<<applicationCourse<<endl;
	outFile<<applicationStatus<<endl;
}

void Application::print() const
{
	cout<<"Application Number: "<<applicationNumber<<endl;
	cout<<"Application Status: "<<applicationStatus<<endl;
}