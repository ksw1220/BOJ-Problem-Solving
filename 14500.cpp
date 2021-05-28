#include<stdio.h>

int arr[501][501];
bool visit[501][501];
int N,M;
int answer=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int cnt,int acc){
    visit[x][y]=true;
    acc+=arr[x][y];
    if(cnt==4){
        if(answer<acc)answer=acc;
        visit[x][y]=false;
        return;
    }
    for(int dir=0;dir<4;dir++){
        int tox=x+dx[dir];
        int toy=y+dy[dir];
        if(tox<0||toy<0||tox>=N||toy>=M||visit[tox][toy])continue;
        dfs(tox,toy,cnt+1,acc);
    }
    visit[x][y]=false;
    return;
}
void dfs2(int x,int y){
    int tmp[4];
    int sum=0;
    for(int dir=0;dir<4;dir++){
        int tox=x+dx[dir];
        int toy=y+dy[dir];
        if(tox<0||toy<0||tox>=N||toy>=M)continue;
        tmp[dir]=arr[tox][toy];
        sum+=tmp[dir];
    }
    sum+=arr[x][y];
    for(int dir=0;dir<4;dir++){
        int target=sum-tmp[dir];
        if(answer<target)answer=target;
    }
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dfs(i,j,1,0);
            dfs2(i,j);
        }
    }
    printf("%d",answer);
    return 0;
}