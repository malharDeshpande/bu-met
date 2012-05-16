#include "BlumBlumShub.h" // class implemented
#include "ExponentiationAlgorithm.h"
#include "BigInteger.h"

#include <ctime>

using namespace tgl;

BlumBlumShub::BlumBlumShub()
{
}// BlumBlumShub

tgl::BigInteger
BlumBlumShub::generate(const tgl::BigInteger& p,
                       const tgl::BigInteger& q,
                       size_t n)
{
  tgl::BigInteger N = p * q;
  
  ::srand(static_cast<size_t> (::time(NULL)));

  tgl::BigInteger s = tgl::BigInteger(::rand()) % N;

  tgl::BigInteger zero(0);
  tgl::BigInteger two(2);
  std::vector<bool> b;
  tgl::ExponentiationAlgorithm ea;

  //  std::cout << "TRACE - ";
  for (size_t loop = 0; loop < n; ++loop) {
    if (zero == (s % two)) {
      b.push_back(false);
      //      std::cout << "0";
    } else {
      b.push_back(true);
      //      std::cout << "1";
    }

    s = ea.pow_mod(s, two, N);
  }

  //  std::cout << std::endl;

  tgl::BigInteger result;

  for (size_t loop = 0;
       loop < b.size();
       ++loop) {
    if (b[loop]) {
      result = result + ea.pow(two, loop);
    }
  }
  
  //  std::cout << "TRACE - " << result << std::endl;

  return result;
}// generate
