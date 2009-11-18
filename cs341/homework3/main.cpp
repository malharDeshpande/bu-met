// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#include "Queue.h"
#include "CheckoutLine.h"

#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

int
main(int argc, char* argv[])
{
  int run_time;
  cout <<  "Enter length of time (in minutes) to run simulation: ";
  if (cin.good() && !cin.eof()) {
    cin >> run_time;
  }

  int join_interval;
  cout <<  "Enter max. interval for a person to join the queue (in minutes): ";
  if (cin.good() && !cin.eof()) {
    cin >> join_interval;
  }

  int serve_interval;
  cout <<  "Enter max. interval for a person to be served (in minutes): ";
  if (cin.good() && !cin.eof()) {
    cin >> serve_interval;
  }

  cout << "\nThe simulation will run for " << run_time << " minutes.\n"
       << "Customers will join the queue every 1 to " << join_interval << " minutes.\n"
       << "Time to serve a customer will vary between 1 and " << serve_interval << " minutes." << endl << endl;

  CheckoutLine checkout(join_interval, serve_interval);

  while (run_time--) {
    checkout.run_one_minute();
    checkout.report();
  }
  
  return EXIT_SUCCESS;
}// main
