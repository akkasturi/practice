#include <iostream>
#include <cstring>

using namespace std;


int findMax(int arr[], int size);
int findLIS(int arr[],
            int size);

int findLIS(int arr[],
            int size)
{
  /* create a list LIS[], which stores the LIS count at every index for that index. Find the Maximum number
   * in that, that'll be our LIS
   */

  /* Algo:
   * For every element in array, check if it is greater than any element starting from 0th index till (current element - 1)
   * if Yes then set the count in LIS list LIS[index] + 1 for current element. Do this only if LIS current element is lesser. 
   */

  int LIS[size];
  memset((void*)LIS,0,size * sizeof(int));
  LIS[0] = 1;// LIS for first element is 1

  for(int current_index = 1; current_index < size; current_index++){
    for(int j = 0; j < current_index; j++){
      if(arr[current_index] > arr[j] && (LIS[current_index] < LIS[j] + 1)){
        LIS[current_index] = LIS[j] + 1;
      }
    }
  }

 cout<<endl;
 for(int i = 0; i<size; i++){
   cout<<LIS[i]<<" ";
 }
 cout<<endl;
 return findMax(LIS,size);
}

int findMax(int arr[], int size)
{
  int max = arr[0];

  for(int i = 1; i < size; i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

int main()
{
  //int arr[] = { 2,4,6,3,5,7,1 };
//  int arr[] = { 1,2,3,4,5,6,7,8,9 };
//  int arr[] = { 9,8,7,6,5,4,3,2,1 };

  int arr[] = { 11,12,13,14,10,1,2,3,6,7,8,9,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,0 };
  //int arr[] = { 2,4,6,3,5,7,9 };
  int size = sizeof(arr)/sizeof(arr[0]);
  int lis = findLIS(arr,size);

  cout<<"\n LIS is : "<< lis<<endl;
  
  return 0;
}

