#ifndef TGL_PRIMITIVEROOTSEARCHALGORITHM_H
#define TGL_PRIMITIVEROOTSEARCHALGORITHM_H

#include "BigInteger.h"

namespace tgl {
  /// Method object to preform an El Gamal signature
  class ElGamalSign {
  public:

    /// Constructor
    ElGamalSign();


    /// Perform the signature
    void run(const BigInteger& e1,
             const BigInteger& p,
             const BigInteger& d,
             const BigInteger& m);


    /// Get-only!
    BigInteger getR() const { return _r; };
    BigInteger getS1() const { return _s1; };
    BigInteger getS2() const { return _s2; };
    
  protected:
  private:

    BigInteger _r;
    BigInteger _s1;
    BigInteger _s2;

  };
}

#endif // #ifndef TGL_PRIMITIVEROOTSEARCHALGORITHM_H

