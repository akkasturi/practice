#include <iostream>
#include <stdlib.h>

using namespace std;

class insertionSort
{
  int arr[10];

  public:
  insertionSort();
  ~insertionSort();

  void sort();
};


insertionSort :: insertionSort()
{
  for(int i=0; i < 10; i++)
  {
    arr[i] = rand() % 1000;
  }

  for(int i=0; i < 10; i++)
  {
    cout<<arr[i] <<",";
  }
  cout<<endl;
}

insertionSort :: ~insertionSort()
{
  cout <<endl;
  cout<<"bye Bye"<<endl;
}

void insertionSort :: sort()
{
  int temp  = 0;

  for(int i=0; i < 10; i++)
  {
    for(int j = i+1; j < 10  ; j++)
    {
      if(arr[i] < arr[j])
      {
        temp = arr[i];
        arr[i] =  arr[j];
        arr[j] = temp;
      }
    }
  }

  for(int i=0; i < 10; i++)
  {
    cout<<arr[i] <<",";
  }
  cout<<endl;
}

int main()
{
  insertionSort sortObj;
  sortObj.sort();
}
