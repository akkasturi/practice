#include <stdio.h>
int main()
{
  int i = 0xFFFFFF00;
  char *c = (char*)&i;
  printf("\n%d\n",*c);


  return 0;
}
