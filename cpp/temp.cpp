#include <iostream>
#include <string>
using namespace std;

int main()
{

  int i{0};
  int k = 9.0;
  int j{9.0};
#if 0
  string prev = "";
  string current;
  while(cin>>current){
    if(current == prev)
      cout<<"Repeated word: "<<current<<'\n';
    prev=current;
  }
#endif

#if 0
  cout << "Please enter your first name and age\n";
  string first_name; // string variable
  int age; // integer variable
  cin >> first_name; // read a string
  cin >> age; // read an integer
  cout << "Hello, " << first_name << " (age " << age << ")\n";
#endif
}
