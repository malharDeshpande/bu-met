#include "CeilingSqrtAlgorithm.h"
#include "BigInteger.h"

#include <iostream>

using namespace tgl;

CeilingSqrtAlgorithm::CeilingSqrtAlgorithm()
{
}// CeilingSqrtAlgorithm
    
BigInteger
CeilingSqrtAlgorithm::compute(const BigInteger &n)
{
  BigInteger g(1);
  BigInteger two(2);
  BigInteger remainder;

  BigInteger last;
  BigInteger result = ((n/g) + g)/two;

  while (last != result) {
    last = result;
    remainder = ((n/last) + last);

    remainder.modWithQuotient(two, result);
  }

  if (remainder == g) {
    result = result + g;
  }
  
  return result;
}// compute
