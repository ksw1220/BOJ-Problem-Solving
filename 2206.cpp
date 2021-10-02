#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
struct pos
{
    int x, y, dist, chk;
};
queue<pos> que;
int map[1001][1001];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool visit[1001][1001][2];
int main()
{
    int N, M, ans = INF;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    que.push({0, 0, 1, 0});
    visit[0][0][0] = visit[0][0][1] = true;
    while (!que.empty())
    {
        pos now = que.front();
        que.pop();
        if (now.x == N - 1 && now.y == M - 1)
        {
            ans = min(ans, now.dist);
            continue;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int tox = now.x + dx[dir];
            int toy = now.y + dy[dir];
            if (tox < 0 || toy < 0 || tox >= N || toy >= M || visit[tox][toy][now.chk])
                continue;
            if (map[tox][toy] == 1)
            {
                if (now.chk)
                    continue;
                visit[tox][toy][1] = true;
                que.push({tox, toy, now.dist + 1, 1});
            }
            else
            {
                visit[tox][toy][now.chk] = true;
                que.push({tox, toy, now.dist + 1, now.chk});
            }
        }
    }
    if (ans == INF)
        printf("-1");
    else
        printf("%d", ans);
    return 0;
}