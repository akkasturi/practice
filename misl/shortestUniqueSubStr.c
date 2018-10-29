#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getShortestUniqueSubstring(char *arr, int arrLength, char *str, char *out) ;
unsigned long
hash(  char *str, int len);

unsigned long
hash1(  char *str, int len);

unsigned long
hash1(  char *str, int len)
{
        unsigned long hash = 0;
        int c;

        while (len--)
        {
           c = *str;
          str++;
          hash = hash + c;
        }

        return hash;
    }


unsigned long
hash(  char *str, int len)
{
        unsigned long hash = 5381;
        int c;

        while (len--)
        {
           c = *str;
          str++;
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        }

        return hash;
    }

void getShortestUniqueSubstring(char *arr, int arrLength, char *str, char *out) 
{
  // your code goes here  
  unsigned long arrHash =  hash1(arr,arrLength);
  char *tempStr =  str;
  unsigned long strHash = 0;
  int strLen = strlen(str);
  int pos = 0;
  
  while(1)
  {
    if( (pos + arrLength) > strLen ) 
    {
      out[0] = 0;
      return;
    }
    
    strHash = hash1(&tempStr[pos],arrLength);
    if(arrHash == strHash)
    {
      strncpy(out,&tempStr[pos],arrLength);
      out[arrLength+1]='\0';
      return;
    }
    pos ++;
  }
}

int main() {
  char arr[]  = {'x','y','z'};
  char out[10];
//  getShortestUniqueSubstring(arr,sizeof(arr),"yzx",out);
getShortestUniqueSubstring(arr,sizeof(arr),"xyyzyzyx",out);
  printf("\n%s\n",out);
  return 0;
}
