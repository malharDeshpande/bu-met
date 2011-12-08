#include "PollardsRho.h" // class implemented
#include "ExponentiationAlgorithm.h"
#include "EuclideanAlgorithm.h"

#include <iostream>

using namespace tgl;

PollardsRho::PollardsRho()
{
}// PollardsRho

tgl::BigInteger
PollardsRho::factor(const tgl::BigInteger& n)
{
  tgl::BigInteger one(1);
  tgl::BigInteger two(2);
  tgl::BigInteger d(1);
  tgl::BigInteger x(2);
  tgl::BigInteger y(2);

  tgl::ExponentiationAlgorithm exa;
  tgl::EuclideanAlgorithm eua;

  while (d == one) {
    x = (exa.pow(x, two) + one) % n;
    y = (exa.pow(x, two) + one) % n;

    std::cout << "TRACE - x y " << x << " " << y << std::endl;

    d = eua.gcd(x - y, n);

    std::cout << "TRACE - d " << d << std::endl;
  }

  return d;
}// factor
