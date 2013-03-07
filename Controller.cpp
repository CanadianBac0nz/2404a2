#include "definitions.h"
#include "Controller.h"

Controller::Controller(){
////////////////////
//Constructor
//Start the program stuff
////////////////////
//#ifdef DEBUG
cout<<"Controller::"<<endl;
//#endif

};

Controller::~Controller(){
////////////////////
//Destructor
////////////////////
};

void Controller::buttonListener(string s){
////////////////////
//Is called from the windows when a button is pressed
////////////////////
#ifdef DEBUG
cout<<s;
#endif
};
