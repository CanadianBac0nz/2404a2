#ifndef VIEW_H
#define VIEW_H

#include <gtkmm.h>
#include "Controller.h"

class View
{
public:
  View(Controller&);
  ~View();
  launchWindow(Controller&);
}

#endif
