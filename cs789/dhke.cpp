#include "lib/BigInteger.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " X I P" << std::endl;
    exit(-1);
  }

  tgl::BigInteger x(::atoi(argv[1]));
  tgl::BigInteger i(::atoi(argv[2]));
  tgl::BigInteger p(::atoi(argv[3]));

  std::cout << "DHKE: " << (x * i) % p << std::endl;

  return 0;
}// main
