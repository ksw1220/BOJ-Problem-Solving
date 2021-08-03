#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> board(9, vector<int>(9, 0));
vector<pair<int, int>> candidate;
bool check = false;
bool isSudoku(int x, int y, int value)
{
    for (int j = 0; j < 9; j++)
    {
        if (board[x][j] == value)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == value)
        {
            return false;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[x / 3 * 3 + i][y / 3 * 3 + j] == value)
            {
                return false;
            }
        }
    }
    return true;
}

void dfs(int now)
{
    if (check)
        return;
    if (now == candidate.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d", board[i][j]);
            }
            printf("\n");
        }
        check = true;
        return;
    }

    for (int value = 1; value <= 9; value++)
    {
        if (isSudoku(candidate[now].first, candidate[now].second, value))
        {
            board[candidate[now].first][candidate[now].second] = value;
            dfs(now + 1);
            board[candidate[now].first][candidate[now].second] = 0;
        }
    }
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%1d", &board[i][j]);
            if (board[i][j] == 0)
            {
                candidate.push_back({i, j});
            }
        }
    }

    dfs(0);
    return 0;
}