#include <stdio.h>
#define MAX_ARR  7

void print_arr(int arr[])
{
  int i=0;
  printf("\n");

  for(;i<MAX_ARR; i++)
    printf(" %d",arr[i]);
  
  printf("\n");
}

void swap(int arr[],
          int l_index,
          int r_index)
{
  int temp = arr[r_index];
  arr[r_index] = arr[l_index];
  arr[l_index] = temp;
}

int partition(int arr[],
              int left,
              int right,
              int pivot)
{
  int l_index = left - 1;
  int r_index = right;

  while(1)
  {
    while(arr[++l_index] < pivot){/* do nothing*/}
    
    while(r_index > 0 && arr[--r_index] > pivot){/* do nothing*/ } 

    if(l_index >= r_index) break;
    else
    {
      swap(arr,l_index,r_index);
    }
  }
      
  swap(arr,l_index,right);

  return l_index;
}

int partition_pivot_first(int arr[],
              int left,
              int right,
              int pivot)
{
  int l_index = left ;
  int r_index = right+1;

  while(1)
  {
    while(arr[++l_index] < pivot){/* do nothing*/}
    
    while(r_index > 0 && arr[--r_index] > pivot){/* do nothing*/ } 

    if(l_index >= r_index) break;
    else
    {
      swap(arr,l_index,r_index);
    }
  }
      
  swap(arr,left,r_index);

  return r_index;
}
void quicksort(int arr[],
               int left,
               int right)
{
  int mid = 0;

  if(left >= right) return;

//  mid = partition(arr,left,right,arr[right]);
  mid = partition_pivot_first(arr,left,right,arr[left]);

  quicksort(arr,left,mid-1);
  quicksort(arr,mid+1,right);
}
void quickSort(int arr[], int low, int high)
{
    while (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high,arr[low]);
 
        // If left part is smaller, then recur for left
        // part and handle right part iteratively
        if (pi - low < high - pi)
        {
            quickSort(arr, low, pi - 1);
      //      low = pi + 1;
        }
 
        // Else recur for right part
        else
        {
            quickSort(arr, pi + 1, high);
        //    high = pi - 1;
        }
    }
}

int main()
{
  //int arr[MAX_ARR] = {45,80,30,90,40,50,70};
  int arr[MAX_ARR] = {1,2,3,4,5,6,7};
  //int arr[MAX_ARR] = {7,6,5,4,3,2,1};

  print_arr(arr);
 // partition_pivot_first(arr,0,6,45);
 quickSort(arr,0,MAX_ARR-1);
//quicksort(arr,0,MAX_ARR-1);
  print_arr(arr);
}
