#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr, dp;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    arr.assign(N, vector<int>(N, 0));
    dp.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < N; i++)
    {
        int diff = arr[0][i] - arr[0][i - 1];
        dp[0][i] = diff >= 0 ? dp[0][i - 1] + diff + 1 : dp[0][i - 1];

        diff = arr[i][0] - arr[i - 1][0];
        dp[i][0] = diff >= 0 ? dp[i - 1][0] + diff + 1 : dp[i - 1][0];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            int diff = arr[i][j] - arr[i - 1][j];
            int a = diff >= 0 ? dp[i - 1][j] + diff + 1 : dp[i - 1][j];
            diff = arr[i][j] - arr[i][j - 1];
            int b = diff >= 0 ? dp[i][j - 1] + diff + 1 : dp[i][j - 1];

            dp[i][j] = a < b ? a : b;
        }
    }

    cout << dp[N - 1][N - 1] << endl;
    return 0;
}