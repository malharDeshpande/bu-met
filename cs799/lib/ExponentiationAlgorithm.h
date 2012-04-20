#ifndef TGL_EXPONENTIATIONALGORITHM_H
#define TGL_EXPONENTIATIONALGORITHM_H

#include "BigInteger.h"

namespace tgl {
  /// The exponentiation algorithm
  class ExponentiationAlgorithm {
  public:
    /// Constructor
    ExponentiationAlgorithm();
    
    /// Raise an integer to another integer
    BigInteger pow(BigInteger x, BigInteger e);

    /// Raise an integer to another integer, then modulus
    BigInteger pow_mod(BigInteger x, BigInteger e, BigInteger m);
    
  protected:
  private:

    void compute(BigInteger& x, BigInteger& e, BigInteger& y, BigInteger m);

  };
}

#endif // #ifndef TGL_EXPONENTIATIONALGORITHM_H
