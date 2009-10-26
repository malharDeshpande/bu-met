#include "DoubleLinkNode.h"
#include <cstdlib>

Node* Node::getNextPointer (){
	return nextPtr;
}
void Node::putNextPointer (Node* x){
	this->nextPtr = x;
}
Node* Node::getPriorPointer (){
	return priorPtr;
}
void Node::putPriorPointer (Node* x){
	this->priorPtr = x;
}
Node* Node::putOneNode (Node* x, double d) {
	Node* temp = NULL;
	if (temp = new Node()) {
		temp->nextPtr = x;
		temp->priorPtr = NULL;
		temp->nr = d;
	}
	return temp;
}
double Node::getOneNode() {
	return nr;
}