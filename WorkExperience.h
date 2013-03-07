#ifndef WORKEXPERIENCE_H
#define WORKEXPERIENCE_H

class WorkExperience
{
  public:
    WorkExperience(string="", string="", int=0, string="", string="");
//    ~WorkExperience();
	///////////////
	////getters////
	///////////////
	string getResponsibilities() const;
	int getDuration() const;
	string getStartDate() const;
	string getEndDate() const;
	///////////////
	////setters////
	///////////////
	void setResponsibilities(string);
	void setDuration(int);
	void setStartDate(string);
	void setEndDate(string);
	///////////////
	////MISC////
	///////////////
	int verifyTitle() const;
	int verifyResponsibilities() const;
	int verifyDuration() const;
	int verifyStartDate() const;
	int verifyEndDate() const;
    void print() const;
	void writeToFile(int) const;

  private:
		string title;
    string responsibilities;
    int duration;
	string startDate;
	string endDate;
};

#endif
