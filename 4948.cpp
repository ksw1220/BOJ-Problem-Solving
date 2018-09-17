#include<stdio.h>
bool prime[300001];
int main() {
	prime[0] = prime[1] = true;
	for (int i = 2; i*i <= 300000; i++) {
		if (!prime[i]) {
			for (int j = i + i; j <= 300000; j += i) {
				prime[j] = true;
			}
		}
	}
	int N, ans = 0;
	while (1) {
		ans = 0;
		scanf("%d", &N);
		if (N == 0)break;
		for (int i = N; i <= 2 * N; i++) {
			if (!prime[i])ans++;
		}
		printf("%d\n",ans)
	}
	return 0;
}