#ifndef TGL_EXPONENTIATIONALGORITHM_H
#define TGL_EXPONENTIATIONALGORITHM_H

namespace tgl {
  /// The exponentiation algorithm
  class ExponentiationAlgorithm {
  public:
    /// Constructor
    ExponentiationAlgorithm();
    
    /// Raise an integer to another integer
    int pow(int x, int e);

    /// Raise an integer to another integer, then modulus
    int pow_mod(int x, int e, int m);
 
 protected:
  private:

    void compute(int& x, int& e, int& y, int m);

  };
}

#endif // #ifndef TGL_EXPONENTIATIONALGORITHM_H
