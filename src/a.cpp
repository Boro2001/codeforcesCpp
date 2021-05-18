#include <iostream>

using namespace std;

// kontenery - 9. wykład - wektor lista kolejka stos zbior i wielozbior słownik map 

class Vector{
	protected:
	double * start, * end;
	int capacity;
	bool reserve(int newCapacity);

	public:
	Vector(int size = 0);
	~Vector();
	int getSize() const;
	bool pushFront(double v);
	bool pushBack(double v);
	bool instertAt(int where, double v);
	bool deleteFront();
	bool deleteBack();
	double & elementAt(int i)const;
	void dump()const;
};
Vector::Vector(int size):start(0),end(0),capacity(0){
	if(size>0){
	start = new double[size];
	capacity=size;
	end=start;
	}
}
Vector::~Vector(){
 if (start!=0)delete []start;
 start=end=0;
 capacity=0;
}
int Vector::getSize()const{
 return end-start;
}

int n