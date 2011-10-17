#include "lib/ExponentiationAlgorithm.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " X E" << std::endl;
    exit(-1);
  }

  int x = ::atoi(argv[1]);
  int e = ::atoi(argv[2]);

  tgl::ExponentiationAlgorithm ea;

  std::cout << "The result is: " << ea.pow(x, e) << std::endl;

  return 0;
}// main
