#include "DoubleLinkList.h"
#include <iostream>
using namespace std;

DoubleLinkList::DoubleLinkList () 
{FwdListPointer = RevListPointer = previous = NULL;}

bool DoubleLinkList::putNode (double dd) {
  bool x = false; 
  Node* temp1;
  Node* tempfwd;
  Node A;
  temp1 = A.putOneNode (FwdListPointer, dd);
  if (temp1 != NULL)
    {	
      if (FwdListPointer == NULL && RevListPointer == NULL)
	FwdListPointer = RevListPointer = temp1;
      else
	{
	  tempfwd = FwdListPointer;
	  tempfwd->putPriorPointer (temp1); 
	  FwdListPointer = temp1;
	}
      x =true;
    }
  return x;
}

Node* DoubleLinkList::findNode (double udata)
{
  Node* temp; 
  previous = FwdListPointer;
  for (temp = FwdListPointer; temp != NULL && temp->getOneNode() != udata; 
       previous = temp, temp = temp->getNextPointer());
  return temp;
}

void DoubleLinkList::getListForward()
{
  Node* temp;
  for (temp = FwdListPointer; temp != NULL;
       temp = temp->getNextPointer()) 
    cout << " User Data " << temp->getOneNode () << endl;
  // from Elena Oulanova
}
 
void DoubleLinkList::getListReverse() {
  Node* temp;
  for (temp = RevListPointer; temp != NULL;
       temp = temp->getPriorPointer()) 
    cout << " User Data " << temp->getOneNode () << endl;
}

void DoubleLinkList::deleteNode (Node* delPtr) {
  Node* temp = NULL;     // temporary pointer variable to a Node - is internal to this method
  if (delPtr != NULL){   // a live pointer?
    if (FwdListPointer == delPtr) { // contains same value as forward list pointer instance variable?
      FwdListPointer = FwdListPointer->getNextPointer();  //yes - get next ptr from first Node and
      // move it to the forward list ptr
    }
    else  // forward list pointer not equal to delPtr - points to an interior Node on the list
      {
	temp = delPtr->getPriorPointer(); // get prior ptr from Node referred to by delPtr and assign it to temp
	temp->putNextPointer(delPtr->getNextPointer());  // get next ptr to next Node and put it into
	  // the prior node's next ptr
      }
    // these statements should have comments which are symmetricdal to comments for teh forward list ptr
    //  above (Left to the students.)
    if (RevListPointer == delPtr) {
      RevListPointer = RevListPointer->getPriorPointer();
    }
    else
      {
	temp = delPtr->getNextPointer();
	temp->putPriorPointer(delPtr->getPriorPointer());
      }
    delete delPtr; // delete Node pointed to by teh delPtr
    
  }
  
}

bool DoubleLinkList::DeleteToEnd(Node* ref)
{
  bool result = false;

  while (ref != NULL) {
    Node* next = ref->getNextPointer();
    this->deleteNode(ref);
    result = true;
    ref = next;
  }

  return result;
}

