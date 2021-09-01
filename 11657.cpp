#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
struct Edge
{
    long long start, end, weight;
};
vector<Edge> edges;
long long dist[501];
int main()
{
    int N, M;
    long long a, b, c;
    scanf("%d %d", &N, &M);
    while (M--)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        edges.push_back({a, b, c});
    }
    for (int i = 0; i <= N; i++)
        dist[i] = INF;
    dist[1] = 0;
    for (int iter = 1; iter <= N; iter++)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            if (dist[edges[i].start] != INF && dist[edges[i].end] > dist[edges[i].start] + edges[i].weight)
            {
                dist[edges[i].end] = dist[edges[i].start] + edges[i].weight;
                if (iter == N)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (dist[i] >= INF)
            cout << -1 << endl;
        else
            cout << dist[i] << endl;
    }
    return 0;
}