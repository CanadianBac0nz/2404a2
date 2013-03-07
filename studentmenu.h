#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include <gtkmm.h>

class StudentMenu : public Gtk::Window
{

public:
  StudentMenu();
  virtual ~StudentMenu();

protected:
  //Signal handlers:
  void btnCreate_clicked();
  void btnEdit_clicked();
  void btnCancel_clicked();
	bool on_delete_event(GdkEventAny*);

  //Member widgets:
  Gtk::VBox verticalBox;
  Gtk::HBox horizontalBox;
  Gtk::Label lblChooser;  
  Gtk::Frame frmMenu;
  Gtk::Button btnCreate, btnEdit, btnCancel;
};

#endif // STUDENTMENU_H
