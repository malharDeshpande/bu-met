#include "lib/ExponentiationAlgorithm.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " e1 M p" << std::endl;
    exit(-1);
  }

  int e = ::atoi(argv[1]);
  int r = ::atoi(argv[2]);
  int p = ::atoi(argv[3]);

  tgl::ExponentiationAlgorithm ea;

  std::cout << e << "^" << r << " mod " << p << " = " << ea.pow_mod(e, r, p) 
            << std::endl;

  return 0;
}// main
