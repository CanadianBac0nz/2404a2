#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <iostream>
#include <cstdlib> 
using namespace std;

class Controller{
	public:
		Controller();
		~Controller();
		void buttonListener(string);
};
#endif
