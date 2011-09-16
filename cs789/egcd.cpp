#include "lib/ExpandedEuclideanAlgorithm.h"

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

  ExpandedEuclideanAlgorithm eea;

  int x;
  int y;

  eea.extendedGcd(m, n, x, y);

  std::cout << "Using EGCD, x0 is: " << x << " and y0 is: " << y << std::endl;

  return 0;
}// main
