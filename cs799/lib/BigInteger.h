#ifndef TGL_BIGINTEGER_H
#define TGL_BIGINTEGER_H

#include <iostream>
#include <ostream>
#include <string>

#include "BigUnsigned.h"

namespace tgl {
  /// Describe an integer of many manu digits
  class BigInteger {
  public:
    static const BigUnsigned::Comparison less = BigUnsigned::less;
    static const BigUnsigned::Comparison equal = BigUnsigned::equal;
    static const BigUnsigned::Comparison greater = BigUnsigned::greater;
  
    enum Sign {Neg = -1, Zero = 0, Pos = 1};

    /// Default constructor
    BigInteger();

    /// Copy constructor
    BigInteger(const BigInteger &x);

    /// Construct from an integer.
    BigInteger(int n);

    /// Construct from a std::string
    BigInteger(const std::string &str);

    size_t length() const { return _mag.length(); };
    
    Sign sign() const { return _sign; };
    
    unsigned long value(size_t index) const { return _mag.value(index); };

    /// Equality operator
    bool operator==(const BigInteger &x) const {
      return _sign == x._sign && _mag == x._mag;
    };

    BigUnsigned::Comparison compareTo(const BigInteger &x) const;

    bool operator!=(const BigInteger &x) const { return !operator==(x); };
    bool operator<(const BigInteger &x) const { return compareTo(x) == less; };
    bool operator<=(const BigInteger &x) const { return compareTo(x) != greater; };
    bool operator>=(const BigInteger &x) const { return compareTo(x) != less; };
    bool operator>(const BigInteger &x) const { return compareTo(x) == greater; };

    bool isZero() const { 
      return (_sign == Zero); 
    }

    BigInteger operator+(const BigInteger &x) const;
    BigInteger operator-(const BigInteger &x) const;
    BigInteger operator*(const BigInteger &x) const;
    BigInteger operator/(const BigInteger &x) const;
    BigInteger operator%(const BigInteger &x) const;
    BigInteger operator-() const;

    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);

    void add(const BigInteger &a, const BigInteger &b);
    void subtract(const BigInteger &a, const BigInteger &b);
    void multiply(const BigInteger &a, const BigInteger &b);
    void modWithQuotient(const BigInteger &b, BigInteger &q);


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

    return out;
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
    r.subtract(*this, x);
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

  struct BigIntegerComp {
    bool operator() (const BigInteger &lhs, const BigInteger &rhs)
    { std::cout << "TRACE - lhs, rhs " << lhs << " " << rhs << " " << (lhs < rhs) << std::endl;
      return lhs < rhs;}
  };
}

#endif // #ifndef TGL_BIGINTEGER_H
