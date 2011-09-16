#include "EuclideanAlgorithm.h" // class implemented

#include <iostream>

EuclideanAlgorithm::EuclideanAlgorithm()
{
}// EuclideanAlgorithm

int
EuclideanAlgorithm::remainder(int m, int n)
{
  std::cout << "TRACE - " << m << " mod " << n << " = " << m % n << std::endl;
  return m % n;
}// remainder

int
EuclideanAlgorithm::gcd(int m, int n)
{
  int r = this->remainder(m, n);
  while (r > 1) {
    m = n;
    n = r;
    r = this->remainder(m, n);
  }

  if (0 == r) {
    return n;
  } else {
    return 1;
  }
}// gcd
