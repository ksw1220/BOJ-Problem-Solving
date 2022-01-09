#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, answer = 0;
bool chk = true;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<vector<bool>> visited;
vector<vector<int>> board, dp;

void dfs(int x, int y, int cnt)
{
    if (!chk)
    {
        return;
    }
    else
    {
        answer = answer > cnt ? answer : cnt;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir] * board[x][y];
        int toy = y + dy[dir] * board[x][y];
        if (tox < 0 || toy < 0 || tox >= N || toy >= M || board[tox][toy] == 0)
            continue;
        if (visited[tox][toy])
        {
            chk = false;
            return;
        }
        if (dp[tox][toy] < cnt + 1)
        {
            dp[tox][toy] = cnt + 1;
            visited[tox][toy] = true;
            dfs(tox, toy, cnt + 1);
            visited[tox][toy] = false;
        }
    }
}
int main()
{
    string line;
    cin >> N >> M;
    visited.assign(N, vector<bool>(M, false));
    board.assign(N, vector<int>(M, 0));
    dp.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            if (line[j] == 'H')
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = line[j] - '0';
            }
        }
    }

    visited[0][0] = true;
    dp[0][0] = 0;
    dfs(0, 0, 0);

    if (chk)
    {
        cout << answer + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}