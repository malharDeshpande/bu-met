#ifndef TGL_ELGAMALSIGN_H
#define TGL_ELGAMALSIGN_H

#include "BigInteger.h"

namespace tgl {
  /// Method object to preform an El Gamal signature
  class ElGamalSign {
  public:

    /// Constructor
    ElGamalSign(const BigInteger& r = tgl::BigInteger(0));


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

#endif // #ifndef TGL_ELGAMALSIGN_H

