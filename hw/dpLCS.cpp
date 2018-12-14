#include <iostream>
#include <cstring>

using namespace std;
 
int max(int a, int b); 
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int rLCS( char *X, char *Y, int m, int n ) 
{ 
   if (m == -1 || n == -1) 
     return 0; 

  std::cout<<"\n [M:N] "<<m <<":"<<n <<","<<X[m]<<":"<<Y[n];

   if (X[m] == Y[n]) 
     return 1 + rLCS(X, Y, m-1, n-1); 
   else
     /* No match, now we have to try by decrement both string one at a time and compare, whichever matches takes its value.
      * assume only last character left, and it matched , we'll get 1. 
      * More character left, we'll be calling it recrusively and get the count*/
     return max(rLCS(X, Y, m, n-1), rLCS(X, Y, m-1, n)); 
} 
  
/* Utility function to get max of 2 integers */
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
int 
dpLCS(char *str1, char *str2, int m, int n)
{  

  int LCS[m+1][n+1];
  
  for(int i=0; i < m+1; i++)
    LCS[i][0] = 0; 
  
  for(int j=0;j<n+1;j++)
    LCS[0][j]=0;

  for(int i=1; i<m+1; i++){
    for(int j=1; j<n+1; j++){

      if(str1[i-1] == str2[j-1]){
        /*character matched, LCS of this index is (1 + LCS of string so far i.e. [0 to i-1] , [0 to j-1] )*/
        LCS[i][j] = 1 + LCS[i-1][j-1];
      }else {
        /* no match, copy the max LCS so far*/
        LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
      }
    }
  }

  return LCS[m][n];
}

/* Driver program to test above function */
int main() 
{ 
  //char X[] = "KAMAL"; 
  //char Y[] = "KOAN"; 

  char X[] = "abc"; 
  //char Y[] = "abc"; 
  char Y[] = "def"; 

  /*
  int m = strlen(X) - 1; 
  int n = strlen(Y) - 1 ; 
  
  printf("\nLength of LCS is %d\n", rLCS( X, Y, m, n ) ); 
  */

  int m = strlen(X) ; 
  int n = strlen(Y) ; 
  cout<<endl<<"Length of LCS is: "<<dpLCS(X,Y,m,n)<<endl;
  
  return 0; 
} 

