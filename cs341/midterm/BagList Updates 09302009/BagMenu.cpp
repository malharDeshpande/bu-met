// John Maslanka  BagMenu.cpp Baglist Demo 09302009

// Author:	John Maslanka
// Date:	9/13/09
// Edit:	Create Bagmenu top-leveaccess to BagList application

#include "BagList.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main () {
    BagList A;
    double nr, udata;
    int nth;
    bool cont = true;
    char sel;
    Node* nodePtr = NULL;
    while (!cin.eof()&&cin.good()&&cont) {
	cout << "Enter your function: Add, Delete, Exit, Find, FindNth(N), List: ";
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
		case 'D': case 'd': { // assume that the current found node is to be deleted
		    if (nodePtr != NULL) {
			A.deleteNode (nodePtr);
			nodePtr = NULL;
			cout << "Delete was successful" << endl;
			}
		    else
			cout << "Valid Find not run previously." << endl;
			break;
			}
		case 'E': case 'e': {
			cont = false;
			break;
			}
  	        case 'N': case 'n': {
		        cout << "Please Enter User Data (double-precision) value to find: ";
                        cin >> udata;
                        if (!cin.eof() && cin.good()) {
			  cout << "Please Enter Occurrence (#) find: ";
			  cin >> nth;
			  if (!cin.eof() && cin.good()) {
			    nodePtr = A.FindNth(nth, udata);
			    if (nodePtr == NULL) 
			      cout << "Data not found for occurrence." << endl;
			    else
			      cout << "The " << nth << " occurrence of your data (" << nodePtr->getOneNode() << ") was found!" << endl;
			  }
			}
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
			        cout << "Your data was found: " << nodePtr->getOneNode() 
					<< endl;
			    }
			else 
			    cont = false;
			break;
			}
		case 'L': case 'l': {
			cout << "List of nodes" << endl;
			A.getList();
			cout << endl;
			break;
			}
		default: {
			cout << "Invalid function entered." << endl;
			 }
		}
	    }
	}
	return 0;
}
