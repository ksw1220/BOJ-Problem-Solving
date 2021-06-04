#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

int arr[21][21];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool chk[21][21];
typedef struct pos
{
    int x, y, dis;
} P;
queue<pos> que;

bool findNext(int &nowX, int &nowY, int &size, int &cnt, int &answer, int N)
{
    if(chk[nowX][nowY]){
        return false;
    }
    bool visit[21][21];
    memset(visit, false, sizeof(visit));
    while (!que.empty())
        que.pop();
    vector<pos> can;
    chk[nowX][nowY]=true;
    que.push({nowX, nowY, 0});
    int standard = -1;
    while (!que.empty())
    {
        pos now= que.front();
        int X = que.front().x;
        int Y = que.front().y;
        int D = que.front().dis;
        que.pop();
        // Check prey
        if (arr[X][Y] != 0 && size > arr[X][Y])
        {
            if(standard==-1){
                standard=D;
            }
            if(D==standard){
                can.push_back(now);
                      }
        }
        if(standard!=-1)continue;
        // Next pos
        for (int dir = 0; dir < 4; dir++)
        {
            int toX = X + dx[dir];
            int toY = Y + dy[dir];

            if (toX >= N || toY >= N || toX < 0 || toY < 0)
                continue;
            if (visit[toX][toY] || size < arr[toX][toY])
                continue;
            visit[toX][toY] = true;
            que.push({toX, toY, D + 1});
        }
    }
    if(standard==-1)return false;
    // renew
    nowX=can[0].x;
    nowY=can[0].y;
    for(int i=1;i<can.size();i++){
        if(nowX>can[i].x){
            nowX=can[i].x;
            nowY=can[i].y;
        }
        else if(nowX==can[i].x&&nowY>can[i].y){
            nowX=can[i].x;
            nowY=can[i].y;
        }
    }
    arr[nowX][nowY]=0;
    cnt++;
    if(cnt>=size){
        cnt=0;
        size++;
    }
    answer+=can[0].dis;

    return true;
}
int main()
{
    int N, nowX, nowY, size = 2, cnt = 0, answer = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 9)
            {
                nowX = i;
                nowY = j;
                arr[i][j] = 0;
            }
        }
    }
    while (findNext(nowX, nowY, size, cnt, answer, N)){}
    printf("%d", answer);
    return 0;
}