#ifndef TGL_EXPANDEDEUCLIDEANALGORITHM_H
#define TGL_EXPANDEDEUCLIDEANALGORITHM_H

namespace tgl {
  /// Method object to use the Expanded Euclidean Algorithm
  class ExpandedEuclideanAlgorithm {
  public:
  
    /// Constructor
    ExpandedEuclideanAlgorithm();
  
    /// Find x0 and y0
    void extendedGcd(int m, int n, int& x, int& y);

  protected:
  private:
  
    /// Quotient & remainder
    void divide(int m, int n, int& q, int& r);

  };
}

#endif // #ifndef TGL_EXPANDEDEUCLIDEANALGORITHM_H
