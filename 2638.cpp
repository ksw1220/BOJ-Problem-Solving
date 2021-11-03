#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> cheezes, nextCheezes;

void dfs(int x, int y)
{
    grid[x][y] = 2;
    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];

        if (tox < 0 || toy < 0 || tox >= N || toy >= M || visited[tox][toy] || grid[tox][toy] == 1)
            continue;

        visited[tox][toy] = true;
        dfs(tox, toy);
    }
}
int main()
{
    int answer = 0;
    cin >> N >> M;
    grid.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                cheezes.push_back({i, j});
            }
        }
    }

    while (cheezes.size())
    {

        visited.assign(N, vector<bool>(M, false));
        visited[0][0] = true;
        dfs(0, 0);

        for (int i = 0; i < cheezes.size(); i++)
        {
            int airCount = 0;
            int x = cheezes[i].first;
            int y = cheezes[i].second;
            for (int dir = 0; dir < 4; dir++)
            {
                int tox = x + dx[dir];
                int toy = y + dy[dir];
                if (tox < 0 || toy < 0 || tox >= N || toy >= M)
                    continue;
                if (grid[tox][toy] == 2)
                    airCount++;
            }
            if (airCount >= 2)
            {
                grid[x][y] = 0;
            }
            else
            {
                nextCheezes.push_back({x, y});
            }
        }
        answer++;
        cheezes = nextCheezes;
        nextCheezes.clear();
    }

    cout << answer << endl;
    return 0;
}