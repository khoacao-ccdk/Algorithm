#include <iostream>
#include <algorithm>
using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    vector<int> balls, boxsize;
    int n =container.size();
    for (int i=0; i<n; i++)
    {
        int type=0;
        int size=0;
        for(int y=0; y<n; y++)
        {
            type += container[y][i];
            size += container[i][y];
        }
        balls.push_back(type);
        boxsize.push_back(size);
    }
    std::sort(balls.begin(), balls.end());
    std::sort(boxsize.begin(), boxsize.end());
    bool flag=true;
    for(int i=0; i<n; i++)
    {
        if(balls[i]!=boxsize[i])
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
        return "Possible";
    else
        return "Impossible";

}

int main()
{

    int q;
    cin >> q;
    for (int i= 0; i < q; i++)
    {
        int n;
        cin >> n;

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++)
        {
            container[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> container[i][j];
        }

        string result = organizingContainers(container);

        cout << result << endl;
    }

    return 0;
}
