#include "lib/ElGamalDss.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc == 4) {
    int n(::atoi(argv[1]));
    int k(::atoi(argv[2]));
    int m(::atoi(argv[3]));

    tgl::ElGamalDss dss;
    dss.run(n, k ,m);
    
  } else {
    std::cerr << "Usage: " << argv[0] << " N K m\n"
              << "  N - number of binary digits to use for result\n"
              << "  K - number of Miller Rabin tests to check for primality\n"
              << "  m - digest to sign"
              << std::endl;
  }

  return 0;
}// main

