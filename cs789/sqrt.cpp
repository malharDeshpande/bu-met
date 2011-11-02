#include "lib/FloorSqrtAlgorithm.h"
#include "lib/ExponentiationAlgorithm.h"
#include "lib/BigInteger.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " X E" << std::endl;
    exit(-1);
  }

  tgl::BigInteger x(::atoi(argv[1]));
  tgl::BigInteger e(::atoi(argv[2]));

  tgl::ExponentiationAlgorithm ea;

  tgl::BigInteger n = ea.pow(x, e);

  tgl::FloorSqrtAlgorithm fsa;

  tgl::BigInteger m = fsa.compute(n);

  std::cout << "Using Newton's method, m is: " << m << std::endl;

  return 0;
}// main
