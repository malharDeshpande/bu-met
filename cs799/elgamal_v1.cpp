#include "lib/ExponentiationAlgorithm.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " e1 M p" << std::endl;
    exit(-1);
  }

  tgl::BigInteger e(argv[1]);
  tgl::BigInteger r(argv[2]);
  tgl::BigInteger p(argv[3]);

  tgl::ExponentiationAlgorithm ea;

  time_t start, end;
  ::time(&start);

  std::cout << e << "^" << r << " mod " << p << " = " << ea.pow_mod(e, r, p) 
            << std::endl;

  ::time(&end);

  std::cout << "Seconds to compute: " << ::difftime(end, start) << std::endl;

  return 0;
}// main
