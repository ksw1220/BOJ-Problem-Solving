#include <stdio.h>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<int>> costs, Rdp, Gdp, Bdp;

int main()
{
    int N;
    scanf("%d", &N);

    costs.assign(N, vector<int>(3, 0));
    Rdp.assign(N, vector<int>(3, INF));
    Gdp.assign(N, vector<int>(3, INF));
    Bdp.assign(N, vector<int>(3, INF));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &costs[i][j]);
        }
    }

    Rdp[0][0] = costs[0][0];
    Gdp[0][1] = costs[0][1];
    Bdp[0][2] = costs[0][2];

    for (int i = 1; i < N; i++)
    {
        Rdp[i][0] = min(Rdp[i][0], min(Rdp[i - 1][1], Rdp[i - 1][2]) + costs[i][0]);
        Rdp[i][1] = min(Rdp[i][1], min(Rdp[i - 1][2], Rdp[i - 1][0]) + costs[i][1]);
        Rdp[i][2] = min(Rdp[i][2], min(Rdp[i - 1][0], Rdp[i - 1][1]) + costs[i][2]);
    }

    for (int i = 1; i < N; i++)
    {
        Gdp[i][0] = min(Gdp[i][0], min(Gdp[i - 1][1], Gdp[i - 1][2]) + costs[i][0]);
        Gdp[i][1] = min(Gdp[i][1], min(Gdp[i - 1][2], Gdp[i - 1][0]) + costs[i][1]);
        Gdp[i][2] = min(Gdp[i][2], min(Gdp[i - 1][0], Gdp[i - 1][1]) + costs[i][2]);
    }

    for (int i = 1; i < N; i++)
    {
        Bdp[i][0] = min(Bdp[i][0], min(Bdp[i - 1][1], Bdp[i - 1][2]) + costs[i][0]);
        Bdp[i][1] = min(Bdp[i][1], min(Bdp[i - 1][2], Bdp[i - 1][0]) + costs[i][1]);
        Bdp[i][2] = min(Bdp[i][2], min(Bdp[i - 1][0], Bdp[i - 1][1]) + costs[i][2]);
    }

    int Rmin = min(Rdp[N - 1][1], Rdp[N - 1][2]);
    int Gmin = min(Gdp[N - 1][2], Gdp[N - 1][0]);
    int Bmin = min(Bdp[N - 1][0], Bdp[N - 1][1]);

    printf("%d\n", min({Rmin, Gmin, Bmin}));
    return 0;
}