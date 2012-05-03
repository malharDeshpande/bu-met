#include "lib/MillerRabinTest.h"
#include "lib/BlumBlumShub.h"
#include "lib/PrimitiveRootSearchAlgorithm.h"
#include "lib/ExponentiationAlgorithm.h"

#include <iostream>
#include <ctime>

tgl::BigInteger
RandomPrime(const tgl::BigInteger& p,
            const tgl::BigInteger& q,
            int n,
            int k)
{
  time_t start, end;
  ::time(&start);

  tgl::BlumBlumShub bbs;
  tgl::BigInteger r = bbs.generate(p, q, n);
  tgl::MillerRabinTest test;
    
  bool witness;
  while (!(witness = test.witness(r, k))) {
    r = bbs.generate(p, q, n);
  }
  
  ::time(&end);
  
  std::cout << "RAND: " << r << std::endl;
  std::cout << "Miller-Rabin test is " << witness << std::endl;
  std::cout << "Seconds to compute: " << ::difftime(end, start) << std::endl;

  return r;
}// RandomPrime

int
main(int argc, char* argv[])
{
  if (argc == 5) {
    tgl::BigInteger p(argv[1]);
    tgl::BigInteger q(argv[2]);
    int n(::atoi(argv[3]));
    int k(::atoi(argv[4]));

    time_t start, end;
    ::time(&start);
    
    tgl::BigInteger r = RandomPrime(p, q, n, k);

    tgl::PrimitiveRootSearchAlgorithm pr;

    tgl::BigInteger e1 = pr.compute(r);

    std::cout << "Using PRS, e1 is: " << e1 << std::endl;

    tgl::BlumBlumShub bbs;

    tgl::BigInteger d = bbs.generate(p, q, n - 1);

    std::cout << "Using BBS, d is: " << d << std::endl;

    tgl::ExponentiationAlgorithm ea;

    tgl::BigInteger e2 = ea.pow_mod(e1, d, r);

    std::cout << "Using EA, e2 is: " << e2  << std::endl;

    std::cout << "Public Key (e1, e2, p)\n"
              << "e1 -> " << e1 << "\n"
              << "e2 -> " << e2 << "\n"
              << "p -> " << p << std::endl;


    std::cout << "Private Key (d)\n"
              << "d -> " << d << std::endl;

    ::time(&end);

    std::cout << "Key generation took " << ::difftime(end, start) << "secs."
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
