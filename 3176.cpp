#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

class Edge
{
public:
    int LCA, MIN, MAX;

    Edge compare(Edge e)
    {
        Edge tmp;
        tmp.LCA = e.LCA;
        tmp.MIN = min(this->MIN, e.MIN);
        tmp.MAX = max(this->MAX, e.MAX);
        return tmp;
    }
};

vector<vector<pair<int, int>>> tree;
vector<int> depth;
vector<vector<Edge>> dp;
void makeLCA(int now, int parent, int dist)
{
    depth[now] = depth[parent] + 1;
    dp[now].push_back({parent, dist, dist});

    int idx = 1;
    while (1)
    {
        int tmp = dp[now][idx - 1].LCA;
        if (idx > dp[tmp].size())
        {
            break;
        }
        dp[now].push_back(dp[now][idx - 1].compare(dp[tmp][idx - 1]));
        idx++;
    }

    for (int i = 0; i < tree[now].size(); i++)
    {
        int there = tree[now][i].first;
        if (there != parent)
        {
            makeLCA(there, now, tree[now][i].second);
        }
    }
}

void getEdge(int a, int b)
{
    int minValue = INF, maxValue = 0;
    if (depth[a] != depth[b])
    {
        if (depth[a] > depth[b])
        {
            swap(a, b);
        }

        for (int i = dp[b].size() - 1; i >= 0; i--)
        {
            if (dp[b].size() <= i)
            {
                continue;
            }
            if (depth[a] <= depth[dp[b][i].LCA])
            {
                minValue = min(minValue, dp[b][i].MIN);
                maxValue = max(maxValue, dp[b][i].MAX);
                b = dp[b][i].LCA;
            }
        }
    }

    if (depth[a] != depth[b])
    {
        return;
    }
    if (a != b)
    {
        for (int i = dp[a].size() - 1; i >= 0; i--)
        {
            if (dp[a].size() <= i)
            {
                continue;
            }
            if (dp[a][i].LCA != dp[b][i].LCA)
            {
                minValue = min(minValue, dp[a][i].MIN);
                maxValue = max(maxValue, dp[a][i].MAX);
                minValue = min(minValue, dp[b][i].MIN);
                maxValue = max(maxValue, dp[b][i].MAX);
                a = dp[a][i].LCA;
                b = dp[b][i].LCA;
            }
        }
        minValue = min(minValue, dp[a][0].MIN);
        maxValue = max(maxValue, dp[a][0].MAX);
        minValue = min(minValue, dp[b][0].MIN);
        maxValue = max(maxValue, dp[b][0].MAX);
    }
    printf("%d %d\n", minValue, maxValue);
}
int main()
{
    int N, K, A, B, C, D, E;

    scanf("%d", &N);
    tree.resize(N + 1);
    depth.assign(N + 1, 0);
    dp.resize(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d %d", &A, &B, &C);
        tree[A].push_back({B, C});
        tree[B].push_back({A, C});
    }

    makeLCA(1, 0, 0);
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d %d", &D, &E);
        getEdge(D, E);
    }

    return 0;
}