#include "../h/BinaryTree.h"

using std::cout;
using std::endl;

BinaryTree* makeTree(int *dataArray, int size)
{
  BinaryTree *root = makeNode(NULL,dataArray[0]);
  BinaryTree *node = NULL;

  for(int i=1; i < size; i++){
    node = makeNode(root,dataArray[i]);
  }

  return root;
}

BinaryTree *makeNode(BinaryTree *root, int data)
{
  BinaryTree *newNode = NULL;

  if(root){
    BinaryTree *node = root;
    BinaryTree *parent = NULL;

    while(node){
      parent = node;
      if(data <= node->data){
        node = node->left;
      }else{
        node = node->right;
      }
      if(node == NULL) break;
    }

    newNode = (BinaryTree*) malloc(sizeof(BinaryTree));
    
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    if(data <= parent->data){
      parent->left = newNode ;
    }else{
      parent->right= newNode;
    }
    
  }else{
    newNode = (BinaryTree*) malloc(sizeof(BinaryTree));
    
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
  }

  return newNode;
}

BinaryTree *makeRealBinaryTreeNode(int data)
{
  BinaryTree *newNode = NULL;


  newNode = (BinaryTree*) malloc(sizeof(BinaryTree));

  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;

  return newNode;
}


void preorder(BinaryTree *root)
{
  if(!root) return;

  preorder(root->left);
  cout<<root->data <<", ";
  preorder(root->right);
}

void inorder(BinaryTree *root)
{
  if(!root) return;

  cout<<root->data <<", ";
  inorder(root->left);
  inorder(root->right);
}

void postorder(BinaryTree *root)
{
  if(!root) return;

  postorder(root->left);
  postorder(root->right);
  cout<<root->data <<", ";
}

#if 0

int main()
{
  int dataArray[] = {19,14,11,9,12,17,15,18,28,23,21,24,27,26,29};
  BinaryTree *root = makeTree(dataArray, (sizeof(dataArray)/sizeof(int)));
  cout<<"--- Pre ---"<<endl;
  preorder(root);
  cout<<endl<<"--- In ---"<<endl;
  inorder(root);
  cout<<endl<<"--- Post ---"<<endl;
  postorder(root);

  return 0;
}
#endif
