#include "ElGamalVerify.h" // class implemented
#include "ExponentiationAlgorithm.h"

#include <iostream>
#include <ctime>

using namespace tgl;

ElGamalVerify::ElGamalVerify()
{
}// ElGamalVerify

void
ElGamalVerify::run(const tgl::BigInteger& e1,
                   const tgl::BigInteger& e2,
                   const tgl::BigInteger& s1,
                   const tgl::BigInteger& s2,
                   const tgl::BigInteger& p,
                   const tgl::BigInteger& m)
{
  tgl::ExponentiationAlgorithm ea;

  _v1 = ea.pow_mod(e1, m, p);

  tgl::BigInteger a = ea.pow_mod(e2, s1, p);
  tgl::BigInteger b = ea.pow_mod(s1, s2, p);

  _v2 = (a * b ) % p;

  return;
}// run

bool
ElGamalVerify::congruent() const
{
  return (_v1 == _v2);
}// congruent
