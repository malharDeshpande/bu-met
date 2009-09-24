// Terry Lorber
// U...

// MET CS341
// Fall 2009
// Maslanka

#ifndef QUADRATIC_H
#define QUADRATIC_H

/**
 * Class for storing a Quadratic equation and manipulating it.
 *
 * ax^2 + bx + c
 */
class Quadratic {
 public:
  /// Default Constructor
  Quadratic();
  
  /**
   * Construct with values.
   *
   * @param a the value of the A coefficient
   * @param b the value of the B coefficient
   * @param c the value of the C coefficient
   */
  Quadratic(double a, double b, double c);
  
  /// Getter method for coefficient A
  double getA() const { return _a; };
  
  /// Getter method for coefficient B
  double getB() const { return _b; };
  
  /// Getter method for coefficient C
  double getC() const { return _c; };
  
  /// Setter method for coefficient A
  void setA(double value) { _a = value; };
  
  /// Setter method for coefficient B
  void setB(double value) { _b = value; };
  
  /// Setter method for coefficientC
  void setC(double value) { _c = value; };
  
  /**
   * Evaluate the equation for the given value of x.
   *
   * @param x the value of x to evaluate the quadratic equation at
   * @returns the double-precision value of the equation at x
   */
  double evaluate(double x) const;

 protected:
 private:
  
  /// instance variables, for each coefficient, A B C
  double _a;
  double _b;
  double _c;
  
};

/// Overload the addition operator
Quadratic operator+(const Quadratic& q1, const Quadratic& q2);

/// Overload the multiplication operator
Quadratic operator*(double r, const Quadratic& q);

#endif // #ifndef QUADRATIC_H
