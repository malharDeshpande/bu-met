#include "lib/BabyStepGiantStepAlgorithm.h"
#include "lib/PrimitiveRootSearchAlgorithm.h"
#include "lib/BigInteger.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " P A B" << std::endl;
    exit(-1);
  }

  tgl::BigInteger p(::atoi(argv[1]));
  tgl::BigInteger a(::atoi(argv[2]));
  tgl::BigInteger b(::atoi(argv[3]));

  tgl::BabyStepGiantStepAlgorithm bsgs;

  tgl::BigInteger r = bsgs.compute(p, a, b);

  std::cout << "Using Baby-Step, Giant-Step: " << r << std::endl;

  return 0;
}// main
