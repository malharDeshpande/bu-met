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

/// A Stack class that implements push, pop, peek
class Stack {
 public:
  
  /// Constructor
  Stack();
  
  /// ~Destructor
  ~Stack();
  
  /**
   * Add user data to the top of the stack
   *
   * @param data the user data
   */
  void push(const double& data);
  
  /**
   * Remove the top-most user data from the stack.
   *
   * @precondition empty() is not true
   * @postcondition top-most user data is remove from the stack
   * @throws exception if the stack is empty
   */
  void pop();
  
  /**
   * View the top-most user data from the stack.
   *
   * @returns the user data from the top of the stack
   * @precondition empty() is not true
   * @throws exception if the stack is empty
   */
  double peek() const;
  
  /// Returns true if the stack is empty
  bool empty() const;
  
  /// Helper method to view data on the stack (outputs to std::cout)
  void dump() const;
  
 protected:
 private:
  Node* _head_ptr;
  
  };

#endif // #ifndef STACK_H
