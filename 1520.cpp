#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> v, dp;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
    int N = v.size(), M = v[0].size();
    int re = 0;
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    if (x == N - 1 && y == M - 1)
    {
        re = 1;
    }
    else
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int tox = x + dx[dir];
            int toy = y + dy[dir];

            if (tox < 0 || toy < 0 || tox >= N || toy >= M || v[x][y] <= v[tox][toy])
                continue;
            re += dfs(tox, toy);
        }
    }

    return dp[x][y] = re;
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    v.assign(N, vector<int>(M, 0));
    dp.assign(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }

    printf("%d\n",dfs(0, 0));

    return 0;
}