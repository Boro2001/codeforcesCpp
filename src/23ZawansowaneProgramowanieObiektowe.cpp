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
zespolona::zespolona(double x, double y){
      re = x; im = y; 
}
zespolona::zespolona(const zespolona & other){
      re = other.re;
      im = other.im;
}
zespolona::zespolona(zespolona && other){
      re = other.re;
      im = other.im;
}
const zespolona & zespolona::operator+(const zespolona & other){
      re += other.re;
      im += other.im;
      return * this;
}
const zespolona & zespolona::operator-(const zespolona & other){
      re -= other.re;
      im -= other.im;
      return * this;
}
const zespolona & zespolona::operator*(const zespolona & other){
      //(a + ib)(c + id)= ac - bd + i(bc+ad)
      zespolona * tmp =  new zespolona(re*other.re - im*other.im, im*other.re+re*other.im);
      return * tmp;
}
namespace zesp{
      const zespolona i(0,1);
}

int main(){

      return 0;
}