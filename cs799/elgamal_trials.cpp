#include "lib/ElGamalDss.h"

#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc == 5) {
    int n(::atoi(argv[1]));
    int k(::atoi(argv[2]));
    int m(::atoi(argv[3]));
    int size(::atoi(argv[4]));

    double key_time(0);
    double exchange_time(0);
    double break_time(0);


    tgl::ElGamalDss dss;
    for (int loop = 0; loop < size; ++loop) {

      std::cout << "##### Starting Loop " << loop << " #####" << std::endl;

      dss.run(n, k ,m);
      
      if (0 == loop) {
        key_time = dss.getKeyTime();
        exchange_time = dss.getExchangeTime();
        break_time = dss.getBreakTime();
      } else {
        key_time = key_time + ((dss.getKeyTime() - key_time)/loop);
        exchange_time = exchange_time + ((dss.getExchangeTime() - exchange_time)/loop);
        break_time = break_time + ((dss.getBreakTime() - break_time)/loop);
      }
   }
    
    std::cout << "For " << size << " iterations, average timings are:\n"
              << " Key generation took " << key_time << "secs\n"
              << " DSS exchange took " << exchange_time << "secs\n"
              << " Breaking took " << break_time << "secs" << std::endl;
  } else {
    std::cerr << "Usage: " << argv[0] << " N K m I\n"
              << "  N - number of binary digits to use for result\n"
              << "  K - number of Miller Rabin tests to check for primality\n"
              << "  m - digest to sign\n"
              << "  I - number of iterations"
              << std::endl;
  }

  return 0;
}// main

