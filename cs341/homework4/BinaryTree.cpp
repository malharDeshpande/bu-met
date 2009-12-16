// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #4

#include "BinaryTree.h" // class implemented

#include <cstdlib>

static double *QUEUE = 0;
static int QUEUE_COUNT = 0;

static void
set_queue(double& val)
{
  QUEUE[QUEUE_COUNT] = val;
  ++QUEUE_COUNT;
}// set_queue

BinaryTree::BinaryTree() :
  _root_ptr(0)
{
}// BinaryTree

BinaryTree::BinaryTree(const BinaryTree& source) :
  _root_ptr(0)
{
  _root_ptr = tree_copy(source._root_ptr);
}// BinaryTree

BinaryTree::~BinaryTree()
{
  tree_clear(_root_ptr);
}// ~BinaryTree

void
BinaryTree::operator+=(const BinaryTree& addend)
{
}// operator+=

void
BinaryTree::operator=(const BinaryTree& source)
{
  if (this != &source) {
    tree_clear(_root_ptr);
    _root_ptr = tree_copy(source._root_ptr);
  }
}// operator=

int
BinaryTree::erase(const double& target)
{
  int many = 0;
  
  while (erase_one(target)) {
    ++many;
  }

  return many;
}// erase

bool
BinaryTree::erase_one(const double& target)
{
  return bt_remove(_root_ptr, target);
}// erase_one

void
BinaryTree::insert(const double& target)
{
  if (_root_ptr == 0) {
    _root_ptr = new Node(target, 0, 0);
  } else {
    Node* cursor = _root_ptr;
    bool done = false;

    while (!done) {
      if (target <= cursor->data()) {
	if (cursor->left_ptr() == 0) {
	  cursor->set_left_ptr(new Node(target, 0, 0));
	  done = true;
	} else {
	  cursor = cursor->left_ptr();
	}
      } else { // target > cursor->data()
	if (cursor->right_ptr() == 0) {
	  cursor->set_right_ptr(new Node(target, 0, 0));
	  done = true;
	} else {
	  cursor = cursor->right_ptr();
	}
      }
    }
  }
}// insert

int
BinaryTree::size() const
{
  return tree_size(_root_ptr);
}// size

int
BinaryTree::count(const double& target) const
{
  int many = 0;
  Node* cursor = _root_ptr;
  while (cursor != 0) {
    if (cursor->data() == target) {
      ++many;
      cursor = cursor->left_ptr();
    } else if (cursor->data() < target) {
      cursor = cursor->right_ptr();
    } else { // cursor->data() > target
      cursor = cursor->left_ptr();
    }
  }

  return many;
}// count

void
BinaryTree::preorder_print() const
{
  preorder(print, _root_ptr);
}// preorder_print

void
BinaryTree::inorder_print() const
{
  inorder(print, _root_ptr);
}// inorder_print

void
BinaryTree::postorder_print() const
{
  postorder(print, _root_ptr);
}// postorder_print

void
BinaryTree::display() const
{
  print(_root_ptr, 0);
}// display

void
BinaryTree::insert_all(Node* ptr)
{
  if (ptr != 0) {
    insert(ptr->data());
    insert_all(ptr->left_ptr());
    insert_all(ptr->right_ptr());
  }
}// insert_all

/// credit: john maslanka w/ ryan butler
static void
find_middle(int start, int end, int level, int total, int round, int& index, int* indices)
{
  if (abs(start - end) < 2) {
    if (start == 1) {
      int loop = level - 1;
      while (0 != indices[loop]) {
	++loop;
      }
      indices[loop] = start;
    }
    if (end == total) {
      int loop = level - 1;
      while (0 != indices[loop]) {
	++loop;
      }
      indices[loop] = end;
    }
    return;
  }

  int middle;
  if ((start + end) % 2) {
    middle = (start+end+round)/2;
    int loop = level - 1;
    while (0 != indices[loop]) {
      ++loop;
    }
    indices[loop] = middle;
   } else {
    middle = (start+end)/2;
    int loop = level - 1;
    while (0 != indices[loop]) {
      ++loop;
    }
    indices[loop] = middle;
  }
 
  find_middle(start,middle,level+1,total,-1,index,indices);
  find_middle(middle,end,level+1,total,1,index,indices);
  return;
}// find_middle

void
BinaryTree::balance()
{
  QUEUE = new double[this->size()];

  inorder(set_queue, _root_ptr);
  
  for (int loop = 0; loop < QUEUE_COUNT; ++loop) {
    this->erase_one(QUEUE[loop]);
  }

  int indices[QUEUE_COUNT];
  for (int loop = 0; loop < QUEUE_COUNT; ++loop) {
    indices[loop] = 0;
  }

  int indexer = 0;

  find_middle(1,QUEUE_COUNT,1,QUEUE_COUNT,1,indexer,indices);

  for (int loop = 0; loop < QUEUE_COUNT; ++loop) {
    this->insert(QUEUE[indices[loop] - 1]);
  }  

  delete QUEUE;
  QUEUE = 0;
  QUEUE_COUNT = 0;
}// balance

void
BinaryTree::compress()
{
  compress_nodes(_root_ptr);
}// compress

bool bt_remove(Node*& ptr, const double& target)
{
  bool deleted = false;

  if (ptr == 0) {
    return deleted;
  }
  
  if (target < ptr->data()) {
    deleted = bt_remove(ptr->left_ptr(), target);
  } else if (target > ptr->data()) {
    deleted = bt_remove(ptr->right_ptr(), target);
  } else { // target == ptr->data()
    if (ptr->left_ptr() == 0) {
      Node*& tmp = ptr;
      ptr = ptr->right_ptr();
      delete tmp;
      tmp = 0;
      deleted = true;
    } else {
      bt_remove_max(ptr->left_ptr(), ptr->data());
      deleted = true;
    }
  }
  
  return deleted;
}// bt_remove

void bt_remove_max(Node*& ptr, double& removed)
{
  if (ptr->right_ptr() == 0) {
    removed = ptr->data();
    Node*& tmp = ptr;
    ptr = ptr->left_ptr();
    delete tmp;
    tmp = 0;
  } else {
    bt_remove_max(ptr->right_ptr(), removed);
  }
}// bt_remove_max
