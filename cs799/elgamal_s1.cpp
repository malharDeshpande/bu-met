#include "lib/ExponentiationAlgorithm.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  int e = ::atoi(argv[1]);
  int r = ::atoi(argv[2]);
  int p = ::atoi(argv[3]);

  tgl::ExponentiationAlgorithm ea;

  std::cout << e << "^" << r << " mod " << p << " = " << ea.pow_mod(e, r, p) 
            << std::endl;

  return 0;
}// main
