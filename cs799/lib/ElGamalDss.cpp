#include "ElGamalDss.h" // class implemented
#include "BigInteger.h"
#include "BlumBlumShub.h"
#include "ElGamalKeyGeneration.h"
#include "ElGamalExchange.h"
#include "BabyStepGiantStepAlgorithm.h"
#include "primes.h"
#include "Timer.h"

#include <iostream>
#include <ctime>

using namespace tgl;

ElGamalDss::ElGamalDss()
{
}// ElGamalDss

void
ElGamalDss::run(int n, int k, int digest)
{
  ::srand(static_cast<size_t> (::time(NULL)));

  int indx = ::rand() % tgl::PRIME_SIZE;
  std::cout << "indx " << indx << std::endl;
  int p = tgl::PRIMES[indx];


  indx = ::rand() % tgl::PRIME_SIZE;
  std::cout << "indx " << indx << std::endl;
  int q = tgl::PRIMES[indx];
    
  std::cout << "Using p, q: " << p << ", " << q << std::endl;

  tgl::Timer t;
    
  tgl::ElGamalKeyGeneration gen;
  gen.makeKeys(p, q, n, k);

  std::cout << "Public Key (e1, e2, p)\n"
            << "e1 -> " << gen.getE1() << "\n"
            << "e2 -> " << gen.getE2() << "\n"
            << "p -> " << gen.getP() << std::endl;

  std::cout << "Private Key (d)\n"
            << "d -> " <<  gen.getD() << std::endl;

  _key_time = t.elapsed();
  std::cout << "Key generation took " << _key_time << "secs."
            << std::endl;

  t.restart();

  tgl::BlumBlumShub bbs;
  indx = ::rand() % tgl::PRIME_SIZE;
  p = tgl::PRIMES[indx];

  indx = ::rand() % tgl::PRIME_SIZE;
  q = tgl::PRIMES[indx];
  std::cout << "Using p, q: " << p << ", " << q << std::endl;
  tgl::BigInteger r = bbs.generate(p, q, n - 1);
  std::cout << "Using BBS, r is: " << r << std::endl;

  t.restart();
    
  tgl::ElGamalExchange exchange;
  exchange.run(gen.getP(), gen.getE1(), gen.getD(), r, digest);

  std::cout << "S1: " << exchange.getS1() << std::endl;
  std::cout << "S2: " << exchange.getS2() << std::endl;
  
  std::cout << "V1: " << exchange.getV1() << std::endl;
  std::cout << "V2: " << exchange.getV2() << std::endl;
  std::cout << "Congruent? " << exchange.congruent() << std::endl;
  
  _exchange_time = t.elapsed();
  std::cout << "Sign & verify time: " << _exchange_time << std::endl;
  
  t.restart();

  tgl::BabyStepGiantStepAlgorithm bsgs;
  tgl::BigInteger D = bsgs.compute(gen.getP(), gen.getE2(), gen.getE1());
  tgl::BigInteger R = bsgs.compute(gen.getP(), exchange.getS1(), gen.getE1());
    
  std::cout << "d: " << D << std::endl;
  std::cout << "r: " << R << std::endl;
  
  std::cout << "Broken? " << ((gen.getD() == D) && (r == R)) << std::endl;
  
  _break_time = t.elapsed();
  std::cout << "Break time: " << _break_time << std::endl;

  return;
}// run
