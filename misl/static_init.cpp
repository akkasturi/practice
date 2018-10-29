#include <iostream>
using namespace std;

int i = 100;

class A
{
  static int i;
  static int j;
  public:
  A()
  {
    cout<<i<<" " <<j<<endl;
  }
};

int A::i=20;
int A::j = i + 1;
int main()
{
  A a;

}
