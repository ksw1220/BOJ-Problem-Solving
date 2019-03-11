#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 187654321
using namespace std;
vector<pair<int, int>> graph[801];
priority_queue<pair<int, int>> pq;
int dist[801];
int main() {
	int N, E, a, b, c, s, e;
	int mid, s_1, s_N, e_1, e_N;
	scanf("%d %d", &N, &E);
	for (int i = 1; i <= N; i++)dist[i] = INF;
	while (E--) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	scanf("%d %d", &s, &e);
	dist[s] = 0;
	pq.push({ -0,s });
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
	mid = dist[e], s_1 = dist[1], s_N = dist[N];
	for (int i = 1; i <= N; i++)dist[i] = INF;
	dist[e] = 0;
	pq.push({ -0,e });
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
	e_1 = dist[1], e_N = dist[N];
	int ans = mid + min(s_1 + e_N, s_N + e_1);
	if (ans >= INF)ans = -1;
	printf("%d", ans);
	return 0;
}