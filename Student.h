#ifndef STUDENT_H
#define STUDENT_H

#include "Application.h"

class Student
{
	public:
		//default initializations for testing purposes
		Student(string="",
				string="",
				string="",
				string="",
				int=0,int=0,double=0.0,double=0.0,
				int=0000, string="", string="");
		void newApplication();
		void writeToFile() const;
		void writeToFile(string) const;
		void print() const;
		//getters
		string getFirstName() const;
		string getLastName() const;
		string getEmailAddress() const;
		string getMajor() const;
		int getStudentNumber() const;
		int getYearStanding() const;
		double getCGPA() const;
		double getMGPA() const;
		int getAppNum() const;
		//setters	
		void setFirstName(string);
		void setLastName(string);
		void setEmailAddress(string);
		void setMajor(string);
		void setStudentNumber(int);
		void setYearStanding(int);
		void setCGPA(double);
		void setMGPA(double);
		void setCourse(string);
		void setStatus(int);
		//verifying functions
		int verifyFirstName() const;
		int verifyLastName() const;
		int verifyEmailAddress() const;
		int verifyMajor() const;
		int verifyStudentNumber();
		int verifyYearStanding() const;
		int verifyCGPA() const;
		int verifyMGPA() const;

	private:
		string firstName;
		string lastName;
		string emailAddress;
		string majorDegree;
		int studentNumber;
		int yearStanding;
		double cgpa;
		double mgpa;
		Application studentApplication;
		void write(ofstream&) const;
};
#endif
