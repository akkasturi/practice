#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <typeinfo>
#include <queue>

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

/***********************************/
/***********************************/
struct Vertex{
  int age;
  vector<string> edges;
};

typedef unordered_map<string,Vertex *> myStrVertexUMap;
typedef unordered_map<string,Vertex *>::const_iterator myStrVertexUMapIter;

void printGraph(myStrVertexUMap &graph);
void addEdge(myStrVertexUMap &graph,string from, string to);
void createAndFindFriendship(myStrVertexUMap graph);
bool findFriendshipUtil(myStrVertexUMap graph,string friendA, string friendB);


/***********************************/
/***********************************/
void addEdge(myStrVertexUMap &graph,string from, string to)
{
  //Assume both from and to vertecies exist.

  myStrVertexUMapIter gIter = graph.find(from);

  gIter->second->edges.push_back(to);
}

void printGraph(myStrVertexUMap &graph)
{
  Vertex *v;
  cout <<"\nKey-->Value(s): "<<endl;
  cout <<"----------------"<<endl;
  for(auto it = graph.begin(); it != graph.end(); ++it){
    cout <<it->first;

    v = it->second;
    vector<string>::const_iterator edgeIter = v->edges.begin();
    cout<< " --> ";
    for( auto edge = v->edges.begin(); edge != v->edges.end(); ++edge){
      cout<< *edge <<",";    
    }
    cout<<endl;
  }
  cout<<endl;
}

/*Create friendship graph and find friendship between two people*/
void createAndFindFriendship(myStrVertexUMap graph)
{
  //create people
  graph.emplace("Amar", new Vertex({30}));
  graph.emplace("Akbar", new Vertex({28}));
  graph.emplace("Anthony", new Vertex({32}));
  graph.emplace("Vijay", new Vertex({23}));
  graph.emplace("Dinanath", new Vertex({23}));
  graph.emplace("Chauhan", new Vertex({23}));

  //create friendship graph
  addEdge(graph,"Amar","Akbar");
  addEdge(graph,"Amar","Anthony");
  addEdge(graph,"Anthony","Vijay");
  addEdge(graph,"Vijay","Dinanath");
  addEdge(graph,"Dinanath","Chauhan");

  printGraph(graph);

  bool friends = findFriendshipUtil(graph,"Amar","Dinanath");
  cout<<"Friends ? " << (friends ? "Yes":"No") << endl;
  
  friends = findFriendshipUtil(graph,"Akbar","Dinanath");
  cout<<"Friends ? " << (friends ? "Yes":"No") << endl;
}

/* Find friendship */
bool findFriendshipUtil(myStrVertexUMap graph,string friendA, string friendB)
{
  unordered_set<string> visited;
  queue<string> friendQueue;
  string f;

  cout<<"\nFinding friendship between "<<friendA <<" and " <<friendB<<endl;
  friendQueue.push(friendA);

  while(!friendQueue.empty()){
    f = friendQueue.front();
    visited.emplace(f);

    cout<<"\tProcessing Friend: "<<f<<endl;
    
    if(f == friendB){
      return true;
    }

    myStrVertexUMapIter gIter = graph.find(f);
    
    if(gIter == graph.end()) return false;

    Vertex *v = gIter->second;
    
    //queue all edges if not already visited.
    for(auto edge = v->edges.begin(); edge != v->edges.end(); ++edge){
      if(visited.count(*edge) > 0 ) continue;
      friendQueue.push(*edge);
    }
    friendQueue.pop();
  }

  return false;
}


int main()
{
  myStrVertexUMap graph;
  createAndFindFriendship(graph);
  return 0;
}
