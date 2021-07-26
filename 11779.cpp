#include<stdio.h>
#include<queue>
#include<vector>

#define INF 987654321
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> dist;

typedef struct NODE{
    int index,distance;
}NODE;

struct compare {
	bool operator()(const NODE& a, const NODE& b) {
		return a.distance > b.distance;
	}
};
priority_queue<NODE,vector<NODE>,compare> nodes;



int main(){
    int N,M;
    int s,e,d;
    int start,end;

    scanf("%d",&N);
    scanf("%d",&M);
    
    adj.assign(N+1,vector<pair<int,int>>(0,{0,0}));
    dist.assign(N+1,INF);
    while(M--){
        scanf("%d %d %d",&s,&e,&d);
        adj[s].push_back({e,d});
    }

    scanf("%d %d",&start,&end);

    dist[start]=end;
    nodes.push({start,0});

    while(!nodes.empty()){
        NODE now=nodes.top();
        nodes.pop();
        dist[now.index]=now.distance;

        for(int i=0;i<adj[now.index].size();i++){
            int next=adj[now.index][i].first;
            int nextDist=adj[now.index][i].second;
            if(dist[next]>now.distance+nextDist){
                nodes.push({next,now.distance+nextDist});
            }
        }
    }

    printf("%d\n",dist[end]);
    return 0;
}