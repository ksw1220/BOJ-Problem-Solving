#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define INF 987654321
using namespace std;

int sx, sy, N, goal = 0;
vector<int> dx = {-1, 0, 1, 0, -1, -1, 1, 1};
vector<int> dy = {0, 1, 0, -1, -1, 1, -1, 1};
vector<vector<int>> heightMap;
vector<vector<char>> map;
vector<vector<bool>> visited;
set<int> height;
vector<int> heightVector;
bool isPossible(int left, int right)
{
    int cnt = 0;
    queue<pair<int, int>> que;
    if (heightMap[sx][sy] < left || heightMap[sx][sy] > right)
        return false;
    visited[sx][sy] = true;
    que.push({sx, sy});

    while (!que.empty())
    {
        int nowx = que.front().first;
        int nowy = que.front().second;

        que.pop();
        if (map[nowx][nowy] == 'K')
        {
            cnt++;
        }

        for (int dir = 0; dir < 8; dir++)
        {
            int tox = nowx + dx[dir];
            int toy = nowy + dy[dir];
            if (tox < 0 || toy < 0 || tox >= N || toy >= N || visited[tox][toy])
                continue;
            if (heightMap[tox][toy] < left || heightMap[tox][toy] > right)
                continue;
            visited[tox][toy] = true;
            que.push({tox, toy});
        }
    }

    return cnt == goal ? true : false;
}
int main()
{
    int l, r, answer = INF;
    cin >> N;
    map.assign(N, vector<char>(N, 0));
    heightMap.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'K')
            {
                goal++;
            }
            else if (map[i][j] == 'P')
            {
                sx = i;
                sy = j;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> heightMap[i][j];
            height.insert(heightMap[i][j]);
        }
    }

    set<int>::iterator it;

    for (it = height.begin(); it != height.end(); it++)
    {
        heightVector.push_back(*it);
    }

    l = 0;
    r = 0;

    while (l < heightVector.size() && r < heightVector.size())
    {
        visited.assign(N, vector<bool>(N, false));
        if (isPossible(heightVector[l], heightVector[r]))
        {
            answer = answer < heightVector[r] - heightVector[l] ? answer : heightVector[r] - heightVector[l];
            l++;
            if (l > r)
                r++;
        }
        else
        {
            r++;
        }
    }
    cout << answer << endl;
    return 0;
}