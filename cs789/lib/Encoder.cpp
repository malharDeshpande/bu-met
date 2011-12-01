#include "Encoder.h" // class enabled
#include "ExponentiationAlgorithm.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace tgl;

Encoder::Encoder()
{
}// Encoder

tgl::BigInteger
Encoder::encode(const std::string& s) const
{
  std::vector<bool> b;

  for (size_t loop = 0; loop < s.size(); ++loop) {
    int quotient = static_cast<int> (s[loop]);
    std::cout << "TRACE - starting with " << s[loop] << " " << quotient << std::endl;
    int remainder = quotient % 2;
    quotient = quotient / 2;
    std::vector<bool> packed;
    while (quotient != 0) {
      std::cout << "TRACE - " << s[loop] << " " << quotient << " " << remainder << std::endl;
      packed.push_back((remainder == 1) ? true : false);
      remainder = quotient % 2;
      quotient = quotient / 2;
    }

    if (remainder == 1) {
      std::cout << "TRACE - " << s[loop] << " " << quotient << " " << remainder << std::endl;
      packed.push_back(true);
    } else {
      packed.push_back(false);
    }

    for (size_t index = 0; index < 8 - packed.size(); ++index) {
      std::cout << "TRACE - appending 0" << std::endl;
      b.push_back(false);
    }

    for (size_t index = 0; index < packed.size(); ++index) {
      b.push_back(packed[index]);
     }
  }

  std::cout << "TRACE - " << s.size() << " " << b.size() << std::endl;

  for (size_t loop = 0; loop < b.size(); ++loop) {
    std::cout <<  b[loop];
    if (((loop + 1) < b.size()) && ((loop + 1) % 8 == 0)) {
      std::cout << "|";
    }
  }

  std::cout << std::endl;

  std::reverse(b.begin(), b.end());

  tgl::BigInteger result(0);
  tgl::ExponentiationAlgorithm ea;
  for (size_t loop = 0; loop < b.size(); ++loop) {
    if (b[loop]) {
      std::cout << "TRACE - accumulating " << loop << " " << ea.pow(2, loop) << std::endl;
      result = result + ea.pow(2, loop);
    }
  }

  return result;
}// encode

std::string
Encoder::decode(const tgl::BigInteger& i) const
{
  std::vector<bool> b;

  tgl::BigInteger two(2);
  tgl::BigInteger one(1);
  tgl::BigInteger zero(0);

  std::cout << "TRACE - i " << i << std::endl;

  tgl::BigInteger r = i % two;
  tgl::BigInteger q = i / two;

  while (q != zero) {
    std::cout << "TRACE - q r " << q  << " " << r << std::endl;
    b.push_back((r == one) ? true : false);
    r = q % two;
    q = q / two;   
  }
  
  if (r == one) {
    b.push_back(true);
  } else {
    b.push_back(false);
  }

  size_t size = b.size();
  std::cout << "TRACE - size " << size << std::endl;
  size_t mod_size = size % 8;
  std::cout << "TRACE - mod_size " << mod_size << std::endl;

  for (size_t loop = 0; loop < (8 - mod_size); ++loop) {
    b.push_back(false);
  }

  for (size_t loop = 0; loop < b.size(); ++loop) {
    std::cout << b[loop];
    if (((loop + 1) < b.size()) && ((loop + 1) % 8 == 0)) {
      std::cout << "|";
    }
  }
  
  std::cout << std::endl;

  std::string result;

  std::cout << "TRACE - b.size() " << b.size() << std::endl;

  for (size_t loop = 0; loop < b.size(); loop = loop + 8) {
    int value = 0;
    std::cout << "TRACE - loop " << loop << std::endl;
    for (size_t index = 0; index < 8; ++index) {
      if (b[loop + index]) {
        std::cout << "TRACE - accumulating " << index << " " << ::pow(2, index) << std::endl;
        value = value + ::pow(2, index);
      }
    }

    char c = value;

    std::cout << "TRACE - value " << value << " " << static_cast<char> (value) << " " << c << std::endl;

    result.push_back(c);
  }

  return result;
}// decode
