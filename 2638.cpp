#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
typedef struct pos
{
    int x, y;
} P;

queue<pos> cheezes, remains;
int main()
{
    int N, M, answer = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                remains.push({i, j});
                //printf("push %d %d\n",i,j);
            }
        }
    }
    while (!remains.empty())
    {
        answer++;
        while (!remains.empty())
        {
            cheezes.push(remains.front());
            remains.pop();
        }
        while (!cheezes.empty())
        {
            pos now = cheezes.front();
            cheezes.pop();
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int tox = now.x + dx[dir];
                int toy = now.y + dy[dir];
                if (arr[tox][toy] == 0)
                    cnt++;
            }
            if (cnt >= 2)
            {
                arr[now.x][now.y] = -1;
            }
            else
            {
                remains.push({now.x, now.y});
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] == -1)
                    arr[i][j] = 0;
            }
        }
    }

    printf("%d", answer);
    return 0;
}