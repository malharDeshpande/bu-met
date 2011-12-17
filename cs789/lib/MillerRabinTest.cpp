
#include "MillerRabinTest.h" // class implemented
#include "ExponentiationAlgorithm.h"

#include <iostream>
#include <cmath>
#include <ctime>

using namespace tgl;

MillerRabinTest::MillerRabinTest()
{
}// MillerRabintest

bool
MillerRabinTest::witness(const tgl::BigInteger& n, size_t k)
{
  tgl::BigInteger neg_one(n - 1);
  tgl::BigInteger zero(0);
  tgl::BigInteger one(1);
  tgl::BigInteger two(2);
  tgl::BigInteger m(n - 1);
  tgl::BigInteger r(0);

  if (n == two) {
    return true;
  }

  if ((n % two) == zero) {
    return false;
  }

  while ((m % two) == zero) {
    m = m / two;
    ++r;
  }

  std::cout << "TRACE - m r " << m << " " << r << std::endl;

  tgl::ExponentiationAlgorithm ea;
  size_t witnesses = 0;
  ::srand(static_cast<size_t> (time(NULL)));

  for (size_t tests = 0; tests < k; ++tests) {
    tgl::BigInteger b = tgl::BigInteger(::rand()) % n;
    std::cout << "TRACE - b m n " << b << " " << m << " " << n << std::endl;
    tgl::BigInteger x = ea.pow_mod(b, m, n);

    std::cout << "TRACE - x " << x << std::endl;

    if (x == one || x == neg_one) {
      continue;
    }

    for (tgl::BigInteger loop(0); loop < r; ++loop) {
      x = ea.pow_mod(x, two, n);
      std::cout << "TRACE - loop x " << loop << " " << x << std::endl;
      if (x == one) {
        return false;
      }
      if (x == neg_one) {
        break;
      }
    }
    if (x != neg_one) {
      return false;
    }
  }

  return true;
}// witness
