#include "BabyStepGiantStepAlgorithm.h" // class implemented
#include "CeilingSqrtAlgorithm.h"
#include "ExponentiationAlgorithm.h"
#include "ExpandedEuclideanAlgorithm.h"
#include <cmath>
#include <map>
#include <iostream>

using namespace tgl;

BabyStepGiantStepAlgorithm::BabyStepGiantStepAlgorithm()
{
}// BabyStepGiantStepAlgorithm

BigInteger
BabyStepGiantStepAlgorithm::compute(const BigInteger &p,
				    const BigInteger &a,
				    const BigInteger &b)
{
  tgl::BigInteger n(p - 1);

  tgl::CeilingSqrtAlgorithm csa;

  BigInteger m = csa.compute(n);
  
  ExponentiationAlgorithm ea;
  BigInteger index;

  std::map< BigInteger, BigInteger > J;
  for (BigInteger loop; loop < m; ++loop) {
    index = ea.pow_mod(b, loop, p);
    J[index] = loop;
    std::cout << "TRACE - b^loop -> loop " << index << " -> " << J[index] << std::endl;
  }

  tgl::ExpandedEuclideanAlgorithm eea;

  tgl::BigInteger x;
  tgl::BigInteger y;

  eea.extendedGcd(b, p, x, y);
  
  if (x.sign() < tgl::BigInteger::Zero) {
    x = p + x;
  }

  tgl::BigInteger c = ea.pow_mod(x, m, p);

  std::cout << "TRACE - x^m mod p " << x << "^" << m << " mod " << p << " = " << c << std::endl;

  std::map< BigInteger, BigInteger>::key_compare comp;
  BigInteger seven(7);

  std::map<BigInteger, BigInteger>::iterator it;
  for (BigInteger loop; loop < m; ++loop) {
    x = (a * ea.pow_mod(c, loop, p)) % p;
    for (it = J.begin();
	 it != J.end();
	 it++) {
      if ((*it).first == x) {
	std::cout << "TRACE - i*m + j --> " << loop << "*" << m << "+" << (*it).second << std::endl; 
	return (loop * m + (*it).second);
      }
    }  
  }

  throw "BabyStepGiantStepAlgorithm - failed to find x.";
}// compute
