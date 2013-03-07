#include <iostream>
#include <cstring>
using namespace std;

#include "WorkExperienceQueue.h"

WorkExperienceQueue::WorkExperienceQueue() : head(0), tail(0) { }

WorkExperienceQueue::~WorkExperienceQueue()
{
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

bool WorkExperienceQueue::empty() {
	bool answer;
	if (head == 0)
		answer = true;
	else answer = false;

	return answer;
}

void WorkExperienceQueue::pushBack(WorkExperience* newWorkExperience)
{
	Node* tmpNode = new Node;
  	tmpNode->data = newWorkExperience;
		tmpNode->next = 0;

	if (head == 0)
		head = tmpNode;
	else
	  tail->next = tmpNode;

	tail = tmpNode;
}

void WorkExperienceQueue::popFront()
{
	if (head == 0) {
		cout << "Queue is empty" << endl;
		return;
	}
	Node* newHead = head;
	head = head->next;
	cout << "Deleting; the work experience deleted is " << newHead->data << endl;
	delete newHead;
}

WorkExperience WorkExperienceQueue::front() {
	if (head == 0)
		cout << "Queue is empty so can't return the first item in the queue." << endl;
	return (*head->data);
}

void WorkExperienceQueue::print() const
{
  Node* currNode = head;

  cout << "RELEVANT WORK EXPERIENCE:" <<endl;
  while (currNode != 0) {
    currNode->data->print();
    currNode = currNode->next;
  }

}

void WorkExperienceQueue::writeToFile(int appNum) const
{
	Node* currNode = head;
  
  while (currNode != 0) {
    currNode->data->writeToFile(appNum);
    currNode = currNode->next;
  }
	cout << "Finished writing" <<endl;
}







