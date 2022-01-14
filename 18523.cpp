#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
vector<vector<int>> graph;
queue<pair<int, int>> que;
vector<int> dist, answer;
int main()
{
    int N, M, K, X, a, b;
    scanf("%d %d %d %d", &N, &M, &K, &X);

    dist.assign(N + 1, INF);
    graph.resize(N + 1);
    while (M--)
    {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }

    dist[X] = 0;
    que.push({X, 0});

    while (!que.empty())
    {
        int now = que.front().first;
        int nowDist = que.front().second;
        que.pop();

        if (nowDist == K)
        {
            break;
        }
        for (int i = 0; i < graph[now].size(); i++)
        {
            int to = graph[now][i];
            if (dist[to] > nowDist + 1)
            {
                dist[to] = nowDist + 1;
                que.push({to, nowDist + 1});
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == K)
        {
            answer.push_back(i);
        }
    }
    sort(answer.begin(), answer.end());

    if (answer.size() == 0)
    {
        printf("-1\n");
    }
    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}