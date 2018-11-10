#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <typeinfo>

using namespace std;

/* How to represent graph?
 * Many ways !!
 * Vertecies : Array/Vector, Link List, Hash Map. Most common are Array/Vector and Hash_Map
 *             Consider Array/Vector if index of Array/Vector is the Vertex's key. It'll help to directly access the Vertex give the index.
 *             Hash Map benefits if key is not index. still Direct access to Vertex and some other. 
 *             Always consider the application need.
 *
 * Edges: Part of Vertex itself as Array/Vector, Link List, Set, Hash Map. Depends on application need.
 *        Or altogether sepearate Arracy/Vector .... 
 */


struct Vertex{
  int label;
  vector<string> edges;
};

typedef unordered_map<string,Vertex *> myStrVertexUMap;
typedef unordered_map<string,Vertex *>::const_iterator myStrVertexUMapIter;

typedef unordered_map <string,unordered_set<string>> myStrSetUMap;
typedef unordered_map <string,unordered_set<string>>::const_iterator myStrSetUMapConstIter;

void getItenrary(myStrSetUMap &graph);
void dfs(myStrSetUMap &graph);

void getItenrary(myStrVertexUMap &graph)

void printGraph(myStrSetUMap &graph)
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
  
  myStrSetUMap graph;

  //getItenrary(graph);
  dfs(graph);
  
  return 0;
}

/*************************************************/
void getItenraryUtil(myStrSetUMap &graph, const string &city);
void getItenrary(myStrSetUMap &graph)
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

void getItenraryUtil(myStrSetUMap &graph, const string &city)
{
  myStrSetUMapConstIter gIter = graph.find(city);
  
  if(gIter == graph.end()){
    return;
  }

  cout<<gIter->first;

  unordered_set<string>::const_iterator edgeIter = gIter->second.begin();
  cout<< "-->"<< *edgeIter<<endl;
  
  getItenraryUtil(graph,*edgeIter);
}
/*************************************************/


void dfsUtil(myStrSetUMap &graph, string v, unordered_set<string> &visited);
void dfs(myStrSetUMap &graph)
{
  
  graph["one"].emplace("two");
  graph["two"].emplace("three");
  graph["three"].emplace("two");
  graph["two"].emplace("four");
  graph["four"].emplace("four");

  unordered_set<string> visited;

//  myStrSetUMapConstIter gIter = graph.begin();
  cout<<endl<<"DFS : " << endl;

  //DfsUtil(graph,gIter->first,visited);
  dfsUtil(graph,"one",visited);
  cout<< endl;
}

void dfsUtil(myStrSetUMap &graph, string v, unordered_set<string> &visited)
{
  myStrSetUMapConstIter gIter = graph.find(v);
  
  if(gIter == graph.end()){
    return;
  }


  cout << gIter->first<<endl;
  visited.emplace(v);

  unordered_set<string>::const_iterator edgeIter = gIter->second.begin();
  for(; edgeIter != gIter->second.end(); ++edgeIter){
    if(visited.count(*edgeIter) > 0 ){
      cout<<"Already visited : " << *edgeIter<< endl;
      continue;
    } 
    dfsUtil(graph,*edgeIter,visited);
  }

}

/*************************************************/
void getItenraryUtil(myStrVertexUMap &graph, const string &city);
void addEdge(myStrVertexUMap &graph,string from, string to);

void getItenrary(myStrVertexUMap &graph)
{
  //Assumptions:
  // i) all cities are connected atleast to 1 city 
  // ii) no back edge/loop
  // iii) starting city exists
  int label = 101;
  //Add Vertecies first.
  graph["pune"].emplace(new Vertex({label++}));
  graph["delhi"].emplace(new Vertex({label++}));
  graph["hyderabad"].emplace(new Vertex({label++}));

  addEdge(graph,"pune","delhi");

  //printGraph(graph);

  cout<<"\nItenrary : "<<endl;
  getItenraryUtil(graph,"pune");
  cout<<endl;
  
}

void addEdge(myStrVertexUMap &graph,string from, string to)
{
  //Assume both from and to vertecies exist.

  myStrVertexUMapIter gIter = graph.find(from);

  gIter->second.edges.push_back(to);
}

void getItenraryUtil(myStrVertexUMap &graph, const string &city)
{
  myStrVertexUMapIter gIter = graph.find(city);
  
  if(gIter == graph.end()){
    return;
  }

  cout<<gIter->first;

  vector<string>::const_iterator edgeIter = gIter->second.begin();
  cout<< "-->"<< edgeIter->second->edges[0] <<endl;
  
  getItenraryUtil(graph, edgeIter->second->edges[0]);
}
