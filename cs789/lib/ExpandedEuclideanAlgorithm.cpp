#include "ExpandedEuclideanAlgorithm.h" // class implemented

#include <iostream>

using namespace tgl;

ExpandedEuclideanAlgorithm::ExpandedEuclideanAlgorithm()
{
}// ExpandedEuclideanAlgorithm

void
ExpandedEuclideanAlgorithm::divide(BigInteger m, BigInteger n, BigInteger& q, BigInteger& r)
{
  q = m / n;
  r = m % n;
  std::cout << "TRACE - " << m << " mod " << n << " = " << q << " & " << r << std::endl;
}// divide

void
ExpandedEuclideanAlgorithm::extendedGcd(BigInteger m, BigInteger n, BigInteger& x, BigInteger& y)
{
  BigInteger zero(0);
  BigInteger one(1);

  if (n == zero) {
    x = one;
    y = zero;
  } else {
    BigInteger q;
    BigInteger r;
    divide(m, n, q, r);
    BigInteger s;
    BigInteger t;
    extendedGcd(n, r, s, t);
    x = t;
    y = s - q * t;
    std::cout << "TRACE - " << m << " * " << x << " + " << n << " * " << y << std::endl;
  }

  return;
}// solve
