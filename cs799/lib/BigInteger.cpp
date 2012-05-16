#include "BigInteger.h" // class implemented

using namespace tgl;

#include <iostream>

BigInteger::BigInteger() :
  _sign(Zero)
{
}// BigInteger

BigInteger::BigInteger(const BigInteger &x) :
  _sign(x._sign),
  _mag(x._mag)
{
}// BigInteger

BigInteger::BigInteger(int n)
{
  if (n < 0) {
    _sign = Neg;
  } else if (n > 0) {
    _sign = Pos;
  } else {
    _sign = Zero;
  }

  if (_sign != Zero) {
    _mag = BigUnsigned(static_cast<unsigned long>(n));
  }

  //  std::cout << "TRACE - BigInteger n " << n << " " << _sign << std::endl;
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

#define ALIASED(cond, op) \
  if (cond) { \
    BigInteger tmp; \
    tmp.op; \
    *this = tmp; \
    return; \
  }

void
BigInteger::add(const BigInteger &a, const BigInteger &b)
{
  ALIASED(this == &a || this == &b, add(a, b));
  if (a.sign() == Zero) {
    *this = b;
  } else if (b.sign() == Zero) {
    *this = a;
  } else if (a.sign() == b.sign()) {
    _sign = a.sign();
    _mag.add(a._mag, b._mag);
  } else {
    switch (a._mag.compareTo(b._mag)) {
    case equal:
      _mag = 0;
      _sign = Zero;
      break;
    case greater:
      _sign = a.sign();
      _mag.subtract(a._mag, b._mag);
      break;
    case less:
      _sign = b.sign();
      _mag.subtract(b._mag, a._mag);
      break;
    }
  }    
}// add

void
BigInteger::subtract(const BigInteger &a, const BigInteger &b)
{
  ALIASED(this == &a || this == &b, add(a, b));
  if (a.sign() == Zero) {
    _mag = b._mag;
    _sign = (b.sign() == Pos) ? Neg : (b.sign() == Zero) ? Zero : Pos;
  } else if (b.sign() == Zero) {
    *this = a;
  } else if (a.sign() != b.sign()) {
    _sign = a.sign();
    _mag.add(a._mag, b._mag);
  } else {
    switch (a._mag.compareTo(b._mag)) {
    case equal:
      _mag = 0;
      _sign = Zero;
      break;
    case greater:
      _sign = a.sign();
      _mag.subtract(a._mag, b._mag);
      break;
    case less:
      _sign = (b.sign() == Pos) ? Neg : (b.sign() == Zero) ? Zero : Pos;
      _mag.subtract(b._mag, a._mag);
      break;
    }
  }
}// subtract

void
BigInteger::multiply(const BigInteger &a, const BigInteger &b)
{
  ALIASED(this == &a || this == &b, multiply(a, b));
  if (a.sign() == Zero || b.sign() == Zero) {
    //    std::cout << "TRACE - a or b zero? " << a.sign() << " " << b.sign() << std::endl;

    _sign = Zero;
    _mag = 0;
    return;
  }

  _sign = (a.sign() == b.sign()) ? Pos : Neg;
  _mag.multiply(a._mag, b._mag);
}// multiply

void
BigInteger::modWithQuotient(const BigInteger &b, BigInteger &q)
{
  if (this == &q) {
    throw "BigInteger::modWithQuotient: Connet write qoutient and remainder to same variable.";
  }

  if (this == &b || &q == &b) {
    BigInteger tmp(b);
    modWithQuotient(tmp, q);
    return;
  }

  if (b.sign() == Zero) {
    q._mag = 0;
    q._sign = Zero;
    return;
  }

  if (_sign == Zero) {
    q._mag = 0;
    q._sign = Zero;
    return;
  }

  if (_sign == b._sign) {
    q._sign = Pos;
  } else {
    q._sign = Neg;
    _mag--;
  }

  //  std::cout << "TRACE - this b q " << _mag << " " << b._mag << " " << q._mag << std::endl;
  _mag.modWithQuotient(b._mag, q._mag);
  //  std::cout << "TRACE - this b q " << _mag << " " << b._mag << " " << q._mag << std::endl;
  if (_sign != b._sign) {
    q._mag++;
    _mag.subtract(b._mag, _mag);
    _mag--;
  }
  //  std::cout << "TRACE - this b q " << _mag << " " << b._mag << " " << q._mag << std::endl;
  _sign = b._sign;

  if (_mag.isZero()) {
    _sign = Zero;
  }

  if (q._mag.isZero()) {
    q._sign = Zero;
  }
}// modWithQuotient

BigUnsigned::Comparison
BigInteger::compareTo(const BigInteger &x) const
{
  if (_sign < x._sign) {
    return less;
  } else if (_sign > x._sign) {
    return greater;
  } else switch (_sign) {
  case Zero:
    return equal;
  case Pos:
    return _mag.compareTo(x._mag);
  case Neg:
    return BigUnsigned::Comparison(-_mag.compareTo(x._mag));
  default:
    throw "BigInteger internal error";
  }
}// compareTo

void
BigInteger::operator++()
{
  if (_sign == Neg) {
    _mag--;
    if (_mag == BigUnsigned(0)) {
      _sign = Zero;
    }
  } else {
    _mag++;
    _sign = Pos;
  }
}// operator++

void
BigInteger::operator++(int)
{
  operator++();
}// operator++

void
BigInteger::operator--()
{
  if (_sign == Pos) {
    _mag--;
    if (_mag == BigUnsigned(0)) {
      _sign = Zero;
    }
  } else {
    _mag++;
    _sign = Neg;
  }
}// operator--

void
BigInteger::operator--(int)
{
  operator--();
}// operator--
