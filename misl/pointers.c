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

  int x = 1;
  int *y = &x;
  int **z = &y;


  printf("\n x:%d, &x:%p,\n"
         "y:%p, &y:%p, *y:%d, &(*y):%p\n"
         "z:%p, &z:%p, *z:%p, &(*z):%p, **z:%d &(**z):%p \n",
         x,&x,
         y,&y,*y,&(*y),
         z,&z,*z,&(*z),**z,&(**z));

  return 0;
 }
