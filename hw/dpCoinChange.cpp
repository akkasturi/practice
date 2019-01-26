#include <iostream>
using namespace std;

int findNumWaysCoin(int coins[],int size,int num)
{
  int subset[size+1][num+1];
  
  //fill base conditions
  //0 element with j num.
  for(int j=0; j<num; j++)
    subset[0][j] = 0;

  //i element with 0 num
  for(int i=0; i<size; i++)
    subset[i][0] = 1;

  //d.p. in action
  //i iterates through elements of array/set
  //j iterates through num
  for(int i=1; i <= size; i++){
    for(int j=1; j <= num; j++){
      subset[i][j] =                          // for element i and num j
        ((j - coins[i-1] >=0) ?               // if element is less than the num
            (subset[i-1][j-coins[i-1]])      //consider the subset of (i-1)th element whose num adds up to j 
                                                                // OR take the previous j, as it(element) is already considered 
             :0 ) + subset[i-1][j];                    // current element in arr is greater than j num, skip it and take previous j 
    }
  }

  //print truth table
  for(int i=1; i <= size; i++){
    for(int j=1; j <= num; j++){
      cout<<subset[i][j]<<" ";
    }
    cout<<endl;
  }

  return subset[size][num];
}

int main()
{
  int coins[] = {1,2,3};
  //int arr[] = {4,3,2,1};
  //int num = 15;
  //int num = 5;
  int num = 4;
  int numWay  = findNumWaysCoin(coins,sizeof(coins)/sizeof(coins[0]),num);

  cout<<"\nNumber of Ways to get the change of "<< num << " is " <<numWay<<endl;
  return 0;
}
