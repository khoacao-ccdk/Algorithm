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
bool BinarySearchTree::checkBST()
{
    return HelpercheckBST(root);
}
void Order(node* root, vector<int> &tree)
    {
        if(root==NULL)
            return;
        Order(root->left, tree);
        tree.push_back(root->data);
        Order(root->right, tree);
    }
bool BinarySearchTree::HelpercheckBST(node* root) {
        vector<int> Tree;
        Order(root, Tree);
        for (int i=0; i<Tree.size()-1; i++)
        {
            if(Tree[i]>=Tree[i+1])
                return false;
        }
        return true;

	}
#endif
