#include<stdio.h>
#include<vector>

#define INF 987654321
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> dist;
void dfs(int now){

    for(int i=0;i<adj[now].size();i++){
        int next=adj[now][i].first;
        int nextDist=adj[now][i].second;
        if(dist[next]>dist[now]+nextDist){
            dist[next]=dist[now]+nextDist;
        }
    }
}
int main(){
    int N,M,start,end;
    int s,e,d;
    scanf("%d %d",&N,&M);

    adj.resize(N+1);
    dist.assign(N+1,INF);
    while(M--){
        scanf("%d %d %d",&s,&e,&d);
        adj[s].push_back({e,d});
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<adj[i].size();i++){
            printf(" %d %d %d\n",i,adj[i][j].first,adj[i][j].second);
        }
    }
    scanf("%d %d",&start,&end);

    dist[start]=0;
    dfs(start);

    printf("%d\n",dist[end]);
    return 0;
}