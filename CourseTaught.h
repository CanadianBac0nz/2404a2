#ifndef COURSETAUGHT_H
#define COURSETAUGHT_H

class CourseTaught
{
  public:
    CourseTaught(string="", string="", int=0, string="");
//    ~CourseTaught();
	///////////////
	////getters////
	///////////////
	string getCourseCode() const;
	string getTermTaught() const;
	int getYearTaught() const;
	string getSupervisor() const;
	///////////////
	////setters////
	///////////////
	void setCourseCode(string);
	void setTermTaught(string);
	void setYearTaught(int);
	void setSupervisor(string);
	///////////////
	////MISC////
	///////////////
	int verifyCourseCode() const;
	int verifyTermTaught() const;
	int verifyYearTaught() const;
	int verifySupervisor() const;
    void print() const;
	void writeToFile(int) const;

  private:
    string courseCode;
    string termTaught;
	int yearTaught;
	string supervisor;
};

#endif
