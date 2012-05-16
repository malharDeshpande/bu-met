#include "lib/BigInteger.h"
#include "lib/ExponentiationAlgorithm.h"
#include "lib/ElGamalSign.h"
#include "lib/ElGamalVerify.h"
#include "lib/Timer.h"

int
main(int argc, char* argv[])
{
  if (argc != 6) {
    std::cerr << "Usage: " << argv[0] << " p g d r m" << std::endl;
    exit(-1);
  }
  
  tgl::BigInteger p(::atoi(argv[1]));
  tgl::BigInteger g(::atoi(argv[2]));
  tgl::BigInteger d(::atoi(argv[3]));
  tgl::BigInteger r(::atoi(argv[4]));
  tgl::BigInteger m(::atoi(argv[5]));

  tgl::BigInteger e1 = g;
  
  tgl::ExponentiationAlgorithm ea;

  tgl::BigInteger e2 = ea.pow_mod(g, d, p);
  
  std::cout << "e2: " << e2 << std::endl;

  tgl::Timer t;

  tgl::Timer tsign;
  tgl::ElGamalSign sign(r);
  sign.run(e1, p, d, m);

  std::cout << "S1: " << sign.getS1() << std::endl;
  std::cout << "S2: " << sign.getS2() << std::endl;
  
  std::cout << "Time to sign: " << tsign.elapsed() << std::endl;

  tgl::Timer tverify;
  tgl::ElGamalVerify verify;
  verify.run(e1, e2, sign.getS1(), sign.getS2(), p, m);

  std::cout << "V1: " << verify.getV1() << std::endl;
  std::cout << "V2: " << verify.getV2() << std::endl;
  std::cout << "Congruent? " << verify.congruent() << std::endl;
  
  std::cout << "Time to verify: " << tverify.elapsed() << std::endl;

  std::cout << "Total time: " << t.elapsed() << std::endl;

  return 0;
}// main

