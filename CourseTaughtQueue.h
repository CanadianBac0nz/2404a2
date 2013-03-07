#ifndef COURSETAUGHTQUEUE_H
#define COURSETAUGHTQUEUE_H
#include "CourseTaught.h"

class CourseTaughtQueue
{
  class Node
  {
    friend class CourseTaughtQueue;
    private:
      CourseTaught* data;
      Node*    next;
  };

  public:
    CourseTaughtQueue();
    ~CourseTaughtQueue();
    void pushBack(CourseTaught*); //adds to tail
    void popFront(); //removes from head
	CourseTaught front();
	bool empty(); 
    void print() const;
		void writeToFile(int) const;

  private:
    Node* head;
	Node* tail; //necessary?
};
#endif
