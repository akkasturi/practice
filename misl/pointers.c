#include <stdio.h>

typedef struct node
{
  int i;
  struct node* next;
}node_t;

int main()
{
  node_t n1 = {1,NULL};
  node_t *n1_ptr = &n1;
  node_t **n1_ptr_ptr = &n1_ptr;

  printf("\n*n1_ptr = %d, n1_ptr->i = %d\n",*n1_ptr,n1_ptr->i);

  return 0;
 }
