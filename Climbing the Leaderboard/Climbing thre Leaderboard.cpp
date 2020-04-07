#include <iostream>
#include <vector>
using namespace std;

vector<string> split_string(string);

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
vector <int> res;
vector <int> rank;
for (int i=0; i<scores.size(); i++)
{
    if(rank.empty()==true)
        rank.push_back(scores[i]);
    else
    {
        if(scores[i] != rank.back())
        {
            rank.push_back(scores[i]);
        }
    }
}
int index=rank.size()-1;
for (int i=0; i<alice.size(); i++)
{
    if(alice[i]>=rank[0])
        res.push_back(1);
    else if (alice[i]<rank.back())
        res.push_back(rank.size()+1);
    else
    {
        while (alice[i]>rank[index] && index >=0)
        {
            index--;
        }
        if(alice[i]==rank[index])
            res.push_back(index+1);
        else
            res.push_back(index+2);
    }
}
return res;
}

int main()
{
    int m,n,x;
    vector <int> scores;
    vector <int> alice;
    cin >> m;
    for (int i=0; i<m; i++)
    {
        cin >> x;
        scores.push_back(x);
    }
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> x;
        alice.push_back(x);
    }
    vector <int> result = climbingLeaderboard(scores, alice);
    for (int i=0; i<n; i++)
        cout << result[i] << endl;
    return 0;
}
