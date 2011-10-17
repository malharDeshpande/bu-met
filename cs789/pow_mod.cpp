#include "lib/ExponentiationAlgorithm.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " X E M" << std::endl;
    exit(-1);
  }

  int x = ::atoi(argv[1]);
  int e = ::atoi(argv[2]);
  int m = ::atoi(argv[3]);

  tgl::ExponentiationAlgorithm ea;

  std::cout << "The result is: " << ea.pow_mod(x, e, m) << std::endl;

  return 0;
}// main
