#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

class Dest
{
public:
    int x, y, cost;
};
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<vector<int>> map;
vector<vector<vector<Dest>>> edge;
vector<vector<int>> dist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int H, W, G, E, X, Y;
    int X1, Y1, X2, Y2, T;

    while (1)
    {
        bool updated;
        cin >> H >> W;
        if (H == 0 && W == 0)
        {
            break;
        }
        map.assign(H, vector<int>(W, 0));
        edge.assign(H, vector<vector<Dest>>(W, vector<Dest>(0, {0, 0, 0})));
        dist.assign(H, vector<int>(W, INF));
        cin >> G;
        while (G--)
        {
            cin >> X >> Y;
            map[X][Y] = 1;
        }
        cin >> E;
        while (E--)
        {
            cin >> X1 >> Y1 >> X2 >> Y2 >> T;
            map[X1][Y1] = 2;
            edge[X1][Y1].push_back({X2, Y2, T});
        }

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!map[i][j])
                {
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int tox = i + dx[dir];
                        int toy = j + dy[dir];
                        if (tox < 0 || toy < 0 || tox >= H || toy >= W || map[tox][toy] == 1)
                            continue;
                        edge[i][j].push_back({tox, toy, 1});
                    }
                }
            }
        }

        edge[H - 1][W - 1].clear();
        dist[0][0] = 0;
        for (int iter = 0; iter < W * H; iter++)
        {
            updated = false;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (i == H - 1 && j == W - 1)
                    {
                        continue;
                    }
                    for (int k = 0; k < edge[i][j].size(); k++)
                    {
                        int tox = edge[i][j][k].x;
                        int toy = edge[i][j][k].y;
                        int toCost = edge[i][j][k].cost;

                        if (dist[i][j] != INF && dist[tox][toy] > dist[i][j] + toCost)
                        {
                            dist[tox][toy] = dist[i][j] + toCost;
                            updated = true;
                        }
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
            cout << "Never" << endl;
        }
        else if (dist[H - 1][W - 1] == INF)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << dist[H - 1][W - 1] << endl;
        }
    }
    return 0;
}