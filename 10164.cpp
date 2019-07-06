#include<stdio.h>
long long comb[30][30];
int main() {
	int N, M, K, x, y;
	long long ans;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i <= 28; i++)
		for (int j = 0; j <= 28; j++)
			comb[i][j] = 1;
	for (int i = 2; i <= 28; i++) {
		for (int j = 1; j <= i - 1; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
	if (K == 0) {
		ans = comb[N + M - 2][N - 1];
	}
	else {
		x = (K - 1) / M;
		y = (K - 1) % M;
		ans = comb[x + y][x] * comb[N + M - x - y - 2][M - y - 1];
	}
	printf("%lld", ans);
	return 0;
}