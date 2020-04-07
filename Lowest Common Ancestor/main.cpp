#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"

using namespace std;

int main()
{
    int n,v1,v2;
    cin >> n;
    BinarySearchTree treeroot;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        treeroot.Insert(a);
    }
    cin >> v1 >> v2;
    cout << treeroot.LCA(v1, v2)->data;
}
