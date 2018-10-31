#include<stdio.h>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;
queue<int> que;
vector<pair<int, int>> tree[40001];
int height[40001], parent[40001], dist[40001];
bool visit[40001];
int main() {
	int N, M, a, b, c;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	height[1] = 0;
	dist[1] = 0;
	que.push(1);
	visit[1] = true;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < tree[now].size(); i++) {
			int to = tree[now][i].first;
			int toDis = tree[now][i].second;
			if (visit[to])continue;
			height[to] = height[now] + 1;
			dist[to] = dist[now] + toDis;
			visit[to] = true;
			parent[to] = now;
			que.push(to);
		}
	}
	scanf("%d", &M);
	while (M--) {
		scanf("%d %d", &a, &b);
		int f, s, root;
		s = b; f = a;
		if (height[a] > height[b]) {
			while (height[s]!=height[f]) {
				f = parent[f];
			}
		}
		else if (height[a] < height[b]) {
			while (height[s] != height[f]) {
				s = parent[s];
			}
		}
		while (s != f) {
			s = parent[s];
			f = parent[f];
		}
		root = s;
		int ans = dist[a] + dist[b] - 2 * dist[root];
		printf("%d\n", ans);
	}
	return 0;
}