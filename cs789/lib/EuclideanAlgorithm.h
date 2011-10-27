#ifndef TGL_EUCLIDEANALGORITHM_H
#define TGL_EUCLIDEANALGORITHM_H

#include "BigInteger.h"

namespace tgl {
  /// Method object to find GCD of two integers
  class EuclideanAlgorithm {
  public:
  
    /// Constructor
    EuclideanAlgorithm();
  
    /// Returns the remainder (m mod n)
    BigInteger remainder(BigInteger m, BigInteger n);
  
    /// Returns the GCD.
    BigInteger gcd(BigInteger m, BigInteger n);
  
  protected:
  private:
  
  };
}

#endif // #ifndef TGL_EUCLIDEANALGORITHM_H
