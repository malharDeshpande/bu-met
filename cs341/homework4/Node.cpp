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

double& Node::data() { return _user_data; };

const double& Node::data() const { return _user_data; };

Node*& Node::left_ptr() { return _left_ptr; };

Node*& Node::right_ptr() { return _right_ptr; };

const Node* Node::left_ptr() const { return _left_ptr; };

const Node* Node::right_ptr() const { return _right_ptr; };

bool Node::is_leaf() const
{
  return (_left_ptr == 0) && (_right_ptr == 0);
}// is_leaf

bool Node::is_leg_left() const
{
  bool result = false;
  if ((_left_ptr != 0) && (_right_ptr == 0)) {
    if ((_left_ptr->left_ptr() != 0) && (_left_ptr->right_ptr() == 0)) {
      if (_left_ptr->left_ptr()->is_leaf()) {
	result = true;
      }
    }
  }

  return result;
}// is_leg_left

bool Node::is_leg_right() const
{
  bool result = false;
  if ((_right_ptr != 0) && (_left_ptr == 0)) {
    if ((_right_ptr->right_ptr() != 0) && (_right_ptr->left_ptr() == 0)) {
      if (_right_ptr->right_ptr()->is_leaf()) {
	result = true;
      }
    }
  }

  return result;
}// is_leg_right

bool Node::is_dog_leg_left() const
{
  bool result = false;
  if ((_left_ptr == 0) && (_right_ptr != 0)) {
    if ((_right_ptr->right_ptr() == 0) && (_right_ptr->left_ptr() != 0)) {
      if (_right_ptr->left_ptr()->is_leaf()) {
	result = true;
      }
    }
  }

  return result;
}// is_dog_leg_left

bool Node::is_dog_leg_right() const
{
  bool result = false;
  if ((_right_ptr == 0) && (_left_ptr != 0)) {
    if ((_left_ptr->right_ptr() != 0) && (_left_ptr->left_ptr() == 0)) {
      if (_left_ptr->right_ptr()->is_leaf()) {
	result = true;
      }
    }
  }

  return result;
}// is_leg_right

void compress_nodes(Node*& ptr)
{
  if (ptr == 0) {
    return;
  }

  if (ptr->is_leg_left()) {
    double tmp = ptr->data();
    ptr->set_data(ptr->left_ptr()->data());    
    ptr->left_ptr()->set_data(ptr->left_ptr()->left_ptr()->data());

    delete ptr->left_ptr()->left_ptr();
    ptr->left_ptr()->set_left_ptr(0);

    ptr->set_right_ptr(new Node(tmp, 0, 0));

  } else if (ptr->is_leg_right()) {
    double tmp = ptr->data();
    ptr->set_data(ptr->right_ptr()->data());    
    ptr->right_ptr()->set_data(ptr->right_ptr()->right_ptr()->data());

    delete ptr->right_ptr()->right_ptr();
    ptr->right_ptr()->set_right_ptr(0);

    ptr->set_left_ptr(new Node(tmp, 0, 0));

  } else if (ptr->is_dog_leg_left()) {
    double tmp = ptr->data();
    ptr->set_data(ptr->right_ptr()->left_ptr()->data());    
    
    delete ptr->right_ptr()->left_ptr();
    ptr->right_ptr()->set_left_ptr(0);

    ptr->set_left_ptr(new Node(tmp, 0, 0));

  } else if (ptr->is_dog_leg_right()) {
    double tmp = ptr->data();
    ptr->set_data(ptr->left_ptr()->right_ptr()->data());    
    
    delete ptr->left_ptr()->right_ptr();
    ptr->left_ptr()->set_right_ptr(0);

    ptr->set_right_ptr(new Node(tmp, 0, 0));

  }

  compress_nodes(ptr->left_ptr());
  compress_nodes(ptr->right_ptr());
}// compress_nodes

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

