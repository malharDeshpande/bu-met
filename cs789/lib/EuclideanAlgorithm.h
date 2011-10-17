#ifndef TGL_EUCLIDEANALGORITHM_H
#define TGL_EUCLIDEANALGORITHM_H

namespace tgl {
  /// Method object to find GCD of two integers
  class EuclideanAlgorithm {
  public:
  
    /// Constructor
    EuclideanAlgorithm();
  
    /// Returns the remainder (m mod n)
    int remainder(int m, int n);
  
    /// Returns the GCD.
    int gcd(int m, int n);
  
  protected:
  private:
  
  };
}

#endif // #ifndef TGL_EUCLIDEANALGORITHM_H
