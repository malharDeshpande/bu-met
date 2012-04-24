#include "lib/EuclideanAlgorithm.h"
#include "lib/ExpandedEuclideanAlgorithm.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 6) {
    std::cerr << "Usage: " << argv[0] << " M d S1 r p" << std::endl;
    exit(-1);
  }

  tgl::BigInteger m(::atoi(argv[1]));
  tgl::BigInteger d(::atoi(argv[2]));
  tgl::BigInteger s(::atoi(argv[3]));
  tgl::BigInteger r(::atoi(argv[4]));
  tgl::BigInteger p(::atoi(argv[5]));

  tgl::BigInteger x, y;

  tgl::BigInteger zero(0);
  tgl::BigInteger one(1);
  tgl::BigInteger p_minus_1 = p - one;

  tgl::ExpandedEuclideanAlgorithm eea;
  eea.extendedGcd(r, p_minus_1, x, y);


  if (x < zero) {
    x = p_minus_1 + x;
  }

  std::cout << "S2 is " << ((m - (d * s)) * x)  % (p_minus_1) << std::endl;

  return 0;
}// main
