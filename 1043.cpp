#include<stdio.h>
int parent[51];
int truth[51];
int peo[51][51];
int find(int x){
	if(parent[x]==x)return x;
	else return parent[x]=find(parent[x]);
}
int main(){
	int N,M,T;
	scanf("%d %d",&N,&M);
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&truth[i]);
		parent[truth[i]]=0;
	}
	
	for(int i=1;i<=N;i++){
		parent[i]=i;
	}
	
	for(int p=0;p<M;p++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&peo[p][i]);
		}
		for(int i=0;i<n-1;i++){
			int a=peo[p][i];
			int b=peo[p][i+1];
			a=find(a);
			b=find(b);
			if(b!=a)parent[b]=a;
		}
	}

	for(int i=1;i<=N;i++){
		printf("%d ",parent[i]);
	}
	return 0;
}
