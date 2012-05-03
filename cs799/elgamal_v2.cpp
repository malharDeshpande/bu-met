#include "lib/ExponentiationAlgorithm.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  if (argc != 5) {
    std::cerr << "Usage: " << argv[0] << " e2 S1 S2 p" << std::endl;
    exit(-1);
  }

  tgl::BigInteger e2(argv[1]);
  tgl::BigInteger s1(argv[2]);
  tgl::BigInteger s2(argv[3]);
  tgl::BigInteger p(argv[4]);

  tgl::ExponentiationAlgorithm ea;

  time_t start, end;
  ::time(&start);

  std::cout << "V2 is " << e2 << "^" << s1 << " * " << s1 << "^" << s2 << " mod " << p << std::endl;

  tgl::BigInteger a = ea.pow_mod(e2, s1, p);
  tgl::BigInteger b = ea.pow_mod(s1, s2, p);

  std::cout << a << " * " << b << " mod " << p << " = " << (a * b ) % p << std::endl;

  ::time(&end);
  std::cout << "Seconds to compute: " << ::difftime(end, start) << std::endl;

  return 0;
}// main
