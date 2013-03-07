#include "mainmenu.h"
#include "studentmenu.h"
#include "adminmenu.h"
#include <iostream>

MainMenu::MainMenu()
: frmMenu("cuTAES Main Menu"), 
  lblChooser("Choose your role : "), 
  btnStudent(" Student "), 
  btnAdmin(" Administrator "),
  btnExit(" Exit ")
{
  set_title("cuTAES Main Menu ");

  set_border_width(50);

  property_modal() = true;

  add(verticalBox);
  
  frmMenu.add(lblChooser);
  verticalBox.pack_start(frmMenu);

  verticalBox.pack_start(horizontalBox);

  btnStudent.signal_clicked().connect(sigc::mem_fun(*this,
              &MainMenu::btnStudent_clicked));
  horizontalBox.pack_start(btnStudent);


  btnAdmin.signal_clicked().connect(sigc::mem_fun(*this,
              &MainMenu::btnAdmin_clicked));
  horizontalBox.pack_start(btnAdmin);

  btnExit.signal_clicked().connect(sigc::mem_fun(*this,
              &MainMenu::btnExit_clicked));
  horizontalBox.pack_start(btnExit);

  show_all_children();
}

MainMenu::~MainMenu()
{
}

void MainMenu::btnStudent_clicked()
{
  //go to student menu
  StudentMenu studentMenu;

  Gtk::Main::run(studentMenu);
}

void MainMenu::btnAdmin_clicked()
{
  //go to admin menu
  AdminMenu adminMenu;

  Gtk::Main::run(adminMenu);
}

void MainMenu::btnExit_clicked()
{
  Gtk::Main::quit();
}
