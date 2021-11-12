#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree, dp;
vector<bool> visited;

int dfs(int now, int isEarly)
{
    if (dp[now][isEarly])
    {
        return dp[now][isEarly];
    }
    else
    {
        int re = 0;

        visited[now] = true;

        if (isEarly)
        {
            for (int i = 0; i < tree[now].size(); i++)
            {
                int next = tree[now][i];
                if (!visited[next])
                {
                    int a = dfs(next, 0);
                    int b = dfs(next, 1);
                    re += a < b ? a : b;
                }
            }
            re++;
        }
        else
        {
            for (int i = 0; i < tree[now].size(); i++)
            {
                int next = tree[now][i];
                if (!visited[next])
                {
                    re += dfs(next, 1);
                }
            }
        }
        visited[now] = false;
        return dp[now][isEarly] = re;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, a, b, answer;
    cin >> N;

    tree.assign(N + 1, vector<int>(0, 0));
    dp.assign(N + 1, vector<int>(2, 0));

    visited.assign(N + 1, false);
    for (int i = 1; i < N; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);
    dfs(1, 1);

    answer = dp[1][0] < dp[1][1] ? dp[1][0] : dp[1][1];

    cout << answer << endl;
    return 0;
}