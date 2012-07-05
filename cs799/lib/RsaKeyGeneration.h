#ifndef TGL_RSAKEYGENERATION_H
#define TGL_RSAKEYGENERATION_H

#include "BigInteger.h"

namespace tgl
{
  class RsaKeyGeneration 
  {
  public:
    RsaKeyGeneration();

    /**
     * Make the private & public keys.
     * 
     * @param p first prime for BBS algorithm
     * @param q second prime for BBS algorithm
     * @param n number of digits for random prime
     * @param k number of miller rabin tests to perform
     */
    void makeKeys(const BigInteger& p,
                  const BigInteger& q,
                  int n,
                  int k);

    BigInteger getP() const { return _p; };
    BigInteger getQ() const { return _q; };
    BigInteger getPhi() const { return _phi; };
    BigInteger getN() const { return _n; };

    /**
     * Make the private & public keys.
     * 
     * @param p first prime for BBS algorithm
     * @param q second prime for BBS algorithm
     * @param n number of digits for random prime
     * @param k number of miller rabin tests to perform
     */
    static BigInteger randomPrime(const BigInteger& p,
                                  const BigInteger& q,
                                  int n,
                                  int k);
  protected:
  private:

    BigInteger _p;
    BigInteger _q;
    BigInteger _phi;
    BigInteger _n;
  };    
}

#endif // #ifndef TGL_RSAKEYGENERATION_H
