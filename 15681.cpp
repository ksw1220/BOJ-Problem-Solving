#include <vector>
#include <stdio.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;
vector<bool> visited;

int dfs(int now)
{
    visited[now] = true;
    if (dp[now])
    {
        return dp[now];
    }
    int re = 1;

    for (int i = 0; i < adj[now].size(); i++)
    {
        int next = adj[now][i];
        if (!visited[next])
        {
            re += dfs(next);
        }
    }

    return dp[now] = re;
}
int main()
{
    int N, R, Q, U, V;

    scanf("%d %d %d", &N, &R, &Q);
    adj.resize(N + 1);
    dp.assign(N + 1, 0);
    visited.assign(N + 1, false);

    for (int i = 1; i < N; i++)
    {
        scanf("%d %d", &U, &V);
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    dfs(R);
    while (Q--)
    {
        scanf("%d", &U);
        printf("%d\n", dp[U]);
    }
    return 0;
}