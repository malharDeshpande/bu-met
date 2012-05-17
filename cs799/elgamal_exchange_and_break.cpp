#include "lib/BigInteger.h"
#include "lib/ElGamalExchange.h"
#include "lib/BabyStepGiantStepAlgorithm.h"
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

  tgl::Timer t;

  tgl::ElGamalExchange exchange;
  exchange.run(p, g, d, r, m);

  std::cout << "S1: " << exchange.getS1() << std::endl;
  std::cout << "S2: " << exchange.getS2() << std::endl;
  
  std::cout << "V1: " << exchange.getV1() << std::endl;
  std::cout << "V2: " << exchange.getV2() << std::endl;
  std::cout << "Congruent? " << exchange.congruent() << std::endl;
  
  std::cout << "Sign & verify time: " << t.elapsed() << std::endl;

  t.restart();

  tgl::BabyStepGiantStepAlgorithm bsgs;
  tgl::BigInteger D = bsgs.compute(p, exchange.getE2(), g);
  tgl::BigInteger R = bsgs.compute(p, exchange.getS1(), g);

  std::cout << "d: " << D << std::endl;
  std::cout << "r: " << R << std::endl;

  std::cout << "Broken? " << ((d == D) && (r == R)) << std::endl;

  std::cout << "Break time: " << t.elapsed() << std::endl;

  return 0;
}// main

