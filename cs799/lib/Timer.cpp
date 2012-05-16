#include "timer.h" // class implemented

using namespace tgl;


Timer::Timer()
{
  _start_time = clock();
}// Timer

void
Timer::restart()
{
  _start_time = clock();
}// restart

double
Timer::elapsed() const
{
  return double(clock() - _start_time) / CLOCKS_PER_SEC;
}// elapsed
