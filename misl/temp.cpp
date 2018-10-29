#include <iostream>
using namespace std;

int main()
{
  const  int i = 5;
  int arr[i];
  int arr1[i];
  cout<<sizeof(arr)/sizeof(*arr)<<":"<<sizeof(arr1)/sizeof(*arr)<<endl;
  return 0;
}
