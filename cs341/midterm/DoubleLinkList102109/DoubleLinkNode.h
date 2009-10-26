#ifndef DLList
#define DLList
class Node {
public:
	Node () {}
	Node* putOneNode (Node*, double);
	double getOneNode ();
	Node* getNextPointer ();
	void putNextPointer (Node*);
	Node* getPriorPointer ();
	void putPriorPointer (Node*);
private:
	double nr;
	Node* nextPtr;
	Node* priorPtr;
};
#endif