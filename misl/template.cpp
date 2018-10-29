#include <iostream>
using namespace std;

template<class T, int size = 10>
class Array {
  T arr[size];
  int currIndex;
  public:

  Array() : currIndex(0) {}

  T& operator [] (int index)
  {
    return arr[index];
  }

  T operator = (T val)
  {
    arr[currIndex] = val;
    currIndex++;
    return arr[currIndex - 1]; 
  }

};

int main()
{
  Array<int,10> myArrI;
  Array<float,10> myArrF;

  for(int i=0; i < 10; i++)
    myArrI[i] = i*10;

  for(int i=0; i < 10; i++)
    myArrF[i] = 1.1F*i;

  cout << endl;

  for(int i=0; i < 10; i++)
     cout<<" " <<myArrI[i];

  cout << endl;
  for(int i=0; i < 10; i++)
     cout<<" " <<myArrF[i];

  cout << endl;
  return 0;
}
