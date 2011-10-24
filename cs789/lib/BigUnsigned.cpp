#include "BigUnsigned.h" // class implemented

#include <iostream>
#include <string>

using namespace tgl;

BigUnsigned::BigUnsigned(unsigned long n)
{
  while (n != 0) {
    _value.push_back(n % 10);
    n /= 10;
  }
}// BigUnsigned

BigUnsigned::BigUnsigned(const std::string &str)
{
  size_t stop = 0;
  if (str[0] == '-') {
    stop = 1;
  }

  for (size_t loop = str.size();
       loop > stop;
       --loop) {
    _value.push_back(str[loop - 1] - '0');
  }
}// BigUnsigned

void
BigUnsigned::write(std::ostream &out)
{
  for (size_t loop = _value.size();
       loop > 0;
       --loop) {
    out << _value[loop - 1]; 
  }
}// write
