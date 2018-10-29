#include<stdlib.h>
#include<stdio.h>

#define MAX_EDGES 2
#define MAX_NODES 10

typedef struct vertex{
  int data;
  int curr_index;
  int adj[MAX_EDGES]; 
}vertex_t;

typedef struct graph{
  vertex_t *nodes[MAX_NODES+1];
  int total_nodes;
  int total_visited;
}graph_t;


char visited[MAX_NODES+1]={0};

void init_graph(graph_t *graph);
int create_vertex(graph_t *graph, int index);
void insert_edge(graph_t *graph,int v, int w); 
void print_graph_info(graph_t *graph);
void dfs(graph_t *graph, int vertex_index);


int main()
{
  //init graph
  //create nodes
  //traverse

  graph_t graph;
  init_graph(&graph);
  create_vertex(&graph,1);
  create_vertex(&graph,2);
  create_vertex(&graph,3);
  create_vertex(&graph,4);
  create_vertex(&graph,5);
  create_vertex(&graph,6);

  insert_edge(&graph,1,2);
  insert_edge(&graph,1,3);
  insert_edge(&graph,3,6);
  insert_edge(&graph,2,4);
  insert_edge(&graph,4,5);
  insert_edge(&graph,5,1);

  //print_graph_info(&graph);
  graph.total_visited= 0;
  dfs(&graph,1);
  printf("\n-----------------\n");
}



void init_graph(graph_t *graph)
{
  graph->total_nodes = 0;
  graph->total_visited= 0;
}

int 
create_vertex(graph_t *graph, int index)
{
  vertex_t *v = (vertex_t*) malloc(sizeof(vertex_t));
  v->data = index;
  v->curr_index = 0;
  graph->nodes[index] = v;
  graph->total_nodes++;
  return 1;
}

void 
insert_edge(graph_t *graph,int from_vertex, int to_vertex) 
{
  //get vertex
  //fill up adjacency list
  vertex_t *from_v = graph->nodes[from_vertex];
  vertex_t *to_v= graph->nodes[to_vertex];

  if(from_v  == NULL || to_v == NULL) return;
 
  from_v->adj[from_v->curr_index] = to_vertex;
  from_v->curr_index++;
}


void print_graph_info(graph_t *graph)
{
  int index = 1;
  printf("\nTotal Nodes in Graph : \n",graph->total_nodes);

  for(; index <= graph->total_nodes; index++)
  {
    printf("Node : %d, Data : %d,Adjacency List : %d\n",index,graph->nodes[index]->data,graph->nodes[index]->curr_index);
  }
}


void 
dfs(graph_t *graph, int vertex_index)
{
  vertex_t * v = NULL;
  vertex_t * adj_v  = NULL;
  int index = 0;
  int adj_index = 0;

  if(graph->total_visited > graph->total_nodes) return;
  
  //if(visited[vertex_index] == 0)
  {
    visited[vertex_index] = 1;
    v =  graph->nodes[vertex_index];
    printf("\nNode: %d, Data : %d",vertex_index,v->data);
    graph->total_visited++;


    for( index = 0; index < v->curr_index;  index++)
    {
      adj_index = v->adj[index];
      if(visited[adj_index] == 0) {
       dfs(graph,adj_index); 
      }else { printf("\nAlready visited :%d",adj_index); }
    }
  } 
}
