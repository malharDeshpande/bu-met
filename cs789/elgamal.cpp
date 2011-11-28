#include <string>

#include "lib/BigInteger.h"
#include "lib/ExponentiationAlgorithm.h"
#include "lib/ExpandedEuclideanAlgorithm.h"

int
main(int argc, char* argv[])
{
  
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " X Y P" << std::endl;
    exit(-1);
  }

  tgl::BigInteger x(::atoi(argv[1]));
  tgl::BigInteger y(::atoi(argv[2]));
  tgl::BigInteger p(::atoi(argv[3]));
    
  std::cout << "X*YmodP: " << ((x * y) % p) << std::endl;

  return 0;
}// main
