#include "lib/ExponentiationAlgorithm.h"
#include "lib/timer.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " e1 M p" << std::endl;
    exit(-1);
  }

  tgl::BigInteger e(::atoi(argv[1]));
  tgl::BigInteger r(argv[2]);
  tgl::BigInteger p(argv[3]);

  tgl::ExponentiationAlgorithm ea;

  tgl::Timer t;

  std::cout << e << "^" << r << " mod " << p << " = " << ea.pow_mod(e, r, p) 
            << std::endl;

  std::cout << "Seconds to compute: " << t.elapsed() << std::endl;

  return 0;
}// main
