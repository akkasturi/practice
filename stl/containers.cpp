#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;


void print_vector(vector<int>& nums)
{
  cout<<endl<<"Vector Contents { ";
  //for(const int& i : nums){
  //for(auto i = nums.begin(); i != nums.end(); i++){
  //for( vector<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  for( vector<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
   cout<<*i<<" ";
  }
  cout<<"}"<<endl<<endl;
}
void vector_example()
{
  vector<int> nums;
  int value;

  nums.push_back(10);
  nums.insert(nums.begin(),9); // via iterator
  nums.insert(nums.begin()+2,11);// At index via iterator
  print_vector(nums);
  nums[0] = 7; //modify via index

  cout<<"After Modification"<<endl;
  print_vector(nums);
}

/**********************************/
/**********************************/
void print_list(list<int>& nums)
{
  cout<<endl<<"List Contents { ";
  //for(const int& i : nums){
  //for(auto i = nums.begin(); i != nums.end(); i++){
  for( list<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  //for( list<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
   cout<<*i<<" ";
  }
  cout<<"}"<<endl<<endl;
}
void list_example()
{
  list<int> nums;
  int value;

  nums.push_back(10);
  nums.push_back(11);
  nums.insert(nums.begin(),9); // via iterator
 //ERROR: No random access in list:  nums.insert(nums.begin()+2,11);// At index via iterator
  print_list(nums);
 //ERROR: No random access in list:  nums[0] = 7; //modify via index
}

/**********************************/
/**********************************/
void print_fwd_list(forward_list<int>& nums)
{
  cout<<endl<<"Forward List Contents { ";
  //for(const int& i : nums){
  //for(auto i = nums.begin(); i != nums.end(); i++){
  for( forward_list<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  //ERROR: for( list<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
   cout<<*i<<" ";
  }
  cout<<"}"<<endl<<endl;
}
void fwd_list_example()
{
  forward_list<int> nums;
  int value;

  nums.push_front(10);
  nums.push_front(11);
 //ERROR: No random access in list:  nums.insert(nums.begin()+2,11);// At index via iterator
  print_fwd_list(nums);
 //ERROR: No random access in list:  nums[0] = 7; //modify via index
}
int&& foo()
{
  return 2;
}
int main()
{
//  vector_example();
//  list_example();
  fwd_list_example();

  return 0;
}

