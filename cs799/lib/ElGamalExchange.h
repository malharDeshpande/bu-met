#ifndef TGL_ELGAMALEXCHANGE_H
#define TGL_ELGAMALEXCHANGE_H

#include "BigInteger.h"

namespace tgl {
  class ElGamalExchange {
  public:

    ElGamalExchange();

    void run(const tgl::BigInteger& p,
             const tgl::BigInteger& g,
             const tgl::BigInteger& d,
             const tgl::BigInteger& r,
             const tgl::BigInteger& m);

    tgl::BigInteger getS1() const { return _s1; };
    tgl::BigInteger getS2() const { return _s2; };
    tgl::BigInteger getV1() const { return _v1; };
    tgl::BigInteger getV2() const { return _v2; };
    tgl::BigInteger getE2() const { return _e2; };
    bool congruent() const { return _v1 == _v2; };

  protected:
  private:

    tgl::BigInteger _s1;
    tgl::BigInteger _s2;
    tgl::BigInteger _v1;
    tgl::BigInteger _v2;
    tgl::BigInteger _e2;

  };
}

#endif // #ifndef TGL_ELGAMALEXCHANGE_H
