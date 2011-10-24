#ifndef TGL_BIGUNSIGNED_H
#define TGL_BIGUNSIGNED_H

#include <ostream>
#include <vector>
#include <string>

namespace tgl {
  /// Describe an unsigned of many many digits
  class BigUnsigned {
  public:
    /// Construct from an unsigned long.
    BigUnsigned(unsigned long n);

    /// Constructor from a std::string
    BigUnsigned(const std::string &str);

    /// Print out
    void write(std::ostream &out);

  protected:
  private:
    
    std::vector<unsigned long> _value;

  };

}

#endif // #ifndef TGL_BIGUNSIGNED_H
