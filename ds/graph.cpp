#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <typeinfo>

using namespace std;
struct node{
  string data;
  int weight;
};

typedef unordered_map <string,unordered_set<string>> myStrSetUGraph;
typedef unordered_map <string,unordered_set<string>>::const_iterator myStrSetUGraphConstIter;

void getItenrary(myStrSetUGraph &graph);

void printGraph(myStrSetUGraph &graph)
{
  for(auto it = graph.begin(); it != graph.end(); ++it){
    cout <<"Key/Value(s): "<< it->first << "/";

    unordered_set<string> &edges = it->second;
    for( auto edge = edges.begin(); edge != edges.end(); ++edge){
      cout<< *edge <<",";    
    }
    cout<<endl;
  }
}

int main()
{
//  unordered_map <string,string> graph;
  //unordered_map <string,unordered_set<string>> graph;
  
  myStrSetUGraph graph;

  getItenrary(graph);

  
  return 0;
}

void getItenraryUtil(myStrSetUGraph &graph, const string &city);
void getItenrary(myStrSetUGraph &graph)
{
  //Assumptions:
  // i) all cities are connected atleast to 1 city 
  // ii) no back edge/loop
  // iii) starting city exists

  graph["pune"].emplace("delhi");
  graph["delhi"].emplace("hyderabad");
  graph["hyderabad"].emplace("bangalore");

  printGraph(graph);

  cout<<"\nItenrary : "<<endl;
  getItenraryUtil(graph,"pune");
  cout<<endl;
  
}

void getItenraryUtil(myStrSetUGraph &graph, const string &city)
{
  myStrSetUGraphConstIter gIter = graph.find(city);
  
  if(gIter == graph.end()){
    return;
  }

  cout<<gIter->first;

  unordered_set<string>::const_iterator edgeIter = gIter->second.begin();
  cout<< "-->"<< *edgeIter<<endl;
  
  getItenraryUtil(graph,*edgeIter);
}


/*
void dfs(myStrSetUGraph &graph)
{
  
  unordered_set<string> visited;

  dfsUtil(graph,visited);
}

void dfsUtil(myStrSetUGraph &graph, unordered_set &visited
*/
