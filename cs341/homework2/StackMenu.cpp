// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #2

#include "Stack.h"

#include <cassert>
#include <cstdlib>
#include <iostream>

void print_menu()
{
  std::cout << "Make a selection: " << std::endl;
  std::cout << " A    Put number onto the stack" << std::endl;
  std::cout << " D    Pop number from the stack" << std::endl; 
  std::cout << " P    Peek at number on the top of the stack" << std::endl;
  std::cout << " L    List all numbers in the stack" << std::endl;
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
  
  std::cout << "Please enter a real number for the stack: ";
  std::cin >> number;

  assert(std::cin.good() && !std::cin.eof());

  std::cout << number << " has been read." << std::endl;

  return number;
}// get_number

int
main(int argc, char* argv[])
{
  Stack stack;
  char choice;

  do {
    print_menu();
    choice = std::toupper(get_command());
    switch (choice) {
    case 'A': stack.push(get_number());
      break;
    case 'S': if (!stack.empty()) stack.pop();
      break;
    case 'P': if (!stack.empty()) std::cout << "Top of the stack: " << stack.peek() << std::endl;
      break;
    case 'L': stack.dump();
      break;
    case 'Q': std::cout << "I'm still not sure I understand ambiguity." << std::endl;
      break;
    default: std::cout << choice << " is invalid." << std::endl;
    }
  } while ('Q' != choice);

  return EXIT_SUCCESS;
}// main
