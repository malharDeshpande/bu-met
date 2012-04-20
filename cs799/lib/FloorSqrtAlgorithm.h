#ifndef TGL_FLOORSQRTALGORITHM_H
#define TGL_FLOORSQRTALGORITHM_H

#include "BigInteger.h"

namespace tgl
{
  /// Method object to calculate floor(sqrt(n))
  class FloorSqrtAlgorithm {
  public:
    /// Constructor
    FloorSqrtAlgorithm();
    
    /// does it
    BigInteger compute(const BigInteger &n);

  protected:
  private:

  };

}

#endif // #ifndef TGL_FLOORSQRTALGORITHM_H
