#include "lib/BigInteger.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " M N" << std::endl;
    exit(-1);
  }

  tgl::BigInteger M(::atoi(argv[1]));
  tgl::BigInteger N(::atoi(argv[2]));

  std::cout << "M   - " << M << std::endl;
  std::cout << "N   - " << N << std::endl;
  
  tgl::BigInteger sum;
  sum.add(M, N);

  std::cout << "Sum - " << sum << std::endl;

  tgl::BigInteger dot;
  dot.multiply(M, N);

  std::cout << "Dot - " << dot << std::endl;

  return 0;
}// main
