// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#ifndef QUEUE_H
#define QUEUE_H

class Node;

/// A Queue class
class Queue {
 public:
  
  /// Constructor
  Queue();
  
  /// ~Destructor
  ~Queue();
  
  /**
   * Add user data to the end of the queue
   *
   * @param data the user data
   */
  void push(const double& data);
  
  /**
   * Remove the first user data from the queue.
   *
   * @precondition empty() is not true
   * @postcondition first user data is remove from the queue
   * @throws exception if the queue is empty
   */
  void pop();
  
  /**
   * View the front user data from the queue.
   *
   * @returns the user data from the top of the queue
   * @precondition empty() is not true
   * @throws exception if the queue is empty
   */
  double front() const;
  
  /// Returns true if the queue is empty
  bool empty() const;

  /// Returns the total number of entries on the queue
  int size() const;

  /// Helper method to view data on the queue (outputs to std::cout)
  void dump() const;
  
 protected:
 private:
  Node* _front_ptr;
  Node* _rear_ptr;
  int _count;

  };

#endif // #ifndef QUEUE_H
