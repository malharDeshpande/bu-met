#ifndef TGL_PRIMITIVEROOTSEARCHALGORITHM_H
#define TGL_PRIMITIVEROOTSEARCHALGORITHM_H

#include "BigInteger.h"

namespace tgl {
  /// Method object to do a primitive root search
  class PrimitiveRootSearchAlgorithm {
  public:
  
    /// Constructor
    PrimitiveRootSearchAlgorithm();

    /// Do it
    BigInteger compute(const BigInteger &p);
    
  protected:
  private:

    /// Search
    bool search(const BigInteger &p, BigInteger &b);

  };
}

#endif // #ifndef TGL_PRIMITIVEROOTSEARCHALGORITHM_H
