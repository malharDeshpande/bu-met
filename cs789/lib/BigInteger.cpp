#include "BigInteger.h" // class implemented

using namespace tgl;

#include <iostream>

BigInteger::BigInteger() :
  _sign(Zero)
{
}// BigInteger

BigInteger::BigInteger(int n) :
  _sign(Zero),
  _mag(static_cast<unsigned long> (abs(n)))
{
  if (n < 0) {
    _sign = Neg;
  } else if (n > 0) {
    _sign = Pos;
  }
}// BigInteger

BigInteger::BigInteger(const std::string &str) :
  _sign(Zero),
  _mag(str)
{
  size_t len = str.size();
  if (str[0] == '-') {
    _sign = Neg;
  } else if (str.size() > 1) {
    _sign = Pos;
  }
}// BigInteger

void
BigInteger::write(std::ostream &out)
{
  if (_sign == Neg) {
    out << "-";
  }

  _mag.write(out);
}// write
