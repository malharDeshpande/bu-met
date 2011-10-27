#ifndef TGL_BIGINTEGER_H
#define TGL_BIGINTEGER_H

#include <ostream>
#include <string>

#include "BigUnsigned.h"

namespace tgl {
  /// Describe an integer of many manu digits
  class BigInteger {
  public:
  
    enum Sign {Neg = -1, Zero = 0, Pos = 1};

    /// Default constructor
    BigInteger();

    /// Construct from an integer.
    BigInteger(int n);

    /// Construct from a std::string
    BigInteger(const std::string &str);

    /// Equality operator
    bool operator==(const BigInteger &x) const;

    /// Less than operator
    bool operator<(const BigInteger &x) const;

    /// Greater than operator
    bool operator>(const BigInteger &x) const;

    bool isZero() const { return _sign == Zero || _mag.isZero(); }

    BigInteger operator+(const BigInteger &x) const;
    BigInteger operator-(const BigInteger &x) const;
    BigInteger operator*(const BigInteger &x) const;
    BigInteger operator/(const BigInteger &x) const;
    BigInteger operator%(const BigInteger &x) const;
    BigInteger operator-() const;


    void add(const BigInteger &a, const BigInteger &b) {
      _mag.add(a._mag, b._mag);
    };

    void multiply(const BigInteger &a, const BigInteger &b) {
      _mag.multiply(a._mag, b._mag);
    };

    void modWithQuotient(const BigInteger &b, BigInteger &q) {
      _mag.modWithQuotient(b._mag, q._mag);
    };

  protected:
  private:
    
    Sign _sign;
    BigUnsigned _mag;

    friend std::ostream &operator<<(std::ostream &out, const BigInteger &x);

    friend BigInteger operator%(BigInteger &a, BigInteger &b);
  };

  inline std::ostream &operator<<(std::ostream &out, const BigInteger &x) {
    if (x._sign == BigInteger::Neg) {
      out << '-';
    }
    out << x._mag;
  };

  inline BigInteger operator%(BigInteger &a, BigInteger &b) {
    BigInteger mod(a);
    BigInteger q;
    mod.modWithQuotient(b, q);
    return mod;
  };

  inline BigInteger BigInteger::operator+(const BigInteger &x) const {
    BigInteger r;
    r.add(*this, x);
    return r;
  };

  inline BigInteger BigInteger::operator-(const BigInteger &x) const {
    BigInteger r;
    r.add(*this, x);
    return r;
  };

  inline BigInteger BigInteger::operator*(const BigInteger &x) const {
    BigInteger r;
    r.multiply(*this, x);
    return r;
  };

  inline BigInteger BigInteger::operator/(const BigInteger &x) const {
    if (x.isZero()) throw "BigInteger::operator%: division by zero";
    BigInteger q, r;
    r = *this;
    r.modWithQuotient(x, q);
    return q;
  };

  inline BigInteger BigInteger::operator%(const BigInteger &x) const {
    if (x.isZero()) throw "BigInteger::operator%: division by zero";
    BigInteger q, r;
    r = *this;
    r.modWithQuotient(x, q);
    return r;
  };

  inline BigInteger BigInteger::operator-() const {
    BigInteger r;
    return r;
  };

}

#endif // #ifndef TGL_BIGINTEGER_H
