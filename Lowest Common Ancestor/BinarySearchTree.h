#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

using namespace std;

struct node
{
    int data;
    node* left = NULL;
    node* right = NULL;
};

class BinarySearchTree
{
    private:
        node* root;
        void HelperInsert(int dat, node* &root);
        node* HelperLCA(node*root, int v1, int v2);
    public:
        BinarySearchTree()
        {
            root = NULL;
        }
        void Insert(int dat);
        node* LCA(int v1, int v2);
};
#endif // BINARYSEARCHTREE_H_INCLUDED
