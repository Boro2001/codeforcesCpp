#include <iostream>
using namespace std;

class Vector{
protected:
      double * start; 
      double * end; 
      int capacity;
      bool reserve(int newCapacity);
public:
      Vector(int i = 0);
      Vector(const Vector &);
      Vector(Vector &&);
      ~Vector();

      int getSize() const;
      bool pushFront(double);
      bool pushBack(double);
      bool insertAt(int, double);
      bool deleteFront();
      bool deleteBack();
      double &elementAt(int)const; // dostęp do itego el
      double & operator[](int);
      void dump() const;
};

Vector::Vector(int size){
      start = new double[size];
      end = start;
      capacity = size;
}
Vector::~Vector(){
      if (start!=nullptr) delete [] start;
      start = nullptr; 
      end = nullptr;
      capacity = 0;
}
int Vector::getSize()const{
      return end-start;
}
bool Vector::reserve(int newCapacity){
      if(newCapacity < capacity) return false; 
      double * tmp = new double[newCapacity];
      if(capacity){//jeśli jest większe niż zero, kopiowanie el. tablicy
            for(int i =0; i<capacity; ++i)tmp[i]=start[i];
            delete [] start;
      }
      end = tmp + (end - start);
      start = tmp;
      return true;
}
bool Vector::pushBack(double v) {
    if(capacity==getSize() && !reserve(capacity+64)) return false;
    start[getSize()]=v; // czyli *end =v
    ++end;
    return true;
}
bool Vector::pushFront(double v) {
      if(capacity==getSize() && !reserve(capacity+64)) return false;
      for(int i=getSize()-1; i>=0;i--)
            start[i+1] = start[i];
      start[0] = v;
      end++;
      return true;
}
bool Vector::insertAt(int where, double v){
      if(capacity==getSize() && !reserve(capacity+64))
            return false;
      if(where>getSize()) where = getSize();

      for(int i = getSize()-1;i>=where; --i)
            start[i+1] = start[i];
      start[where]= v;
      end++;
      return true;     
}
bool Vector::deleteBack(){
      if(getSize()==0) return false;
      end --;
      return true;
}
bool Vector::deleteFront(){
      if(getSize()==0) return false;
      for(int i=1;i<getSize();++i)
            start[i-1] = start[i];
      end --;
      return true;
}
class BadIndex{
public:
      int index;
      BadIndex(int i):index(i){};
};
double & Vector::elementAt(int i) const{
    if(i<0 || i >= getSize()) throw BadIndex(i);
    return start[i];
}
void Vector::dump() const {
    cout<<"[";
    for(int i=0; i<getSize();++i)
        cout<<start[i]<<" ";
    cout<< "]\n";
}


int main(){
    Vector vect;
    for(int i=0;i<5;i++){
        vect.pushFront(i);
        vect.pushBack(i+5);
    }
    vect.insertAt(5,100);
    vect.insertAt(0,100);
    vect.insertAt(1000,100);
    vect.dump();
    for( int i=0;i<6;i++){
        vect.deleteBack();
        vect.deleteFront();
        vect.dump();
    }
    vect.elementAt(0)=-1;
    vect.dump();
      return 0;
}