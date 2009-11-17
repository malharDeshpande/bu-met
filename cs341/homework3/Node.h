// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#ifndef NODE_H
#define NODE_H


/// Node class to hold user data and link reference
class Node {
 public:
  
  /// Constructor
  Node(const double& data, Node* link);
  
  /// Set user data
  void set_data(const double& data);
  
  /// Set reference link
  void set_link(Node* link);

  /// Get user data
  double data() const;
  
  /// Get link reference
  Node* link();
  
  /// Get link reference
  const Node* link() const;

 protected:
 private:
  double _user_data;
  Node* _link;

};

#endif // #ifndef NODE_H
