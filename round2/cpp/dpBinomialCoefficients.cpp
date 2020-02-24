#include <iostream>

using std::cout;
using std::endl;

//skiena 279, search google.
int binomialCoeff(int n, int k)
{
  if (k == 0 or k == n) return 1; //base condition

  return (binomialCoeff(n-1,k-1) + binomialCoeff(n-1,k));
}


int dpBinomialCoefficient(int n, int k)
{
  const int MAX_M = 10;
  const int MAX_N = 10;

  int bc[MAX_M+1][MAX_N+1]; // +1 is needed as first column has taken base condition ie. all 1's and n==10 and k ==10 can be equal to max.

  //initialize base cases. i.e. k == 0 is 1 and k==n is 1
  for(int i=0; i<=MAX_M; i++) bc[i][0] = 1;
  for(int j=1; j<=MAX_N; j++) bc[j][j] = 1;

  //fill Pascle triangle now.
  for(int i=1; i<=MAX_M; i++)
    for(int j=1; j<i; j++)
      bc[i][j] = bc[i-1][j-1] + bc[i-1][j];

  return bc[n][k];
}

int main()
{

  int n = 10;
  int k = 5;

  int res = binomialCoeff(n,k);
  cout<<"Binomial Coefficient for (n,k):("<<n <<"," <<k <<"): "<<res<<endl;
  res = dpBinomialCoefficient(n,k);
  cout<<"Binomial Coefficient for (n,k):("<<n <<"," <<k <<"): "<<res<<endl;
}
