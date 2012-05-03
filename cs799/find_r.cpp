#include "lib/ExpandedEuclideanAlgorithm.h"
#include "lib/BigInteger.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 6) {
    std::cerr << "Usage: " << argv[0] << " M S1 S2 d p" << std::endl;
    exit(-1);
  }

  tgl::BigInteger m(::atoi(argv[1]));
  tgl::BigInteger s1(::atoi(argv[2]));
  tgl::BigInteger s2(::atoi(argv[3]));
  tgl::BigInteger d(::atoi(argv[4]));
  tgl::BigInteger p(::atoi(argv[5]));
  tgl::BigInteger p_minus_1(::atoi(argv[5]) - 1);

  tgl::BigInteger val(m - d * s1);

  std::cout << "(m - d * s1) = " << val << std::endl;
  std::cout << "s2 = " << s2 << std::endl;
  std::cout << "p_minus_1 = " << p_minus_1 << std::endl;
  std::cout << "(p_minus_1 + s2) = " << (p_minus_1 + s2) << std::endl;

  // s2 = val*r_inv mod p_minus_1

  // k*p_minus_1 + s2 = val * r_inv

  // r_inv = (k * p_minus_1 + s2) / val

  tgl::BigInteger temp;
  tgl::BigInteger zero(0);
  tgl::BigInteger r_inv;

  for (tgl::BigInteger loop(0); loop < p_minus_1; loop++) {
    temp = (loop * p_minus_1 + s2);
    if (temp % val == zero) {
      r_inv = temp / val;
    }
  }

  std::cout << "r_inv " << r_inv << std::endl;

  tgl::ExpandedEuclideanAlgorithm eea;

  tgl::BigInteger r, y;

  eea.extendedGcd(r_inv, p_minus_1, r, y);
  
  if (r < zero) {
    r = p_minus_1 + r;
  }

  std::cout << "r is " << r << std::endl; 

  return 0;
}// main
