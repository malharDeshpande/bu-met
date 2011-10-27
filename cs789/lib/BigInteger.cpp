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

bool
BigInteger::operator<(const BigInteger &x) const
{
  if (this->_sign < x._sign) {
    return true;
  } else if (this->_sign > x._sign) {
    return false;
  } else switch (this->_sign) {
  case Zero:
    return false;
  case Pos:
    
  case Neg:
    
  default:
    throw "BigInteger internal error";
  }
}// operator<

bool
BigInteger::operator>(const BigInteger &x) const
{
  if (this->_sign < x._sign) {
    return false;
  } else if (this->_sign > x._sign) {
    return true;
  } else switch (this->_sign) {
  case Zero:
    return false;
  case Pos:
    
  case Neg:
    
  default:
    throw "BigInteger internal error";
  }
}// operator>

bool
BigInteger::operator==(const BigInteger &x) const
{
  return (_sign == x._sign && _mag == x._mag);
}// operator==
