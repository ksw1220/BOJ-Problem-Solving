#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef struct PIPE
{
    int x, y, status;
} PIPE;

queue<PIPE> pipes;
vector<vector<int>> arr;
int N;

void horizontal(PIPE pipe)
{
    if (pipe.y + 1 < N && !arr[pipe.x][pipe.y + 1])
        pipes.push({pipe.x, pipe.y + 1, 0});
}
void vertical(PIPE pipe)
{
    if (pipe.x + 1 < N && !arr[pipe.x + 1][pipe.y])
        pipes.push({pipe.x + 1, pipe.y, 1});
}
void diagonal(PIPE pipe)
{
    if (pipe.x + 1 < N && pipe.y + 1 < N && !arr[pipe.x + 1][pipe.y] && !arr[pipe.x][pipe.y + 1] && !arr[pipe.x + 1][pipe.y + 1])
        pipes.push({pipe.x + 1, pipe.y + 1, 2});
}

int main()
{
    int answer = 0;
    scanf("%d", &N);
    arr.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    pipes.push({0, 1, 0});
    while (!pipes.empty())
    {
        PIPE now = pipes.front();
        pipes.pop();

        if (now.x == N - 1 && now.y == N - 1)
        {
            answer++;
        }

        if (now.status != 1)
            horizontal(now);
        if (now.status != 0)
            vertical(now);
        diagonal(now);
    }
    printf("%d\n", answer);
    return 0;
}