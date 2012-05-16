#ifndef TGL_TIMER_H
#define TGL_TIMER_H

#include <ctime>

namespace tgl {

  class Timer
  {
  public:
    Timer();

    void restart();

    double elapsed() const;

  protected:
  private:

    clock_t _start_time;
  };

}

#endif // #ifndef TGL_TIMER_H
