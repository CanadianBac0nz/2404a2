using namespace std;
#include "applicationUI.h"
#include "Student.h"

#include <iostream>
#include <fstream>
#define MAX_BUF 10
#define BIG_BUF 300

ApplicationUI::ApplicationUI()
: frmApplication("Application Form"), 
  frmCourseTaken("Course Taken"),
  frmCourseTA(" Course TA'ed "),
  frmWorkExperience(" Work Experiences "),
  lblCourse(" Pick a course : "),
  lblCourse2(" Pick a course : "),
  lblCourse3(" Pick a course : "),
  lblStudentNum(" Student ID: "), 
  lblFirstName(" First Name: "), 
  lblLastName(" Last Name: "), 
  lblEmail(" Email: "), 
  lblMajor(" Major: "), 
  lblYearStanding(" Year Standing: "), 
  lblCGPA(" CGPA: "), 
  lblMajorGPA(" Major GPA: "),
  lblTerm(" Term: "), 
  lblYear(" Year: "), 
  lblGrade(" Grade: "),
  lblTerm2(" Term: "), 
  lblYear2(" Year: "), 
  lblName2(" Name of Supervisor: "),
  lblTitle(" Job Title: "), 
  lblDur(" Duration: "), 
  lblStart(" Start Date: "), 
  lblEnd(" End Date: "),  
  btnSubmit(" Submit "), 
  btnCancel(" Cancel "),
  btnCourseAdd(" Add Course "),
  btnCourseTA(" Add Course "),
  btnWork("Add Work "),
	ctQueue(),
	ctaQueue()
{
  set_title(" Application ");

  property_modal() = true;

  add(verticalBox);
  
  frmApplication.add(verticalBox2);

  verticalBox2.pack_start(horizontalBox2);
  horizontalBox2.pack_start(lblCourse);
  
  char text[MAX_BUF];
  std::ifstream inFile("courses.txt", std::ios::in);
  if(!inFile){
		exit(1);
  }
  while(!inFile.eof()) {
		inFile.getline(text,MAX_BUF);
		cboCourse.append(text);
		cboCourse2.append(text);
		cboCourse3.append(text);
  }

  horizontalBox2.pack_start(cboCourse);

  verticalBox2.pack_start(horizontalBox3);
  horizontalBox3.pack_start(lblStudentNum);

  horizontalBox3.pack_start(txtStudentNum);
  horizontalBox3.pack_start(lblFirstName);

  horizontalBox3.pack_start(txtFirstName);
  horizontalBox3.pack_start(lblLastName);
  
  horizontalBox3.pack_start(txtLastName);

  verticalBox2.pack_start(horizontalBox4);
  horizontalBox4.pack_start(lblEmail);

  horizontalBox4.pack_start(txtEmail);
  horizontalBox4.pack_start(lblMajor);

  horizontalBox4.pack_start(txtMajor);

  verticalBox2.pack_start(horizontalBox5);
  horizontalBox5.pack_start(lblYearStanding);

  horizontalBox5.pack_start(txtYearStanding);
  horizontalBox5.pack_start(lblCGPA);

  horizontalBox5.pack_start(txtCGPA);
  horizontalBox5.pack_start(lblMajorGPA);

  horizontalBox5.pack_start(txtMajorGPA);
  

  verticalBox.pack_start(frmApplication);

  frmCourseTaken.add(verticalBox3);

  verticalBox3.pack_start(horizontalBox7);

  horizontalBox7.pack_start(lblCourse2);
  horizontalBox7.pack_start(cboCourse2);

  horizontalBox7.pack_start(lblTerm);
  horizontalBox7.pack_start(txtTerm);

  horizontalBox7.pack_start(lblYear);
  horizontalBox7.pack_start(txtYear);

  horizontalBox7.pack_start(lblGrade);
  horizontalBox7.pack_start(txtGrade);

  btnCourseAdd.signal_clicked().connect(sigc::mem_fun(*this,
              &ApplicationUI::btnCourseAdd_clicked));
  horizontalBox7.pack_start(btnCourseAdd);

  m_ScrolledWindow.add(txtTakenSummary);

  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  verticalBox3.pack_start(m_ScrolledWindow);

  verticalBox.pack_start(frmCourseTaken);

  frmCourseTA.add(verticalBox4);

  verticalBox4.pack_start(horizontalBox8);

  horizontalBox8.pack_start(lblCourse3);
  horizontalBox8.pack_start(cboCourse3);

  horizontalBox8.pack_start(lblTerm2);
  horizontalBox8.pack_start(txtTerm2);

  horizontalBox8.pack_start(lblYear2);
  horizontalBox8.pack_start(txtYear2);

  horizontalBox8.pack_start(lblName2);
  horizontalBox8.pack_start(txtName2);

  btnCourseTA.signal_clicked().connect(sigc::mem_fun(*this,
              &ApplicationUI::btnCourseTA_clicked));
  horizontalBox8.pack_start(btnCourseTA);

  m_ScrolledWindow2.add(txtTASummary);

  m_ScrolledWindow2.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  verticalBox4.pack_start(m_ScrolledWindow2);

  verticalBox.pack_start(frmCourseTA);

  frmWorkExperience.add(verticalBox5);

  verticalBox5.pack_start(horizontalBox9);

  horizontalBox9.pack_start(lblTitle);
  horizontalBox9.pack_start(txtTitle);

  horizontalBox9.pack_start(lblDur);
  horizontalBox9.pack_start(txtDur);

  horizontalBox9.pack_start(lblStart);
  horizontalBox9.pack_start(txtStart);

  horizontalBox9.pack_start(lblEnd);
  horizontalBox9.pack_start(txtEnd);

  btnWork.signal_clicked().connect(sigc::mem_fun(*this,
              &ApplicationUI::btnWork_clicked));
  horizontalBox9.pack_start(btnWork);

  m_ScrolledWindow3.add(txtWork);

  m_ScrolledWindow3.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  verticalBox5.pack_start(m_ScrolledWindow3);

  verticalBox.pack_start(frmWorkExperience);

  verticalBox.pack_start(horizontalBox6);
  horizontalBox6.pack_start(txtError);

  verticalBox.pack_start(horizontalBox);

  btnSubmit.signal_clicked().connect(sigc::mem_fun(*this,
              &ApplicationUI::btnSubmit_clicked));
  horizontalBox.pack_start(btnSubmit);


  btnCancel.signal_clicked().connect(sigc::mem_fun(*this,
              &ApplicationUI::btnCancel_clicked));
  horizontalBox.pack_start(btnCancel);
	setGeneralInfo();
  show_all_children();
}

ApplicationUI::~ApplicationUI()
{
}

void ApplicationUI::setGeneralInfo()
{
	char text[BIG_BUF];
  std::ifstream inFile("temp.txt", std::ios::in);
  if(!inFile){
		return;
  }
  if(!inFile.eof()) {
		inFile.getline(text,BIG_BUF);
		txtFirstName.set_text(text);
		
		inFile.getline(text,BIG_BUF);
		txtLastName.set_text(text);
		
		inFile.getline(text,BIG_BUF);
		txtEmail.set_text(text);
		
		inFile.getline(text,BIG_BUF);
		txtMajor.set_text(text);
		
		inFile.getline(text,BIG_BUF);
		txtStudentNum.set_text(text);
		
		inFile.getline(text,BIG_BUF);
		txtYearStanding.set_text(text);
		
		inFile.getline(text,BIG_BUF);
		txtCGPA.set_text(text);
		
		inFile.getline(text,BIG_BUF);
		txtMajorGPA.set_text(text);
  }
}

void ApplicationUI::btnSubmit_clicked()
{
  //save application to text
  Glib::ustring n = txtStudentNum.get_text();
  Glib::ustring y = txtYearStanding.get_text();
  Glib::ustring c = txtCGPA.get_text();
  Glib::ustring m = txtMajorGPA.get_text();
  stringstream s1,s2,s3,s4;
  int stuNum, year;
  double cgpa, mgpa;
  s1<<n; s1>>stuNum;
  s2<<y; s2>>year;
  s3<<c; s3>>cgpa;
  s4<<m; s4>>mgpa;
  Student newStu(txtFirstName.get_text(), txtLastName.get_text(), txtEmail.get_text(), txtMajor.get_text(),
				 stuNum, year, cgpa, mgpa);
				 
  while(1) {
		if(!newStu.verifyYearStanding()) {
			txtError.set_text("Year standing must be either 1, 2, 3, or 4");
			break;
		}
		if(!newStu.verifyMGPA()) {
			txtError.set_text("MGPA not between expected bounds of 0.0 and 12.0");
			break;
		}
		if(!newStu.verifyCGPA()) {
			txtError.set_text("CGPA not between expected bounds of 0.0 and 12.0");
			break;
		}
		if(!newStu.verifyStudentNumber()) {
			txtError.set_text("Empty or non-numeric student number of length greater or less than nine digits");
			break;
		}
	  if(!newStu.verifyMajor()) {
			txtError.set_text("Empty or non-alpha major");
			break;
	  }
	  if(!newStu.verifyEmailAddress()) {
			txtError.set_text("Must be a valid cmail.carleton.ca email");
			break;
	  }
	  if(!newStu.verifyLastName()) {
			txtError.set_text("Empty or non-alpha last name");
			break;
	  }
	  if(!newStu.verifyFirstName()) {
			txtError.set_text("Empty or non-alpha first name");
			break;
	  }
		if(cboCourse.get_active_text() == "") {
			txtError.set_text("Select a course");
			break;
		}
	  
	  
	  else {
			newStu.newApplication();
			newStu.setStatus(1);
			newStu.setCourse(cboCourse.get_active_text());
			newStu.writeToFile();
			newStu.writeToFile("temp");
			ctQueue.writeToFile(newStu.getAppNum());
			while(!ctQueue.empty()){
				ctQueue.popFront();
			}
			ctaQueue.writeToFile(newStu.getAppNum());
			while(!ctaQueue.empty()){
				ctaQueue.popFront();
			}
			wQueue.print();
			wQueue.writeToFile(newStu.getAppNum());
			while(!wQueue.empty()){
				wQueue.popFront();
			}
			Gtk::Main::quit();
			break;
	  }
  }
  
}


void ApplicationUI::btnCancel_clicked()
{
  //return to student menu
  Gtk::Main::quit();
}

void ApplicationUI::btnCourseAdd_clicked()
{
  Glib::ustring y = txtYear.get_text();
  stringstream s1;
  int year;
  s1<<y; s1>>year;
	
  //append to txtTakenSummary
	CourseTaken *course = new CourseTaken(cboCourse2.get_active_text(), txtTerm.get_text(), year, txtGrade.get_text());
	while(1) {
		if(!course->verifyCourseCode()) {
			txtError.set_text("Select a course");
			break;
		}
		if(!course->verifyTermTaken()) {
			txtError.set_text("Empty or term entered not of Fall, Winter or Summer");
			break;
		}
		if(!course->verifyYearTaken()) {
			txtError.set_text("Empty or year not between 1942 and 2013");
			break;
		}
		if(!course->verifyFinalGrade()) {
			txtError.set_text("Empty or grade below A-");
			break;
		}
		else {
			ctQueue.pushBack(course);
			break;
		}
	}
	

}

void ApplicationUI::btnCourseTA_clicked()
{
	Glib::ustring y = txtYear2.get_text();
  stringstream s1;
  int year;
  s1<<y; s1>>year;
	
  //append to txtTakenSummary
	CourseTaught *course = new CourseTaught(cboCourse3.get_active_text(), txtTerm2.get_text(), year, txtName2.get_text());
	while(1) {
		if(!course->verifyCourseCode()) {
			txtError.set_text("Select a course");
			break;
		}
		if(!course->verifyTermTaught()) {
			txtError.set_text("Empty or term entered not of Fall, Winter or Summer");
			break;
		}
		if(!course->verifyYearTaught()) {
			txtError.set_text("Empty or year not between 1942 and 2013");
			break;
		}
		if(!course->verifySupervisor()) {
			txtError.set_text("Empty or grade below A-");
			break;
		}
		else {
			ctaQueue.pushBack(course);
			break;
		}
	}
}

void ApplicationUI::btnWork_clicked()
{
  //append to txtWork
	Glib::ustring y = txtDur.get_text();
  stringstream s1;
  int duration;
  s1<<y; s1>>duration;
	
	Glib::RefPtr<Gtk::TextBuffer> text;
	text = txtWork.get_buffer();
	cout<<text->get_text()<<endl;
	string txt2 = text->get_text();
	//text->set_text("blah blah blah\n" "derp derp derp\n");
	
  //append to txtTakenSummary
	WorkExperience *work = new WorkExperience(txtTitle.get_text(), txt2, duration, txtStart.get_text(), txtEnd.get_text());
	while(1) {
		if(!work->verifyTitle()) {
			txtError.set_text("No title entered");
			break;
		}
		if(!work->verifyResponsibilities()) {
			txtError.set_text("No responsibilities entered");
			break;
		}
		if(!work->verifyDuration()) {
			txtError.set_text("No duration or non-integer entered");
			break;
		}
		if(!work->verifyStartDate()) {
			txtError.set_text("Use DD/MM/YY format");
			break;
		}
		if(!work->verifyEndDate()) {
			txtError.set_text("Use DD/MM/YY format");
			break;
		}
		else {
			wQueue.pushBack(work);
			break;
		}
	}
	
}
