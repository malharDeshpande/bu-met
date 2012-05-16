#include "lib/ElGamalSign.h"
#include "lib/Timer.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  if (argc != 6) {
    std::cerr << "Usage: " << argv[0] << " e1 p d M r" << std::endl;
    exit(-1);
  }

  tgl::BigInteger e1(::atoi(argv[1]));
  tgl::BigInteger p(argv[2]);
  tgl::BigInteger d(argv[3]);
  tgl::BigInteger m(argv[4]);
  tgl::BigInteger r(argv[5]);

  tgl::Timer t;

  tgl::ElGamalSign sign(r);
  sign.run(e1, p, d, m);

  std::cout << "Random secret (r)\n"
            << "r -> " << sign.getR() << std::endl;

  std::cout << "Signatures (S1, S2)\n"
            << "S1 -> " << sign.getS1() << "\n"
            << "S2 -> " << sign.getS2() << std::endl;

  std::cout << "Signing took " << t.elapsed() << "secs."
            << std::endl;

  return 0;
}// main
