#include "ExponentiationAlgorithm.h" // class implemented

#include <iostream>

using namespace tgl;

ExponentiationAlgorithm::ExponentiationAlgorithm()
{
}// ExponentiationAlgorithm
    
int
ExponentiationAlgorithm::pow(int x, int e)
{
  int y = 1;
  std::cout << "TRACE - " << x << " " << e << " " << y << " " << std::endl;
  while (e != 0) {
    compute(x, e, y, 0);
    std::cout << "TRACE - " << x << " " << e << " " << y << " " << std::endl;
  }
  return y;
}// pow

int
ExponentiationAlgorithm::pow_mod(int x, int e, int m)
{
  int y = 1;
  std::cout << "TRACE - " << x << " " << e << " " << y << " " << std::endl;
  while (e != 0) {
    compute(x, e, y, m);
    std::cout << "TRACE - " << x << " " << e << " " << y << " " << std::endl;
  }
  return y;
}// pow_mod

void
ExponentiationAlgorithm::compute(int& x, int& e, int& y, int m)
{
  if (e % 2 == 1) {
    y = (x * y);
    e = e - 1;
  } else {
    x = (x * x);
    e = e / 2;
  }

  if (m != 0) {
    y = y % m;
    x = x % m;
  }
}// compute
