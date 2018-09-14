#include<stdio.h>
#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
int dp[501][501];
int main() {
	int N, M, a, b, ans = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++)for (int j = 0; j <= N; j++)dp[i][j] = INF;
	for (int i = 0; i <= N; i++)dp[i][i] = 0;
	while (M--) {
		scanf("%d %d", &a, &b);
		dp[a][b] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == INF&&dp[j][i] == INF) {
				cnt++;
				break;
			}
		}
		if (cnt == 0)ans++;
	}
	printf("%d", ans);
	return 0;
}