// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #2

#ifndef NODE_H
#define NODE_H

class Node {
 public:
  
  /// Constructor
  Node(const double& data, Node* link);
  
  void set_data(const double& data);
  
  void set_link(Node* link);
  
  double data() const;
  
  Node* link();
  
  const Node* link() const;
  
 protected:
 private:
  double _user_data;
  Node* _link;

};

#endif // #ifndef NODE_H
