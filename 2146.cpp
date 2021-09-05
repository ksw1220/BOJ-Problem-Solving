#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> borders;
vector<vector<int>> islandNumber;

int N;
int islandCount = 0, answer = INF;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    bool isBorder = false;
    islandNumber[x][y] = islandCount;

    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];
        if (tox < 0 || toy < 0 || tox >= N || toy >= N || islandNumber[tox][toy])
            continue;
        if (map[tox][toy] == 0)
        {
            isBorder = true;
            continue;
        }

        dfs(tox, toy);
    }

    if (isBorder)
    {
        borders.push_back({x, y});
    }
}
void findBorders()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] && !islandNumber[i][j])
            {
                islandCount++;
                dfs(i, j);
            }
        }
    }
}

void findBridgeLength()
{
    for (int i = 0; i < borders.size(); i++)
    {
        for (int j = i + 1; j < borders.size(); j++)
        {
            if (islandNumber[borders[i].first][borders[i].second] != islandNumber[borders[j].first][borders[j].second])
            {
                int lenX = borders[i].first - borders[j].first;
                int lenY = borders[i].second - borders[j].second;

                lenX = lenX > 0 ? lenX : lenX * -1;
                lenY = lenY > 0 ? lenY : lenY * -1;

                answer = answer > lenX + lenY ? lenX + lenY : answer;
            }
        }
    }
}
int main()
{
    cin >> N;
    map.assign(N, vector<int>(N, 0));
    islandNumber.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    findBorders();
    findBridgeLength();

    cout << answer - 1 << endl;
    return 0;
}