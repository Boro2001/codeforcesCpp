#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;
class point{
public:
      double x; 
      double y; 
      point():x(0),y(0){};
      point(double a, double b):x(a), y(b){};
      bool operator<(const point& other){
            if(other.x*other.x + other.y*other.y > x*x + y*y) return true;
            return false;
      }
      void print(){cout<<x<<"\t"<<y<<"\n";}
};
int main(){
      list<point> list;
      for(int i=0; i<10; ++i) list.push_back(point(rand()%234, rand()%234));
      for(auto &element : list) element.print();
      list.sort();
      cout<<"\n";
      for(auto &element : list) element.print();

      map<string,int>dict;
      dict.insert(map<string, int>::value_type("siemano", 3));
      dict["c"]==1;
      dict["a"]==3;dict["d"]==41;
      dict["a"]=123;
      map<string, int>::const_iterator element;
      for(element = dict.begin(); element!=dict.end(); element++) cout<<element->first<<"\t"<<element->second<<"\n";

      return 0;
}