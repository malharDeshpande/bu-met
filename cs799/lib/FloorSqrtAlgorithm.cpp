#include "FloorSqrtAlgorithm.h"
#include "BigInteger.h"

#include <iostream>

using namespace tgl;

FloorSqrtAlgorithm::FloorSqrtAlgorithm()
{
}// FloorSqrtAlgorithm
    
BigInteger
FloorSqrtAlgorithm::compute(const BigInteger &n)
{
  BigInteger g(1);
  BigInteger two(2);

  BigInteger last;
  BigInteger result = ((n/g) + g)/two;
  while (last != result) {
    last = result;
    result = ((n/last) + last)/two;
  }

  return result;
}// compute
