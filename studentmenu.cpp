using namespace std;
#include "studentmenu.h"
#include "mainmenu.h"
#include "applicationUI.h"
#include <iostream>
#include <fstream>

StudentMenu::StudentMenu()
: frmMenu("Student Menu"), 
  lblChooser("Select : "), 
  btnCreate(" Create an application "), 
  btnEdit(" Edit an application "),
  btnCancel(" Back ")
{
  set_title("Student Application Menu ");

  set_border_width(50);

  property_modal() = true;

  add(verticalBox);
  
  frmMenu.add(lblChooser);
  verticalBox.pack_start(frmMenu);

  verticalBox.pack_start(horizontalBox);

  btnCreate.signal_clicked().connect(sigc::mem_fun(*this,
              &StudentMenu::btnCreate_clicked));
  horizontalBox.pack_start(btnCreate);


  btnEdit.signal_clicked().connect(sigc::mem_fun(*this,
              &StudentMenu::btnEdit_clicked));
  horizontalBox.pack_start(btnEdit);

  btnCancel.signal_clicked().connect(sigc::mem_fun(*this,
              &StudentMenu::btnCancel_clicked));
  horizontalBox.pack_start(btnCancel);

  show_all_children();
}

StudentMenu::~StudentMenu()
{
}

void StudentMenu::btnCreate_clicked()
{
  //go to application
  ApplicationUI newApp;

  Gtk::Main::run(newApp);
}

void StudentMenu::btnEdit_clicked()
{
  //go to edit application
}

void StudentMenu::btnCancel_clicked()
{
  //return to main menu
	ofstream outFile("temp.txt", ios::trunc);
  Gtk::Main::quit();
}

bool StudentMenu::on_delete_event(GdkEventAny* event)
{
	ofstream outFile("temp.txt", ios::trunc);
	Gtk::Main::quit();
	return true;
}
