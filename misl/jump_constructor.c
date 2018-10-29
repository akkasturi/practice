#include <iostream>
using namespace std;

class A
{
  public:
    A();
};

int main()
{
  int i = 0;
  switch(i)
  {
    case 0:
      A a;
      break;
    case 1:
      A a1;
      break;
    default:
      break;
  }
}
