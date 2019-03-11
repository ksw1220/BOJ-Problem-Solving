#include<stdio.h>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[20001];
priority_queue<pair<int,int>> pq;
int main() {
	int dist[20001];
	int V, E, K, a, b, c;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 1; i <= V; i++)dist[i] = INF;
	while (E--) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
	}
	pq.push({ -0,K });
	dist[K] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int nowDis = -pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int to = graph[now][i].first; 
			int toDis = graph[now][i].second + nowDis;
			if (dist[to] > toDis) {
				dist[to] = toDis;
				pq.push({ -toDis,to });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
} 