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
        void Helperprint(node* root);
        int HelperHeight(node* root);
        void HelperRemove(int value, node* &root);
    public:
        BinarySearchTree()
        {
            root = NULL;
        }
        void Insert(int dat);
        void print();
        int Height();
        void Remove(int value);
};
#endif // BINARYSEARCHTREE_H_INCLUDED
