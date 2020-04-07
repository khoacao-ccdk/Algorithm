#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int n, x, y;
    set <int> data;
    vector<bool> flag;
    cin >> n;
    for (int i=0; i< n; i++)
    {
        cin >> x >> y;
        switch(x)
        {
            case (1):
                {
                    data.insert(y);
                    break;
                }
            case (2):
                {
                    data.erase(y);
                    break;
                }
            case (3):
            {
                bool result;
                set<int>::iterator itr=data.find(y);
                if (itr==data.end())
                    result = false;
                else
                    result = true;
                flag.push_back(result);
                break;
            }
        }
    }
    for (int i=0; i<flag.size(); i++)
    {
        if (flag[i]==true)
            cout << "Yes" << endl;
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
