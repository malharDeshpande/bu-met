#ifndef TGL_EXPANDEDEUCLIDEANALGORITHM_H
#define TGL_EXPANDEDEUCLIDEANALGORITHM_H

#include "BigInteger.h"

namespace tgl {
  /// Method object to use the Expanded Euclidean Algorithm
  class ExpandedEuclideanAlgorithm {
  public:
  
    /// Constructor
    ExpandedEuclideanAlgorithm();
  
    /// Find x0 and y0
    void extendedGcd(BigInteger m, BigInteger n, BigInteger& x, BigInteger& y);

  protected:
  private:
  
    /// Quotient & remainder
    void divide(BigInteger m, BigInteger n, BigInteger& q, BigInteger& r);

  };
}

#endif // #ifndef TGL_EXPANDEDEUCLIDEANALGORITHM_H
