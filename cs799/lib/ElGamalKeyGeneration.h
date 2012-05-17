#ifndef TGL_ELGAMALKEYGENERATION_H
#define TGL_ELGAMALKEYGENERATION_H

#include "BigInteger.h"

namespace tgl
{
  class ElGamalKeyGeneration 
  {
  public:
    ElGamalKeyGeneration();

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
    BigInteger getE1() const { return _e1; };
    BigInteger getE2() const { return _e2; };
    BigInteger getD() const { return _d; };

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
    BigInteger _e1;
    BigInteger _e2;
    BigInteger _d;
  };    
}

#endif // #ifndef TGL_ELGAMALKEYGENERATION_H
