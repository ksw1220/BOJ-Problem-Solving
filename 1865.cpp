#include <stdio.h>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;

typedef struct Edge
{
    int start, end, time;
} E;

vector<Edge> Edges;
vector<int> dist;
int main()
{
    int TC, N, M, W, S, E, T;

    scanf("%d", &TC);
    while (TC--)
    {
        bool answer = false;
        scanf("%d %d %d", &N, &M, &W);
        Edges.clear();
        dist.clear();
        dist.assign(N + 1, INF);
        while (M--)
        {
            scanf("%d %d %d", &S, &E, &T);
            Edges.push_back({S, E, T});
            Edges.push_back({E, S, T});
        }
        while (W--)
        {
            scanf("%d %d %d", &S, &E, &T);
            Edges.push_back({S, E, -T});
        }

        dist[1] = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < Edges.size(); j++)
            {
                if (dist[Edges[j].end] > dist[Edges[j].start] + Edges[j].time)
                {
                    dist[Edges[j].end] = dist[Edges[j].start] + Edges[j].time;
                    if (i == N)
                        answer = true;
                }
            }
        }
        if (answer)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}