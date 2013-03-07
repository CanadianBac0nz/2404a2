#ifndef MAINMENU_H
#define MAINMENU_H

#include <gtkmm.h>

class MainMenu : public Gtk::Window
{

public:
  MainMenu();
  virtual ~MainMenu();

protected:
  //Signal handlers:
  void btnStudent_clicked();
  void btnAdmin_clicked();
  void btnExit_clicked();

  //Member widgets:
  Gtk::VBox verticalBox;
  Gtk::HBox horizontalBox;
  Gtk::Label lblChooser;  
  Gtk::Frame frmMenu;
  Gtk::Button btnStudent, btnAdmin, btnExit;
};

#endif // MAINMENU_H
