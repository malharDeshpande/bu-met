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
  eea.extendedGcd(r, p, x, y);


  if (x < zero) {
    x = p + x;
  }

  std::cout << "(d * s) = " << (d * s) << std::endl;
  std::cout << "(m - d * s) = " << (m - d * s) << std::endl;
  std::cout << "(m - d * s) * r(inv) = " << ((m - d * s) * x) << std::endl;
  std::cout << "(m - d * s) * r(inv) mod (p - 1) = " << (((m - d * s) * x))%(p_minus_1) << std::endl;

  std::cout << "(" << m << " - " << d << " * " << s << ") * " << x << " mod " << (p_minus_1) << std::endl;
  std::cout << "S2 is " << ((m - (d * s)) * x)  % (p_minus_1) << std::endl;
  

  tgl::BigInteger num(-571774244);

  std::cout << num << " -- " <<  (num % p_minus_1) << std::endl;
  return 0;
}// main
