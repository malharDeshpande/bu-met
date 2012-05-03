#include "lib/ExponentiationAlgorithm.h"
#include "lib/BlumBlumShub.h"
#include "lib/ExpandedEuclideanAlgorithm.h"

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

  tgl::BlumBlumShub bbs;
  
  tgl::BigInteger r = bbs.generate(26681, 68483, 32);

  tgl::ExponentiationAlgorithm ea;

  tgl::BigInteger s1 = ea.pow_mod(e1, r, p);

  tgl::BigInteger x, y;

  tgl::BigInteger zero(0);
  tgl::BigInteger one(1);
  tgl::BigInteger p_minus_1 = p - one;

  tgl::ExpandedEuclideanAlgorithm eea;
  eea.extendedGcd(r, p_minus_1, x, y);

  if (x < zero) {
    x = p_minus_1 + x;
  }

  
  tgl::BigInteger s2 = ((m - (d * s1)) * x)  % (p_minus_1);

  std::cout << "Random secret (r)\n"
            << "r -> " << r << std::endl;

  std::cout << "Signatures (S1, S2)\n"
            << "S1 -> " << s1 << "\n"
            << "S2 -> " << s2 << std::endl;

  time_t start, end;
  ::time(&start);

  ::time(&end);

  std::cout << "Signing took " << ::difftime(end, start) << "secs."
            << std::endl;

  return 0;
}// main
