
#include "MillerRabinTest.h" // class implemented
#include "ExponentiationAlgorithm.h"

#include <iostream>
#include <cmath>

using namespace tgl;

MillerRabinTest::MillerRabinTest()
{
}// MillerRabintest

bool
MillerRabinTest::witness(const tgl::BigInteger& n)
{
  tgl::BigInteger neg_one(n - 1);
  tgl::BigInteger zero(0);
  tgl::BigInteger one(1);
  tgl::BigInteger two(2);
  tgl::BigInteger m(n - 1);
  tgl::BigInteger r(0);

  while ((m % two) == zero) {
    m = m / two;
    ++r;
  }

  std::cout << "TRACE - m r " << m << " " << r << std::endl;

  tgl::ExponentiationAlgorithm ea;
  size_t witnesses = 0;
  bool false_witness = false;
  ::srand(static_cast<size_t> (time(NULL)));
  for (size_t tests = 0; tests < 10 && !false_witness; ++tests) {
    std::cout << "Miller-Rabin test #" << tests << ", " << 100*(1. - (1. / ::pow(4, tests + 1))) << "%" << std::endl;

    tgl::BigInteger b = tgl::BigInteger(::rand()) % n;
    std::cout << "TRACE - b n " << b << " " << n << std::endl;
    tgl::BigInteger x = ea.pow_mod(b, m, n);
    
    if (x == one) {
      return false;
    }

    if (x == neg_one) {
      continue;
    }

    for (tgl::BigInteger loop(0); loop < r; ++loop) {
      x = ea.pow_mod(x, two, n);
      std::cout << "TRACE - x r loop " << x << " " << r << " " << loop << std::endl;

      if (x == one) {
        return false;
      }

      if (x == neg_one) {
        continue;
      }
    }
    
    if (x != one && x != neg_one) {
      return false;
    }
  }

  return true;
}// witness
