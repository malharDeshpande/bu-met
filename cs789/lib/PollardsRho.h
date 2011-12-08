#ifndef TGL_POLLARDSRHO_H
#define TGL_POLLARDSRHO_H

#include "BigInteger.h"

namespace tgl {
  class PollardsRho {
  public:

    PollardsRho();

    tgl::BigInteger factor(const tgl::BigInteger& n);

  protected:
  private:

  };
}

#endif // #ifndef TGL_POLLARDSRHO_H
