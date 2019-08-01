#include<stdio.h>
int map[102][102], ans[102];
int main() {
	int N, a, b, c, d;
	scanf("%d", &N);
	for(int iter=1;iter<=N;iter++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = a; i < a + c; i++) {
			for (int j = b; j < b + d; j++) {
				map[i][j] = iter;
			}
		}
	}
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			ans[map[i][j]]++;
		}
	}
	for (int i = 1; i <= N; i++)printf("%d\n", ans[i]);
	return 0;
}