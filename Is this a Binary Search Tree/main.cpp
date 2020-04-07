#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"

using namespace std;

int main()
{
    int n,m;
    cin >> n;
    BinarySearchTree treeroot;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        treeroot.Insert(a);
    }
    if (treeroot.checkBST()==true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
