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
     compute(x, e, y, 0);
  }
   return y;
}// pow

BigInteger
ExponentiationAlgorithm::pow_mod(BigInteger x, BigInteger e, BigInteger m)
{
  std::cout << "TRACE - " << x << " " << e << " 1 " << m << std::endl;
  std::cout << "TRACE - x x.sign() " << x << " " << x.sign() << std::endl;

  BigInteger y(1);
  while (!e.isZero()) {
     compute(x, e, y, m);
     std::cout << "TRACE - " << x << " " << e << " " << y << " " << m  << std::endl;
  }
  return y;
}// pow_mod

void
ExponentiationAlgorithm::compute(BigInteger& x, BigInteger& e, BigInteger& y, BigInteger m)
{ 
  BigInteger one(1);
  BigInteger two(2);
    
  if ((e % two) == one) {
    std::cout << "TRACE - odd " << x << " " << e << " " << y << " " << m  << std::endl;
    std::cout << "TRACE - check zero " << x .sign() << " " << y.sign() << std::endl;
    std::cout << "TRACE - (x * y) " << (x * y) << std::endl;
    y = (x * y);
    std::cout << "TRACE - y " << y << std::endl;
    e = e - one;
    std::cout << "TRACE - odd " << x << " " << e << " " << y << " " << m  << std::endl;
  } else {
    std::cout << "TRACE - even " << x << " " << e << " " << y << " " << m  << std::endl;
    x = (x * x);
    e = (e / two);
    std::cout << "TRACE - even " << x << " " << e << " " << y << " " << m  << std::endl;
  }

  if (!m.isZero()) {
    std::cout << "TRACE - !m.isZero " << x << " " << e << " " << y << " " << m  << std::endl;
    y = y % m;
    x = x % m;
    std::cout << "TRACE - !m.isZero " << x << " " << e << " " << y << " " << m  << std::endl;  }
}// compute
