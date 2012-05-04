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

  time_t start, end;
  ::time(&start);

  _v1 = ea.pow_mod(e1, m, p);

  tgl::BigInteger a = ea.pow_mod(e2, s1, p);
  tgl::BigInteger b = ea.pow_mod(s1, s2, p);

  _v2 = (a * b ) % p;

  std::cout << "Verify (V1, V2)\n"
            << "V1 -> " << _v1 << "\n"
            << "V2 -> " << _v2 << std::endl;
  std::cout << "[" << ((_v1 == _v2) ? "TRUE" : "FALSE") << "]" << std::endl;
    
  ::time(&end);

  std::cout << "Verifing took " << ::difftime(end, start) << "secs."
            << std::endl;

  return;
}// run

bool
ElGamalVerify::congruent() const
{
  return (_v1 == _v2);
}// congruent
