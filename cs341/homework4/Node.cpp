// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #4

#include "Node.h" // class implemented

#include <iostream>
#include <iomanip>

Node::Node(double data, Node* left, Node* right) :
  _user_data(data),
  _left_ptr(left),
  _right_ptr(right)
{
}// Node

void Node::set_data(double data)
{
  _user_data = data;
}// set_data

void Node::set_left_ptr(Node* link)
{
  _left_ptr = link;
}// set_left_ptr

void Node::set_right_ptr(Node* link)
{
  _right_ptr = link;
}// set_right_ptr

double Node::data() const { return _user_data; };

Node* Node::left_ptr() { return _left_ptr; };

Node* Node::right_ptr() { return _right_ptr; };

bool Node::is_leaf() const
{
  return (_left_ptr == 0) && (_right_ptr == 0);
}// is_leaf

void preorder(void f(double&), Node* ptr)
{
  if (0 != ptr) {
    f(ptr->data());
    preorder(f, ptr->left_ptr());
    preorder(f, ptr->right_ptr());
  }
}// preorder

void inorder(void f(double&), Node* ptr)
{
  if (0 != ptr) {
    inorder(f, ptr->left_ptr());
    f(ptr->data());
    inorder(f, ptr->right_ptr());
  }
}// inorder

void postorder(void f(double&), Node* ptr)
{
  if (0 != ptr) {
    postorder(f, ptr->left_ptr());
    postorder(f, ptr->right_ptr());
    f(ptr->data());
  }
}// postorder

void print(Node* ptr, int depth)
{
  std::cout << std::setw(4*depth) << "";
  if (ptr == 0) {
    std::cout << "[empty]" << std::endl;
  } else if (ptr->is_leaf()) {
    std::cout << ptr->data();
    std::cout << " [leaf]" << std::endl;
  } else {
    std::cout << ptr->data() << std::endl;
    print(ptr->right_ptr(), depth+1);
    print(ptr->left_ptr(), depth+1);
  }
}// print

void tree_clear(Node*& ptr)
{
  if (ptr != 0) {
    tree_clear(ptr->left_ptr());
    tree_clear(ptr->right_ptr());
    delete ptr;
    ptr = 0;
  }
}// tree_clear

Node* tree_copy(Node* ptr)
{
  if (ptr == 0) {
    return 0;
  } else {
    Node* left_ptr = tree_copy(ptr->left_ptr());
    Node* right_ptr = tree_copy(ptr->right_ptr());
    return new Node(ptr->data(), left_ptr, right_ptr);
  }
}// tree_copy

int tree_size(Node* ptr)
{
  if (ptr == 0) {
    return 0;
  } else {
    return 1 + tree_size(ptr->left_ptr()) + tree_size(ptr->right_ptr());
  }
}// tree_size

void print(double& data)
{
  std::cout << " " << data;
}// print
