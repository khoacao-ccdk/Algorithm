#include <iostream>
#include "BinarySearchTree.h"
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

void BinarySearchTree::print()
{
    Helperprint(root);
}

void BinarySearchTree::Helperprint(node* root)
{
    if (root == NULL)
        return;
    else
    {
        Helperprint(root->left);
        cout << root->data << " ";
        Helperprint(root->right);
    }
}

int BinarySearchTree::Height()
{
    return HelperHeight(root);
}

int BinarySearchTree::HelperHeight(node* root)
{
    if (root == NULL)
        return 0;
    else if (HelperHeight(root->left)>HelperHeight(root->right))
        return 1 + HelperHeight(root->left);
    else
        return 1 + HelperHeight(root->right);
}

void BinarySearchTree::Remove(int value)
{
    HelperRemove(value, root);
}

void BinarySearchTree::HelperRemove(int value, node* &root)
{
    node* temp=root;
    node* subparent=NULL;
    while (temp!=NULL && temp->data != value)
    {
        subparent = temp;
        if (value < temp->data)
            temp=temp->left;
        else
            temp = temp->right;
    }
    if (temp==NULL)
        return;
    if (temp->left == NULL && temp->right == NULL)
    {
        if (subparent == NULL)
        {
            delete root;
            root = NULL;
            return;
        }
        if (subparent->left == temp)
            subparent->left==NULL;
        if (subparent->right == temp)
            subparent->right==NULL;
        return;
    }
    if (temp->left == NULL)
    {
        if(subparent==NULL)
        {
            node* temp2 = root;
            root = root->right;
            delete temp2;
            return;
        }
        if (temp->data < subparent->data)
            subparent->left=temp->right;
        else
            subparent->right=temp->right;
        return;
    }
    if (temp->right == NULL)
    {
        if(subparent==NULL)
        {
            node* temp2 = root;
            root = root->left;
            delete temp2;
            return;
        }
        if (temp->data < subparent->data)
            subparent->left=temp->left;
        else
            subparent->right=temp->left;
        return;
    }
    if (temp->left != NULL && temp->right!=NULL)
    {
        node* temp2 = temp->right;
        node* smallparent = temp2;
        while (temp2->left!=NULL)
        {
            smallparent=temp2;
            temp2=temp2->left;
        }
        temp->data=temp2->data;
        smallparent->right = temp2->right;
    }
}
