#ifndef TGL_CEILINGSQRTALGORITHM_H
#define TGL_CEILINGSQRTALGORITHM_H

#include "BigInteger.h"

namespace tgl
{
  /// Method object to calculate ceiling(sqrt(n))
  class CeilingSqrtAlgorithm {
  public:
    /// Constructor
    CeilingSqrtAlgorithm();
    
    /// does it
    BigInteger compute(const BigInteger &n);

  protected:
  private:

  };

}

#endif // #ifndef TGL_CEILINGSQRTALGORITHM_H
