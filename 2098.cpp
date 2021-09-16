#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<vector<int>> W;
vector<vector<int>> dp;

int N;
int answer = INF;
int dfs(int now, int visit)
{
    if (visit == (1 << N) - 1)
    {
        return W[now][0] ? W[now][0] : INF;
    }
    else if (dp[now][visit])
    {
        return dp[now][visit];
    }
    else
    {
        int re = INF;
        for (int i = 1; i < N; i++)
        {
            if (!(1 << i & visit) && W[now][i])
            {
                re = min(re, dfs(i, visit | 1 << i) + W[now][i]);
            }
        }
        return dp[now][visit] = re;
    }
}
int main()
{
    cin >> N;

    W.assign(N, vector<int>(N, 0));
    dp.assign(N, vector<int>(1 << N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }

    cout << dfs(0, 1) << endl;

    return 0;
}