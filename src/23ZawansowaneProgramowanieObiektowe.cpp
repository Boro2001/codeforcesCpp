#include <iostream>

using namespace std;


class stale{
      static const double PI;
      static const double e;
};
const double stale::PI = 3.1321;
class liczba{
public:
      static int licz;
};
int liczba::licz = 0;

class zespolona{
public:
      double re, im;
      zespolona();
      zespolona(double, double);
      zespolona(const  zespolona &);
      zespolona(zespolona && );

      const zespolona & operator+(const zespolona &);
      const zespolona & operator-(const zespolona &);
      const zespolona & operator*(const zespolona &);
      bool operator==(const zespolona &);
};

int main(){

      return 0;
}