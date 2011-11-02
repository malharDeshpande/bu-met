#ifndef TGL_BABYSTEPGIANTSTEPALGORITHM_H
#define TGL_BABYSTEPGIANTSTEPALGORITHM_H

#include "BigInteger.h"

namespace tgl {
  /// Method object to use the Baby-Step Giant-Step Algorithm
  class BabyStepGiantStepAlgorithm {
  public:
  
    /// Constructor
    BabyStepGiantStepAlgorithm();

    /// Do it
    BigInteger compute(const BigInteger &p,
		       const BigInteger &b,
		       const BigInteger &a);
    
  protected:
  private:

  };
}

#endif // #ifndef TGL_BABYSTEPGIANTSTEPALGORITHM_H
