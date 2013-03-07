
#include <string>
#include <iostream>
using namespace std;
#include "Student.h"

#include "mainmenu.h"
#include <gtkmm.h>

int main (int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  MainMenu mainMenu;

  Gtk::Main::run(mainMenu);
  
  return 0;
}
