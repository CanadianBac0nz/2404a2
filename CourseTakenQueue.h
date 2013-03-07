#ifndef COURSETAKENQUEUE_H
#define COURSETAKENQUEUE_H
#include "CourseTaken.h"

class CourseTakenQueue
{
  class Node
  {
    friend class CourseTakenQueue;
    private:
      CourseTaken* data;
      Node*    next;
  };

  public:
    CourseTakenQueue();
    ~CourseTakenQueue();
    void pushBack(CourseTaken*); //adds to tail
    void popFront(); //removes from head
	CourseTaken front();
	bool empty(); 
    void print() const;
		void writeToFile(int) const;

  private:
    Node* head;
	Node* tail; //necessary?
};
#endif