#ifndef APPLICATION_H
#define APPLICATION_H

class Application
{
	friend class Student;
	
	public:
		Application(int=0000, string="", string="");
		void generateAppNumber();
		int getAppNum() const;
		string getCourse() const;
		void setStatus(int);
		void setCourse(string);
		void writeToFile() const;
		void print() const;
	
	private:
		int applicationNumber;
		string applicationStatus;
		string applicationCourse;
	

};
#endif