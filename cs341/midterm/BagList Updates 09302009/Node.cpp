// John Maslanka  Node.cpp Baglist Demo 09302009

#include "Node.h"
#include <cstdlib>

Node* Node::getNextPointer (){
	return nextPtr;
}
void Node::putNextPointer (Node* x){
	this->nextPtr = x;
}
Node* Node::putOneNode (Node* x, double d) {
	Node* temp = NULL;
	if (temp = new Node()) {
		temp->nextPtr = x;
		temp->nr = d;
	}
	return temp;
}
double Node::getOneNode() {
	return nr;
}