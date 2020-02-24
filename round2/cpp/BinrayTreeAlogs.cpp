#include "../h/BinaryTree.h"

using std::cout;
using std::endl;

/* ============= ALGO : Least Common Ancestor (LCA) in BST. PATTERN : search, pre-processing   =================== */

//Logic
// - start from root, if both nodes are less than the root then go to left
//   if both nodes are greater than the root than go right
//   else root node would lie between two nodes, hence would be LCA of two
///  nodes. 
//   if all of above fails, there's no LCA and return NULL.
// Additional Checks/Asks: 
//                      return -1 if n1 or n2 doesn't exist. Sol: Check for existence first in separate loop.
//                      if n1 and n2 are same return NULL.
//                      If duplicate are allowed in tree 
//                      Provide Non recursive solution.


BinaryTree* lca(BinaryTree *root , int n1, int n2)
{
  if(root == NULL) return NULL;

  if(root->data > n1 && root->data > n2){
    return lca(root->left,n1,n2);
  }

  if(root->data < n1 && root->data < n2){
    return lca(root->right,n1,n2);
  }

  return root;
}

//Test 
void testLCA_util(BinaryTree *root, int n1, int n2)
{
  BinaryTree *lcaNode = lca(root,n1,n2);

  if(lcaNode){
    cout<<"LCA of "<< n1 <<" and " << n2 << " is : " <<lcaNode->data<<endl;
  }else{
    cout<<"No LCA for "<< n1 <<" and " << n2 <<endl;
  }
}

void testLCA()
{
  int dataArray[] = {19,14,11,9,12,17,15,18,28,23,21,24,27,26,29};
  BinaryTree *root = (BinaryTree*) makeTree(dataArray, (sizeof(dataArray)/sizeof(int)));

  testLCA_util(root,9,12);
  testLCA_util(root,14,14); //** repeated the node. returns the same node, or we can put check to return null in this case.
  testLCA_util(root,26,27);
  testLCA_util(root,21,24);
  testLCA_util(root,26,15);
  testLCA_util(root,19,28); //** A node can be descendant of itself.
  testLCA_util(root,45,44); //** Non existent nodes; code tries to further towards right there are no more nodes.
}


/* ============= ALGO : Least Common Ancestor (LCA) in Binary Tree . PATTERN : search,   =================== */

//Logic : - post traversal
//        - if any node is equal to n1 or n2 then return node ptr to caller (parent.
//        - if parent has not null ptr from both children, it is the LCA.
//        - if parent has one not null ptr from children then continue other side.
//        - if parent has both null ptr from children return null.
BinaryTree* lca_realBinaryTree(BinaryTree *root, int n1, int n2)
{
  if(root == NULL) return NULL;


  if(root->data == n1 or root->data == n2){ cout<<root->data<< " ";  return root;}

  BinaryTree* leftNode = lca_realBinaryTree(root->left,n1,n2);
  BinaryTree* rightNode = lca_realBinaryTree(root->right,n1,n2);

  if(leftNode && rightNode) return root;

  return (leftNode != NULL) ? leftNode : rightNode;
}


void testLCA_realBinaryTree_util(BinaryTree *root, int n1, int n2)
{
  BinaryTree *lcaNode = lca_realBinaryTree(root,n1,n2);

  if(lcaNode){
    cout<<"LCA of "<< n1 <<" and " << n2 << " is : " <<lcaNode->data<<endl;
  }else{
    cout<<"No LCA for "<< n1 <<" and " << n2 <<endl;
  }
}

void testLCA_realBinaryTree()
{
  BinaryTree *root = makeRealBinaryTreeNode(20);

  root->left = makeRealBinaryTreeNode(23);
  root->left->left = makeRealBinaryTreeNode(120);
  root->left->right = makeRealBinaryTreeNode(4);
  root->left->right->right = makeRealBinaryTreeNode(6);

  root->right = makeRealBinaryTreeNode(8);
  root->right->left = makeRealBinaryTreeNode(29);
  root->right->right = makeRealBinaryTreeNode(83);
  root->right->right->left = makeRealBinaryTreeNode(2);

  //tests
  testLCA_realBinaryTree_util(root,120,4);
  testLCA_realBinaryTree_util(root,8,1);
  testLCA_realBinaryTree_util(root,4,6);
  testLCA_realBinaryTree_util(root,4,1);
  testLCA_realBinaryTree_util(root,1,4);
  testLCA_realBinaryTree_util(root,20,8);
  testLCA_realBinaryTree_util(root,20,7);
}


/* ============= XXX =================== */

void testOrders()
{
  int dataArray[] = {19,14,11,9,12,17,15,18,28,23,21,24,27,26,29};
  BinaryTree *root = (BinaryTree*) makeTree(dataArray, (sizeof(dataArray)/sizeof(int)));
  cout<<"--- Pre ---"<<endl;
  preorder(root);
  cout<<endl<<"--- In ---"<<endl;
  inorder(root);
  cout<<endl<<"--- Post ---"<<endl;
  postorder(root);
}

int main()
{
  //testOrders();
  //testLCA();
  testLCA_realBinaryTree();
    return 0;
}

