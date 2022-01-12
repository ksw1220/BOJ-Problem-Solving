#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<int>> dist;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, a, b, c;
    cin >> N >> M;
    dist.assign(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }
    while (M--)
    {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}