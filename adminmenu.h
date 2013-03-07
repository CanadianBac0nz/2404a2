#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <gtkmm.h>

class AdminMenu : public Gtk::Window
{

public:
  AdminMenu();
  virtual ~AdminMenu();

protected:
  //Signal handlers:
  void btnView_clicked();
  void btnPending_clicked();
  void btnAssigned_clicked();
  void btnEdit_clicked();
  void btnCancel_clicked();

  //Member widgets:
  Gtk::VBox verticalBox;
  Gtk::HBox horizontalBox;
  Gtk::Label lblChooser;  
  Gtk::Frame frmMenu;
  Gtk::Button btnView, btnPending, btnAssigned, btnEdit, btnCancel;
};

#endif // AdminMenu_H
