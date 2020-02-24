#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;


// DP version caching the result
int fib(int n,std::unordered_map<int,int> &fibCache)
{
  if(n <= 1) return n;

  if(!fibCache.count(n)){
    fibCache[n] = fib(n-1,fibCache) + fib(n-2,fibCache);
  }

  return fibCache[n];
}

int noDpFib(int n)
{
  if(n <= 1) return n;
  return (noDpFib(n-1) + noDpFib(n-2));
}

// DP version, with last 2 variables only.
int dpFibLastTwoVar(int n)
{
  int curr = 0;
  int n_2 = 0; // n-2 place's value
  int n_1 = 1; // n-1 place's value

  for(int i=2; i<n; i++) // loops till <n, as actual result is counted outside the loop. take 2,3 as n to understand.
  {
    curr = n_2 + n_1;
    n_2 = n_1;
    n_1 = curr;
  }


  return (n_1 + n_2);
}


int noDpFact(int n, int fact)
{
  if(n <= 0) return 1;
  if(n <= 2 ) return n;

  return (n * noDpFact(n-1,1)); 
}

// DP version caching the result
int fact(int n, std::unordered_map<int,int> &factCache)
{
  if(n <= 0) return 1;
  if(n <= 2 ) return n;

  if(!factCache.count(n)){
    factCache[n] = n * fact(n-1,factCache);
  }

  return factCache[n];
}

int main()
{
  std::unordered_map<int,int> fibCache;
  
  fibCache[0] = 0;
  fibCache[1] = 1;

  int num = 6;
  int result = fib(num,fibCache);
  cout<<"Fibonacci of Number "<< num <<": "<< result <<endl;
  result = noDpFib(num);
  cout<<"Fibonacci of Number "<< num <<": "<< result <<endl;
  
  result = dpFibLastTwoVar(num);
  cout<<"Fibonacci of Number "<< num <<": "<< result <<endl;



  num = 7;
  result = noDpFact(num,1);
  cout<<"Factorial of Number "<< num <<": "<< result <<endl;

  std::unordered_map<int,int> factCache;
  result = fact(num,factCache);
  cout<<"Factorial of Number "<< num <<": "<< result <<endl;
}
