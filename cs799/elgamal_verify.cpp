#include "lib/ExponentiationAlgorithm.h"

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

  tgl::ExponentiationAlgorithm ea;

  time_t start, end;
  ::time(&start);

  tgl::BigInteger v1 = ea.pow_mod(e1, m, p);

  tgl::BigInteger a = ea.pow_mod(e2, s1, p);
  tgl::BigInteger b = ea.pow_mod(s1, s2, p);

  tgl::BigInteger v2 = (a * b ) % p;

  std::cout << "Verify (V1, V2)\n"
            << "V1 -> " << v1 << "\n"
            << "V2 -> " << v2 << std::endl;
  std::cout << "[" << ((v1 == v2) ? "TRUE" : "FALSE") << "]" << std::endl;
    
  ::time(&end);

  std::cout << "Verifing took " << ::difftime(end, start) << "secs."
            << std::endl;

  return 0;
}// main
