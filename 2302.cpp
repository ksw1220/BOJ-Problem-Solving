#include<stdio.h>
int num[42], dp[42];
int main() {
	int N, M, pre = 0, now, cnt = 0, ans = 1;
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d", &now);
		num[cnt++] = now - pre - 1;
		pre = now;
	}
	num[cnt++] = N - pre;
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 40; i++)dp[i] = dp[i - 1] + dp[i - 2];
	for (int i = 0; i < cnt; i++) ans *= dp[num[i]];
	printf("%d", ans);
	return 0;
}