#ifndef TGL_ENCODER_H
#define TGL_ENCODER_H

#include "BigInteger.h"

namespace tgl
{

  /// Encode/decode a string to a big integer
  class Encoder {
  public:

    /// Constructor
    Encoder();

    tgl::BigInteger encode(const std::string& s) const;
    
    std::string decode(const tgl::BigInteger& i) const;

  protected:
  private:
  };
}

#endif // #ifndef TGL_ENCODER_H
