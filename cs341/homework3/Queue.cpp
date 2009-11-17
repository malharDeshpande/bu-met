// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#include "Queue.h" // class included
#include "Node.h"

#include <cassert>
#include <iostream>

Queue::Queue() : _front_ptr(0), _rear_ptr(0), _count(0) {}

Queue::~Queue()
{
  while (_rear_ptr != 0) {
    Node* remove_ptr = _rear_ptr;
    _rear_ptr = _front_ptr->link();
    delete remove_ptr;
  }
}// ~Queue

void Queue::push(const double& data)
{
  if (this->empty()) {
    _front_ptr = _rear_ptr = new Node(data, 0);
  } else {
    _rear_ptr->set_link(new Node(data, _rear_ptr->link()));
    _rear_ptr = _rear_ptr->link();
  }

  ++_count;
}// push

void Queue::pop()
{
  assert(!this->empty());
  Node* remove_ptr = _front_ptr;
  _front_ptr = _front_ptr->link();
  delete remove_ptr;
  --_count;
}// pop

double Queue::front() const
{
  assert(!this->empty());
  return _front_ptr->data();
}// front

bool Queue::empty() const
{
  return (_front_ptr == 0) ? true : false;
}// is_empty

int Queue::size() const
{
  return _count;
}// size

void Queue::dump() const
{
  std::cout << "QUEUE DUMP" << std::endl;
  for (Node* cursor = _front_ptr; cursor != 0; cursor = cursor->link()) {
    std::cout << "data: " << cursor->data() << std::endl;
  }
}// dump


