// Author:	John Maslanka and CS341 class
// Date:	10/7/09
// Edit:	Create DoubleLinkMenu top-level access to DoubleLinkList application

#include "DoubleLinkList.h"
#include "DoubleLinkNode.h"
#include <iostream>
using namespace std;

int main () {
  DoubleLinkList A;
  double nr, udata;
  bool cont = true;
  char sel;
  Node* nodePtr = NULL;
  while (!cin.eof()&&cin.good()&&cont) {
    cout << "Enter your function: Add, Delete, DeleteToEnd(T), Exit, Find, ListForward, ListReverse(R): ";
    cin >> sel;
    if (!cin.eof()) {
      switch (sel) {		
      case 'A': case 'a': {
	cout << "Enter a double-precision number or control-z to end ";
	cin >> nr;
	if (!cin.eof() && cin.good())
	  cont = A.putNode(nr);
	else
	  cont = false;
	break;
      }
      case 'D': case 'd': { // assume that thye current found node is to be deleted
	if (nodePtr != NULL) {
	  A.deleteNode (nodePtr);
	  nodePtr = NULL;
	  cout << "Delete was successful" << endl;
	}
	else
	  cout << "Valid Find not run previously." << endl;
	break;
      }			
      case 'T': case 't': {
	if (nodePtr != NULL) {
	  if (A.DeleteToEnd(nodePtr)) {
	    cout << "Dete to end was successfull" << endl;
	  }
	  else
	    cout << "Delete to end failed." << endl;
	}
	else
	  cout << "Valid Find not run previously." << endl;
	break;
      }
      case 'E': case 'e': {
	cont = false;
	break;
      }
      case 'F': case 'f': {
	cout << "Please Enter User Data value to find: ";
	cin >> udata;
	if (!cin.eof() && cin.good()) {
	  nodePtr = A.findNode(udata);
	  if (nodePtr == NULL)
	    cout << "Data not found." << endl;
	  else
	    cout << "Your data was found: " << nodePtr->getOneNode() << endl;
	}
	else 
	  cont = false;
	break;
      }
      case 'L': case 'l': {
	cout << "Forward List of nodes" << endl;
	A.getListForward();
	cout << endl;
	break;
      }
      case 'R': case 'r': {
	cout << "Reverse List of nodes" << endl;
	A.getListReverse();
	cout << endl;
	break;
      }
      default: {
	cout << "Invalid funciton entered." << endl;
      }
      }
    }
  }
  return 0;
}
