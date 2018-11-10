#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
minof(int a, int b, int c)
{
  if(a < b && a < c) return a;
  if(b < a && b < c) return b;
  if(c < b && c < a) return c;

  return a; // all are equal, return any
}

int 
dynamicEditDistance(char *str1, char *str2)
{
    int row = strlen(str1) + 1 ;
    int col = strlen(str2) + 1;
    int i = 0;
    int j = 0;

    int **distanceMatrix = (int **)malloc(row * sizeof(int *)); 
    for (i=0; i<row; i++) 
         distanceMatrix[i] = (int *)malloc(col * sizeof(int)); 


    for(i = 0; i<col; i++)
    {
      distanceMatrix[0][i] = i;
    }
    
    for(i = 0; i<row; i++)
    {
      distanceMatrix[i][0] = i;
    }

    for(i=1; i<row; i++)
    {
      for(j=0; j<col; j++)
      {
        if(str1[i-1] == str2[j-1])
        {
          distanceMatrix[i][j] = distanceMatrix[i-1][j-1];
        }
        else
        {
          distanceMatrix[i][j] = 1 + minof(distanceMatrix[i-1][j-1],distanceMatrix[i-1][j],distanceMatrix[i][j-1]);
        }
      }
    }

    
    for(i = 0; i<row; i++)
    {
      printf("\n");
      for(j = 0; j<col; j++)
      {
        printf("%d ",distanceMatrix[i][j]);
      }
    }
    printf("\n");

    return distanceMatrix[row-1][col-1];
}

int main()
{
//char *str1 = "azced";
  //char *str2 = "abcdef";
  char *str1 = "same but different";
  char *str2 = "lame but similar";
  int res = dynamicEditDistance(str1,str2);
  printf("\nDistance : %d\n",res);

  return 0;
}

