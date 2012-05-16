#include "ElGamalSign.h" // class implemented
#include "ExponentiationAlgorithm.h"
#include "BlumBlumShub.h"
#include "ExpandedEuclideanAlgorithm.h"

#include <iostream>
#include <ctime>

using namespace tgl;

ElGamalSign::ElGamalSign(const tgl::BigInteger& r) :
  _r(r)
{
}// ElGamalSign

void
ElGamalSign::run(const BigInteger& e1,
                 const BigInteger& p,
                 const BigInteger& d,
                 const BigInteger& m)
{


  if (_r == tgl::BigInteger(0)) {
    tgl::BlumBlumShub bbs;
  
    _r = bbs.generate(26681, 68483, 32);
  }

  tgl::ExponentiationAlgorithm ea;

  _s1 = ea.pow_mod(e1, _r, p);

  tgl::BigInteger x, y;

  tgl::BigInteger zero(0);
  tgl::BigInteger one(1);
  tgl::BigInteger p_minus_1(p - one);

  tgl::ExpandedEuclideanAlgorithm eea;
  eea.extendedGcd(_r, p_minus_1, x, y);

  if (x < zero) {
    x = p_minus_1 + x;
  }
  
  _s2 = ((m - (d * _s1)) * x) % p_minus_1;

  return;
}// run

