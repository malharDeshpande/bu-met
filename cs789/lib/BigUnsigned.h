#ifndef TGL_BIGUNSIGNED_H
#define TGL_BIGUNSIGNED_H

#include <ostream>
#include <vector>
#include <string>

namespace tgl {
  /// Describe an unsigned of many many digits
  class BigUnsigned {
  public:
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

    /// Equality operator
    bool operator==(const BigUnsigned &x);

    /// Imequality operator
    bool operator!=(const BigUnsigned &x) {
      return !operator ==(x);
    };

    /// Print out
    void write(std::ostream &out);

    void add(BigUnsigned &a, BigUnsigned &b);

    void multiply(BigUnsigned &a, BigUnsigned &b);
    
    void modWithQuotient(const BigUnsigned &b, BigUnsigned &x);
    
    size_t length() const { return _value.size(); };

    /// Return value at index, does not check for overrun of std::vector!
    unsigned long value(size_t index) const { return _value[index]; };

    /// Set to zero.
    void zero() { _value.clear(); };

  protected:
  private:
    
    std::vector<unsigned long> _value;

  };

}

#endif // #ifndef TGL_BIGUNSIGNED_H
