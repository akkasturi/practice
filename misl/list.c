#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node_t;

int build_list(node_t **head, int num_elements, int randomize)
{
  int count = 0;
  static int data = 0;
  for(;count < num_elements; count++)
  {
    node_t *new_node = malloc(sizeof(node_t));
    //@TODO : error checking
    if(randomize)
    {
      new_node->data = random() % 1000;
    }
    else 
    {
      new_node->data = data++;
    }

    new_node->next = *head;
    *head = new_node;
  }
  return 1;
}


void print_list(node_t *head)
{
  printf("\n===================================");

  while(head)
  {
    printf("\n%d",head->data);
    head = head->next;
  }
  printf("\n===================================\n");
}

// split the list. If odd elements, front list has that extra element.
void front_back_split(node_t **head, node_t **front, node_t **back)
{
  node_t *slow = *head;
  node_t *fast = *head;
  int slow_count = 0;
  int fast_count = 0;

  if(slow == NULL) return; // 0 Node
  if(slow->next == NULL) // 1 node
  {
    *front = slow; return;
  }
  if(fast->next->next == NULL) //2 nodes
  {
    *front = slow;
    *back = fast->next;
    slow->next = NULL;
    return;
  }

  // >= 3 nodes
  slow_count = 1;
  fast_count = 3;
  fast = fast->next->next;
  
  while(fast)
  {
    fast = fast->next;
    //If fast move one/two steps, slow moves too.
    if(fast)
    {
      fast_count++;
      slow = slow->next;
      slow_count++;
      
      fast = fast->next;
      if(fast)
      {
        fast_count++;
      }
    }
  }

  if((fast_count % 2)  != 0)
  {
    slow = slow->next;
  }

  *back = slow->next;
  slow->next = NULL;
  *front = *head;

  *head = NULL;
}

int main(int argc, char *argv[])
{
  node_t *head = NULL;
  node_t *front = NULL;
  node_t *back = NULL;
  int num_elements  = 0;
  int randomize = 0;
  char *p=NULL;


  if(argc < 3)
  {
    printf("\nUsage: <Number of Elements in List> <Randmozie elements? 1/0>\n");
    exit(0);
  }

  num_elements = strtol(argv[1],&p,10);
  randomize = strtol(argv[2],&p,10);

  build_list(&head,num_elements,randomize);
  
  print_list(head);
  printf("\n*head : %p\n",*head);

  front_back_split(&head,&front,&back);

  printf("\nFront");
  print_list(front);
  
  printf("\nBack");
  print_list(back);

  return 0;
}
