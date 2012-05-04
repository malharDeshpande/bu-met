#include "lib/ElGamalSign.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  if (argc != 5) {
    std::cerr << "Usage: " << argv[0] << " e1 p d M" << std::endl;
    exit(-1);
  }


  tgl::BigInteger e1(argv[1]);
  tgl::BigInteger p(argv[2]);
  tgl::BigInteger d(argv[3]);
  tgl::BigInteger m(argv[4]);


  tgl::ElGamalSign sign;
  sign.run(e1, p, d, m);

  std::cout << "Random secret (r)\n"
            << "r -> " << sign.getR() << std::endl;

  std::cout << "Signatures (S1, S2)\n"
            << "S1 -> " << sign.getS1() << "\n"
            << "S2 -> " << sign.getS2() << std::endl;

  time_t start, end;
  ::time(&start);

  ::time(&end);

  std::cout << "Signing took " << ::difftime(end, start) << "secs."
            << std::endl;

  return 0;
}// main
