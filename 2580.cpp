#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int sudoku[9][9];
bool square[3][3][10];
bool rows[9][10], cols[9][10];

typedef struct pos
{
    int x, y;
} P;
vector<pos> can;

void back_tracking(int cnt, int N, bool &chk)
{
    if (chk)
        return;
    if (cnt == N)
    {
        chk = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
        return;
    }
    int x = can[cnt].x;
    int y = can[cnt].y;
    for (int i = 1; i <= 9; i++)
    {
        if (!square[x / 3][y / 3][i] && !rows[x][i] && !cols[y][i])
        {
            square[x / 3][y / 3][i] = rows[x][i] = cols[y][i] = true;
            sudoku[x][y] = i;
            back_tracking(cnt + 1, N, chk);
            square[x / 3][y / 3][i] = rows[x][i] = cols[y][i] = false;
            sudoku[x][y] = 0;
        }
    }
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] == 0)
            {
                pos tmp = {i, j};
                can.push_back(tmp);
            }
            square[i / 3][j / 3][sudoku[i][j]] = true;
            rows[i][sudoku[i][j]] = true;
            cols[j][sudoku[i][j]] = true;
        }
    }
    bool chk = false;
    back_tracking(0, can.size(), chk);
    return 0;
}