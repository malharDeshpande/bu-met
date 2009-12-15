// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #4

#ifndef NODE_H
#define NODE_H

/// Node class to hold user data and ptr references
class Node {
 public:
  
  /// Constructor
  Node(double data, Node* left, Node* right);
  
  /// Set user data
  void set_data(double data);
  
  /// Set reference ptr
  void set_left_ptr(Node* ptr);

  /// Set reference ptr
  void set_right_ptr(Node* ptr);
  
  /// Reference to the data.
  double& data();

  /// Get left ptr
  Node*& left_ptr();

  /// Get right ptr
  Node*& right_ptr();


  /// Const reference.
  const double& data() const;

  /// Get left ptr, const reference
  const Node* left_ptr() const;

  /// Get right ptr, const reference
  const Node* right_ptr() const;
  
  /// Is this the end?
  bool is_leaf() const;

  /// true if a r-> b r-> c
  bool is_leg_right() const;

  /// true if a l-> b l-> c
  bool is_leg_left() const;

  /// true if a l-> b r-> c
  bool is_dog_leg_right() const;

  /// true if a r-> b l-> c
  bool is_dog_leg_left() const;

 protected:
 private:
  double _user_data;
  Node* _left_ptr;
  Node* _right_ptr;
};

/// Functions to work on nodes

void compress_nodes(Node*& ptr);

void preorder(void f(double&), Node* ptr);

void inorder(void f(double&), Node* ptr);

void postorder(void f(double&), Node* ptr);

void print(Node* ptr, int depth);

void tree_clear(Node*& ptr);

Node* tree_copy(Node* ptr);

int tree_size(Node* ptr);

void print(double&);

#endif // #ifndef NODE_H
