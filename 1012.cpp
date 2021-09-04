#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> field;
vector<vector<bool>> visited;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];

        if (tox < 0 || toy < 0 || tox >= M || toy >= N || !field[tox][toy] || visited[tox][toy])
            continue;

        dfs(tox, toy);
    }
}
int main()
{
    int T, K, a, b;
    cin >> T;

    while (T--)
    {
        int answer = 0;

        cin >> M >> N >> K;
        field.assign(M, vector<bool>(N, false));
        visited.assign(M, vector<bool>(N, false));

        while (K--)
        {
            cin >> a >> b;
            field[a][b] = true;
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (field[i][j] && !visited[i][j])
                {
                    dfs(i, j);
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }

    return 0;
}