#ifndef WINDOW_H
#define WINDOW_H

#include "Controller.h"
#include <string>
#include <cstdlib>
using namespace std;

class Window{
	public:
		Window(Controller&);
		~Window();
};

#endif
