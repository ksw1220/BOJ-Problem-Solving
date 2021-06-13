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

void CheckBlank(int N, int M)
{
    queue<pos> blanks;
    bool visit[101][101];
    blanks.push({0, 0});
    visit[0][0] = true;

    while (!blanks.empty())
    {
        pos now = blanks.front();
        blanks.pop();

        arr[now.x][now.y] = 2;
        for (int dir = 0; dir < 4; dir++)
        {
            int tox = now.x + dx[dir];
            int toy = now.y + dy[dir];
            if (tox < 0 || toy < 0 || tox >= N || toy >= M)
                continue;
            if (visit[tox][toy] || arr[tox][toy] == 1)
                continue;
            visit[tox][toy] = true;
            blanks.push({tox, toy});
        }
    }
}
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
    arr[0][0] = 2;

    while (!remains.empty())
    {
        answer++;
        CheckBlank(N, M);
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
                if (arr[tox][toy] == 2)
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
                    arr[i][j] = 2;
            }
        }
    }

    printf("%d\n", answer);
    return 0;
}