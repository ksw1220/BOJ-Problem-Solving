#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int num[1001], dp[1001], in[1001];
bool visit[1001];
vector<int> graph[1001];
stack<int> sorted;
void dfs(int now) {
	visit[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		int to = graph[now][i];
		if (visit[to])continue;
		dfs(to);
	}
	sorted.push(now);
}
void dp_dfs(int now) {
	for (int i = 0; i < graph[now].size(); i++) {
		int to = graph[now][i];
		dp[to] = max(dp[to], dp[now] + num[to]);
	}
}
int main() {
	int T, N, K, a, b, W;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &num[i]);
			dp[i] = num[i];
			graph[i].clear();
			in[i] = 0;
			visit[i] = false;
		}
		while (K--) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			in[b]++;
		}
		for (int i = 1; i <= N; i++)if(in[i]==0)dfs(i);
		while (!sorted.empty()) {
			dp_dfs(sorted.top());
			sorted.pop();
		}
		scanf("%d", &W);
		printf("%d\n", dp[W]);
	}
	return 0;
}