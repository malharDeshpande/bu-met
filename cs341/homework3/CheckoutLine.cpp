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
}// ~CheckoutLine

void
CheckoutLine::run_one_minute()
{
  --_join_countdown;
  ++_current_time;

 if (!_queue->empty()) {
    if (0 == _serve_countdown) {
      _queue->pop();
      _serve_countdown = rand() % _serve_interval + 1;
    } else {
      Customer *served = _queue->front();
      served->increment_time_being_served();
    }
    --_serve_countdown;
  }

   if (0 == _join_countdown) {
    _queue->push(new Customer(_current_time));
    _join_countdown = rand() % _join_interval + 1;
  }

  Queue *temp = new Queue;
  Customer *curr;
  while (!_queue->empty()) {
    curr = _queue->front();
    curr->increment_time_in_queue();
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


