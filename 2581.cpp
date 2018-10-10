#include<stdio.h>
bool prime[100001];
int main() {
	int M, N;
	prime[0] = prime[1] = true;
	for (int i = 2; i*i <= 10000; i++) {
		if (!prime[i]) {
			for (int j = i + i; j <= 10000; j += i) {
				prime[j] = true;
			}
		}
	}
	scanf("%d %d", &M, &N);
	int ans = -1, sum = 0;
	for (int i = M; i <= N; i++) {
		if (!prime[i]) {
			if (ans == -1)ans = i;
			sum += i;
		}
	}
	if (ans == -1)printf("-1");
	else printf("%d\n%d", sum, ans);
	return 0;
}