// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #1

#include "Quadratic.h" // class implemented

Quadratic::Quadratic() :
  _a(0.),
  _b(0.),
  _c(0.)
{
}// Quadratic

Quadratic::Quadratic(double a, double b, double c) :
  _a(a),
  _b(b),
  _c(c)
{
}// Quadratic

double Quadratic::evaluate(double x) const
{
  return _a * x * x + _b * x + _c;
}// evaluate

Quadratic operator+(const Quadratic& q1, const Quadratic& q2)
{
  double a = q1.getA() + q2.getA();
  double b = q1.getB() + q2.getB();
  double c = q1.getC() + q2.getC();
  
  return Quadratic(a, b, c);
}// operator+

Quadratic operator*(double r, const Quadratic& q)
{
  double a = r * q.getA();
  double b = r * q.getB();
  double c = r * q.getC();
  
  return Quadratic(a, b, c);
}// operator+
