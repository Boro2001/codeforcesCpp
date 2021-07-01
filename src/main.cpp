#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main(){

      int n=424;
      int *length = new int[n];
      int *array = new int[n]; for(int i = 0; i < n; ++i) array[i] = rand()%20;
      
      for(int i = 0; i < n; ++i){
            length[i] = 1;
            for(int j = 0; j < i; ++j)
                  if(array[j] < array[i])
                        length[i] = max(length[i], length[j]+1);
      }
      int max = 0;
      for(int i = 0; i < n; ++i) max = (length[i] > max) ? length[i] : max;
      for(int i = 0; i < n; ++i)cout<< array[i] << "\t";
      cout<<max; 
      return 0;
}