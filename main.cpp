#include "definitions.h"

#ifdef DEBUG
#include <iostream>
#endif

#include "Controller.h"
using namespace std;

int main (int argc, char *argv[])
{
  #ifdef DEBUG
  cout<<"Main Method::"<<endl;
  #endif
  Controller c;   
c.buttonListener("sssss"); 
  return 0;
}
