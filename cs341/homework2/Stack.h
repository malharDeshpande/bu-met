// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #2

#ifndef STACK_H
#define STACK_H

#include "Node.h"

namespace lorber_homework2
{
  class Stack {
  public:

    /// Constructor
    Stack();

    /// ~Destructor
    ~Stack();

    void push(const Node::value_type& data);

    void pop();

    Node::value_type peek() const;

    bool empty() const;

    void dump() const;

  protected:
  private:
    Node* _head_ptr;
    
  };

}

#endif // #ifndef STACK_H
