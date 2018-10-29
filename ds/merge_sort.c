#include <stdlib.h>
#include <stdio.h>

int merge(int a[], int start, int mid, int end);

int min(int x, int y) { return (x<y)? x :y; } 

void mergeSort(int arr[], int n)
{
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray
                   // to be merged

   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting
           // point of right
           int mid = left_start + curr_size - 1;

           int right_end = min(left_start + 2*curr_size - 1, n-1);

           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
}

int merge2(int a[], int start, int mid, int end){
  int set1_index = start;
  int set1_end = mid;
  int set2_index = mid+1;
  int temp_arr[end - start + 1];
  int index = 0;
  int i = 0;
  int inv_count = 0;

  // copy the sorted values to temp array
  // possible one array would exhaust first
  // after while copy the second array to temp 
  while(set1_index <= mid){
    if(a[set1_index] < a[set2_index]){
      temp_arr[index] =  a[set1_index];
      index++;
      set1_index++;
    }
    else {
      temp_arr[index] =  a[set2_index];
      index++;
      set2_index++;
      inv_count += (mid - set1_index + 1);
    }
    if(set2_index > end) break;
  }

  while(set1_index <= mid){
    temp_arr[index] = a[set1_index];
    set1_index++;
    index++;
  }

  while(set2_index <= end){
    temp_arr[index] = a[set2_index];
    set2_index++;
    index++;
  }

  index =0;
  for(i = start;i <= end; i++)
  {
    a[i] = temp_arr[index++];
  }
  return inv_count;
}

int merge(int a[], int start, int mid, int end){
  
    int i,j,k;
    int temp[end-start+1];
  
    i = start; j = mid+1; k =0;
    /* Compare all elements of two sorted arrays and store
      them in sorted array. */
    while(i <= mid && j <= end){
        if(a[i]< a[j]){
            temp[k++]= a[i++];
        }
        else {
            temp[k++]  = a[j++];
        }
    }
    while(i <= mid){
        temp[k++] = a[i++]; 
    }
    while(j <= end){
        temp[k++] = a[j++]; 
    }
    //Copy the temporary array into original array
    for(i=0; i<k; i++){
        a[i+start] = temp[i];
    }
}
int mergeSort1(int a[], int start, int end ){
  
    int mid  = (start + end)/2;
    int inv_count = 0;
    if(start<end){
        //sort the left part
        inv_count = mergeSort1(a, start, mid);
        //sort right part
        inv_count += mergeSort1(a, mid+1, end);
  
        //merge them together
        inv_count += merge2(a, start, mid, end);
    }
    return inv_count;
}
int main(){
     //int a[] = {25,15,16,19,2,5,30};
     int a[] = { 1, 20, 6,5, 4, 5,5 };
//     int a[] = {2,4,1,3,5};
    //int a[] = {2,3,4,1,8,7,6,9};
    int size = sizeof(a)/sizeof(a[0]);
  
    //mergeSort(a,  size);
    int inv_count = mergeSort1(a, 0, size-1);
    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\nInv Count : %d\n",inv_count);

}
