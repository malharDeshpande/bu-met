#include "PrimitiveRootSearchAlgorithm.h"
#include "ExponentiationAlgorithm.h"
#include "BigInteger.h"

#include <iostream>

using namespace tgl;

PrimitiveRootSearchAlgorithm::PrimitiveRootSearchAlgorithm()
{
}// PrimitiveRootSearchAlgorithm

bool
PrimitiveRootSearchAlgorithm::search(const BigInteger &p, BigInteger &b)
{
  std::cout << "TRACE - try " << b << std::endl;

  BigInteger pminus1(p - 1);
  BigInteger half_pminus1(pminus1 / 2);
  BigInteger zero(0);

  std::cout << "TRACE - for p " << p << std::endl;

  std::vector<BigInteger> qs;
  for (BigInteger q(2); q < half_pminus1; ++q) {
    if ((pminus1 % q) == zero) {
      std::cout << "TRACE - pminus1 factor is " << q << std::endl;
      qs.push_back(q);
    }
  }

  tgl::ExponentiationAlgorithm ea;
  BigInteger e;
  BigInteger r;
  BigInteger one(1);

  bool reject = false;
  std::vector<BigInteger>::iterator iter = qs.begin();
  while (iter != qs.end() && !reject) {
    e = pminus1 / (*iter);
    std::cout << "TRACE - trying " << b << "^" << e << std::endl;
    r = ea.pow_mod(b, e, p);
    std::cout << "TRACE - result is " << r << std::endl;
    if (r == one) {
      std::cout << "TRACE - rejecting!" << r << std::endl;
      reject == true;
    }
    iter++;
  }
  
  return !reject;
}// search

BigInteger
PrimitiveRootSearchAlgorithm::compute(const BigInteger &p)
{
  srand( time(NULL) );

  BigInteger b;

  bool found = false;
  while (!found) {
    b = (BigInteger(rand()) % p);
    found = search(p, b);
  }

  return b;
}// compute
