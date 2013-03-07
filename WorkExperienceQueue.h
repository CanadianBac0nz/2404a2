#ifndef WORKEXPERIENCEQUEUE_H
#define WORKEXPERIENCEQUEUE_H
#include "WorkExperience.h"

class WorkExperienceQueue
{
  class Node
  {
    friend class WorkExperienceQueue;
    private:
      WorkExperience* data;
      Node*    next;
  };

  public:
    WorkExperienceQueue();
    ~WorkExperienceQueue();
    void pushBack(WorkExperience*); //adds to tail
    void popFront(); //removes from head
	WorkExperience front();
	bool empty(); 
    void print() const;
		void writeToFile(int) const;

  private:
    Node* head;
	Node* tail; 
};
#endif
