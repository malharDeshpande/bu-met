// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#ifndef CHECKOUTLINE_H
#define CHECKOUTLINE_H

class Queue;

class CheckoutLine {
 public:
  /// Constructor
  CheckoutLine(int join_interval, int serve_interval);

  /// Destructor
  ~CheckoutLine();

  /// Simulate one minute
  void run_one_minute();

  /// Writes to standard out the current state of the simulation.
  void report();

 protected:
 private:

  Queue *_queue;

  int _join_interval;
  int _serve_interval;

  int _current_time;
  int _join_countdown;
  int _serve_countdown;
  
};

#endif // #ifndef CHECKOUTLINE_H
