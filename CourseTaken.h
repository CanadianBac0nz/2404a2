#ifndef COURSETAKEN_H
#define COURSETAKEN_H

class CourseTaken
{
  public:
    CourseTaken(string="", string="", int=0, string="");
//    ~CourseTaken();
	///////////////
	////getters////
	///////////////
	string getCourseCode() const;
	string getTermTaken() const;
	int getYearTaken() const;
	string getFinalGrade() const;
	///////////////
	////setters////
	///////////////
	void setCourseCode(string);
	void setTermTaken(string);
	void setYearTaken(int);
	void setFinalGrade(string);
	///////////////
	////MISC////
	///////////////
	int verifyCourseCode();
	int verifyTermTaken();
	int verifyYearTaken();
	int verifyFinalGrade();
    void print() const;
	void writeToFile(int) const;

  private:
    string courseCode;
    string termTaken;
	int yearTaken;
	string finalGrade;
};

#endif
