#include "ElGamalExchange.h" // class implemented
#include "ExponentiationAlgorithm.h"
#include "ElGamalSign.h"
#include "ElGamalVerify.h"

using namespace tgl;

ElGamalExchange::ElGamalExchange()
{
}// ElGamalExchange

void
ElGamalExchange::run(const BigInteger& p,
                     const BigInteger& g,
                     const BigInteger& d,
                     const BigInteger& r,
                     const BigInteger& m)
{
  BigInteger e1 = g;
  
  ExponentiationAlgorithm ea;

  _e2 = ea.pow_mod(g, d, p);
  
  ElGamalSign sign(r);
  sign.run(e1, p, d, m);

  ElGamalVerify verify;
  verify.run(e1, _e2, sign.getS1(), sign.getS2(), p, m);

  _s1 = sign.getS1();
  _s2 = sign.getS2();
  _v1 = verify.getV1();
  _v2 = verify.getV2();
}// run
