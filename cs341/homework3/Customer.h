// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
 public:
  /// Constructor
  Customer(int id) : _id(id), _time_in_queue(0), _time_being_served(0) { };

  int id() const { return _id; };
  
  int time_in_queue() const { return _time_in_queue; };

  void increment_time_in_queue() { ++_time_in_queue; }

  int time_being_served() const { return _time_being_served; };

  void increment_time_being_served() { ++_time_being_served; };

 protected:
 private:

  int _id;
  int _time_in_queue;
  int _time_being_served;

};

#endif // #ifndef CUSTOMER_H
