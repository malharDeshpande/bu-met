#ifndef TGL_ELGAMALDSS_H
#define TGL_ELGAMALDSS_H

namespace tgl 
{
  class ElGamalDss
  {
  public:
    ElGamalDss();

    void run(int n, int k, int digest);

    double getKeyTime() const { return _key_time; };
    double getExchangeTime() const { return _exchange_time; };
    double getBreakTime() const { return _break_time; };

  protected:
  private:

    double _key_time;
    double _exchange_time;
    double _break_time;
  };
}

#endif // #ifndef TGL_ELGAMALDSS_H
