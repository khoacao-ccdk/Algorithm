#include <iostream>
#include <vector>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
int max = -64;
for(int z=0; z<4; z++)
{
    int i=z;
    for(int y=1; y<5; y++)
    {
        int sum = arr[i][y-1] + arr[i][y] + arr[i][y+1] + arr[i+1][y] + arr[i+2][y-1] + arr[i+2][y] + arr[i+2][y+1];
        if(sum>max)
            max=sum;
    }
}
return max;
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    int result = hourglassSum(arr);

    cout << result << endl;

    return 0;
}
