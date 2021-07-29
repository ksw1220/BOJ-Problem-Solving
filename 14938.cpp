#include <stdio.h>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<int> items;
vector<vector<int>> dist;

int main()
{
    int n, m, r;
    int a, b, I;
    int answer = 0;
    scanf("%d %d %d", &n, &m, &r);
    items.assign(n + 1, 0);
    dist.assign(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &items[i]);
    }

    for (int i = 0; i < r; i++)
    {
        scanf("%d %d %d", &a, &b, &I);
        dist[a][b] = min(dist[a][b], I);
        dist[b][a] = min(dist[b][a], I);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    dist[i][j] = dist[j][i] = 0;
                    continue;
                }
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] <= m)
            {
                tmp += items[j];
            }
        }
        if (answer < tmp)
        {
            answer = tmp;
        }
    }

    printf("%d\n", answer);
    return 0;
}