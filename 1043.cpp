#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int graph[51][51];
int group[51][51];
bool visit[51];
int S[51];
queue<int> que;
int main(){
	int N,M,T,ans=0;
	int truth[51];
	scanf("%d %d",&N,&M);
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&truth[i]);
		que.push(truth[i]);
		visit[truth[i]]=true;
	}
	for(int i=0;i<M;i++){
		scanf("%d",&S[i]);
		for(int j=0;j<S[i];j++){
			scanf("%d",&group[i][j]);
		}
		for(int j=0;j<S[i]-1;j++){
			graph[group[i][j]][group[i][j+1]]=graph[group[i][j+1]][group[i][j]]=1;
		}
	}
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(int i=1;i<=N;i++){
			if(graph[now][i]==0||visit[i])continue;
			visit[i]=true;
			que.push(i);
		}
	}
	for(int i=0;i<M;i++){
		int chk=true;
		for(int j=0;j<S[i];j++){
			if(visit[group[i][j]]){
				chk=false;
				break;
			}
		}
		if(chk){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
