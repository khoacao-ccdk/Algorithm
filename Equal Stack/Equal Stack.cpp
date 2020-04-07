#include<iostream>
#include<vector>
using namespace std;
int Sum(vector<int> h)
{
    int sum=0;
    for(int i=0; i<h.size(); i++)
        sum+=h[i];
    return sum;
}
vector<int> traversesum(vector<int> h)
{
    vector<int> res;
    int sum=Sum(h);
    while(h.empty()!=true)
    {
        res.push_back(sum);
        sum-=h.back();
        h.pop_back();
    }
    return res;
}

vector<int> reverse(vector<int> traverse)
{
    vector<int>res;
    while(traverse.empty()!=true)
    {
        res.push_back(traverse.back());
        traverse.pop_back();
    }
    return res;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    /*
     * Write your code here.
     */
    vector<int> traverse1=reverse(h1);
    vector<int> traverse2=reverse(h2);
    vector<int> traverse3=reverse(h3);

    traverse1=traversesum(traverse1);
    traverse2=traversesum(traverse2);
    traverse3=traversesum(traverse3);

    traverse1=reverse(traverse1);
    traverse2=reverse(traverse2);
    traverse3=reverse(traverse3);
    while(traverse1.back()!=traverse2.back() && traverse2.back()!=traverse3.back() && traverse3.back()!=traverse1.back() && (traverse1.empty()==false && traverse2.empty()==false && traverse3.empty()==false))
    {
        if(traverse1.back()>traverse2.back() && traverse1.back()>traverse3.back())
            traverse1.pop_back();
        if(traverse2.back()>traverse1.back() && traverse2.back()>traverse3.back())
            traverse2.pop_back();
        if(traverse3.back()>traverse2.back() && traverse3.back()>traverse2.back())
            traverse3.pop_back();
    }
    if(traverse1.empty() == true || traverse2.empty() == true || traverse3.empty() == true)
        return 0;
    else
        return traverse2.back();
}

int main()
{
    int m,n,k,x;
    vector<int> h1,h2,h3;
    cin >> m >> n >> k;
    for (int i=0; i<m; i++)
    {
        cin >> x;
        h1.push_back(x);
    }
    for (int i=0; i<n; i++)
    {
        cin >> x;
        h2.push_back(x);
    }
    for (int i=0; i<k; i++)
    {
        cin >> x;
        h3.push_back(x);
    }
    cout << equalStacks(h1,h2,h3);
    return 0;
}
