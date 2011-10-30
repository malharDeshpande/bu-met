#include "lib/ExpandedEuclideanAlgorithm.h"
#include "lib/BigInteger.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " M N" << std::endl;
    exit(-1);
  }

  tgl::BigInteger m(::atoi(argv[1]));
  tgl::BigInteger n(::atoi(argv[2]));

  tgl::ExpandedEuclideanAlgorithm eea;

  tgl::BigInteger x;
  tgl::BigInteger y;

  eea.extendedGcd(m, n, x, y);

  std::cout << "Using EGCD, x0 is: " << x << " and y0 is: " << y << std::endl;

  return 0;
}// main
