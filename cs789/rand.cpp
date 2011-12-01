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

    std::cout << "RAND: " << r << std::endl;
  } else {
    std::cerr << "Usage: " << argv[0] << " P Q N" << std::endl;
  }
  return 0;
}// main
