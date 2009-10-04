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

using namespace lorber_homework2;

void print_menu()
{
  std::cout << "Make a selection: " << std::endl;
  std::cout << " +    Put data onto the stack" << std::endl;
  std::cout << " -    Pop data from the stack" << std::endl; 
  std::cout << " P    Show the data on the top of the stack" << std::endl;
  std::cout << " S    List all data on the stack" << std::endl;
  std::cout << " Q    Quit this program" << std::endl;
}// print_menu

char get_command()
{
  char choice;
  std::cout << "Enter choice: ";
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
    case '+': stack.push(get_number());
      break;
    case '-': if (!stack.empty()) stack.pop();
      break;
    case 'P': if (!stack.empty()) std::cout << "Top of the stack: " << stack.peek() << std::endl;
      break;
    case 'S': stack.dump();
      break;
    case 'Q': std::cout << "I'm still not sure I understand ambiguity." << std::endl;
      break;
    default: std::cout << choice << " is invalid." << std::endl;
    }
  } while ('Q' != choice);

  return EXIT_SUCCESS;
}// main
