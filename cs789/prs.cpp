#include "lib/PrimitiveRootSearchAlgorithm.h"
#include "lib/BigInteger.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " P" << std::endl;
    exit(-1);
  }

  tgl::BigInteger p(::atoi(argv[1]));

  tgl::PrimitiveRootSearchAlgorithm prs;

  tgl::BigInteger b = prs.compute(p);

  std::cout << "Using PRS, b is: " << b << std::endl;

  return 0;
}// main
