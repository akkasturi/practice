#include <stdio.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */
int mice(int* A, int n1, int* B, int n2) {
    int i = 0;
    int j = 0;
    int min = 0XFFFFFFFF;
    int max = 0;
    int temp = 0;
    int distance = 0;
    
    //sort holes first
    for(;i<n2-1;i++)
    {
        for(j=0;j<n2-i-1;j++)
        {
            if(B[j] > B[j+1])
            {
                temp = B[j];
                B[j] =  B[j+1];
                B[j+1] = temp;
            }
        }
    }
    for(i=0;i<n2-1;i++)
    {
        for(j=0;j<n2-i-1;j++)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] =  A[j+1];
                A[j+1] = temp;
            }
        }
    }

    printf("\n");
    for(i=0; i<n1; i++)
    {
      printf("%d ",B[i]);
    }
    printf("\n");
    for(i=0; i<n1; i++)
    {
      printf("%d ",A[i]);
    }


    for(i=0; i<n1; i++)
    {

      distance = A[i]-B[i];
      if(distance < 0) distance *= -1;

      max =  distance > max ? distance:max;

      /*min = 0X0FFFFFFF;
        for(j=0; j<n2; j++)
        {
        distance = A[i]-B[j];
        if(distance < 0) distance *= -1;
        min = distance < min?distance:min;
        }
        max = min > max? min:max;
        printf("\nMin/Max[%d:%d/%d]",i,min,max);
        */
        printf("\nMax[%d:%d]",i,max);
    }
    printf("\n-------------------------------\n");
    
    return max;
}

int main()
{
  int A[] = 
             //{4, -4, 2 };
              {-49, 58, 72, -78, 9, 65, -42, -3};
  int B[] = 
            //{4, 0, 5 };
            {30, -13, -70, 58, -34, 79, -36, 27};

  mice(A,(sizeof(A)/sizeof(int)),B,(sizeof(B)/sizeof(int)));
  return 0;
}

