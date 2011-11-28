#include "ExponentiationAlgorithm.h" // class implemented

#include <iostream>

using namespace tgl;

ExponentiationAlgorithm::ExponentiationAlgorithm()
{
}// ExponentiationAlgorithm
    
BigInteger
ExponentiationAlgorithm::pow(BigInteger x, BigInteger e)
{
  BigInteger y(1);

  while (!e.isZero()) {
    std::cout << "TRACE - x e y " << x << " " << e << " " << y << std::endl;
    compute(x, e, y, 0);
  }
  std::cout << "TRACE - x e y " << x << " " << e << " " << y << std::endl;
  return y;
}// pow

BigInteger
ExponentiationAlgorithm::pow_mod(BigInteger x, BigInteger e, BigInteger m)
{
  BigInteger y(1);
  while (!e.isZero()) {
    std::cout << "TRACE - x e y " << x << " " << e << " " << y << std::endl;
    compute(x, e, y, m);
  }
  std::cout << "TRACE - x e y " << x << " " << e << " " << y << std::endl;
  return y;
}// pow_mod

void
ExponentiationAlgorithm::compute(BigInteger& x, BigInteger& e, BigInteger& y, BigInteger m)
{ 
  BigInteger one(1);
  BigInteger two(2);

  if ((e % two) == one) {
    y = (x * y);
    e = e - one;
  } else {
    x = (x * x);
    e = (e / two);
  }

  if (!m.isZero()) {
    y = y % m;
    x = x % m;
  }
}// compute
