#include <iostream>
#include <cstring>
using namespace std;

#include "CourseTakenQueue.h"

CourseTakenQueue::CourseTakenQueue() : head(0), tail(0) { }

CourseTakenQueue::~CourseTakenQueue()
{
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

bool CourseTakenQueue::empty() {
	bool answer;
	if (head == 0)
		answer = true;
	else answer = false;

	return answer;
}

void CourseTakenQueue::pushBack(CourseTaken* newCourse)
{
	Node* tmpNode = new Node;
  	tmpNode->data = newCourse;
		tmpNode->next = 0;

	if (head == 0)
		head = tmpNode;
	else
	  tail->next = tmpNode;

	tail = tmpNode;
}

void CourseTakenQueue::popFront()
{
	if (head == 0) {
		cout << "Queue is empty" << endl;
		return;
	}
	Node* newHead = head;
	head = head->next;
	cout << "Deleting; the course deleted is " << newHead->data << endl;
	delete newHead->data;
	delete newHead;
}

CourseTaken CourseTakenQueue::front() {
	if (head == 0)
		cout << "Queue is empty so can't return the first item in the queue." << endl;
	return (*head->data);
}

void CourseTakenQueue::print() const
{
  Node* currNode = head;

  cout << "COURSES TAKEN:" <<endl;
  while (currNode != 0) {
    currNode->data->print();
    currNode = currNode->next;
  }

}

void CourseTakenQueue::writeToFile(int appNum) const
{
	Node* currNode = head;
  
  while (currNode != 0) {
    currNode->data->writeToFile(appNum);
    currNode = currNode->next;
  }
	cout << "Finished writing" <<endl;
}







