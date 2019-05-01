#include <iostream>
#include <vector>

struct S{
  int i;
};

int main()
{
  S s1 = {10};
  S s2 = {20};
  std::vector<S> s = {s1,s2};
  std::vector<S*> sptr = {&s1,&s2};

  for(S ts : s) std::cout<<ts.i<<'\n';
  for(S *ts : sptr) std::cout<<ts->i<<'\n';
  return 0;
}
