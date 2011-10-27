#ifndef TGL_BIGUNSIGNED_H
#define TGL_BIGUNSIGNED_H

#include <ostream>
#include <vector>
#include <string>

namespace tgl {

  /// Describe an unsigned of many many digits
  class BigUnsigned {
  public:
    
    enum Comparison { less = -1, equal = 0, greater = 1 };

    // Default constructor
    BigUnsigned(); 

    /// Construct from an unsigned long.
    BigUnsigned(unsigned long n);

    /// Constructor from a std::string
    BigUnsigned(const std::string &str);

    /// Copy constructor
    BigUnsigned(const BigUnsigned &x);

    /// Assignment operator
    void operator=(const BigUnsigned &x);

    Comparison compareTo(const BigUnsigned &x) const;

    /// Equality operator
    bool operator==(const BigUnsigned &x) const;

    /// Imequality operator
    bool operator!=(const BigUnsigned &x) const {
      return !operator ==(x);
    };

    bool operator<(const BigUnsigned &x) const { return compareTo(x) == less; };
    bool operator<=(const BigUnsigned &x) const { return compareTo(x) != greater; };
    bool operator>=(const BigUnsigned &x) const { return compareTo(x) != less; };
    bool operator>(const BigUnsigned &x) const { return compareTo(x) == greater; };

    void add(const BigUnsigned &a, const BigUnsigned &b);

    void multiply(const BigUnsigned &a, const BigUnsigned &b);
    
    void modWithQuotient(const BigUnsigned &b, BigUnsigned &x);

    void zapLeadingZeros();

    size_t length() const { return _value.size(); };

    /// Return value at index, does not check for overrun of std::vector!
    unsigned long value(size_t index) const { return _value[index]; };

    /// Set to zero.
    void zero() { _value.clear(); };

    bool isZero() const;

  protected:
  private:
    
    std::vector<unsigned long> _value;

    friend std::ostream &operator<<(std::ostream &out, const BigUnsigned &x);

  };

  std::string convert2str(const BigUnsigned &x);

  inline std::ostream &operator<<(std::ostream &out, const BigUnsigned &x) {
    std::string s = convert2str(x);
    out << s;
    return out;
  }
}

#endif // #ifndef TGL_BIGUNSIGNED_H
