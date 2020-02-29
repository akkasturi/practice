#include <iostream>


void modulus()
{
  int i = 0;

  for(i=0; i<=10; i++)
  {
    if( (i&1) == 1){
      std::cout<<i<<" is odd."<<std::endl;
    }
    else{
      std::cout<<i<<" is even."<<std::endl; 
    }
  }
}

void shift0()
{
  printf("\nShift 1 by zero:%u\n",(unsigned int) (1<<0));
}


int main()
{
  //modulus();
  shift0();
  return 0;
}
