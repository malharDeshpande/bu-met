#include "lib/MillerRabinTest.h"
#include "lib/BlumBlumShub.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  int p, q, n;
  if (argc == 4) {
    p = ::atoi(argv[1]);
    q = ::atoi(argv[2]);
    n = ::atoi(argv[3]);

    tgl::BlumBlumShub bbs;
    tgl::BigInteger r = bbs.generate(p, q, n);
    tgl::MillerRabinTest test;
 
    std::cout << "TRACE - check with 9511 " << test.witness(9511) << std::endl;
    std::cout << "TRACE - check with 5521 " << test.witness(5521) << std::endl;

    while (!test.witness(r)) {
      r = bbs.generate(p, q, n);
    }

    std::cout << "RAND: " << r << std::endl;
    std::cout << "Miller-Rabin test is " << test.witness(r) << std::endl;

  } else {
    std::cerr << "Usage: " << argv[0] << " P Q N" << std::endl;
  }

  return 0;
}// main

