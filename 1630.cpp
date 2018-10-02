#include<stdio.h>
int prime[1000001];
int N;
long long ans = 1;
long long func(int now) {
	long long re = 1;
	while (1) {
		if (re*now > N)break;
		re *= now;
	}
	return re % 987654321;
}
int main() {
	prime[0] = prime[1] = 1;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		if (prime[i] == 0) {
			for (int j = i + i; j <= N; j += i) prime[j] = 1;
		}
	}
	for (int i = N; i >= 2; i--) {
		if (prime[i] == 0) {
			long long tmp = func(i);
			tmp %= 987654321;
			ans = (ans*tmp) % 987654321;
		}
	}
	printf("%lld", ans);
	return 0;
}