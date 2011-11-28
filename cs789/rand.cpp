#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  int max;
  if (argc > 1) {
    max = ::atoi(argv[1]);

    ::srand(static_cast<size_t> (::time(NULL)));

    std::cout << "RAND: " << (::rand() % max) << std::endl;
  }

  return 0;
}// main
