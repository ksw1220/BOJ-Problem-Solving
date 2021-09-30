#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<int> towns;
vector<vector<int>> adj;
vector<vector<vector<int>>> dp;

int dfs(int now, int is_exc, int parent, int parentExc)
{
    int re = 0;

    if (dp[now][is_exc][parentExc])
    {
        return dp[now][is_exc][parentExc];
    }
    if (is_exc)
    {
        re += towns[now];
        for (int i = 0; i < adj[now].size(); i++)
        {
            int next = adj[now][i];
            if (next == parent)
                continue;
            re += dfs(next, 0, now, 1);
        }
    }
    else
    {
        int cnt = 0, MIN = INF;
        int a, b;
        for (int i = 0; i < adj[now].size(); i++)
        {
            int next = adj[now][i];
            if (next == parent)
                continue;
            a = dfs(next, 0, now, 0);
            b = dfs(next, 1, now, 0);
            MIN = min(MIN, a - b);
            if (a > b)
            {
                re += a;
            }
            else
            {
                re += b;
                cnt++;
            }
        }
        if (parentExc == 0 && cnt == 0)
        {
            re -= MIN;
        }
    }
    return dp[now][is_exc][parentExc] = re;
}
int main()
{
    int N, a, b;
    cin >> N;

    towns.assign(N + 1, 0);
    adj.resize(N + 1);
    dp.assign(N + 1, vector<vector<int>>(2, vector<int>(2, 0)));

    for (int i = 1; i <= N; i++)
    {
        cin >> towns[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << max(dfs(1, 0, -1, 0), dfs(1, 1, -1, 0)) << endl;

    return 0;
}