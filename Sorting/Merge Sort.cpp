#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &array, int start, int middle, int end)
{
    vector<int>a1;
    vector<int>a2;
    for(int i=start; i<=middle; i++)
    {
        a1.push_back(array[i]);
    }
    for(int i=middle+1; i<=end; i++)
    {
        a2.push_back(array[i]);
    }
    int i1=0;
    int i2=0;
    int j=start;

    while ((i1<a1.size()) && (i2<a2.size()))
    {
       if(a1[i1]>=a2[i2])
       {
           array[j]=a2[i2];
           i2++;
       }
       else
       {
           array[j]=a1[i1];
           i1++;
       }
       j++;
    }
    while(i1<a1.size())
    {
        array[j]=a1[i1];
        i1++;
        j++;
    }
    while(i2<a2.size())
    {
        array[j]=a2[i2];
        i2++;
        j++;
    }
}

void AuxSort(vector<int> &array, int start, int end)
{
    if(start>=end)
        return;
    int middle=(start+end)/2;
    AuxSort(array, start, middle);
    AuxSort(array, middle+1, end);
    Merge(array, start, middle, end);
}

void MergeSort(vector<int> &array)
{
    AuxSort(array, 0, array.size()-1);
}
int main()
{
    int x,n;
    vector<int> array;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        array.push_back(x);
    }
    MergeSort(array);
    for(int i=0; i<n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
