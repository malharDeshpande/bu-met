// John Maslanka  Node.h Baglist Demo 09302009
// Note: #-sign commands are a contribution of a student

#ifndef NODE
#define NODE
class Node {
public:
        Node () {};
	Node* putOneNode (Node*, double);
	double getOneNode ();
	Node* getNextPointer ();
	void putNextPointer (Node*);
private:
	double nr;
	Node* nextPtr;
};
#endif
