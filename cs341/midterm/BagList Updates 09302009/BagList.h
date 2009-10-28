// John Maslanka  Baglist.h Baglist Demo 09302009

#ifndef BAGLIST
#define BAGLIST

class Node;

class BagList {
public:
	BagList();
	bool putNode (double d);
	void getList ();
	Node* findNode (double);
	void  deleteNode (Node*);
	Node* FindNth(int n, double userValue);
private:
	Node* ListPointer;
	Node* previous;
};

#endif
