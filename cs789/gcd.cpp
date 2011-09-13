#include "lib/EuclideanAlgorithm.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " M N" << std::endl;
    exit(-1);
  }

  int m = ::atoi(argv[1]);
  int n = ::atoi(argv[2]);

  EuclideanAlgorithm ea;

  std::cout << "The GCD is: " << ea.gcd(m, n) << std::endl;

  return 0;
}// main
