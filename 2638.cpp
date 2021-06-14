#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
bool visit[101][101];
typedef struct pos
{
    int x, y;
} P;

queue<pos> cheezes, remains, blanks;

void CheckBlank()
{
    visit[0][0] = true;
    blanks.push({0, 0});

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
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            visit[i][j] = false;
        }
    }
}
int main()
{
    int answer = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                remains.push({i, j});
            }
        }
    }

    while (!remains.empty())
    {
        answer++;
        CheckBlank();
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
    }

    printf("%d\n", answer);
    return 0;
}