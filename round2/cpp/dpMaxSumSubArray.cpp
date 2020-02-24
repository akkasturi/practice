#include <iostream>
#include <limits>

using std::cout;
using std::endl;


int noDpMaxSubarraySum(int *arr, int len);

int noDpMaxSubarraySum(int *arr, int len)
{
  int sum = 0;
//  int maxSum = static_cast<int>(0x80000000); // max -ve integer. array might have only -ve numbers.
  int maxSum =  std::numeric_limits<int>::min();

  //Go through each sub array and keep updating the maximum sum.
  for(int i=0; i<len; i++){ 
    sum = 0;
    
    //0..(n-1), 1..(n-1) and so on
    for(int j=i; j<len; j++){
      sum += arr[j];
      if(sum > maxSum) maxSum = sum;
    }
  }

  return maxSum;
}

int recursiveMaxSubarraySum(int *arr, int len, int currIndex, int *maxSum)
{

  if(currIndex == (len-1)) {
    *maxSum = arr[currIndex];
    return arr[currIndex];
  }

  int sum  = recursiveMaxSubarraySum(arr,len,(currIndex+1),maxSum);
   
  sum += arr[currIndex];
  if(sum > *maxSum) *maxSum = sum;

  return sum;
}

int main()
{
  int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
  int arr1[] = {-2, -5, -6, -2, -3, -1, -5, -6};
  int arr2[] = {1,2,3,4,5};

  int maxSum = noDpMaxSubarraySum(arr1, (sizeof(arr1)/sizeof(arr1[0])));

  cout<<"Max Sum of sub array is : "<< maxSum << endl;
  int sum = recursiveMaxSubarraySum(arr2, (sizeof(arr2)/sizeof(arr2[0])),0, &maxSum);
  cout<<"Sum : "<<sum <<endl;

  sum = recursiveMaxSubarraySum(arr1, (sizeof(arr1)/sizeof(arr1[0])),0, &maxSum);
  cout<<"Max Sum of sub array is : "<< maxSum << endl;
  cout<<"Sum : "<<sum <<endl;

  int d = (-1) + (-1);
  int e = (-1) - (-1);
  cout<<endl<<d;
  cout<<endl<<e;
}
