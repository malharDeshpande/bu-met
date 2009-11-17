// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#include "Node.h" // class implemented

Node::Node(const double& data, Node* link) :
  _user_data(data),
  _link(link)
{
}// Node

void Node::set_data(const double& data)
{
  _user_data = data;
}// set_data

void Node::set_link(Node* link)
{
  _link = link;
}// set_link
  
double Node::data() const { return _user_data; };

Node* Node::link() { return _link; };

const Node* Node::link() const { return _link; };
