#include "ElGamalKeyGeneration.h" // class implemented
#include "MillerRabinTest.h"
#include "BlumBlumShub.h"
#include "PrimitiveRootSearchAlgorithm.h"
#include "ExponentiationAlgorithm.h"

using namespace tgl;

ElGamalKeyGeneration::ElGamalKeyGeneration()
{
}// ElGamalKeyGeneration

BigInteger
ElGamalKeyGeneration::randomPrime(const BigInteger& p,
                                  const BigInteger& q,
                                  int n,
                                  int k)
{
  BlumBlumShub bbs;
  BigInteger r = bbs.generate(p, q, n);
  MillerRabinTest test;
    
  bool witness;
  while (!(witness = test.witness(r, k))) {
    r = bbs.generate(p, q, n);
  }
  
  return r;
}// randomPrime

void
ElGamalKeyGeneration::makeKeys(const BigInteger& p,
                               const BigInteger& q,
                               int n,
                               int k)
{
  _p = ElGamalKeyGeneration::randomPrime(p, q, n, k);

  PrimitiveRootSearchAlgorithm pr;
  _e1 = pr.compute(_p);

  BlumBlumShub bbs;
  _d = bbs.generate(p, q, n - 1);

  ExponentiationAlgorithm ea;
  _e2 = ea.pow_mod(_e1, _d, _p);
                   
  return;
}// makeKeys

