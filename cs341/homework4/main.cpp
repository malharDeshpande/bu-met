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
  std::cout << "Make a selection: " << std::endl;
  std::cout << " A    Add a node to the tree" << std::endl;
  std::cout << " D    Delete a node from the tree" << std::endl; 
  std::cout << " T    Tree traversal" << std::endl;
  std::cout << " P    Pretty print the tree" << std::endl;
  std::cout << " Q    Quit this program" << std::endl;
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
  
  std::cout << "Please enter a real number for the tree: ";
  std::cin >> number;

  assert(std::cin.good() && !std::cin.eof());

  std::cout << number << " has been read." << std::endl;

  return number;
}// get_number

char get_character()
{
  char character;
  
  std::cout << "Please enter a (P)reorder, (I)norder, Postorde(R) traversal: ";
  std::cin >> character;

  assert(std::cin.good() && !std::cin.eof());

  std::cout << character << " has been read." << std::endl;

  return character;
}// get_character

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
    case 'D': if (!bt.erase_one(get_number())) std::cout << "\nCould not find value to delete." << std::endl;
      break;
    case 'P': bt.display();
      break;
    case 'T': {
      char p = std::toupper(get_character());
      switch (p) {
      case 'P': bt.preorder_print();
	break;
      case 'I': bt.inorder_print();
	break;
      case 'R': bt.postorder_print();
	break;
      default:
	std::cout << "\nInvalid traversal command." << std::endl;
      }

      break;
    }
    case 'Q': std::cout << "\n\n" << std::endl;
      break;
    default: std::cout << "\n" << choice << " is invalid.\n" << std::endl;
    }
  } while ('Q' != choice);

  
  return EXIT_SUCCESS;
}// main
