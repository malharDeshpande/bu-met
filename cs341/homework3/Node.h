// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#ifndef NODE_H
#define NODE_H

#include "Customer.h"

/// Node class to hold user data and link reference
class Node {
 public:
  
  /// Constructor
  Node(Customer* data, Node* link);
  
  /// Set user data
  void set_data(Customer* data);
  
  /// Set reference link
  void set_link(Node* link);

  /// Get user data
  Customer* data();

  /// Get user data
  const Customer* data() const;
  
  /// Get link reference
  Node* link();
  
  /// Get link reference
  const Node* link() const;

 protected:
 private:
  Customer* _user_data;
  Node* _link;

};

#endif // #ifndef NODE_H
