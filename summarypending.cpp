using namespace std;
#include "summarypending.h"
#include <iostream>
#include <fstream>
#include <string>
#define MAX_BUF 100

SummaryPending::SummaryPending()
: lblCourses(" Pick a course : "),
  lblStudents(" List of Applications: "),
  btnSave(" Save "),
  btnBack(" Back ")
{
  set_title(" Summary of Pending Applications ");

  property_modal() = true;

  add(verticalBox);
  
  frmMenu.add(horizontalBox);

  horizontalBox.pack_start(lblCourses);
  
	char text[MAX_BUF];
  std::ifstream inFile("courses.txt", std::ios::in);
  if(!inFile){
		exit(1);
  }
  while(!inFile.eof()) {
		inFile.getline(text,MAX_BUF);
		cboCourses.append(text);
  }
	
  horizontalBox.pack_start(cboCourses);

  cboCourses.signal_changed().connect(sigc::mem_fun(*this,
              &SummaryPending::cboCourses_changed) );

  horizontalBox.pack_start(lblStudents);
  
  cboStudents.append("Students 1");
  cboStudents.append("Students 2");
  horizontalBox.pack_start(cboStudents);

  cboStudents.signal_changed().connect(sigc::mem_fun(*this,
              &SummaryPending::cboStudents_changed) );

  verticalBox.pack_start(frmMenu);

  m_ScrolledWindow.add(txtSummary);
	
	m_ScrolledWindow.set_min_content_height(20);

  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  verticalBox.pack_start(m_ScrolledWindow);

  verticalBox.pack_start(horizontalBox2);

  btnSave.signal_clicked().connect(sigc::mem_fun(*this,
              &SummaryPending::btnSave_clicked));
  horizontalBox2.pack_start(btnSave);


  btnBack.signal_clicked().connect(sigc::mem_fun(*this,
              &SummaryPending::btnBack_clicked));
  horizontalBox2.pack_start(btnBack);

  show_all_children();
}

SummaryPending::~SummaryPending()
{
}

void SummaryPending::btnSave_clicked()
{
  //save to file from the txtview 
	Glib::RefPtr<Gtk::TextBuffer> text;
	text = txtSummary.get_buffer();
	string s = cboCourses.get_active_text();
	string buffer = text->get_text();
	
	ostringstream fileName;
	fileName << "summaries/" << s << ".txt";
	ofstream outFile(fileName.str().c_str(), ios::trunc);
	
	if(!outFile) {
		cout<<"Could not open " << fileName.str() << " file"<<endl;
		exit(1);
	}
	
	outFile<<buffer<<endl;
}

void SummaryPending::btnBack_clicked()
{
  //go to back to admin menu
  Gtk::Main::quit();
}

void SummaryPending::cboCourses_changed()
{
  //changed load cboStudents
	Glib::RefPtr<Gtk::TextBuffer> textSum;
	textSum = txtSummary.get_buffer();
	
	
	string course = cboCourses.get_active_text();
	string appNum, stuNum, firstName, lastName, buffer;
	buffer = "";
	textSum->set_text(buffer);
	
	char text[MAX_BUF];
	char stuText[MAX_BUF];
  std::ifstream inFile("applications.txt", std::ios::in);
  if(!inFile){
		exit(1);
  }
  while(!inFile.eof()) {
		inFile.getline(text,MAX_BUF);
		string currLine(text);
		if(course == currLine) {
			cout<<"found match!"<<endl;
			cout<<"first name: "<< firstName <<endl;
			
			std::ifstream inFile("applications.txt", std::ios::in);
			
			buffer = buffer + "Application Number: " + appNum + " Student Number: " + stuNum + " First Name:" + firstName + " Last Name:" + lastName;
			
			ostringstream fileName;
	
			fileName << "applications/" << appNum << ".txt";
			std::ifstream inFileStu(fileName.str().c_str(), ios::in);
			inFileStu.getline(stuText,MAX_BUF);
			string currStuLine(stuText);
			
			if(currStuLine == appNum) {
				for(int i=0; i<5; i++) {
					inFileStu.getline(stuText,MAX_BUF);
				}
				string email(stuText);
				inFileStu.getline(stuText,MAX_BUF);
				string majorP(stuText);
				inFileStu.getline(stuText,MAX_BUF);
				string stuNumber(stuText);
				inFileStu.getline(stuText,MAX_BUF);
				string year(stuText);
				inFileStu.getline(stuText,MAX_BUF);
				string cgpa(stuText);
				inFileStu.getline(stuText,MAX_BUF);
				string mgpa(stuText);
				
				buffer = buffer + " Email Address: " + email + " Major: " + majorP + " Year: " + year + " CGPA: " + cgpa + " MGPA: " + mgpa + "\n";
				
			
			}
			else {
				cout<<currStuLine<<endl;
				cout<<fileName.str().c_str()<<endl;
				cout<<appNum<<endl;
			}
			
			textSum->set_text(buffer);
		}
		appNum = stuNum;
		stuNum = firstName;
		firstName = lastName;
		lastName = currLine;
  }
	
}

void SummaryPending::cboStudents_changed()
{
  //changed load to the txtSummary
}

