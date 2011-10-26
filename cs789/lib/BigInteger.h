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

    /// Print out
    void write(std::ostream &out);

    void add(BigInteger &a, BigInteger &b) {
      _mag.add(a._mag, b._mag);
    };

    void multiply(BigInteger &a, BigInteger &b) {
      _mag.multiply(a._mag, b._mag);
    };

  protected:
  private:
    
    Sign _sign;
    BigUnsigned _mag;

    friend std::ostream &operator<<(std::ostream &out, BigInteger b);
  };

  inline std::ostream &operator<<(std::ostream &out, BigInteger b) {
    b.write(out);
  };
}

#endif // #ifndef TGL_BIGINTEGER_H
