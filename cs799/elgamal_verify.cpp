#include "lib/ElGamalVerify.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  if (argc != 7) {
    std::cerr << "Usage: " << argv[0] << " e1 e2 S1 S2 p M" << std::endl;
    exit(-1);
  }

  tgl::BigInteger e1(argv[1]);
  tgl::BigInteger e2(argv[2]);
  tgl::BigInteger s1(argv[3]);
  tgl::BigInteger s2(argv[4]);
  tgl::BigInteger p(argv[5]);
  tgl::BigInteger m(argv[6]);

  tgl::ElGamalVerify verify;
  verify.run(e1, e2, s1, s2, p, m);

  return 0;
}// main
