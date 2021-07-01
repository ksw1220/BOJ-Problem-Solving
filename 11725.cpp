#include<stdio.h>
#include<vector>

using namespace std;

vector<int> adj[100001];
vector<bool> visit(100001,false);
vector<int> parent(100001,1);
void dfs(int now){
    visit[now]=true;

    for(int i=0;i<adj[now].size();i++){
        int to=adj[now][i];
        if(visit[to])continue;
        parent[to]=now;
        dfs(to);
    }

    visit[now]=false;
}
int main(){
    int N,a,b;
    scanf("%d",&N);
    for(int i=0;i<N-1;i++){
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    for(int i=2;i<=N;i++){
        printf("%d\n",parent[i]);
    }
    return 0;
}