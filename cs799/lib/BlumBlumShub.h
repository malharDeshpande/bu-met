#ifndef TGL_BLUMBLUMSHUB_H
#define TGL_BLUMBLUMSHUB_H

#include "BigInteger.h"

namespace tgl {

  class BlumBlumShub {
  public:

    BlumBlumShub();

    tgl::BigInteger generate(const tgl::BigInteger& p,
                             const tgl::BigInteger& q,
                             size_t n);

  protected:
  private:

  };

}

#endif // #ifndef TGL_BLUMBLUMSHUB_H
