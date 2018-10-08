#include<stdio.h>
#include<algorithm>
using namespace std;
int graph[501][501];
int T[501];
int dp[501];
int N, a, b;
void dfs(int now) {
	for (int i = 1; i <= N; i++) {
		if (graph[now][i] == 1) {
			if (dp[i] < dp[now] + T[i]) {
				dp[i] = dp[now] + T[i];
				dfs(i);
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &T[i]);
		dp[i] = T[i];
		while (1) {
			scanf("%d", &a);
			if (a == -1)break;
			graph[a][i] = 1;
		 }
	}
	for (int i = 1; i <= N; i++) {
		dfs(i);
	}
	for (int i = 1; i <= N; i++)printf("%d\n", dp[i]);
	return 0;
}