#ifndef APPLICATIONUI_H
#define APPLICATIONUI_H

#include <gtkmm.h>
#include "CourseTakenQueue.h"
#include "CourseTaughtQueue.h"
#include "WorkExperienceQueue.h"

class ApplicationUI : public Gtk::Window
{

public:
  ApplicationUI();
  virtual ~ApplicationUI();

protected:
  //Signal handlers:
  void btnSubmit_clicked();
  void btnCancel_clicked();
  void btnCourseAdd_clicked();
  void btnCourseTA_clicked();
	void btnWork_clicked();

  //Member widgets:
  Gtk::VBox verticalBox, verticalBox2, verticalBox3, verticalBox4, verticalBox5;
  Gtk::HBox horizontalBox, horizontalBox2, horizontalBox3, horizontalBox4, horizontalBox5, horizontalBox6, horizontalBox7, horizontalBox8, horizontalBox9;
  Gtk::Label lblCourse, lblCourse2, lblCourse3, lblStudentNum, lblFirstName, lblLastName, lblEmail, lblMajor, lblYearStanding, lblCGPA, lblMajorGPA, lblTerm, lblYear, lblGrade,lblTerm2, lblYear2, lblName2, lblTitle, lblDur, lblStart, lblEnd; 
  Gtk::ComboBoxText cboCourse, cboCourse2, cboCourse3;
  Gtk::Entry txtStudentNum, txtFirstName, txtLastName, txtEmail, txtMajor, txtYearStanding, txtCGPA, txtMajorGPA, txtTerm, txtYear, txtGrade, txtTerm2, txtYear2, txtName2, txtTitle, txtDur, txtStart, txtEnd, txtError; 
  Gtk::Frame frmApplication, frmCourseTaken, frmCourseTA, frmWorkExperience;
  Gtk::Button btnSubmit, btnCancel, btnCourseAdd, btnCourseTA, btnWork;
  Gtk::ScrolledWindow m_ScrolledWindow, m_ScrolledWindow2, m_ScrolledWindow3;
  Gtk::TextView txtTakenSummary, txtTASummary, txtWork;

private:
	CourseTakenQueue ctQueue;
	CourseTaughtQueue ctaQueue;
	WorkExperienceQueue wQueue;
	void setGeneralInfo();
};

#endif // APPLICATION_H
