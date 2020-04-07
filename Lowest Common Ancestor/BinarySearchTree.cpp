#ifndef BINARYSEARCHTREE_CPP_INCLUDED
#define BINARYSEARCHTREE_CPP_INCLUDED
#include <iostream>
#include "BinarySearchTree.h"
#include <vector>
using namespace std;

void BinarySearchTree::Insert(int dat)
{
    HelperInsert(dat, root);
}

void BinarySearchTree::HelperInsert(int dat, node* &root)
{
    if (root == NULL)
    {
        root = new node;
        root -> data = dat;
    }
    else if (dat > root->data)
        HelperInsert(dat, root->right);
    else
        HelperInsert(dat, root->left);
}
node* BinarySearchTree::LCA(int v1,int v2)
{
    return HelperLCA(root, v1,v2);
}

node* BinarySearchTree::HelperLCA(node* root, int v1, int v2) {
    if (v1>v2)
    {
        int temp=v2;
        v2=v1;
        v1=temp;
        }
    node*temp = root;
    while(v1>temp->data || v2<temp->data)
    {
        if(v1>temp->data)
            temp=temp->right;
        else
            temp=temp->left;
    }
    return temp;
}
#endif
