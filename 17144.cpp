#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> arr, tmp;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void diffusion(int R, int C, int a1, int a2)
{
    tmp.assign(R, vector<int>(C, 0));
    tmp[a1][0] = tmp[a2][0] = -1;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == -1)
                continue;
            int cnt = 0;
            int diff = arr[i][j] / 5;
            for (int dir = 0; dir < 4; dir++)
            {
                int tox = i + dx[dir];
                int toy = j + dy[dir];
                if (tox < 0 || toy < 0 || tox >= R || toy >= C || tmp[tox][toy] == -1)
                    continue;
                tmp[tox][toy] += diff;
                cnt++;
            }
            tmp[i][j] += (arr[i][j] - cnt * diff);
        }
    }
    arr = tmp;
}

void airCondition(int R, int C, int a1, int a2)
{
    tmp = arr;

    tmp[a1][1] = tmp[a2][1] = 0;
    for (int j = 2; j < C; j++)
    {
        tmp[a1][j] = arr[a1][j - 1];
    }

    for (int i = a1 - 1; i >= 0; i--)
        tmp[i][C - 1] = arr[i + 1][C - 1];

    for (int j = C - 2; j >= 0; j--)
        tmp[0][j] = arr[0][j + 1];

    for (int i = 1; i < a1; i++)
        tmp[i][0] = arr[i - 1][0];


    for (int j = 2; j < C; j++)
        tmp[a2][j] = arr[a2][j - 1];

    for (int i = a2 + 1; i < R; i++)
        tmp[i][C - 1] = arr[i - 1][C - 1];

    for (int j = C - 2; j >= 0; j--)
        tmp[R - 1][j] = arr[R - 1][j + 1];

    for (int i = R - 2; i > a2; i--)
        tmp[i][0] = arr[i + 1][0];

    arr = tmp;
}

int sumOfDust(int R, int C)
{
    int sum = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum + 2;
}

int main()
{
    int R, C, T, answer;
    int a1 = -1, a2 = -1;

    scanf("%d %d %d", &R, &C, &T);
    arr.assign(R, vector<int>(C, 0));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == -1)
            {
                if (a1 == -1)
                    a1 = i;
                else
                    a2 = i;
            }
        }
    }

    while (T--)
    {
        diffusion(R, C, a1, a2);
        airCondition(R, C, a1, a2);
        answer = sumOfDust(R, C);
    }

    printf("%d\n", answer);
    return 0;
}