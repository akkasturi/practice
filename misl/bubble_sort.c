#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;   
}

int main()
{
  int arr[10] = {3,5,7,8,1,0,10,6,2,4};
  int i=0;
  int j=0;

  for(; i<10; i++)
  {
    for(j=0; j<10-i-1; j++)
    {
      if(arr[j+1] < arr[j])
      {
        swap(&arr[j+1] , &arr[j]);
      }
    }
  }

  printf("\n");
  
  for(i=0; i<10; i++)
  {
    printf("%d ",arr[i]);
  }
  
  printf("\n");
  return 0;
}
