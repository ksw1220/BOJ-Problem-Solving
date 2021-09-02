#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<int> answer;
vector<vector<bool>> visited;

int N, cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visited[x][y] = true;
    cnt++;

    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];

        if (tox < 0 || toy < 0 || tox >= N || toy >= N || !map[tox][toy] || visited[tox][toy])
            continue;

        dfs(tox, toy);
    }
}
int main()
{
    scanf("%d", &N);

    map.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] && !visited[i][j])
            {
                dfs(i, j);
                answer.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(answer.begin(), answer.end());
    
    printf("%lu\n", answer.size());

    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d\n", answer[i]);
    }

    return 0;
}