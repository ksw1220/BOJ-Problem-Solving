#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int,int>> adj[100001];
bool visit[100001];
int ans=0;
int e=1;
void dfs(int now,int dist){
	for(int i=0;i<adj[now].size();i++){
		int next=adj[now][i].first;
		int next_d=adj[now][i].second;
		if(visit[next])continue;
		visit[next]=true;
		dfs(next,dist+next_d);
		visit[next]=false;
	}
	if(dist>ans){
		ans=dist;
		e=now;
	}
	return;
}
int main(){
	int V;
	scanf("%d",&V);
	for(int i=1;i<=V;i++){
		int now,n,d;
		scanf("%d",&now);
		while(1){
			scanf("%d",&n);
			if(n==-1)break;;
			scanf("%d",&d);
			adj[now].push_back({n,d});
		}
	}
	visit[1]=true;
	dfs(1,0);
	visit[1]=false;
	visit[e]=true;
	dfs(e,0);
	visit[e]=false;
	printf("%d",ans);
	return 0;
}
