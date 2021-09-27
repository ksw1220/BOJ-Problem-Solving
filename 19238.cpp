#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

typedef pair<int, int> POS;

vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<POS> startPoint, endPoint;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int N, M, F;

void nowToStart(int x, int y, int &dist, int &start)
{
    queue<pair<POS, int>> que;
    que.push({{x, y}, 0});
    dist = INF;
    start = -1;
    while (!que.empty())
    {
        POS now = que.front().first;
        int nowDist = que.front().second;
        que.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int tox = now.first + dx[dir];
            int toy = now.second + dy[dir];
            if (tox < 0 || toy < 0 || tox >= N || toy >= N)
                continue;
            if (visited[tox][toy] || arr[tox][toy] == -1 || dist > nowDist + 1)
                continue;
            que.push({{tox, toy}, nowDist + 1});
        }
    }
}
int main()
{
    cin >> N >> M >> F;

    arr.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, false));
    startPoint.resize(M + 1);
    endPoint.resize(M + 1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                arr[i][j] = -1;
            }
        }
    }

    for (int i = 1; i <= M; i++)
    {
        cin >> startPoint[i].first >> startPoint[i].second >> endPoint[i].first >> endPoint[i].second;
        arr[startPoint[i].first][startPoint[i].second] = i;
    }

    return 0;
}