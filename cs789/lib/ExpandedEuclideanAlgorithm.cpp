#include "ExpandedEuclideanAlgorithm.h" // class implemented

#include <iostream>

ExpandedEuclideanAlgorithm::ExpandedEuclideanAlgorithm()
{
}// ExpandedEuclideanAlgorithm

void
ExpandedEuclideanAlgorithm::divide(int m, int n, int& q, int& r)
{
  q = m / n;
  r = m % n;
  std::cout << "TRACE - " << m << " mod " << n << " = " << q << " & " << r << std::endl;
}// divide

void
ExpandedEuclideanAlgorithm::extendedGcd(int m, int n, int& x, int& y)
{
  if (n == 0) {
    x = 1;
    y = 0;
  } else {
    int q;
    int r;
    divide(m, n, q, r);
    int s;
    int t;
    extendedGcd(n, r, s, t);
    x = t;
    y = s - q * t;
    std::cout << "TRACE - " << m << " * " << x << " + " << n << " * " << y << std::endl;
  }

  return;
}// solve
