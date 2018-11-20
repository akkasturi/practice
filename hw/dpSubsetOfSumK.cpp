#include <iostream>
using namespace std;

int findSubsetKSum(int arr[],int size,int sum)
{
  bool subset[size+1][sum+1];
  
  //fill base conditions
  //0 element with j sum.
  for(int j=0; j<sum; j++)
    subset[0][j] = false;

  //i element with 0 sum
  for(int i=0; i<size; i++)
    subset[i][0] = true;

  //d.p. in action
  //i iterates through elements of array/set
  //j iterates through sum
  for(int i=1; i <= size; i++){
    for(int j=1; j <= sum; j++){
      subset[i][j] =                          // for element i and sum j
        (j - arr[i-1] >=0) ?               // if element is less than the sum
            (subset[i-1][j-arr[i-1]] || subset[i-1][j])      //consider the subset of (i-1)th element whose sum adds up to j 
                                                                // OR take the previous j, as it(element) is already considered 
             :subset[i-1][j];                    // current element in arr is greater than j sum, skip it and take previous j 
    }
  }

  //print truth table
  for(int i=1; i <= size; i++){
    for(int j=1; j <= sum; j++){
      cout<<subset[i][j]<<" ";
    }
    cout<<endl;
  }

  return subset[size][sum];
}

int main()
{
  int arr[] = {4,3,2,1};
  //int sum = 15;
  //int sum = 5;
  int sum = 0;
  bool isSubsetPresent  = findSubsetKSum(arr,sizeof(arr)/sizeof(arr[0]),sum);

  cout<<"\nSubset with K set present : "<< (isSubsetPresent ? "Yes":"No")<<endl;
  return 0;
}
