// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #4

#include "BinaryTree.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void print_menu()
{
  std::cout << "\nMake a selection: \n"
	    << " A    Add a node to the tree\n"
            << " C    Count nodes matching given value\n"
	    << " D    Delete a node from the tree\n"
            << " S    Total number of nodes\n"
	    << " T    Tree traversal (preorder, inorder, postorder)\n"
	    << " P    Pretty print the tree\n"
	    << " Q    Quit this program" << std::endl;
}// print_menu

char get_command()
{
  char choice;
  std::cout << "\nEnter choice: ";
  std::cin >> choice;

  assert(std::cin.good() && !std::cin.eof());

  return choice;
}// get_command

double get_number()
{
  double number;
  
  std::cout << "Please enter a real number: ";
  std::cin >> number;

  assert(std::cin.good() && !std::cin.eof());

  std::cout << number << " has been read." << std::endl;

  return number;
}// get_number

char get_traversal_type()
{
  char character;
  
  std::cout << "Please enter a (P)reorder, (I)norder, Postorde(R) traversal: ";
  std::cin >> character;

  assert(std::cin.good() && !std::cin.eof());

  std::cout << character << " has been read." << std::endl;

  return character;
}// get_traversal_type

int
main(int argc, char* argv[])
{
  BinaryTree bt;
  char choice;

  do {
    print_menu();
    choice = std::toupper(get_command());
    switch (choice) {
    case 'A': bt.insert(get_number());
      break;
    case 'C': std::cout << bt.count(get_number()) << " found." << std::endl;
      break;
    case 'S': std::cout << bt.size() << " nodes in this tree." << std::endl;
      break;
    case 'D': if (!bt.erase_one(get_number())) std::cout << "Could not find value to delete." << std::endl;
      break;
    case 'P': bt.display();
      break;
    case 'T': {
      char p = std::toupper(get_traversal_type());
      switch (p) {
      case 'P': std::cout << "Preorder: "; bt.preorder_print(); std::cout << std::endl;
	break;
      case 'I': std::cout << "Inorder: "; bt.inorder_print(); std::cout << std::endl;
	break;
      case 'R': std::cout << "Postorder: "; bt.postorder_print(); std::cout << std::endl;
	break;
      default:
	std::cout << "\nInvalid traversal command." << std::endl;
      }

      break;
    }
    case 'Q': std::cout << "\n\nI think that I shall never see\nA poem lovely as a tree.\nJoyce Kilmer" << std::endl;
      break;
    default: std::cout << "\n" << choice << " is invalid.\n" << std::endl;
    }
  } while ('Q' != choice);

  
  return EXIT_SUCCESS;
}// main
