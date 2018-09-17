#include<stdio.h>
bool prime[1001];
int main() {
	int N, K, cnt = 0;
	scanf("%d %d", &N, &K);
	prime[0] = prime[1] = true;
	for (int i = 2; i <= N; i++) {
		if (prime[i])continue;
		for (int j = i; j <= N; j += i) {
			if (prime[j])continue;
			prime[j] = true;
			cnt++;
			if (cnt == K) {
				printf("%d", j);
				return 0;
			}
		}
	}
	return 0;
}