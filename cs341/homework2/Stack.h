// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #2

#ifndef STACK_H
#define STACK_H

class Node;

class Stack {
 public:
  
  /// Constructor
  Stack();
  
  /// ~Destructor
  ~Stack();
  
  void push(const double& data);
  
  void pop();
  
  double peek() const;
  
  bool empty() const;
  
  void dump() const;
  
 protected:
 private:
  Node* _head_ptr;
  
  };

#endif // #ifndef STACK_H
