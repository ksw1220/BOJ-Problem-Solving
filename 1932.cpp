#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> arr, dp;
int main()
{
    int N;
    cin >> N;
    arr.assign(N + 1, vector<int>(N + 1, 0));
    dp.assign(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
        }
    }
    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        answer = max(answer, dp[N][i]);
    }
    cout << answer << endl;
    return 0;
}