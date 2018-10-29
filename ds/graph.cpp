#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <typeinfo>

using namespace std;
struct node{
  string data;
  int weight;
};

int main()
{
//  unordered_map <string,string> graph;
  unordered_map <string,unordered_set<string>> graph;
  graph["pune"].emplace("delhi");
  graph["delhi"].emplace("hyderabad");
  graph["hyederabad"].emplace("pune");
  graph["delhi"].emplace("bangalore");

  for(auto it = graph.begin(); it != graph.end(); ++it){
    cout <<"Key/Value(s): "<< it->first << "/";
    
    unordered_set<string> &edges = it->second;
    for( auto edge = edges.begin(); edge != edges.end(); ++edge){
      cout<< *edge <<",";    
    }
    cout<<endl;
  }

  return 0;
}
