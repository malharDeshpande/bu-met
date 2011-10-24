#include "lib/BigInteger.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " M N" << std::endl;
    exit(-1);
  }

  tgl::BigInteger M(argv[1]);
  tgl::BigInteger N(argv[2]);

  std::cout << "M is: "; M.write(std::cout); std::cout << std::endl;
  std::cout << "N is: "; N.write(std::cout); std::cout << std::endl;

  return 0;
}// main
