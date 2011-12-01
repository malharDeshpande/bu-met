#include "lib/MillerRabinTest.h"
#include "lib/BlumBlumShub.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  int p, q, n, k;
  if (argc == 5) {
    p = ::atoi(argv[1]);
    q = ::atoi(argv[2]);
    n = ::atoi(argv[3]);
    k = ::atoi(argv[4]);

    tgl::BlumBlumShub bbs;
    tgl::BigInteger r = bbs.generate(p, q, n);
    tgl::MillerRabinTest test;

    bool witness;
    while (!(witness = test.witness(r, k))) {
      r = bbs.generate(p, q, n);
    }

    std::cout << "RAND: " << r << std::endl;
    std::cout << "Miller-Rabin test is " << witness << std::endl;

  } else {
    std::cerr << "Usage: " << argv[0] << " P Q N K" << std::endl;
  }

  return 0;
}// main

