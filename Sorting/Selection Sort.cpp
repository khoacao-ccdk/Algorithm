#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &array)
{
    int temp;
    int maxPos;
    for (int i = array.size()-1; i>0; i--)
    {
        maxPos = 0;
        for (int j=0; j<i+1; j++)
        {
            if (array[j]>array[maxPos])
                maxPos=j;
        }
        temp=array[maxPos];
        array[maxPos]=array[i];
        array[i]=temp;
    }
}

void print(vector<int> array)
{
    for(int i=0; i < array.size(); i++)
        cout << array[i] << " ";
}
int main()
{
    int y,n;
    vector<int> array;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> y;
        array.push_back(y);
    }
    selectionSort(array);
    print(array);
}
