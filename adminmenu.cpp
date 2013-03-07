#include "adminmenu.h"
#include "summarypending.h"
#include <iostream>

AdminMenu::AdminMenu()
: frmMenu("Admin Menu"), 
  lblChooser("Select : "),
  btnView(" View an application "), 
  btnPending(" View a summary of pending applications "), 
  btnAssigned(" View a summary of assigned applications "),
  btnEdit(" View and edit a TA evaluation "),
  btnCancel(" Back ")
{
  set_title("Administration Menu ");

  set_border_width(50);

  property_modal() = true;

  add(verticalBox);
  
  frmMenu.add(lblChooser);
  verticalBox.pack_start(frmMenu);


  btnView.signal_clicked().connect(sigc::mem_fun(*this,
              &AdminMenu::btnView_clicked));
  verticalBox.pack_start(btnView);


  btnPending.signal_clicked().connect(sigc::mem_fun(*this,
              &AdminMenu::btnPending_clicked));
  verticalBox.pack_start(btnPending);

  btnAssigned.signal_clicked().connect(sigc::mem_fun(*this,
              &AdminMenu::btnAssigned_clicked));
  verticalBox.pack_start(btnAssigned);

  btnEdit.signal_clicked().connect(sigc::mem_fun(*this,
              &AdminMenu::btnEdit_clicked));
  verticalBox.pack_start(btnEdit);

  btnCancel.signal_clicked().connect(sigc::mem_fun(*this,
              &AdminMenu::btnCancel_clicked));
  verticalBox.pack_start(btnCancel);

  show_all_children();
}

AdminMenu::~AdminMenu()
{
}

void AdminMenu::btnView_clicked()
{
  //go to View an application 
}

void AdminMenu::btnPending_clicked()
{
  //go to View a summary of pending applications
  SummaryPending summaryPending;

  Gtk::Main::run(summaryPending);
}

void AdminMenu::btnAssigned_clicked()
{
  //return to View a summary of assigned applications 
}

void AdminMenu::btnEdit_clicked()
{
  //return to View and edit a TA evaluation 
}

void AdminMenu::btnCancel_clicked()
{
  //return to main menu
  Gtk::Main::quit();
}
