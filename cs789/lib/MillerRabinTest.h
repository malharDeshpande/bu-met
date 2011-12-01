#ifndef TGL_MILLERRABINTEST_H
#define TGL_MILLERRABINTEST_H

#include "BigInteger.h"

namespace tgl {

  class MillerRabinTest {
  public:

    MillerRabinTest();

    bool witness(const tgl::BigInteger& n);

  protected:
  private:

  };
}

#endif // #ifndef TGL_MILLERRABINTEST_H

