#include "lib/PollardsRho.h" // class implmented

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc == 2) {
    tgl::BigInteger n(::atoi(argv[1]));

    tgl::PollardsRho rho;
    tgl::BigInteger d = rho.factor(n);

    if (n == d) {
      std::cout << "Failed, n == d!" << std::endl;
    } else {
      std::cout << "Found d for n: " << d << std::endl;
    }
  } else {
    std::cerr << "Usage: " << argv[0] << " N" << std::endl;
  }

  return 0;
}// main
