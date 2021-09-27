#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

typedef pair<int, int> POS;

vector<vector<int>> arr;
vector<POS> startPoint, endPoint;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int N, M, F;

void getStartPoint(int x, int y, int &reDist, int &reIdx)
{
    queue<pair<POS, int>> que;
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    visited[x][y] = true;
    que.push({{x, y}, 0});
    reDist = reIdx = INF;

    while (!que.empty())
    {
        POS now = que.front().first;
        int nowDist = que.front().second;
        que.pop();

        if (arr[now.first][now.second] > 0)
        {
            if (reIdx == INF)
            {
                reIdx = arr[now.first][now.second];
                reDist = nowDist;
            }
            else if (reDist < nowDist)
            {
                continue;
            }
            else if (startPoint[reIdx].first > now.first)
            {
                reIdx = arr[now.first][now.second];
            }
            else if (startPoint[reIdx].first == now.first && startPoint[reIdx].second > now.second)
            {
                reIdx = arr[now.first][now.second];
            }
        }
        else if (nowDist >= reDist)
        {
            continue;
        }
        else
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int tox = now.first + dx[dir];
                int toy = now.second + dy[dir];
                if (tox <= 0 || toy <= 0 || tox > N || toy > N)
                    continue;
                if (visited[tox][toy] || arr[tox][toy] == -1)
                    continue;

                visited[tox][toy] = true;
                que.push({{tox, toy}, nowDist + 1});
            }
        }
    }
}

int getDistToEndPoint(int idx, int feul)
{
    queue<pair<POS, int>> que;
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));

    POS start = startPoint[idx];
    POS end = endPoint[idx];
    visited[start.first][start.second] = true;
    que.push({{start.first, start.second}, 0});

    while (!que.empty())
    {
        POS now = que.front().first;
        int nowDist = que.front().second;
        que.pop();

        if (now.first == end.first && now.second == end.second)
        {
            return nowDist;
        }
        else if (nowDist >= feul)
        {
            continue;
        }
        else
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int tox = now.first + dx[dir];
                int toy = now.second + dy[dir];
                if (tox <= 0 || toy <= 0 || tox > N || toy > N)
                    continue;
                if (visited[tox][toy] || arr[tox][toy] == -1)
                    continue;

                visited[tox][toy] = true;
                que.push({{tox, toy}, nowDist + 1});
            }
        }
    }
    return INF;
}
int main()
{
    int X, Y, startPointDist, startPointIdx, cnt = 0;
    cin >> N >> M >> F;

    arr.assign(N + 1, vector<int>(N + 1, 0));
    startPoint.resize(M + 1);
    endPoint.resize(M + 1);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            arr[i][j] *= -1;
        }
    }

    cin >> X >> Y;
    for (int i = 1; i <= M; i++)
    {
        cin >> startPoint[i].first >> startPoint[i].second >> endPoint[i].first >> endPoint[i].second;
        arr[startPoint[i].first][startPoint[i].second] = i;
    }
    while (1)
    {
        if (cnt == M)
        {
            cout << F << endl;
            return 0;
        }
        getStartPoint(X, Y, startPointDist, startPointIdx);
        if (startPointDist > F)
        {
            cout << -1 << endl;
            return 0;
        }
        F -= startPointDist;
        int distToEnd = getDistToEndPoint(startPointIdx, F);

        if (distToEnd <= F)
        {
            F += distToEnd;
            arr[startPoint[startPointIdx].first][startPoint[startPointIdx].second] = 0;
            X = endPoint[startPointIdx].first;
            Y = endPoint[startPointIdx].second;
            cnt++;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    return 0;
}