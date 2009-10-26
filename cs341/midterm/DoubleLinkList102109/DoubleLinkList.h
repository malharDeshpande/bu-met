#include "DoubleLinkNode.h"
class DoubleLinkList {
public:
	DoubleLinkList ();
	bool putNode (double d);
	void getListForward ();
	void getListReverse ();
	Node* findNode (double);
	void  deleteNode (Node*);
        bool DeleteToEnd(Node*);
private:
	Node* FwdListPointer;
	Node* RevListPointer;
	Node* previous;
};
