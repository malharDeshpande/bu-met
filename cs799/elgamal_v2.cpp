#include "lib/ExponentiationAlgorithm.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 5) {
    std::cerr << "Usage: " << argv[0] << " e2 S1 S2 p" << std::endl;
    exit(-1);
  }

  int e2 = ::atoi(argv[1]);
  int s1 = ::atoi(argv[2]);
  int s2 = ::atoi(argv[3]);
  int p = ::atoi(argv[3]);

  tgl::ExponentiationAlgorithm ea;

  std::cout << "V2 is " << e2 << "^" << s1 << " * " << s1 << "^" << s2 << " mod " << p << std::endl;

  tgl::BigInteger a = ea.pow_mod(e2, s1, p);
  tgl::BigInteger b = ea.pow_mod(s1, s2, p);

  std::cout << a << " * " << b << " mod " << p << " = " << (a * b ) % p << std::endl;

  return 0;
}// main
