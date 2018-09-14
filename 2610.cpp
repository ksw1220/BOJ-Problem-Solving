#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
int dist[101][101];
bool visit[101];
vector<int> ans;
vector<int> group[101];
queue<int> que;
int main() {
	int N, M, a, b;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i <= N; i++)for (int j = 0; j <= N; j++)dist[i][j] = INF;
	for (int i = 0; i <= N; i++)dist[i][i] = 0;
	while (M--) {
		scanf("%d %d", &a, &b);
		dist[a][b] = dist[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int team = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i])continue;
		visit[i] = true;
		group[team].push_back(i);
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			if (dist[i][j] > 0 && dist[i][j] != INF) {
				group[team].push_back(j);
				visit[j] = true;
			}
		}
		team++;
	}
	for (int k = 0; k < team; k++) {
		int MIN = INF;
		int idx;
		for (int i = 0; i < group[k].size(); i++) {
			int tmp = 0;
			int now = group[k][i];
			for (int j = 0; j < group[k].size(); j++) {
				int to = group[k][j];
				tmp = max(tmp, dist[now][to]);
			}
			if (tmp < MIN) {
				MIN = tmp;
				idx = now;
			}
		}
		ans.push_back(idx);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", team);
	for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);
	return 0;
}