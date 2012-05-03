#include "lib/EuclideanAlgorithm.h"
#include "lib/ExpandedEuclideanAlgorithm.h"

#include <iostream>
#include <ctime>

int
main(int argc, char* argv[])
{
  if (argc != 6) {
    std::cerr << "Usage: " << argv[0] << " M d S1 r p" << std::endl;
    exit(-1);
  }

  tgl::BigInteger m(argv[1]);
  tgl::BigInteger d(argv[2]);
  tgl::BigInteger s(argv[3]);
  tgl::BigInteger r(argv[4]);
  tgl::BigInteger p(argv[5]);

  tgl::BigInteger x, y;

  tgl::BigInteger zero(0);
  tgl::BigInteger one(1);
  tgl::BigInteger p_minus_1 = p - one;

  time_t start, end;
  ::time(&start);

  tgl::ExpandedEuclideanAlgorithm eea;
  eea.extendedGcd(r, p_minus_1, x, y);

  if (x < zero) {
    x = p_minus_1 + x;
  }

  std::cout << "(" << m << " - " << d << " * " << s << ") * " << x << " mod " << p_minus_1 << std::endl;
  std::cout << "S2 is " << ((m - (d * s)) * x)  % (p_minus_1) << std::endl;

  ::time(&end);

  std::cout << "Seconds to compute: " << ::difftime(end, start) << std::endl;

  return 0;
}// main
