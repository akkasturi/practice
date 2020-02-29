#include <iostream>

struct Node {
  int data;
  struct Node *next;
};

void createList(Node **head, int *arr, int len)
{
  Node *newNode = NULL;
  Node *prev = NULL;


  for(int i=0; i<len; i++){
    newNode = new Node();
    newNode->data =  arr[i];
    newNode->next = prev;

    prev = newNode;
  }

  *head = prev;
}

void printList(Node *head)
{
  Node *curr = head;
  std::cout<<"List is : "<<std::endl;
  
  while(curr)
  {
    std::cout<<curr->data<< ", ";

    curr = curr->next;
  }

  std::cout<<std::endl;
}

void findMiddle(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  if(slow == NULL) return;

  while(slow and fast and fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  printList(head);
  std::cout<<"Middle of list is : "<<slow->data <<std::endl;
}


void findKth(Node *head, int k)
{
  int j = k;

  Node *curr = head;
  
  while(j && curr)
  {
    curr = curr->next;
    j--;
  }

  if(j > 0) std::cout<<"Less than "<<k <<" elements in list. Exiting"<<std::endl;

  Node *start = head;
  Node *end = curr;

  while(end)
  {
    start = start->next;
    end = end->next;
  }

  printList(head);
  std::cout<<k <<"th element from the last in the list is : "<<start->data <<std::endl;
}

int main()
{
  int arr[]={9,8,7,6,5,4,3,2,1};
  //int arr1[]={2,3,4};
  
  Node *head =NULL;
  
  createList(&head, arr, (sizeof(arr)/sizeof(arr[0])));
  //createList(&head, arr1, (sizeof(arr1)/sizeof(arr1[0])));
  //printList(head);
 // findMiddle(head);
  findKth(head,1);
  findKth(head,2);
  findKth(head,3);
  findKth(head,4);
  findKth(head,9);

  return 0;
}
