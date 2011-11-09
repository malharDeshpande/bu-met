#include <iostream>

int
main(int argc, char* argv[])
{
  ::srand(time(NULL));

  std::cout << "RAND - " << ::rand() % 1000 << std::endl;

  return 0;
}// main
