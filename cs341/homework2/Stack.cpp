// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #2

#include "Stack.h" // class included

#include <cassert>
#include <iostream>

namespace lorber_homework2
{

  Stack::Stack() : _head_ptr(0) {}

  Stack::~Stack()
  {
    while (_head_ptr != 0) {
      Node* remove_ptr = _head_ptr;
      _head_ptr = _head_ptr->link();
      delete remove_ptr;
    }
  }// ~Stack

  void Stack::push(const Node::value_type& data)
  {
    _head_ptr = new Node(data, _head_ptr);
  }// push
  
  void Stack::pop()
  {
    assert(!this->empty());
    Node* remove_ptr = _head_ptr;
   _head_ptr = _head_ptr->link();
    delete remove_ptr;
  }// pop

  Node::value_type Stack::peek() const
  {
    assert(!this->empty());
    return _head_ptr->data();
  }// peek

  bool Stack::empty() const
  {
    return (_head_ptr == 0) ? true : false;
  }// is_empty

  void Stack::dump() const
  {
    std::cout << "STACK DUMP" << std::endl;
    for (Node* cursor = _head_ptr; cursor != 0; cursor = cursor->link()) {
      std::cout << "data: " << cursor->data() << std::endl;
    }
  }// dump
}

