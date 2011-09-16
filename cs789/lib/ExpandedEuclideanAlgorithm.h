#ifndef EXPANDEDEUCLIDEANALGORITHM_H
#define EXPANDEDEUCLIDEANALGORITHM_H

/// Method object to use the Expanded Euclidean Algorithm
class ExpandedEuclideanAlgorithm {
 public:
  
  /// Constructor
  ExpandedEuclideanAlgorithm();
  
  /// Quotient & remainder
  void divide(int m, int n, int& q, int& r);

  /// Find x0 and y0
  void extendedGcd(int m, int n, int& x, int& y);

 protected:
 private:
  
};

#endif // #ifndef EXPANDEDEUCLIDEANALGORITHM_H
