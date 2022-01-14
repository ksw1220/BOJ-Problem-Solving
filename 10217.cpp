#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

class Node
{
public:
    int idx, cost, time;

    bool operator<(const Node &n) const
    {
        return time > n.time;
    }
};
vector<vector<int>> dp;
vector<vector<Node>> graph;
priority_queue<Node> pq;
int main()
{
    int T, N, M, K, u, v, c, d;

    scanf("%d", &T);
    while (T--)
    {
        int answer = INF;
        scanf("%d %d %d", &N, &M, &K);
        dp.assign(N + 1, vector<int>(M + 1, INF));
        graph.assign(N + 1, vector<Node>(0, {0, 0, 0}));
        while (K--)
        {
            scanf("%d %d %d %d", &u, &v, &c, &d);
            graph[u].push_back({v, c, d});
        }
        dp[1][0] = 0;
        pq.push({1, 0, 0});

        while (!pq.empty())
        {
            int now = pq.top().idx;
            int nowCost = pq.top().cost;
            int nowTime = pq.top().time;
            pq.pop();

            if (now == N)
            {
                if (answer > nowTime)
                {
                    answer = nowTime;
                }
            }
            for (int i = 0; i < graph[now].size(); i++)
            {
                int to = graph[now][i].idx;
                int toCost = graph[now][i].cost + nowCost;
                int toTime = graph[now][i].time + nowTime;

                if (toCost <= M && dp[to][toCost] > toTime)
                {
                    dp[to][toCost] = toTime;
                    pq.push({to, toCost, toTime});
                }
            }
        }
        if (answer == INF)
        {
            printf("Poor KCM\n");
        }
        else
        {
            printf("%d\n", answer);
        }
    }
    return 0;
}