#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;


/* Vertex/Node */
struct Node{
  int value;
  list<struct Node*> edges;
};

/* whole Graph */
class Graph{
  public:
    void createNodes();
    void createNodes(int arr[],int size);
    bool addEdge(int from,int to);
    void dfs();
    void dfsUtil(set<int> visited, int index);
    void bfs();
    void maxArmyMen();
    void dfsTopologicalSort();
    void dfsTopologicalSortUtil(set<int>& visited,stack<int>& nodes_stack, int index);

    void processNode(int index);
    bool isValidNode(int index);
    void printNodes();

  private:
  enum { MAX_NODES = 6 };
  vector<Node *> graph; //dynamic array of nodes, index of array represents the node index. 
};

void Graph::createNodes()
{
  graph.emplace(graph.begin(),nullptr); // 0th index not valid


  for(int i=1; i<=MAX_NODES; i++){
    Node *n = new Node({i});
    graph.emplace((graph.begin()+i),n); //insert at index i
  }
}

void Graph::createNodes(int arr[],int size)
{
  graph.emplace(graph.begin(),nullptr); // 0th index not valid

  for(int i = 1; i <=size; i++){
    Node *n = new Node({i});
    graph.emplace((graph.begin()+i),n); //insert at index i
  }
}

bool Graph::addEdge(int from, int to)
{
  /*Check both nodes should exist, else return failure*/
  if( (from < 0 || from > graph.size()) || 
        (to < 0 || to > graph.size())){
    return false;
  }

//  cout<<"Adding Edge From : "<< from <<", To : "<< to <<endl;
  //add edge
  graph[from]->edges.push_back(graph[to]);

  return true;
}

void Graph::printNodes()
{
  cout<<"Graph nodes:"<<endl;

  for(auto node = graph.begin()+1; node != graph.end(); node++){
    cout<<"\tNode: "<<(*node)->value<<", Edges :  ";
    
    //print edges for current node
    for(Node* &i : (*node)->edges){
      cout<<i->value<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}

void Graph::processNode(int index)
{
  cout<<"\tProcessing Node : "<<graph[index]->value<<endl;
}

bool  Graph::isValidNode(int index)
{
  if( index > 0 &&
      index < graph.size()) return true;

  return false;
}


/***********************************/
void Graph::dfs()
{
  set<int> visited;
  cout<<"DFS: "<<endl;
  dfsUtil(visited,1);
}

void Graph::dfsUtil(set<int> visited, int index)
{
  if(!isValidNode(index)) return;

  processNode(index);

  //mark node visited.
  visited.emplace(index);

  //process edges
  for(Node * &edgeNode : graph[index]->edges){
    //already visited the node, skip it.
    if(visited.count(edgeNode->value) > 0) continue;

    dfsUtil(visited,edgeNode->value);
  }
}

/***********************************/
void Graph::bfs()
{
  set<int> visited;
  queue<int> q;
  int index = 0;

  cout<<"BFS: "<<endl;
  q.push(1); //first node value.

  while(!q.empty()){
    index = q.front();

    visited.emplace(index);
    processNode(index);
    q.pop();

    //process edges
    for(Node* &edgeNode : graph[index]->edges){
      // node already visited, skip it
      if(visited.count(edgeNode->value) > 0) continue;

      //queue the node
      q.push(edgeNode->value);
    }
  }
}

/***********************************/
void Graph::maxArmyMen()
{
  //problem statement at
  //https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/containers-of-choclates-1/
  set<int> visited;
  queue<int> army[2];
  int index = 0;
  int components = 0;
  int currentArmy = 0; // 0 armyA, 1 armyB
  int cCount[] = {0,0};

  /* Logic:
   * There could be disjoint components, for loops takes care of iterating through all the components.
   * Internal while loops go through a whole component (sub graph)
   * Maintain 2 Army queue one for each army
   * Duel can be between men of opposite armies, so egdes going out from one nodes belongs to men of  different armies.
   * While processing a node store its opponents to other queue and also keep the count 
   */

  cout<<"MaxArmyMen: "<<endl;

  for(int i=1; i < graph.size(); i++){
    if(visited.count(i) > 0) continue;

    /*Assume first node of new component always belong to army A*/
    currentArmy = 0;
    army[currentArmy].push(i);
    components++;

    while(!army[currentArmy].empty() || !army[!currentArmy].empty()){

      /** if currentyArmy queue empty switch to other army queue */
      if(army[currentArmy].empty()) currentArmy = !currentArmy;

      index = army[currentArmy].front();

      /** if not already visited, mark it visited and incrment */
      if(visited.count(index) <= 0){
        cCount[currentArmy]++;
        visited.emplace(index);
      }

      processNode(index);

      army[currentArmy].pop();

      //process edges
      for(Node* &edgeNode : graph[index]->edges){
        // node already visited, skip it
        if(visited.count(edgeNode->value) > 0) continue;

        /** Node on other side of edge belongs to other army */
        cCount[(!currentArmy)]++;
        visited.emplace(edgeNode->value);

        //queue the node
        army[!currentArmy].push(edgeNode->value);
      }
      currentArmy = !currentArmy;
    }
  }
  cout<<"Total Components : "<<components <<", Army A : "<<cCount[0] <<", Army B : "<<cCount[1]<<endl;
}

/***********************************/
void Graph::dfsTopologicalSort()
{
 /** Logic:
  *  Traverse the graph in DFS.
  *  In post processing i.e. after processing the edges, add the current node to Stack
  *  Complexity :
  *  Time : O(N) - traverse each node node.
  *  Space : O(N) - Extra stack storage. ( recursion stack space can alos be cosidered, it'll depend of how long the path is created by edges)  
  */

  set<int> visited;
  stack<int> nodes_stack; //stores topologial sorted nodes

  for( int i = 1; i < graph.size(); i++){
    if(visited.count(i) > 0) continue;
    dfsTopologicalSortUtil(visited,nodes_stack,i);
  }

  //print stack 
  cout<<"Topological Sort : "<<endl;

  while(nodes_stack.size() > 0){
    cout<<"\t"<<nodes_stack.top()<<endl;
    nodes_stack.pop();
  }

}

void Graph::dfsTopologicalSortUtil(set<int>& visited, stack<int>& nodes_stack, int index)
{
  if(!isValidNode(index)) return;

  visited.emplace(index);
  processNode(index); // pre processing in DFS

  for(Node* &edgeNode : graph[index]->edges){
    if(visited.count(edgeNode->value) > 0) continue;
    dfsTopologicalSortUtil(visited,nodes_stack,edgeNode->value);
  }
  
  nodes_stack.push(index);  // post processing in DFS,
}



/***********************************/
void createAndTraverse()
{
  Graph g;
  
  g.createNodes();

  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(2,4);
  g.addEdge(4,5);
  g.addEdge(5,6);

  g.printNodes();
  g.dfs();
  g.bfs();
}

void createAndFindArmyMen()
{
  //problem statement at
  //https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/containers-of-choclates-1/
  Graph g;
  int nodes[] = {1,2,3,4,5,6,7,8,9,10};
  //  int fighterGrp1[] = {1,1,4};
  // int fighterGrp2[] = {2,3,5};

  //int fighterGrp1[] = {1,2,2,2};
  //int fighterGrp2[] = {2,3,4,5};

  //int fighterGrp1[] = {1,2,3,4};
  //int fighterGrp2[] = {2,3,4,5};

  int fighterGrp1[] = {2,1,3,7,5,4};
  int fighterGrp2[] = {6,5,4,9,8,10};

  g.createNodes(nodes,(sizeof(nodes)/sizeof(*nodes)));

  //add fighting couple 
  for(int i=0; i<(sizeof(fighterGrp1)/sizeof(*fighterGrp1));i++){
    g.addEdge(fighterGrp1[i],fighterGrp2[i]);
  }

  g.printNodes();

  //find Max Army Men from both side
  g.maxArmyMen();
}

void createAndTopologicalSort()
{
  Graph g;
  int nodes[] = {1,2,3,4,5,6,7,8,9,10};

  g.createNodes(nodes,(sizeof(nodes)/sizeof(*nodes)));

  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(2,4);
  g.addEdge(4,5);
  g.addEdge(5,6);
  g.addEdge(5,7);
  g.addEdge(6,8);
  g.addEdge(8,10);
  g.addEdge(9,10);

  g.printNodes();
  g.dfsTopologicalSort();
  //g.bfs();
}

int main()
{
 // createAndTraverse();
 //createAndFindArmyMen();
 createAndTopologicalSort();
}




