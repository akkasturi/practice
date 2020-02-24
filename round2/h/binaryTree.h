#include <iostream>

struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};


BinaryTree*  makeTree(int *dataArray, int size);
BinaryTree *makeNode(BinaryTree *root, int data);
BinaryTree *makeRealBinaryTreeNode(int data);

void preorder(BinaryTree *root);
void postorder(BinaryTree *root);
void inorder(BinaryTree *root);
