#include "EuclideanAlgorithm.h" // class implemented

#include <iostream>

using namespace tgl;

EuclideanAlgorithm::EuclideanAlgorithm()
{
}// EuclideanAlgorithm

BigInteger
EuclideanAlgorithm::remainder(BigInteger m, BigInteger n)
{
  std::cout << "TRACE - " << m << " mod " << n << " = " << m % n << std::endl;
  return m % n;
}// remainder

BigInteger
EuclideanAlgorithm::gcd(BigInteger m, BigInteger n)
{
  BigInteger r = this->remainder(m, n);
  while (r > BigInteger(1)) {
    m = n;
    n = r;
    r = this->remainder(m, n);
  }

  if (BigInteger(0) == r) {
    return n;
  } else {
    return BigInteger(1);
  }
}// gcd
