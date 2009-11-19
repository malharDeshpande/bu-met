// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#include "CheckoutLine.h"
#include "Queue.h"
#include "Customer.h"

#include <iostream>
#include <iomanip>

using namespace std;

CheckoutLine::CheckoutLine(int join_interval,
                           int serve_interval) :
  _queue(new Queue),
  _served(new Queue),
  _join_interval(join_interval),
  _serve_interval(serve_interval),
  _current_time(0),
  _join_countdown(0),
  _serve_countdown(0)
{
  srand(time(0));
  _join_countdown = rand() % _join_interval + 1;
  _serve_countdown = rand() % _serve_interval + 1;
}// CheckoutLine

CheckoutLine::~CheckoutLine()
{
  delete _queue;
  delete _served;
}// ~CheckoutLine

void
CheckoutLine::run_one_minute()
{
  --_join_countdown;
  ++_current_time;

  if (!_queue->empty()) {
    _queue->front()->increment_time_being_served();
   
    if (0 == _serve_countdown) {
      _served->push(_queue->front());
      _queue->pop();
      _serve_countdown = rand() % _serve_interval + 1;
    }

    --_serve_countdown;
  }

   if (0 == _join_countdown) {
    _queue->push(new Customer(_current_time));
    _join_countdown = rand() % _join_interval + 1;
  }

  Queue *temp = new Queue;
  Customer *curr;
  bool first = true;
  while (!_queue->empty()) {
    curr = _queue->front();
    if (first) {
      first = false;
    } else {
      curr->increment_time_in_queue();
    }

    temp->push(curr);
    _queue->pop();
  }

  while (!temp->empty()) {
    _queue->push(temp->front());
    temp->pop();
  }

  delete temp;
}// run_one_minute

void
CheckoutLine::report()
{
  if (1 == _current_time) {
    cout << "Min# | Current    | Waiting" << endl;
    cout << "     | Id/MinLeft | Id/MinInQ ..." << endl;
    cout << "-----+------------+------------------------------------------------------------" << endl;
  }

  cout << setw(4) << _current_time << " | ";
  
  if (_queue->empty()) {
    cout << "           |" << endl;

  } else {
    bool first = true;
    Queue *temp = new Queue;
    Customer *curr;
    while (!_queue->empty()) {
      curr = _queue->front();
      if (first) {
        cout << setw(4) << curr->id() << " / " << left << setw(3) << _serve_countdown + 1 << right << " | ";
        first = false;
      } else {
        cout << curr->id() << "/" << curr->time_in_queue() << "  ";
      }
      
      temp->push(curr);
      _queue->pop();
    }
    
    cout << endl;
    
    while (!temp->empty()) {
      _queue->push(temp->front());
      temp->pop();
    }

    delete temp;
  }
}// report

void
CheckoutLine::tally()
{
  int sum_wait_times = 0;
  int sum_served_times = 0;
  int size = _served->size();

  Queue *temp = new Queue;
  while (!_served->empty()) {
    sum_wait_times += _served->front()->time_in_queue();
    sum_served_times += _served->front()->time_being_served();
    temp->push(_served->front());
    _served->pop();
  }

  delete temp;

  cout << "-------------------------------------------------------------------------------" << endl;
  cout << "-------------------------------------------------------------------------------" << endl;
  cout << "Total customers served: " << size << endl;
  cout << "Average wait time: " << (double) sum_wait_times / size << endl;
  cout << "Average serving time: " << (double) sum_served_times / size << endl;
  if (0 == _queue->size()) {
    cout << "Zero (0) customers in queue." << endl;
  } else {
    cout << "One (1) customer being served." << endl;
    cout << "Total customers still waiting: " << _queue->size() - 1 << endl;
  }
  cout << "-------------------------------------------------------------------------------" << endl;
  cout << "-------------------------------------------------------------------------------" << endl;
}// tally
