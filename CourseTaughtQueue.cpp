#include <iostream>
#include <cstring>
using namespace std;

#include "CourseTaughtQueue.h"

CourseTaughtQueue::CourseTaughtQueue() : head(0), tail(0) { }

CourseTaughtQueue::~CourseTaughtQueue()
{
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

bool CourseTaughtQueue::empty() {
	bool answer;
	if (head == 0)
		answer = true;
	else answer = false;

	return answer;
}

void CourseTaughtQueue::pushBack(CourseTaught* newCourse)
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

void CourseTaughtQueue::popFront()
{
	if (head == 0) {
		cout << "Queue is empty" << endl;
		return;
	}
	Node* newHead = head;
	head = head->next;
	cout << "Deleting; the course deleted is " << newHead->data << endl;
	delete newHead;
}

CourseTaught CourseTaughtQueue::front() {
	if (head == 0)
		cout << "Queue is empty so can't return the first item in the queue." << endl;
	return (*head->data);
}

void CourseTaughtQueue::print() const
{
  Node* currNode = head;

  cout << "COURSES TAUGHT:" <<endl;
  while (currNode != 0) {
    currNode->data->print();
    currNode = currNode->next;
  }

}

void CourseTaughtQueue::writeToFile(int appNum) const
{
	Node* currNode = head;
  
  while (currNode != 0) {
    currNode->data->writeToFile(appNum);
    currNode = currNode->next;
  }
	cout << "Finished writing" <<endl;
}








