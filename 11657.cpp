#include <stdio.h>
#include <vector>

#define INF 987654321
using namespace std;

vector<vector<pair<int, long long>>> edge;
vector<long long> dist;
int main()
{

    int N, M, A, B;
    long long C;
    bool updated;
    scanf("%d %d", &N, &M);
    edge.resize(N + 1);
    dist.assign(N + 1, INF);
    while (M--)
    {
        scanf("%d %d %lld", &A, &B, &C);
        edge[A].push_back({B, C});
    }

    dist[1] = 0;
    for (int iter = 0; iter < N; iter++)
    {
        updated = false;
        for (int here = 1; here <= N; here++)
        {
            for (int i = 0; i < edge[here].size(); i++)
            {
                int there = edge[here][i].first;
                long long nextCost = dist[here] + edge[here][i].second;
                if (dist[here] != INF && dist[there] > nextCost)
                {
                    dist[there] = nextCost;
                    updated = true;
                }
            }
        }
        if (!updated)
        {
            break;
        }
    }

    if (updated)
    {
        printf("-1\n");
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (dist[i] == INF)
            {
                printf("-1\n");
            }
            else
            {
                printf("%lld\n", dist[i]);
            }
        }
    }
    return 0;
}