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

  /// Get user data
  double data() const;

  /// Get left ptr
  Node* left_ptr();

  /// Get right ptr
  Node* right_ptr();
  
  /// Is this the end?
  bool is_leaf() const;

 protected:
 private:
  double _user_data;
  Node* _left_ptr;
  Node* _right_ptr;
};

/// Functions to work on nodes

void preorder(void f(double&), Node* ptr);

void inorder(void f(double&), Node* ptr);

void postorder(void f(double&), Node* ptr);

void print(Node* ptr, int depth);

void tree_clear(Node*& ptr);

Node* tree_copy(Node* ptr);

int tree_size(Node* ptr);

void print(double&);

#endif // #ifndef NODE_H
