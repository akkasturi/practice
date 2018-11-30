#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;


void print_vector(vector<int>& nums)
{
  cout<<"Vector Contents["<<nums.size()<<"] { ";
  //for(const int& i : nums){
  //for(auto i = nums.begin(); i != nums.end(); i++){
  //for( vector<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  for( vector<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
   cout<<*i<<" ";
  }
  cout<<"}"<<endl;
}
void vector_example()
{
  vector<int> nums;
  int value;

  cout<<"--------------------------"<<endl;
  nums.push_back(10);
  nums.insert(nums.begin(),9); // via iterator
  nums.insert(nums.begin()+2,11);// At index via iterator
  print_vector(nums);
  nums[0] = 7; //modify via index

  cout<<"After Modification"<<endl;
  print_vector(nums);
  cout<<"After erase"<<endl;
  nums.erase(nums.begin()+1);
  print_vector(nums);
}

/**********************************/
/**********************************/
void print_list(list<int>& nums)
{
  cout<<"List Contents["<<nums.size()<<"] { ";
  //for(const int& i : nums){
  //for(auto i = nums.begin(); i != nums.end(); i++){
  for( list<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  //for( list<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
   cout<<*i<<" ";
  }
  cout<<"}"<<endl;
}

void list_example()
{
  list<int> nums;
  int value;

  cout<<"--------------------------"<<endl;
  nums.push_back(10);
  nums.push_back(11);
  nums.emplace_back(12);
  nums.emplace_front(9);
  nums.insert(nums.begin(),8); // via iterator
 //ERROR: No random access in list:  nums.insert(nums.begin()+2,11);// At index via iterator
  print_list(nums);
 //ERROR: No random access in list:  nums[0] = 7; //modify via index
 cout<<"Pop front and back, one each"<<endl;
 nums.pop_front();
 nums.pop_back();

 print_list(nums);
}

/**********************************/
/**********************************/
void print_fwd_list(forward_list<int>& nums)
{
  cout<<"Forward List Contents { ";
  //for(const int& i : nums){
  //for(auto i = nums.begin(); i != nums.end(); i++){
  for( forward_list<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  //ERROR: for( list<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
   cout<<*i<<" ";
  }
  cout<<"}"<<endl;
}
void fwd_list_example()
{
  forward_list<int> nums;
  int value;

  cout<<"--------------------------"<<endl;
  nums.push_front(10);
  nums.push_front(11);
  nums.emplace_front(12);
 //ERROR: No random access in list:  nums.insert(nums.begin()+2,11);// At index via iterator
  print_fwd_list(nums);
  cout<<"Front element : "<<nums.front()<<endl;

  cout<<"Poping front element "<<endl;
  nums.pop_front();
  print_fwd_list(nums);
  
}

/**********************************/
/**********************************/
void print_deque(deque<int>& nums)
{
  cout<<"Deque Contents["<<nums.size()<<"] { ";
  //for(const int& i : nums){
  //for(auto i = nums.begin(); i != nums.end(); i++){
  //for( deque<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  for( deque<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
   cout<<*i<<" ";
  }
  cout<<"}"<<endl;
}
void deque_example()
{
  deque<int> nums;
  int value;

  cout<<"--------------------------"<<endl;
  nums.push_front(10);
  nums.push_front(11);
  nums.emplace_front(9);
  print_deque(nums);
  nums[0] = 7; //modify via index
  print_deque(nums);

  nums.push_back(12);
  nums.push_back(13);
  nums.emplace_back(14);
  
  print_deque(nums);
  cout<<"\nRemoving from Front and Back, one each\n";
  nums.pop_front();
  nums.pop_back();
  
  print_deque(nums);
}



/**********************************/
/**********************************/
void print_stack(stack<int>& nums)
{
  cout<<"Stack Contents["<<nums.size()<<"] { ";
  //ERROR:for(const int& i : nums){
  //ERROR: for(auto i = nums.begin(); i != nums.end(); i++){
  //ERROR: for( stack<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  //ERROR: for( stack<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
  while(nums.size() > 0){
   cout<<nums.top()<<" ";
   nums.pop();
  }
  cout<<"}"<<endl;
}
void stack_example()
{
  stack<int> nums;
  int value;

  cout<<"--------------------------"<<endl;
  nums.push(10);
  nums.push(11);
  nums.emplace(9);
  print_stack(nums);
}

/**********************************/
/**********************************/
void print_queue(queue<int>& nums)
{
  cout<<"Queue Contents["<<nums.size()<<"] { ";
  //ERROR:for(const int& i : nums){
  //ERROR: for(auto i = nums.begin(); i != nums.end(); i++){
  //ERROR: for( stack<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  //ERROR: for( stack<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
  while(nums.size() > 0){
   cout<<nums.front()<<" ";
   nums.pop();
  }
  cout<<"}"<<endl;
}
void queue_example()
{
  queue<int> nums;
  int value;

  cout<<"--------------------------"<<endl;
  nums.push(10);
  nums.push(11);
  nums.emplace(9);
  cout<<"Front and Back Elements: "<< nums.front() <<","<<nums.back()<<endl;
  print_queue(nums);
}

/**********************************/
/**********************************/
void print_priority_queue(priority_queue<int>& nums)
{
  cout<<"Priority Queue Contents["<<nums.size()<<"] { ";
  //ERROR:for(const int& i : nums){
  //ERROR: for(auto i = nums.begin(); i != nums.end(); i++){
  //ERROR: for( stack<int>::const_iterator i = nums.begin(); i != nums.end(); i++){
  //ERROR: for( stack<int>::const_reverse_iterator i = nums.rbegin(); i != nums.rend(); i++){
  while(nums.size() > 0){
   cout<<nums.top()<<" ";
   nums.pop();
  }
  cout<<"}"<<endl;
}
void priority_queue_example()
{
  priority_queue<int> nums;
  int value;

  cout<<"--------------------------"<<endl;
  nums.push(10);
  nums.push(11);
  nums.emplace(9);
  nums.emplace(987869);
  print_priority_queue(nums);
}

/**********************************/
/**********************************/
template<typename SET>
void print_set(SET& nums)
{
  cout<<"Set Contents["<<nums.size()<<"] { ";
  //for(const int& i : nums){
  //for(auto i = nums.begin(); i != nums.end(); i++){
  for( typename SET::const_iterator i = nums.begin(); i != nums.end(); i++){
   cout<<*i<<" ";
  }
  cout<<"}"<<endl;
}
void set_example()
{
  set<int> nums;
  int value;

  cout<<"--------------------------"<<endl;
  cout<<"set"<<endl;
  nums.insert(10);
  nums.emplace(11);
  nums.emplace(9);
  nums.emplace(987869);
  cout<<"element 1 Found ? "<< (nums.count(1)?"Yes":"No")<<endl;
  print_set<set<int>>(nums);
  
  cout<<"--------------------------"<<endl;
  cout<<"unordered set"<<endl;
  unordered_set<int> nums1;

  nums1.insert(10);
  nums1.emplace(11);
  nums1.emplace(9);
  nums1.emplace(987869);
  
  cout<<"element 10 Found ? "<< (nums1.count(10)?"Yes":"No")<<endl;

  print_set<unordered_set<int>>(nums1);
 
}
/**********************************/
/**********************************/
int main()
{
  //vector_example();
  //list_example();
  //fwd_list_example();
  //deque_example();
 // stack_example();
 //   queue_example();
 //  priority_queue_example();
 set_example();

  return 0;
}

