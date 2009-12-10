// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #4

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

/// Container class to define operations for a binary tree
class BinaryTree {
 public:
  
  /// Deafult constructor
  BinaryTree();

  /// Constructor
  BinaryTree(const BinaryTree& source);

  /// Destructor
  ~BinaryTree();

  void operator +=(const BinaryTree& addend);

  void operator =(const BinaryTree& source);

  int erase(const double& target);

  bool erase_one(const double& target);

  void insert(const double& target);

  int size() const;

  int count(const double& target) const;

  void preorder_print() const;

  void inorder_print() const;

  void postorder_print() const;

  void display() const;

 protected:
 private:
  Node* _root_ptr;

  void insert_all(Node* ptr);
};

bool bt_remove(Node*& ptr, const double& target);

void bt_remove_max(Node*& ptr, double& removed);

#endif // #ifndef BINARYTREE_H
