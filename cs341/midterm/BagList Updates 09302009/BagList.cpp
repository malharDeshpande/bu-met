// John Maslanka  Baglist.cpp Baglist Demo 09302009

#include "Node.h"
#include "BagList.h"

#include <iostream>

using namespace std;

BagList::BagList () 
	{ListPointer = previous = NULL;}
bool BagList::putNode (double dd) {
	bool x = false; Node* temp1;
	Node A;
	temp1 = A.putOneNode (ListPointer, dd);
	if (temp1 != NULL)
	{	ListPointer = temp1;
		x =true;
	}
	return x;
}
Node* BagList::findNode (double udata){
	Node* temp; 
	previous = ListPointer;
	for (temp = ListPointer; temp != NULL && temp->getOneNode() != udata; 
		                   previous = temp, temp = temp->getNextPointer());
	return temp;
}
void BagList::getList() {
	Node* temp;
	for (temp = ListPointer; temp != NULL;
									temp = temp->getNextPointer()) 
		cout << " User Data " << temp->getOneNode () << endl;
}
void BagList::deleteNode (Node* delPtr) {
	if (delPtr != NULL){
		if (ListPointer == previous){
			Node* temp = ListPointer;
			ListPointer = previous->getNextPointer();
			delete temp;
		}
		else 
		{
			Node* linkPtr = previous->getNextPointer()->getNextPointer();
			Node* NodeToDelete = previous->getNextPointer();
			previous->putNextPointer(linkPtr);
			delete NodeToDelete;
		}
	}
}

Node* BagList::FindNth(int n, double userValue)
{
  Node* temp = ListPointer; 
  previous = ListPointer;
  int count = 0;
  while (temp != NULL) {
    if (temp->getOneNode() == userValue) {
      count++;
    }

    if (count == n) {
      break;
    }
     
    previous = temp;
    temp = temp->getNextPointer();
  }

  if (count = n) {
    temp = NULL;
  }

  return temp;
}
