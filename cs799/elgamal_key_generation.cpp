#include "lib/ElGamalKeyGeneration.h"
#include "lib/Timer.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc == 5) {
    tgl::BigInteger p(argv[1]);
    tgl::BigInteger q(argv[2]);
    int n(::atoi(argv[3]));
    int k(::atoi(argv[4]));

    tgl::Timer t;

    tgl::ElGamalKeyGeneration gen;
    gen.makeKeys(p, q, n, k);

    std::cout << "Public Key (e1, e2, p)\n"
              << "e1 -> " << gen.getE1() << "\n"
              << "e2 -> " << gen.getE2() << "\n"
              << "p -> " << gen.getP() << std::endl;

    std::cout << "Private Key (d)\n"
              << "d -> " <<  gen.getD() << std::endl;

    std::cout << "Key generation took " << t.elapsed() << "secs."
              << std::endl;
  } else {
    std::cerr << "Usage: " << argv[0] << " P Q N K\n"
              << "  P - first prime number for BBS\n"
              << "  Q - second prime number for BBS\n"
              << "  N - number of binary digits to use for result\n"
              << "  K - number of Miller Rabin tests to check for primality"
              << std::endl;
  }
  
  return 0;
}// main
