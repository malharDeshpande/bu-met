#ifndef TGL_ELGAMALVERIFY_H
#define TGL_ELGAMALVERIFY_H

#include "BigInteger.h"

namespace tgl {
  /// Method object to preform an El Gamal verification
  class ElGamalVerify {
  public:

    /// Constructor
    ElGamalVerify();

    /// Perform the verification
    void run(const BigInteger& e1,
             const BigInteger& e2,
             const BigInteger& s1,
             const BigInteger& s2,
             const BigInteger& p,
             const BigInteger& m);

    /// Check V1 & V2
    bool congruent() const;

    /// Get-only!
    BigInteger getV1() const { return _v1; };
    BigInteger getV2() const { return _v2; };
    
  protected:
  private:

    BigInteger _v1;
    BigInteger _v2;

  };
}

#endif // #ifndef TGL_ELGAMALVERIFY_H
