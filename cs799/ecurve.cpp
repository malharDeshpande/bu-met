#include <iostream>

int
main(int argc, char* argv[])
{
  int p = ::atoi(argv[1]);
  int a = ::atoi(argv[2]);
  int b = ::atoi(argv[3]);

  std::cout << "y^2 = x^3 + " << a << "x + " << b << " in the field F" << p << std::endl;

  int x = 0;
  while (x < p) {
    int y2 = (x*x*x+a*x+b);
    int q = y2/p;
    std::cout << x << " -> " << (y2 - (p*q)) << std::endl;
    ++x;
  }
}// main
