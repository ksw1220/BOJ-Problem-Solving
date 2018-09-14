#include<iostream>
#include<stdio.h>
using namespace std;
int dp[21][21];
int dist[21][21];
int N, ans = 0;
void func(int s, int e) {
	if (dist[s][e] != 0 && dist[s][e] <= dp[s][e])return;
	int cnt = 0;
	for (int k = 1; k <= N; k++) {
		if (s == k || e == k)continue;
		
		if (dp[s][e] == dp[s][k] + dp[k][e]) {
			cnt++;
			func(s, k);
			func(k, e);
		}
	}
	if (cnt == 0) {
		dist[s][e] = dist[e][s] = dp[s][e];
		ans += dp[s][e];
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)scanf("%d", &dp[i][j]);
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) {
		for (int k = 1; k <= N; k++) {
			if (dp[i][j] > dp[i][k] + dp[k][j]) {
				printf("-1");
				return 0;
			}
		}
		if (i == j)continue;
		func(i, j);
	}
	printf("%d", ans);
	return 0;
}