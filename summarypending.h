#ifndef SUMMARYPENDING_H
#define SUMMARYPENDING_H

#include <gtkmm.h>

class SummaryPending : public Gtk::Window
{

public:
  SummaryPending();
  virtual ~SummaryPending();

protected:
  //Signal handlers:
  void btnSave_clicked();
  void btnBack_clicked();
  void cboCourses_changed();
  void cboStudents_changed();
 

  //Member widgets:
  Gtk::HBox horizontalBox,horizontalBox2;
  Gtk::VBox verticalBox;
  Gtk::Label lblCourses, lblStudents;  
  Gtk::Frame frmMenu;
  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TextView txtSummary;
  Gtk::Button btnSave, btnBack;
  Gtk::ComboBoxText cboCourses, cboStudents;
};

#endif // SUMMARYPENDING_H
