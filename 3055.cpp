#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
int answer = -1;
typedef struct POS
{
    int x, y, t;
} pos;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<pair<int, int>> water;
vector<vector<char>> map;
vector<vector<bool>> visited;
queue<POS> que;
void moveWater()
{
    vector<pair<int, int>> newWater;
    for (int i = 0; i < water.size(); i++)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int tox = water[i].first + dx[dir];
            int toy = water[i].second + dy[dir];
            if (tox < 0 || toy < 0 || tox >= R || toy >= C)
                continue;
            if (map[tox][toy] == '.')
            {
                map[tox][toy] = '*';
                newWater.push_back({tox, toy});
            }
        }
    }
    water = newWater;
}

void move()
{
    queue<POS> newQue;
    while (!que.empty())
    {
        POS now = que.front();
        que.pop();
        if (map[now.x][now.y] == 'D')
        {
            answer = now.t;
            return;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int tox = now.x + dx[dir];
            int toy = now.y + dy[dir];
            if (tox < 0 || toy < 0 || tox >= R || toy >= C)
                continue;
            if (!visited[tox][toy] && (map[tox][toy] == 'D' || map[tox][toy] == '.'))
            {
                visited[tox][toy] = true;
                newQue.push({tox, toy, now.t + 1});
            }
        }
    }
    que = newQue;
}
int main()
{
    cin >> R >> C;
    map.assign(R, vector<char>(C, ' '));
    visited.assign(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                visited[i][j] = true;
                map[i][j] = '.';
                que.push({i, j, 0});
            }
            else if (map[i][j] == '*')
            {
                water.push_back({i, j});
            }
        }
    }

    while (1)
    {
        if (que.empty())
        {
            break;
        }
        if (!water.empty())
        {
            moveWater();
        }
        move();
    }

    if (answer == -1)
    {
        cout << "KAKTUS" << endl;
    }
    else
    {
        cout << answer << endl;
    }

    return 0;
}