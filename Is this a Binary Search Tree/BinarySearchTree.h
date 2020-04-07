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
        bool HelpercheckBST(node*root);
    public:
        BinarySearchTree()
        {
            root = NULL;
        }
        void Insert(int dat);
        bool checkBST();
};
#endif // BINARYSEARCHTREE_H_INCLUDED
