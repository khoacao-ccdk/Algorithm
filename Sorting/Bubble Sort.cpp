#include<iostream>
#include<vector>

using namespace std;

int swap(int &a, int &b)
{
    int temp = a;
    a=b;
    b=temp;
}

void BubbleSort(vector<int> &array)
{
    bool swapped;
    for(int i=0; i<array.size()-1; i++)
    {
        swapped = false;
        for (int j=0; j<array.size()-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
                swapped=true;
            }
        }
        if(!swapped)
        {
            return;
        }
    }
}

int main()
{
    vector<int> array;
    int n, x;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> x;
        array.push_back(x);
    }
    BubbleSort(array);
    for (int i=0; i<array.size(); i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
