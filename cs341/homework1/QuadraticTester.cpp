// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #1

#include "Quadratic.h" // class to test
#include <iostream>

#include <math.h>

void
test_equal(double v1, double v2)
{
  bool result = true;
  if (fabs(v1 - v2) > 1e-06) {
    std::cerr << "FAIL! (" << v1 << " != " << v2 << ")" << std::endl;
    throw;
  } else {
    std::cout << ".";
  }
}// test_equal

int
main(int argc, char* argv[])
{
  Quadratic q0;

  test_equal(q0.getA(), 0.);
  test_equal(q0.getB(), 0.);
  test_equal(q0.getC(), 0.);

  Quadratic q1;
  q1.setA(3.);
  q1.setB(2.);
  q1.setC(5.);

  test_equal(q1.evaluate(0), 5.);
  test_equal(q1.evaluate(1), 10.);
  test_equal(q1.evaluate(2), 21.);
  test_equal(q1.evaluate(3), 38.);

  test_equal(q1.evaluate(-1), 6.);
  test_equal(q1.evaluate(-2), 13.);
  test_equal(q1.evaluate(-3), 26.);
  
  Quadratic q2(4., 7., 2.);

  Quadratic q3 = q1 + q2;

  test_equal(q3.getA(), 7.);
  test_equal(q3.getB(), 9.);
  test_equal(q3.getC(), 7.);

  Quadratic q4 = 5. * q2;

  test_equal(q4.getA(), 20.);
  test_equal(q4.getB(), 35.);
  test_equal(q4.getC(), 10.);

  Quadratic q5(0.25, 0.5, 0.125);

  test_equal(q5.evaluate(.2), .235);
  test_equal(q5.evaluate(-.2), .035);
  test_equal(q5.evaluate(1.3), 1.1975);

  std::cout << std::endl << "All tests passed!" << std::endl;

  return 0;
}// main

