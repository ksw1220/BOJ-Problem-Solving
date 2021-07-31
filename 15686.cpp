#include <stdio.h>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

vector<pair<int, int>> chickens, houses;
vector<bool> isExist;

int N, M, answer = INF;

int findDist(int x, int y)
{
    int re = INF;
    for (int i = 0; i < chickens.size(); i++)
    {
        if (!isExist[i])
            continue;
        int diffX = chickens[i].first - x;
        int diffY = chickens[i].second - y;

        if (diffX < 0)
            diffX *= -1;
        if (diffY < 0)
            diffY *= -1;

        if (re > diffX + diffY)
            re = diffX + diffY;
    }
    return re;
}

void dfs(int now, int cnt)
{

    if (cnt == M)
    {
        int totalDist = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            totalDist += findDist(houses[i].first, houses[i].second);
        }
        if (answer > totalDist)
            answer = totalDist;
    }

    for (int i = now + 1; i < chickens.size(); i++)
    {
        isExist[i] = true;
        dfs(i, cnt + 1);
        isExist[i] = false;

        dfs(i, cnt);
    }

    return;
}

int main()
{
    int x;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &x);
            if (x == 1)
            {
                houses.push_back({i, j});
            }
            else if (x == 2)
            {
                chickens.push_back({i, j});
            }
        }
    }

    isExist.assign(chickens.size(), false);

    isExist[0] = true;
    dfs(0, 1);
    isExist[0] = false;

    dfs(0, 0);

    printf("%d\n", answer);
    return 0;
}