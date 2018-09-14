#include<stdio.h>
#include<iostream>
#include<algorithm>
#define INF 987654321
int dp[251][251];
using namespace std;
int main() {
	int N, M, K, a, b, c;
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++)for (int j = 0; j <= N; j++)dp[i][j] = INF;
	for (int i = 0; i <= N; i++)dp[i][i] = 0;
	while (M--) {
		scanf("%d %d %d", &a, &b, &c);
		if (c == 0) dp[b][a] = 1, dp[a][b] = 0;
		else dp[a][b] = dp[b][a] = 0;
	}
	for (int k = 1; k <= N; k++) 
		for(int i=1;i<=N;i++)
			for (int j = 1; j <= N; j++) {
				if (dp[i][j]>dp[i][k]+dp[k][j]) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
	scanf("%d", &K);
	while (K--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
	return 0;
}